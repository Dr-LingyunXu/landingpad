#to be the new tangent bug
	
import rospy
from math import atan2, sqrt, pi, cos, sin
from std_msgs.msg import Bool, UInt16
from geometry_msgs.msg import Twist, PoseStamped
from sensor_msgs.msg import LaserScan
from tf import transformations


#bug stuff
class bugt():
	def __init__(self):
		#state of robot
		self.x = 0.0
		self.y = 0.0 
		self.last_x = 0.0
		self.last_y = 0.0
		self.t = 0.0 #which is theta
		self.mode = 0
		self.count = 0

		#scanning
		self.range_max = 0.0
		self.ranges = []
		self.a_increment = 0.015956
		self.a_max = 0.0
		self.a_min = 0.0

		#wall sensing
		self.bump_left = False
		self.bump_right = False
		self.last_wall = 0	

		#boundary follow
		self.follow_closest_x = 0
		self.follow_closest_y = 0

		#movement speed
		self.speed_scale = 1.0
		self.linear_x = self.speed_scale * 0.3
		self.angular_z = self.speed_scale * pi/2

		#ros pub/sub
		self.cmd_vel_pub = rospy.Publisher('cmd_vel', Twist)
		self.sim_pose_sub = rospy.Subscriber('sim_pose', PoseStamped, self.poseCB)
		self.bump_left_sub = rospy.Subscriber('bump/left', Bool, self.bumpLeftCB)
		self.bump_right_sub = rospy.Subscriber('bump/right', Bool, self.bumpRightCB)
		self.wall_sub = rospy.Subscriber('wall', UInt16, self.wallCB)
		self.scan_sub = rospy.Subscriber('scan', LaserScan, self.scanCB)

		rospy.init_node('bugt')

		#goal
		self.goal_x = rospy.get_param("goal_x", 2);
		self.goal_y = rospy.get_param("goal_y", 2.5);


	#callbacks
	def poseCB(self,msg): 
		self.x = msg.pose.position.x
		self.y = msg.pose.position.y
		self.t = transformations.euler_from_quaternion(
			[msg.pose.orientation.x, msg.pose.orientation.y,
			msg.pose.orientation.z, msg.pose.orientation.w])[2]

	def scanCB(self, msg):#do we need intensities?
		self.range_max = msg.range_max
		self.ranges = msg.ranges
		self.a_increment = msg.angle_increment
		self.a_max = msg.angle_max
		self.a_min = msg.angle_min

	def bumpLeftCB(self, msg):
		self.bump_left = msg.data

	def bumpRightCB(self, msg):
		self.bump_right = msg.data

	def wallCB(self, msg):
		self.wall = msg.data #gives us a number between 0 and 290


	#helpers
	def angleTo(self, x, y):
		return atan2(y - self.y, x - self.x) #may not need?

	def angleToGoal(self):
		return self.angleTo(self.goal_x, self.goal_y)

	def distanceTo(self, x, y):
		return sqrt((y - self.y) * (y - self.y) +
					(x - self.x) * (x - self.x)) #is this not eq to **2?

	def distanceToGoal(self):
		return self.distanceTo(self.goal_x, self.goal_y)

	#tanbug helpers
	def hitDistToGoal(self, x, y):
		return sqrt((self.goal_y - y) * (self.goal_y - y)+
					(self.goal_x - x) * (self.goal_x - x))

	def hitPoint(self, angle, dist):
		x = dist*cos(angle)
		y = dist*sin(angle)
		return [x,y]


	#movement functions
