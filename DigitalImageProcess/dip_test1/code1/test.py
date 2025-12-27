import cv2 as cv
import numpy as np

img = cv.imread('letter.jpg', -1)

# 将图像转换为灰度图像
gray = cv.cvtColor(img, cv.COLOR_BGR2GRAY)

# 应用阈值化以创建二值图像
_, thresh = cv.threshold(gray, 150, 255, cv.THRESH_BINARY_INV)

# 检测图像中的轮廓
contours, _ = cv.findContours(thresh, cv.RETR_EXTERNAL, cv.CHAIN_APPROX_SIMPLE)

# 创建一个空白掩膜
mask = np.zeros_like(img)

# 绘制轮廓到掩膜上
cv.drawContours(mask, contours, -1, (255, 255, 255), thickness=cv.FILLED)

# 使用掩膜提取字母和数字
result = cv.bitwise_and(img, mask)

# 显示结果
# cv.imshow('Original Image', img)
# cv.imshow('Threshold Image', thresh)#显示二值图像
cv.imshow('Extracted Letters and Numbers', result)#显示提取的字母和数字


cv.waitKey(0)
cv.destroyAllWindows()