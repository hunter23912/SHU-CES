import cv2 as cv
import numpy as np

# 读取图像
img = cv.imread('letter.jpg')

# 从图像中截取出需要的字母和数字，调整高度一致
W = img[305:390,180:270]
A = img[20:105,26:106]
N = img[115:200,480:555]
G = img[20:105,485:575]
J = img[115:200,190:250]
I = img[115:200,140:185]
H = img[115:200,65:140]
O = img[210:295,30:115]
one = img[400:480, 120:180]
two = img[400:480, 180:260]
three = img[400:480, 260:320]
zero = img[495:575, 405:470]    
six = img[495:575, 125:200]

# 将姓名和学号构成list
name = [W, A, N, G, J, I,A,N,G, H,A, O]
id = [two,two,one,two,one,six,three,zero]

# 水平拼接
name_row = np.hstack(name)
id_row = np.hstack(id)

# 创建一个合适的背景
background_color = (211,223,229) #颜色选取原背景色
background_height = name_row.shape[0] + id_row.shape[0] + 100
background_width = max(name_row.shape[1], id_row.shape[1])
result = np.full((background_height, background_width, 3), background_color, dtype=np.uint8)

# 将连接好的内容放到指定位置
result[50:50 + name_row.shape[0], 0:name_row.shape[1]] = name_row
result[50 + name_row.shape[0]:50 + name_row.shape[0]+id_row.shape[0], 0:id_row.shape[1]] = id_row

# 显示并保存图片
cv.imshow('result', result)
cv.imwrite('result.jpg', result)
# cv.imwrite('name.jpg', name_row)
# cv.imwrite('id.jpg', id_row)

# cv.imshow('image_W', W)
# cv.imshow('image_A', A)
# cv.imshow('image_N', N)
# cv.imshow('image_G', G)
# cv.imshow('image_I', I)
# cv.imshow('image_O', O)
# cv.imshow('image_J', J)
# cv.imshow('image_H', H)
# cv.imshow('image_one', one)
# cv.imshow('image_two', two)
# cv.imshow('image_three', three)
# cv.imshow('image_six', six)
cv.waitKey(0)
cv.destroyAllWindows()