##############
#START FOLLOW#
##############
	def forward(self, msg):
		msg.linear.x=self.linear_x 
		for i in range (1,10):
			self.cmd_vel_pub.publish(msg)
			rospy.sleep(.015)

	def back_up(self, msg):
		msg.linear.x = -self.linear_x
		for i in range(1,13): 
			self.cmd_vel_pub.publish(msg)
			rospy.sleep(.015)
		msg.linear.x = 0.0
		self.cmd_vel_pub.publish(msg)

	def turn_left(self, msg):
		msg.angular.z = self.angular_z
		for i in range(1,15):
			self.cmd_vel_pub.publish(msg)
			rospy.sleep(.015)
		msg.angular.z = 0.0
		self.cmd_vel_pub.publish(msg)

	def turn_right(self, msg):
		msg.angular.z = -self.angular_z
		for i in range(1,10):
			self.cmd_vel_pub.publish(msg)
			rospy.sleep(.015)
		msg.angular.z = 0.0
		self.cmd_vel_pub.publish(msg)

	#attempt to make yourself parallel to the object (from a left_bump)
	def paral(self, msg):
		self.mode = 3
		self.count = self.count + 1
		self.turn_left(msg)
		if self.wall>150:
			self.mode = 1
		if self.count > 1:
			self.forward(msg)
			self.mode = 1
		rospy.sleep(.015)
		self.cmd_vel_pub.publish(msg)

	#attempt to make yourself parallel to the object (from a right_bump)
	def parar(self, msg):
		self.mode = 4
		self.count = self.count + 1
		self.turn_left(msg)
		if self.wall>150:
			self.mode = 1
		if self.count == 1:
			self.forward(msg)
			self.mode = 1
		rospy.sleep(.015)
		self.cmd_vel_pub.publish(msg)

	#following algorithm
	def follow(self,msg):
		self.last_wall = self.wall 

		if self.bump_right: #you're too close; back up and turn left.
			self.count = 0
			self.back_up(msg)
			self.parar(msg)

		if self.wall < 3: #you've lost your wall; go find it.
			if self.bump_left:
				self.back_up(msg)
				self.count = 0
				self.paral(msg)
			else:
				self.turn_right(msg)	
			self.forward(msg)
			self.forward(msg)

		if self.wall > 280: #too close; turn left
			self.turn_left(msg) 

		if self.wall > 0: #go forward
			self.forward(msg)

		if self.wall == self.last_wall and self.wall!=0: #you're stuck somehow
			self.turn_left(msg)
			self.turn_left(msg)
			self.forward(msg)
			self.turn_left(msg)
###############
##END FOLLOW###
###############

	def toward_point(self, x, y, msg):
		tgt = self.angleTo(x,y) - self.t

		#if positive, turn left
		if tgt > .1:
			msg.angular.z = self.angular_z

		#if negative, turn right
		elif tgt < -.1:
			msg.angular.z = -self.angular_z 

		#if close to zero, compensate for difference and go forward
		elif tgt > 0:
			msg.angular.z = self.angular_z
			msg.linear.x = self.linear_x
		elif tgt < 0:
			msg.angular.z = -self.angular_z
			msg.linear.x = self.linear_x

		self.cmd_vel_pub.publish(msg)
		rospy.sleep(.015)


	#tanbug specific
	def goal_scan(self):
		spot = int((self.angleToGoal()-self.t)/self.a_increment)
		for i in self.ranges[min(spot-1,0):min(spot+1,len(self.ranges))]:
			if i > self.range_max or i > self.distanceToGoal():
				return False
		return True
		
	def scanner(self): 
		#set up list
		O = [] 
		
		#set initial mode
		mode = 0 #for, was previously R

		#set up a loop
		i = 0
		while i < len(self.ranges): 
			#get distance informations #should also check disconts
		
			hit = self.ranges[i] 
			ang = self.a_min + i*self.a_increment 
			
			if hit >= self.range_max and mode == 1:
				O.append([ang,hit])
				mode = 0
			
			if hit < self.range_max and mode == 0:
				O.append([ang,hit])
				mode = 1
			i = i+1
				
		return O


	#spin
	def spin(self):
		while not rospy.is_shutdown():
			msg = Twist()

			#check for goal
			if self.distanceToGoal() < .1:
				print('Goal!')
				self.cmd_vel_pub.publish(msg)
				break

			if self.mode == 3: self.paral(msg)
			if self.mode == 4: self.parar(msg)

			if self.mode!=1:
				O = self.scanner()
				if self.goal_scan() == True: self.mode = 0
				elif len(O) == 0: self.mode = 0
				else: self.mode = 2 

			#check for hit obst
			if self.bump_left: self.mode=5
			if self.bump_right: self.mode=5 

			#move towards goal
			if self.mode == 0:
				self.toward_point(self.goal_x, self.goal_y, msg)

			if self.mode == 2: #sensed a hit
				best = self.hitPoint(O[0][0], O[0][1]) 
				i = 1
				while i < len(O):
					curr = self.hitPoint(O[i][0], O[i][1])
					if self.hitDistToGoal(curr[0],curr[1]) < self.hitDistToGoal(best[0],best[1]):
						best = curr
					i = i+1
				#move towards best
				#print(best)
				self.toward_point(best[0], best[1], msg) 

			#set up to boundry follow
			if self.mode==5:
				self.follow_start_x = self.x
				self.follow_start_y = self.y	
				self.mode = 1	
		
			#boundary following mode
			if self.mode == 1: #boundary follow
				self.follow(msg) 
				if self.goal_scan(): 
					self.mode = 0
					#print('free!')

			rospy.sleep(.015)


if __name__ == '__main__':
	try:
		bug = bugt()
		bug.spin()
	except rospy.ROSInterruptException:
		pass


