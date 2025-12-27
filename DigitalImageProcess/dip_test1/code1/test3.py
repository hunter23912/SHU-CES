import numpy as np
import cv2 as cv

img = cv.imread('letter.jpg', -1)
# px = img[100, 100]
# print(px)

# blue = img[100, 100, 0]#获取像素值BGR,0代表蓝色
# print(blue)

# print(img.shape)#获取图像的形状
# print(img.size)#获取图像的大小

ball = img[280:340, 330:390]#行范围280-340，列范围330-390
img[273:333, 100:160] = ball#将ball放到行范围273-333，列范围100-160

cv.imshow('image', img)
cv.waitKey(0)
