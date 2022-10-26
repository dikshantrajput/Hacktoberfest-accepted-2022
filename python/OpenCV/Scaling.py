# Scaling (Resizing) Images - Cubic, Area, Linear Interpolations
# Interpolation is a method of estimating values between known data points 

# Import Computer Vision package - cv2
import cv2

# Import Numerical Python package - numpy as np
import numpy as np

# Read the image using imread built-in function
image = cv2.imread('image_2.jpg')

# Display original image using imshow built-in function
cv2.imshow("Original", image)

# Wait until any key is pressed
cv2.waitKey()

# cv2.resize(image, output image size, x scale, y scale, interpolation)

# Scaling using cubic interpolation
scaling_cubic = cv2.resize(image, None, fx=.75, fy=.75, interpolation = cv2.INTER_CUBIC)

# Display cubic interpolated image
cv2.imshow('Cubic Interpolated', scaling_cubic)

# Wait until any key is pressed
cv2.waitKey()

# Scaling using area interpolation
scaling_skewed = cv2.resize(image, (600, 300), interpolation = cv2.INTER_AREA)

# Display area interpolated image
cv2.imshow('Area Interpolated', scaling_skewed) 

# Wait until any key is pressed
cv2.waitKey()

# Scaling using linear interpolation
scaling_linear  = cv2.resize(image, None, fx=0.5, fy=0.5, interpolation = cv2.INTER_LINEAR)

# Display linear interpolated image
cv2.imshow('Linear Interpolated', scaling_linear) 

# Wait until any key is pressed
cv2.waitKey()

# Close all windows
cv2.destroyAllWindows()
