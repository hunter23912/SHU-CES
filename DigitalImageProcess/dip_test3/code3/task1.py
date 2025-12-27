# 实现gamma变换
import cv2 as cv
import numpy as np


# gamma变换，不使用查找表
def gamma_transform(img, gamma):
    return np.clip((img / 255.0) ** gamma * 255.0, 0, 255).astype(np.uint8)


# gamma变换，使用查找表
def gamma_transform_with_lut(img, gamma):

    # 创建lut
    lut = np.array([((i / 255.0) ** gamma) * 255 for i in np.arange(0, 256)]).astype(
        "uint8"
    )

    return cv.LUT(img, lut)


output_path1 = "../dark_gamma.jpg"
output_path2 = "../light_gamma.tif"

img1 = cv.imread("../dark.jpg")
img2 = cv.imread("../light.tif")

# img1_gamma = gamma_transform(img1, 0.5)
# img1_gamma = gamma_transform_with_lut(img1, 0.5)
img2_gamma = gamma_transform_with_lut(img2, 3)

cv.imwrite(output_path2, img2_gamma)
cv.imshow("res", img2_gamma)
cv.waitKey(0)
cv.destroyAllWindows()
