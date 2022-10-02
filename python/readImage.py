#READ THE IMAGE
import cv2
img = cv2.imread('1.jpg')# to read image
cv2.imshow('Output',img) # to display image
cv2.waitKey(3000) #wait for 3 secs , for 0 value it will stay forever
cv2.destroyAllWindows() #it closes all python windows if its open
