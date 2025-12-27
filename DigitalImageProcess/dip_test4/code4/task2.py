from matplotlib.gridspec import GridSpec as GS
import cv2 as cv
import numpy as np
import matplotlib.pyplot as plt

# 设置图片字体
plt.rcParams["font.sans-serif"] = ["SimHei"]
plt.rcParams["axes.unicode_minus"] = False


# 应用卷积核
def apply_kernel(image, kernel):
    # 获取图像尺寸
    height, width = image.shape

    # 获取卷积核尺寸
    k_height, k_width = kernel.shape

    # 计算边界偏移量
    offset_h = k_height // 2
    offset_w = k_width // 2

    # 创建一个空的输出图像
    filtered_image = np.zeros((height, width), dtype=np.float64)

    # 遍历图像的每个像素
    for x in range(offset_h, height - offset_h):
        for y in range(offset_w, width - offset_w):
            # 获取当前窗口内的像素值
            window = image[
                x - offset_h : x + offset_h + 1, y - offset_w : y + offset_w + 1
            ]

            # 计算卷积结果
            filtered_image[x, y] = np.sum(window * kernel)

    return filtered_image


# 拉普拉斯锐化
def laplacian_sharpen(image, laplacian_kernel):

    # 应用拉普拉斯算子-自实现方式
    laplacian = apply_kernel(image, laplacian_kernel)

    # 将拉普拉斯算子结果添加回原图像以实现锐化
    image_filtered = np.clip(image + laplacian, 0, 255).astype(np.uint8)

    return image_filtered


# 画图函数1(采用subplot)
def show_image1(img, img_filtered):
    plt.figure()

    plt.subplot(1, 2, 1)
    plt.imshow(img, cmap="gray")
    plt.title("blurry_moon原图")
    plt.axis("off")

    plt.subplot(1, 2, 2)
    plt.imshow(img_filtered, cmap="gray")
    plt.title("blurry_moon锐化后图像(算子4)")
    plt.axis("off")

    plt.tight_layout()
    # plt.savefig("./blurry_moon锐化后(算子4).tif")
    plt.show()


# 画图函数2(采用subplot2grid)
def show_image2(img, res1, res2, res3, res4):
    plt.figure(figsize=(15, 10))

    plt.subplot2grid((2, 3), (0, 0), rowspan=2)
    plt.imshow(img, cmap="gray")
    plt.title("blurry_moon原图")
    plt.axis("off")

    plt.subplot2grid((2, 3), (0, 1))
    plt.imshow(res1, cmap="gray")
    plt.title("blurry_moon锐化后图像(算子1)")
    plt.axis("off")

    plt.subplot2grid((2, 3), (0, 2))
    plt.imshow(res2, cmap="gray")
    plt.title("blurry_moon锐化后图像(算子2)")
    plt.axis("off")

    plt.subplot2grid((2, 3), (1, 1))
    plt.imshow(res3, cmap="gray")
    plt.title("blurry_moon锐化后图像(算子3)")
    plt.axis("off")

    plt.subplot2grid((2, 3), (1, 2))
    plt.imshow(res4, cmap="gray")
    plt.title("blurry_moon锐化后图像(算子4)")
    plt.axis("off")

    plt.tight_layout()
    # plt.savefig("./blurry_moon锐化后(算子4).tif")
    plt.show()


# 画图函数3(采用GridSpec)
def show_image3(img, res1, res2, res3, res4):
    fig = plt.figure(figsize=(15, 9))
    gs = GS(2, 3, figure=fig)

    ax1 = fig.add_subplot(gs[:, 0])
    ax1.imshow(img, cmap="gray")
    ax1.set_title("blurry_moon原图")
    ax1.axis("off")

    ax2 = fig.add_subplot(gs[0, 1])
    ax2.imshow(res1, cmap="gray")
    ax2.set_title("blurry_moon锐化后图像(算子1)")
    ax2.axis("off")

    ax3 = fig.add_subplot(gs[0, 2])
    ax3.imshow(res2, cmap="gray")
    ax3.set_title("blurry_moon锐化后图像(算子2)")
    ax3.axis("off")

    ax4 = fig.add_subplot(gs[1, 1])
    ax4.imshow(res3, cmap="gray")
    ax4.set_title("blurry_moon锐化后图像(算子3)")
    ax4.axis("off")

    ax5 = fig.add_subplot(gs[1, 2])
    ax5.imshow(res4, cmap="gray")
    ax5.set_title("blurry_moon锐化后图像(算子4)")
    ax5.axis("off")

    plt.tight_layout()
    plt.savefig("./blurry_moon_filtered.tif")
    plt.show()


####
# 主函数
blurry_moon = cv.imread("blurry_moon.tif", cv.IMREAD_GRAYSCALE)

# 定义四种拉普拉斯算子
laplacian_kernel1 = np.array([[0, -1, 0], [-1, 4, -1], [0, -1, 0]])
laplacian_kernel2 = np.array([[-1, -1, -1], [-1, 8, -1], [-1, -1, -1]])
laplacian_kernel3 = np.array([[0, 1, 0], [1, -4, 1], [0, 1, 0]])
laplacian_kernel4 = np.array([[1, 1, 1], [1, -8, 1], [1, 1, 1]])

# 生成拉普拉斯锐化后的图像
# res1 = laplacian_sharpen(blurry_moon, laplacian_kernel1)
# res2 = laplacian_sharpen(blurry_moon, laplacian_kernel2)
# res3 = laplacian_sharpen(blurry_moon, laplacian_kernel3)
# res4 = laplacian_sharpen(blurry_moon, laplacian_kernel4)

res1 = cv.imread("./res1.tif", cv.IMREAD_GRAYSCALE)
res2 = cv.imread("./res2.tif", cv.IMREAD_GRAYSCALE)
res3 = cv.imread("./res3.tif", cv.IMREAD_GRAYSCALE)
res4 = cv.imread("./res4.tif", cv.IMREAD_GRAYSCALE)


# 保存图片
# cv.imwrite("./res1.tif", res1)
# cv.imwrite("./res2.tif", res2)
# cv.imwrite("./res3.tif", res3)
# cv.imwrite("./res4.tif", res4)

# 画图
show_image3(blurry_moon, res1, res2, res3, res4)
