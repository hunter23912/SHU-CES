import cv2 as cv
import numpy as np

# 读取图片
img = cv.imread("./green.png")
bg = cv.imread("./tree.jpg")

# 将green转换为HSV颜色空间
hsv = cv.cvtColor(img, cv.COLOR_BGR2HSV)

# 定义绿色的范围,三个值分别是H、S、V，表示色调、饱和度、亮度
lower_green = np.array([30, 100, 0])
upper_green = np.array([85, 255, 255])

# 创建掩膜，选择绿色背景
mask = cv.inRange(hsv, lower_green, upper_green)

# 反转掩膜,选择人物
mask_inv = cv.bitwise_not(mask)

# 使用掩膜将人物从green中抠出
person = cv.bitwise_and(img, img, mask=mask_inv)

# 将tree调整为与green相同大小，宽、高
bg_resized = cv.resize(bg, (img.shape[1], img.shape[0]))

# 使用掩膜将背景从tree中抠出
bg_masked = cv.bitwise_and(bg_resized, bg_resized, mask=mask)

result = cv.add(person, bg_masked)

cv.imwrite("task3.jpg", result)
cv.imshow("result", result)
cv.waitKey(0)
cv.destroyAllWindows()
