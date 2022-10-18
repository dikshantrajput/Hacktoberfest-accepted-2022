import numpy as np
import pandas as pd
import cv2 as cv
from google.colab.patches import cv2_imshow
from skimage import io
from PIL import Image
import matplotlib.pylab as plt

#change the url address according to your url make sure it is correct and not google own generated url
url = "https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcRrvajGCniEQoOTZw0T-P99E-TPmx2CxsaaAA&usqp=CAU"
image=io.imread ( url )
image_2=cv.cvtColor ( image , cv.COLOR_RGB2BGR )
final_frame = cv.hconcat ( ( image_2 , image ) )
cv2_imshow ( final_frame )

#This will show the data the image have!!
print ( image.dtype )
print ( image.shape )
print ( image.size )


#Will make an histogram
plt.hist ( image.ravel ( ) , bins=256 , range = [ 0,256 ] )
plt.show ( )


#Histogram of that image according to r g b colours
color=('b','g','r')
for i,col in enumerate(color):
    histr=cv.calcHist([image],[i],None,[256],[0,256])
    plt.plot(histr,color=col)
    plt.xlim([0,256])
plt.show()


#Image in black and white 
gray_image = cv.cvtColor ( image , cv.COLOR_BGR2GRAY )
cv2_imshow ( gray_image )