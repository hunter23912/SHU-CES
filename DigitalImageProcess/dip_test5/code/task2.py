import cv2 as cv
import matplotlib.pyplot as plt


# 彩色图像的直方图均衡化
def img_eq_rgb(img):
    # 分离RGB三个通道
    b, g, r = cv.split(img)

    # 对每个通道进行直方图均衡化
    b = cv.equalizeHist(b)
    g = cv.equalizeHist(g)
    r = cv.equalizeHist(r)

    # 合并三个通道
    equalized_img = cv.merge([b, g, r])

    return equalized_img


def img_eq_hsv(img):
    # 转换到HSV空间
    hsv = cv.cvtColor(img, cv.COLOR_BGR2HSV)

    # 对亮度分量V进行直方图均衡化,三个维度分别表示高、宽和通道
    hsv[:, :, 2] = cv.equalizeHist(hsv[:, :, 2])

    # 转换回RGB空间
    equalized_img = cv.cvtColor(hsv, cv.COLOR_HSV2BGR)

    return equalized_img


# 显示原图和直方图均衡化后的图
def show(img, res_rgb, res_hsv):
    plt.figure(figsize=(10, 3))
    plt.subplot(1, 3, 1)
    plt.title("Original Image")
    plt.imshow(cv.cvtColor(img, cv.COLOR_BGR2RGB))

    plt.subplot(1, 3, 2)
    plt.title("Equalized Image(RGB)")
    plt.imshow(cv.cvtColor(res_rgb, cv.COLOR_BGR2RGB))

    plt.subplot(1, 3, 3)
    plt.title("Equalized Image (HSV)")
    plt.imshow(cv.cvtColor(res_hsv, cv.COLOR_BGR2RGB))

    plt.tight_layout()
    plt.savefig("task2_sky.jpg")
    plt.show()


# 读取图片
img1 = cv.imread("./sky.bmp")
img2 = cv.imread("./mushroom.png")

res1_rgb = img_eq_rgb(img1)
res1_hsv = img_eq_hsv(img1)
show(img1, res1_rgb, res1_hsv)

# res2_rgb = img_eq_rgb(img2)
# res2_hsv = img_eq_hsv(img2)
# show(img2, res2_rgb, res2_hsv)
