import numpy as np
import scipy as sp
import pylab as plt
from matplotlib.patches import Ellipse, Circle

NP = 200
t = np.arange(0, NP, 1)
x = np.zeros((NP))
y = np.zeros((NP))
x[0] = 0.0
y[0] = 0.0
gamma = 1.0
zeta = 0.1

for i in range (1, NP):
	Ua = (x-10)**2 + (y-10)**2
	Ur1 = gamma/((x[i-1]-2.5)**2+(y[i-1]-4.25)**2-4)
	Ur2 = gamma/((x[i-1]-7.5)**2+(y[i-1]-4.5)**2-1.8**2)
	Ur3 = gamma/((x[i-1]-8.5)**2+(y[i-1]-8.5)**2-.4**2) 

	Ur = Ur1+Ur2+Ur3
	U = Ua+Ur
#where is his attractive force? why can i not find his attractive force?

	#what is gamma? #oh. gamma is 1.
	#v = gamma/(((x[i-1]-3.0)**2+((y[i-1]-4.0)**2)/4-1.0)**2) #this is his ur.

	#this actually appears to be his ua. I'm gonna run with that.
	#vx = 2.0*(x[i-1]-5.0)-2*(x[i-1]-3)*v #i think this is his ua? vx and vy
	#vy = 2.0*(y[i-1]-6.0)-0.5*(y[i-1]-4)*v #i dont know what these numbers are or where they're coming from. #why is thisone .5? whatever i guess.
	vx = (x[i-1]-10.0)-4*(x[i-1]-2.5)*Ur1-1.8**2*(x[i-1]-7.5)*Ur2-.4**2*(x[i-1]-8.5)*Ur3
	vy = (y[i-1]-10.0)-4*(y[i-1]-4.25)*Ur1-1.8**2*(y[i-1]-4.5)*Ur2-.4**2*(y[i-1]-8.8)*Ur3 

	vn = np.sqrt(vx*vx+vy*vy)
	vx2 = vx/vn
	vy2 = vy/vn
	print Ur1, -vx2, -vy2
	x[i] = x[i-1]-zeta*vx2
	y[i] = y[i-1]-zeta*vy2

'''ell = Ellipse((3.0, 4.0), 2, 4, 0)
a = plt.subplot(111, aspect='equal')
ell.set_alpha(0.1)
a.add_artist(ell)'''

c1 = Circle((2.5,4.25),2) #he has a third number. do we need a third number?
c2 = Circle((7.5,4.5),1.8)
c3 = Circle((8.5,8.5),.4)

a = plt.subplot(111, aspect='equal') #assuming 111 makes it grey colored?

c1.set_alpha(0.1)
a.add_artist(c1)
c2.set_alpha(0.1)
a.add_artist(c2)
c3.set_alpha(0.1)
a.add_artist(c3)


plt.plot(x,y,'b.')
plt.xlabel('X')
plt.ylabel('Y')
plt.title('Path')
plt.show()
