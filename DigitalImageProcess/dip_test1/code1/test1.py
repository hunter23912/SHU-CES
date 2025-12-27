import numpy as np
import cv2 as cv

# 创建黑色图像
img = np.zeros((512, 512, 3), np.uint8)
# 绘制蓝色对角线，厚度为5
cv.line(img,(0,0),(511,511),(255,0,0),5)

cv.rectangle(img,(384,0),(510,128),(0,255,0),3)

cv.circle(img,(447,63),63,(0,0,255),-1)

cv.ellipse(img,(256,256),(100,50),90,0,180,255,-1)

font = cv.FONT_HERSHEY_SIMPLEX
cv.putText(img,'OpenCV',(10,500), font, 4,(255,255,255),2,cv.LINE_AA)
cv.imshow('image', img)
cv.waitKey(0)
