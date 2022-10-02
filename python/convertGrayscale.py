#SHORTCUT FOR GRAYSCALE
import cv2
img = cv2.imread('1.jpg',0)
cv2.imshow('GRAYSCALE IMAGE',img)
cv2.waitKey(0)
cv2.destroyAllWindows()
