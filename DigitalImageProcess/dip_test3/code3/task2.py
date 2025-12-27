import cv2 as cv
import numpy as np
import matplotlib.pyplot as plt

# 设置图片字体
plt.rcParams["font.sans-serif"] = ["SimHei"]
plt.rcParams["axes.unicode_minus"] = False


def histogram_equalization(img):

    # 将图像转为灰度图
    img_gray = cv.cvtColor(img, cv.COLOR_BGR2GRAY)

    # 计算灰度图像的直方图
    # hist纵坐标数值数组，bins是直方图的横坐标
    hist, bins = np.histogram(img_gray.flatten(), 256, [0, 256])

    # 计算累计分布函数
    cdf = hist.cumsum()  # 累积函数，表示每个灰度级的累计像素数量

    # 使用cdf对图像均衡化
    cdf_m = np.ma.masked_equal(cdf, 0)  # 掩盖cdf数组中的0值

    # 按权重映射到0-255之间
    cdf_m = (cdf_m - cdf_m.min()) * 255 / (cdf_m.max() - cdf_m.min())
    cdf = np.ma.filled(cdf_m, 0).astype("uint8")  # 恢复掩盖的0值

    # 将原图像的灰度级映射到均衡化后的灰度级
    img_res = cdf[img_gray]

    return img_res


# 绘制直方图及均衡化后的直方图
def plot_histograms(img, img_res, img_res_cv):

    plt.figure(figsize=(10, 10))

    # 原始图像及其直方图
    plt.subplot(3, 2, 1)
    plt.imshow(cv.cvtColor(img, cv.COLOR_BGR2RGB))
    plt.title("hill原图像")
    plt.axis("off")

    plt.subplot(3, 2, 2)
    plt.hist(img.ravel(), 256, [0, 256], color="black")
    plt.title("hill原图像直方图")
    # 关闭纵坐标
    # plt.gca().axes.get_yaxis().set_visible(False)

    # 均衡化后的图像及其直方图
    plt.subplot(3, 2, 3)
    plt.imshow(img_res, cmap="gray")
    plt.title("自实现均衡化后的hill图像")
    plt.axis("off")

    plt.subplot(3, 2, 4)
    plt.hist(img_res.ravel(), 256, [0, 256], color="black")
    plt.title("自实现均衡化后的hill图像直方图")

    # opencv直方图均衡化后的图像及其直方图
    plt.subplot(3, 2, 5)
    plt.imshow(img_res_cv, cmap="gray")
    plt.title("opencv均衡化后的hill图像")
    plt.axis("off")

    plt.subplot(3, 2, 6)
    plt.hist(img_res_cv.ravel(), 256, [0, 256], color="black")
    plt.title("opencv均衡化后的hill图像直方图")

    # 调整图像参数
    plt.tight_layout()
    plt.subplots_adjust(
        left=0.01, right=0.95, top=0.95, bottom=0.05, wspace=0.3, hspace=0.3
    )
    plt.savefig("../hill_result.png")
    plt.show()


img = cv.imread("../hill.jpg")
img_res = histogram_equalization(img)
# 使用opencv的直方图均衡化
img_res_cv = cv.equalizeHist(cv.cvtColor(img, cv.COLOR_BGR2GRAY))

plot_histograms(img, img_res, img_res_cv)

# cv.imwrite("../hill_equalization.jpg", img_res)
# cv.imshow("after_img", img_res)
# cv.waitKey(0)
# cv.destroyAllWindows()
