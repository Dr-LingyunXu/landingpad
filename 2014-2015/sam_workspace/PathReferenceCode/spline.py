#!/bin/python

'''
Robot Wheel Base (axel length): 0.2635m
Robot Wheel Diameter: 0.0750m
'''

import rospy
import numpy as np
from scipy import interpolate
import matplotlib.pyplot as plt
from math import sqrt, pi
from trajectory_msgs.msg import JointTrajectory, JointTrajectoryPoint
from std_msgs.msg import Header

class curve_driving():
	def __init__(self):
#2pir^2
		self.diameter = 0.075
		self.radius = 5*self.diameter/2
		self.axel_length = 0.2635
		self.probsize = 0
		self.n = 1.01
		self.dt = .01 #but i should keep you.
		self.dist = 0.0
		self.v = 0.0
		#self.t = np.arange(0,1.01,self.dt) #i dont need to make these here, do i? am i just making this harder on myself? 

		self.dx = []
		self.dy = []

		self.joint_traj_pub = rospy.Publisher('joint_trajectory', JointTrajectory)
		rospy.init_node('following_a_curve_node')
		


#so what do we need?
#get spline, get derivatives(fake?), 

	def get_spline(self, x, y):
		tck,u = interpolate.splprep([x,y],s=0)
		t = np.arange(0, self.n, self.dt) #generates points 
		self.spline = interpolate.splev(t,tck) #evals spline
		return self.spline

	def compute_v(self, spline, t): #where t is current spot
		#print(t)
		dt = self.dt
		#print(spline)
		dy = (spline[1][t+1] - spline[1][t])/dt #may be backwards
		dx = (spline[0][t+1] - spline[0][t])/dt #think you may be miscalculating y
		ddy = (spline[1][t+1] - 2*spline[1][t] + spline[1][t-1])/(dt*dt)
		ddx = (spline[0][t+1] - 2*spline[0][t] + spline[0][t-1])/(dt*dt)
		
		'''dy/=(self.probsize-1)
		dx/=(self.probsize-1)
		ddy/=(self.probsize-1)
		ddx/=(self.probsize-1)'''

		#self.dx.append(dx)
		#self.dy.append(dy)

		#if t%10==0:
			#print(dx, dy)

		r = self.radius
		l = self.axel_length

		self.v = sqrt(dx*dx+dy*dy)
		v = self.v
		k = (dx*ddy - dy*ddx)/(v*v*v)

		v1 = (v/r)*(k*l+1)/(self.probsize-1)
		v2 = (v/r)*(-k*l+1)/(self.probsize-1)
		
		if t%10==0:
			print "Vel1: ", v1, "Vel2: ", v2

		return [v1,v2]


	def spin(self,x,y):
		spline = self.get_spline(x,y)
		i=1
		self.probsize = len(x) #probably
		#while not rospy.is_shutdown(): #should still have this somewhere
		while i < (int(self.n/self.dt)-1):
			myvel = self.compute_v(spline, i)
			mypoint = JointTrajectoryPoint(velocities=myvel)
			msg = JointTrajectory(header=Header(stamp=rospy.Time.now()),
				joint_names=['left_wheel_joint', 'right_wheel_joint'],
				points=[mypoint])#angular vel in rad/sec
			self.joint_traj_pub.publish(msg)
			tm = .02
			rospy.sleep(tm)
			

			self.dist += abs(self.v)*(tm)+.5*(tm)*(tm)

			i = i+1
			#print(i)

			#force rospy shutdown
			#rospy.shutdown('path complete') #im not sure this works. #it doesnt

		mypoint = JointTrajectoryPoint(velocities=[0.0, 0.0])
		msg = JointTrajectory(header=Header(stamp=rospy.Time.now()),
				joint_names=['left_wheel_joint', 'right_wheel_joint'],
				points=[mypoint])#angular vel in rad/sec
		self.joint_traj_pub.publish(msg)
		print('path complete')
		print('distance estimate: ', self.dist)
		#plt.plot(self.spline[0],self.spline[1])
		#plt.plot(self.dy)
		#plt.plot(self.dx)
		#plt.show()
		#break
		

if __name__ == '__main__':
	try:

		#x=y works. #sort of. #y=2x has the same dx as x=y. (but dy is doubled.)
		x = np.array([0,1,2,3])
		y = np.array([0,-1,0,-1])

		curve = curve_driving()
		curve.spin(x,y) 
	except rospy.ROSInterruptException:
		pass


