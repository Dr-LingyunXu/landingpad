#!/bin/python
#to be motion following
#success!
#mostly. (if you count flower patterns as success.)
#(and I do.)

import rospy
from std_msgs.msg import Bool, UInt16
from geometry_msgs.msg import Twist
from math import pi

class follow_bug():
	def __init__(self):
		#state of robot
		self.x = 0.0
		self.y = 0.0 
		self.t = 0.0 #which is theta
		self.mode = 0
		self.count = 0
		#self.c = 0

		#wall sensing
		self.bump_left = False
		self.bump_right = False
		self.wall = 0 
		self.last_wall = 0	
		self.state = 0

		#movement speed
		self.speed_scale = 1.0
		self.linear_x = self.speed_scale * 0.3
		self.angular_z = self.speed_scale * pi/2

		#ros pub/sub
		self.cmd_vel_pub = rospy.Publisher('cmd_vel', Twist)
		self.bump_left_sub = rospy.Subscriber('bump/left', Bool, self.bumpLeftCB)
		self.bump_right_sub = rospy.Subscriber('bump/right', Bool, self.bumpRightCB)
		self.wall_sub = rospy.Subscriber('wall', UInt16, self.wallCB)
		rospy.init_node('boundry_following_node') 


	#callbacks
	def bumpLeftCB(self, msg):
		self.bump_left = msg.data

	def bumpRightCB(self, msg):
		self.bump_right = msg.data

	def wallCB(self, msg):
		self.wall = msg.data #gives us a number between 0 and 290


	#movement functions
	def forward(self, msg):
		msg.linear.x=self.linear_x 
		for i in range (1,7):
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
	def b_follow(self, msg):
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

		if self.wall > 270: #too close; turn left
			self.turn_left(msg) 

		if self.wall > 0: #go forward
			self.forward(msg)

		if self.wall == self.last_wall and self.wall!=0: #you're stuck somehow
			self.turn_left(msg)
			self.turn_left(msg)
			self.forward(msg)
			self.turn_left(msg)


	#event loop
	def spin(self):
		while not rospy.is_shutdown():
			msg = Twist() 
			#check to see if we've hit an obstacle
			if self.wall > 10: self.mode=1

			if (self.bump_left or self.bump_right) and self.mode==0:
				if self.bump_left: flag=1
				if self.bump_right: flag=2

				self.back_up(msg)
				#print("back up")
				if flag == 1: self.paral(msg)
				if flag == 2: self.parar(msg)

			if self.mode == 3: self.paral(msg)
			if self.mode == 4: self.parar(msg)

			if self.mode == 0: #go find a boundry.
				self.forward(msg)

			if self.mode == 1: #youve found a boundry, so follow it.
				self.b_follow(msg)

			rospy.sleep(.015) #~66hz


#main
if __name__ == '__main__':
	try:
		bot = follow_bug()
		bot.spin()
	except rospy.ROSInterruptException:
		pass






	
	
