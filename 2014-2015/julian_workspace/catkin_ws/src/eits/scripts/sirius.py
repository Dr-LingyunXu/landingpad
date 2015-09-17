#!/usr/bin/env python
from math import atan2, sqrt, pi

import rospy
from std_msgs.msg import Bool, UInt16
from geometry_msgs.msg import Twist, PoseStamped
from tf import transformations


# sirius #
class sirius():
    def __init__(self):

        # State info
        self.x = 0.0;
        self.y = 0.0;
        self.t = 0.0;
        
        #Movement Speed
        self.speed_scale = 1.0
        self.linear_x = self.speed_scale * 0.3
        self.angular_z = self.speed_scale * 1.8
        
        #ROS Publishers go HERE
        self.cmd_vel_pub = rospy.Publisher('cmd_vel', Twist, queue_size=10)

        #initialize the node
        rospy.init_node('sirius')
        
    # Wrappers #
    def up(self,msg):
        msg.linear.z = 1.0
        self.cmd_vel_pub.publish(msg)
        
    def down(self,msg):
        msg.linear.z = -1.0
        self.cmd_vel_pub.publish(msg)
        

    # Event Loop #
    def spin(self):
        last_mode = 0
        uflag = False
        dflag = False
        print('Starting UAV Flight demo...')
        counter = 0
        while not rospy.is_shutdown():
            msg = Twist()
            if (counter > 900):
                uflag = False
                dflag = False
                counter = 0
            elif (counter < 500):
                if(not uflag):
                    print "going UP"
                    uflag = True
                    dflag = False
                self.up(msg)
            else:
                if(not dflag):
                    print "....and going back DOWN"
                    uflag = False
                    dflag = True
                self.down(msg)
            rospy.sleep(.015)
            counter = counter + 1
            

# Main #
if __name__ == '__main__':
    try:
        uav = sirius()
        uav.spin()
    except rospy.ROSInterruptException:
        pass
