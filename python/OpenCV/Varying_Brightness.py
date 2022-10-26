# Varying Brightness of Images using Add and Subtract Operations

# Import Computer Vision package - cv2
import cv2

# Import Numerical Python package - numpy as np
import numpy as np

# Read the image using imread built-in function
image = cv2.imread('image_2.jpg')

# Display original image using imshow built-in function
cv2.imshow("Original", image)

# Wait until any key is pressed
cv2.waitKey(0)

# np.ones returns an array of given shape and type, filled with ones
# np.ones(shape, dtype)

matrix = np.ones(image.shape, dtype = "uint8") * 120 
# image.shape: gives takes the shape of original image
# uint8: unsigned integer (0 to 255)
# matrix: contains ones, having same dimension as original image but mutlipied by 120

# Adding matrix to orginal image, increases brightness 
add = cv2.add(image, matrix)

# Display added image
cv2.imshow("Added", add)

# Wait until any key is pressed
cv2.waitKey(0)

# Subtracting matrix and original image, decreases brightness
subtract = cv2.subtract(image, matrix)

# Display subtracted image
cv2.imshow("Subtracted", subtract)

# Wait untill any key is pressed
cv2.waitKey(0)

# Close all windows
cv2.destroyAllWindows()
