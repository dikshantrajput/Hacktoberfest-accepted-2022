import cv2
import numpy as np
# from ast import pattern
import random
import sys
from PIL import Image, ImageDraw

# im, pattern, samples = sys.argv [1:]/
im = r"certificate_sample.jpg"
im2 = r"original_certificate.jpg"
pattern = r"sample.png"
text = "Divyam Gupta"
samples = "5"
def get_cor3(im):

    image = cv2.imread(im)
    # image = cv2.imread(im)
    original = image.copy()
    original1 = image.copy()
    # original1 = cv2.imread(im2)
    gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
    thresh = cv2.threshold(gray, 0, 255, cv2.THRESH_BINARY_INV + cv2.THRESH_OTSU)[1]
    cnts = cv2.findContours(thresh, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
    cnts = cnts[0] if len(cnts) == 2 else cnts[1]
    for c in cnts:
        x,y,w,h = cv2.boundingRect(c)
        if(h>100 or w>100):
            print("cordinates : ",x,w,y,h)
            font = cv2.FONT_HERSHEY_SIMPLEX
            org = (x, y+(h//2))
            fontScale = 1
            color = (255, 0, 0)
            thickness = 1
            original1 = cv2.putText(original1, text, org, font, 
                            fontScale, color, thickness, cv2.LINE_AA)
        cv2.rectangle(image, (x, y), (x + w, y + h), (0,0,255), 2)

    cv2.imshow('image', image)
    cv2.imshow('Thresh',thresh)
    cv2.imshow('Named',original1)
    cv2.waitKey()
# get_cor1(im,pattern,samples)
# get_cor2(im,pattern,samples)
get_cor3(im)





# def get_cor2(im,pattern,samples):
#     samples = int (samples)

#     im = Image.open (im)
#     walnut = Image.open (pattern)
#     print(walnut.size [0] - 1)
#     print(walnut.size [1] - 1)
#     pixels = []
#     while len (pixels) < samples:
#         x = random.randint (0, walnut.size [0] - 1)
#         y = random.randint (0, walnut.size [1] - 1)
#         pixel = walnut.getpixel ( (x, y) )
#         if pixel [-1] > 200:
#             pixels.append ( ( (x, y), pixel [:-1] ) )



#     print(pixels)
#     def diff (a, b):
#         return sum ( (a - b) ** 2 for a, b in zip (a, b) )

#     best = []

#     for x in range (im.size [0] ):
#         for y in range (im.size [1] ):
#             d = 0
#             for coor, pixel in pixels:
#                 try:
#                     ipixel = im.getpixel ( (x + coor [0], y + coor [1] ) )
#                     d += diff (ipixel, pixel)
#                 except IndexError:
#                     d += 256 ** 2 * 3
#             best.append ( (d, x, y) )
#             best.sort (key = lambda x: x [0] )
#             best = best [:3]

#     draw = ImageDraw.Draw (im)
#     for b in best:
#         x, y = b [1:]
#         draw.rectangle ( (x, y, x + walnut.size [0], y + walnut.size [1] ), outline = 'red')
#     im.save ('out.png')



# def get_cor1(im,pattern,samples):
#     im = Image.open (im)
#     # im.size = im.size
#     walnut = Image.open (pattern)
#     # walnut.size = walnut.size
#     x0, y0 = walnut.size [0] // 2, walnut.size [1] // 2
#     pixel = walnut.getpixel ( (x0, y0) ) [:-1]

#     def diff (a, b):
#         return sum ( (a - b) ** 2 for a, b in zip (a, b) )

#     best = (100000, 0, 0)
#     for x in range (im.size [0] ):
#         for y in range (im.size [1] ):
#             ipixel = im.getpixel ( (x, y) )
#             d = diff (ipixel, pixel)
#             if d < best [0]: best = (d, x, y)

#     draw = ImageDraw.Draw (im)
#     x, y = best [1:]
#     draw.rectangle ( (x - x0, y - y0, x + x0, y + y0), outline = 'red')
#     im.save ('out.png')
