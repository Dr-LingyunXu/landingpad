#AUTHOR: Jon Dixon

#The purpose of this code is just a quick and dirty hough transform circle detector.
#It just takes camera inputs and find circles, and plots them on the image.
#It works alright, but it needs some tweaking:
#
# 1) Try to limit the number of circles that can be detected.
# 2) Try to fiddle with the parameters for HoughCircles function.

#This method will work well if we go with a pad target that has a number of concentric circles!

#UPDATE: So it works pretty well, actually, the big problem seems to be that the results are noisy.
#        So, see how to reduce the noise!

import numpy as np
import cv2

cap = cv2.VideoCapture(0)

while(True):
	ret, frame = cap.read()

	if( frame == None ): continue

	frame = cv2.medianBlur(frame,5)
	gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)

	circles = cv2.HoughCircles(gray,cv2.HOUGH_GRADIENT,1,200,param1=50,param2=30,minRadius=15,maxRadius=0)
	circles = np.uint16(np.around(circles))

	for i in circles[0,:]:
		cv2.circle(gray, (i[0],i[1]),i[2],(0,255,0),2)
		cv2.circle(gray,(i[0],i[1]),2,(0,0,255),3)


	cv2.imshow('frame',gray)
	if cv2.waitKey(1) & 0xFF == ord('q'):
		break

cap.release()
cv2.destroyAllWindows()
