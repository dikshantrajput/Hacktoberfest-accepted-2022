# Flipping Images - Horizontally, Vertically, Horizontally & Vertically

# Import Computer Vision package - cv2
import cv2

# Read the image using imread built in function
image = cv2.imread('image_1.jpg')

# Display original image using imshow built in function
cv2.imshow("Original-Press any Key to contd", image)

# Wait until any key is pressed
cv2.waitKey(0)

# cv2.flip is used to flip images
# Horizontal flipping of images using value '1'
flipping = cv2.flip(image, 1)

# Display horizontally flipped image
cv2.imshow("Horizontal Flipping", flipping)

# Wait until any key is pressed
cv2.waitKey(0)

# Vertical flipping of images using value '0'
flipping = cv2.flip(image, 0)

# Display vertically flipped image
cv2.imshow("Vertical Flipping", flipping)

# Wait until any key is pressed
cv2.waitKey(0)

# Horizontal & Vertical flipping of images using value '-1'
flipping = cv2.flip(image, -1)

# Display horizontally & vertically flipped image
cv2.imshow("Horizontal & Vertical Flipping", flipping)

# Wait until any key is pressed
cv2.waitKey(0)

# Close all windows
cv2.destroyAllWindows()

