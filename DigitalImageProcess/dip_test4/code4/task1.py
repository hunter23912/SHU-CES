import cv2 as cv
import numpy as np
import matplotlib.pyplot as plt

# 设置图片字体
plt.rcParams["font.sans-serif"] = ["SimHei"]
plt.rcParams["axes.unicode_minus"] = False


# 均值滤波
def average_filter(image, kernel_size):
    height, width = image.shape[0:2]
    offset = kernel_size // 2
    filtered_image = np.zeros((height, width, 3), dtype=np.uint8)
    for y in range(offset, height - offset):
        for x in range(offset, width - offset):
            window = image[y - offset : y + offset + 1, x - offset : x + offset + 1]
            mean = np.mean(window)
            filtered_image[y, x] = mean
    return filtered_image


# 中值滤波
def median_filter(image, kernel_size):
    # 获取图像尺寸
    height, width = image.shape[0:2]
    # 计算边界偏移量
    offset = kernel_size // 2
    filtered_image = np.zeros((height, width, 3), dtype=np.uint8)

    # 遍历每个像素
    for y in range(offset, height - offset):
        for x in range(offset, width - offset):
            window = image[y - offset : y + offset + 1, x - offset : x + offset + 1]
            # 计算中值
            median = np.median(window)
            # 将中值赋值给输出图像对应像素
            filtered_image[y, x] = median
    return filtered_image


# 画图函数
def show_images(img, img_average, img_median):
    fig = plt.figure(figsize=(16, 9))
    plt.subplot(1, 3, 1)
    plt.imshow(cv.cvtColor(img, cv.COLOR_BGR2RGB))
    plt.title("mona原图")
    plt.axis("off")

    plt.subplot(1, 3, 2)
    plt.imshow(cv.cvtColor(img_average, cv.COLOR_BGR2RGB))
    plt.title("mona均值滤波=3后图像")
    plt.axis("off")

    plt.subplot(1, 3, 3)
    plt.imshow(cv.cvtColor(img_median, cv.COLOR_BGR2RGB))
    plt.title("mona中值滤波=7后图像")
    plt.axis("off")

    fig.tight_layout()
    plt.savefig("./mona_filtered.jpg")
    plt.show()


space = cv.imread("./space.jpg")
mona = cv.imread("./mona.jpg")
pcb = cv.imread("./pcb.png")

# space_average = average_filter(space, 3)
# space_median = median_filter(space, 3)

mona_average = average_filter(mona, 3)
mona_median = median_filter(mona, 7)

# pcb_average = average_filter(pcb, 3)
# pcb_median = median_filter(pcb, 3)

show_images(mona, mona_average, mona_median)
