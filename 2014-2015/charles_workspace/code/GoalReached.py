import sys
from math import sqrt

#determines if the current position is within a certain threshold distance
#from the goal
def goalReached(pos_x, pos_y, goal_x, goal_y):
    threshold = .6
    dist = sqrt((goal_x - pos_x)**2 + (goal_y - pos_y)**2)
    if( abs(dist) < threshold):
        return True
    return False

#for testing the module
if (__name__ == '__main__'):
    print("x pos = " + sys.argv[1])
    print("y pos = " + sys.argv[2])
    print("x_goal = " + sys.argv[3])
    print("y_goal = " + sys.argv[4])
    diff = sqrt((float(sys.argv[3]) - float(sys.argv[1]))**2 + (float(sys.argv[4]) - float(sys.argv[2]))**2)
    print("difference = " + str(abs(diff)))
    print(goalReached(float(sys.argv[1]), float(sys.argv[2]), float(sys.argv[3]), float(sys.argv[4])))
