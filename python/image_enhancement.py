# pip install pillow
from PIL import Image,ImageFilter
from PIL import ImageEnhance
 
im = Image.open('img.jpg')
 
# Choose your filter
# add Hastag at start if you don't want to any filter below
en = ImageEnhance.Color(im)
en = ImageEnhance.Contrast(im)
en = ImageEnhance.Brightness(im)
en = ImageEnhance.Sharpness(im)
# result
en.enhance(1.5).show("enhanced")
