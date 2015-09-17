'''Calculates the cubic spline given 2 points, derivatives at those points, the time step at which
those points were taken, and the current time step'''

import sys

def cubicSpline(x0, y0, x1, y1, x0dot, y0dot, x1dot, y1dot, t, t0, t1):
    z = (t - t0) / (t1 - t0)
    zdot = 1.0 / (t1 - t0)
    
    a = x0dot * (t1 - t0) - (x1 - x0)
    b = -x1dot * (t1 - t0) + (x1 - x0)
    c = y0dot * (t1 - t0) - (y1 - y0)
    d = -y1dot * (t1 - t0) + (y1 - y0)
    
    #solves for x(t) and y(t)
    x = (1 - z) * x0 + z * x1 + z * (1 - z) * (a * (1 - z) + b * z)
    y = (1 - z) * y0 + z * y1 + z * (1 - z) * (c * (1 - z) + d * z)
    
    #solves for xdot(t) and ydot(t) where xdot and ydot are derivatives 
    #of x and y
    xdot = (x1 - x0 + (1 - 2 * z) * (a * (1 - z) + b * z) + z * (1 - z) * (b - a)) * zdot
    ydot = (y1 - y0 + (1 - 2 * z) * (c * (1 - z) + d * z) + z * (1 - z) * (d - c)) * zdot
    
    #solves for xddot(t) and yddot(t) where xddot and yddot are second
    #derivatives of x and y
    xddot = (-2 * (a * (1 - z) + b * z) + 2 * (1 - 2 * z) * (b - a)) * zdot**2
    yddot = (-2 * (c * (1 - z) + d * z) + 2 * (1 - 2 * z) * (d - c)) * zdot**2
    
    #return x, y, xdot, ydot, xddot, yddot in a list
    return [x, y, xdot, ydot, xddot, yddot]

#used for testing, arguments must be x0, y0, x1, y1, x0dot, y0dot,
#x1dot, y1dot, t, t0, t1
if(__name__ == "__main__"):
    px0 = float(sys.argv[1])
    py0 = float(sys.argv[2])
    px1 = float(sys.argv[3])
    py1 = float(sys.argv[4])
    px0dot = float(sys.argv[5])
    py0dot = float(sys.argv[6])
    px1dot = float(sys.argv[7])
    py1dot = float(sys.argv[8])
    time = float(sys.argv[9])
    time0 = float(sys.argv[10])
    time1 = float(sys.argv[11])
    print(cubicSpline(px0, py0, px1, py1, px0dot, py0dot, px1dot, py1dot, time, time0, time1))