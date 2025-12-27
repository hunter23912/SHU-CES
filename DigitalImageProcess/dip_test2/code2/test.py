import cv2 as cv
import numpy as np


# 最近邻插值法
def nearest(img, scale):
    height, width, channels = img.shape
    new_height = int(height * scale)
    new_width = int(width * scale)
    new_img = np.zeros((new_height, new_width, channels), dtype=np.uint8)

    for i in range(new_height):
        for j in range(new_width):
            x = int(i / scale)
            y = int(j / scale)
            new_img[i, j] = img[x, y]
    return new_img


# 双线性插值法
def bilinear(img, scale):
    height, width, channels = img.shape
    new_height = int(height * scale)
    new_width = int(width * scale)
    new_img = np.zeros((new_height, new_width, channels), dtype=np.uint8)

    for i in range(new_height):
        for j in range(new_width):

            # 找出原图中对应的周围4个像素点
            x = (i + 0.5) / scale - 0.5
            y = (j + 0.5) / scale - 0.5
            x0 = int(np.floor(x))
            y0 = int(np.floor(y))
            x1 = min(x0 + 1, height - 1)
            y1 = min(y0 + 1, width - 1)

            # 双线性插值,对像素颜色进行修正
            for c in range(channels):
                a = (x1 - x) * img[x0, y0, c] + (x - x0) * img[x1, y0, c]
                b = (x1 - x) * img[x0, y1, c] + (x - x0) * img[x1, y1, c]
                new_img[i, j, c] = np.clip(int((y1 - y) * a + (y - y0) * b), 0, 255)

    return new_img


test1 = cv.imread("./test1/test1.jpg")
test2 = cv.imread("./test2/test2.jpg")

# opencv自带的resize函数
# res = cv.resize(test2, None, fx=2, fy=2, interpolation=cv.INTER_NEAREST)

# res = nearest(test2, 2)
res = bilinear(test1, 2)

cv.imshow("res", res)
cv.imwrite("./test1/test1_inter_bilinear_byself.jpg", res)
cv.waitKey(0),
cv.destroyAllWindows()
# print(test2.shape)
