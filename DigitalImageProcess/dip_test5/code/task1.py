import cv2 as cv
import matplotlib.pyplot as plt

# 读取图片
img = cv.imread("./araras.jpg")

# 分离RGB三个通道
b, g, r = cv.split(img)

# 将每个通道转换为灰度图
gray_b = cv.cvtColor(cv.merge([b, b, b]), cv.COLOR_BGR2GRAY)
gray_g = cv.cvtColor(cv.merge([g, g, g]), cv.COLOR_BGR2GRAY)
gray_r = cv.cvtColor(cv.merge([r, r, r]), cv.COLOR_BGR2GRAY)

# 显示原图和灰度图
plt.figure(figsize=(10, 7))

plt.subplot(2, 2, 1)
plt.title("Original Image")
plt.imshow(cv.cvtColor(img, cv.COLOR_BGR2RGB))

plt.subplot(2, 2, 2)
plt.title("Blue Channel")
plt.imshow(gray_b, cmap="gray")

plt.subplot(2, 2, 3)
plt.title("Green Channel")
plt.imshow(gray_g, cmap="gray")

plt.subplot(2, 2, 4)
plt.title("Red Channel")
plt.imshow(gray_r, cmap="gray")

# 自动调整合适大小
plt.tight_layout()
plt.savefig("task1.jpg")
plt.show()
