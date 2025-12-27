import time
import cv2 as cv
import numpy as np
import heapq
import os
from collections import Counter
from bitarray import bitarray
import matplotlib.pyplot as plt

# 为代码添加注释


# 哈夫曼树节点
# 频率，符号，左右子节点，当前节点的哈夫曼编码
class HuffmanNode:
    def __init__(self, freq, symbol, left=None, right=None):
        self.freq = int(freq)
        self.symbol = int(symbol)
        self.left = left
        self.right = right
        self.huff = None

    # 重载小于运算符，用于在优先队列中比较节点的频率
    def __lt__(self, other):
        return self.freq < other.freq


# 构建哈夫曼树，frequency为符号频率字典
def build_huffman_tree(frequency):
    heap = [HuffmanNode(freq, symbol) for symbol, freq in frequency.items()]
    heapq.heapify(heap)  # 将列表转换为优先队列

    while len(heap) > 1:
        left = heapq.heappop(heap)
        right = heapq.heappop(heap)
        left.huff = 0
        right.huff = 1
        newNode = HuffmanNode(
            left.freq + right.freq, left.symbol + right.symbol, left, right
        )
        heapq.heappush(heap, newNode)

    return heap[0]


# 递归构建哈夫曼编码,
def build_codes(node, val=None):
    if val is None:
        val = bitarray()
    # 构造哈夫曼键值对[symbol:编码]
    codes = {}
    if node:
        newVal = val.copy()
        if node.huff is not None:
            newVal.append(node.huff)
        if not node.left and not node.right:
            codes[node.symbol] = newVal
        codes.update(build_codes(node.left, newVal))
        codes.update(build_codes(node.right, newVal))
    return codes


# 哈夫曼编码
def huffman_encoding(data):
    # 从大到小给出[像素值：频率]
    frequency = Counter(data)
    huffman_tree = build_huffman_tree(frequency)
    # 是一个字典[symbol:编码]
    huffman_codes = build_codes(huffman_tree)
    encoded_data = bitarray()

    #
    cnt = 0
    for symbol in data:
        encoded_data += huffman_codes[symbol]
        cnt += 1
    print(f"编码完毕,{cnt}个像素值已编码")
    return encoded_data, huffman_codes


# 哈夫曼解码
def huffman_decoding(encoded_data, huffman_codes, length):
    # reverse_codes = [编码：symbol]
    reverse_codes = {code.to01(): symbol for symbol, code in huffman_codes.items()}
    decoded_data = []
    current_code = ""
    # 写入解码,bit以字节为单位，每次读取一个字节，最后一个字节不足8位会补0
    cnt = 0
    for bit in encoded_data:
        current_code += "1" if bit else "0"
        # 检索字典中的键
        if current_code in reverse_codes:
            decoded_data.append(reverse_codes[current_code])
            cnt += 1
            if cnt == length:
                break
            current_code = ""
    print(f"解码完毕,{len(decoded_data)}个像素值已解码")
    return decoded_data


# ----------------------------------------------------------#


# 无损预测编码
def predictive_encoding(img):
    height, width = img.shape
    # 创建一个和原图像大小相同的数组
    img = img.astype(np.int16)
    pred_error = np.zeros((height, width), dtype=np.int16)
    for i in range(height):
        for j in range(width):
            if j == 0:
                pred_error[i][j] = img[i][j]
            else:
                pred_error[i][j] = img[i][j] - img[i][j - 1]
    return pred_error


# 无损预测解码
def predictive_decoding(pred_error):
    height, width = pred_error.shape
    img = np.zeros((height, width), dtype=np.int16)
    for i in range(height):
        for j in range(width):
            if j == 0:
                img[i, j] = pred_error[i, j]
            else:
                img[i, j] = pred_error[i, j] + img[i, j - 1]
    return img


# 压缩图片，无损预测方式
def compress_image_pre(img, output_path, huffman_codes_path):
    pred_error = predictive_encoding(img)
    flat_error = pred_error.flatten()
    encoded_data, huffman_codes = huffman_encoding(flat_error)

    with open(output_path, "wb") as f:
        encoded_data.tofile(f)

    with open(huffman_codes_path, "w") as f:
        for symbol, code in huffman_codes.items():
            f.write(f"{symbol} : {code.to01()}\n")
    return huffman_codes, pred_error.shape


# 解压图片，无损预测方式
def decompress_image_pre(encoded_path, huffman_codes, shape):
    encoded_data = bitarray()
    with open(encoded_path, "rb") as f:
        encoded_data.fromfile(f)

        length = shape[0] * shape[1]
        decoded_data = huffman_decoding(encoded_data, huffman_codes, length)

    pred_error = np.array(
        [int(pixel) for pixel in decoded_data], dtype=np.int16
    ).reshape(shape)
    decoded_img = predictive_decoding(pred_error)
    return decoded_img


# 压缩图片，哈夫曼方式
def compress_image(img, output_path, huffman_codes_path):

    shape = img.shape
    # 将图片像素值转换为一维数组
    flat_img = img.flatten()
    print(f"源图像的像素个数：{flat_img.size}")
    encoded_data, huffman_codes = huffman_encoding(flat_img)
    # 写入encoded_data
    with open(output_path, "wb") as f:
        encoded_data.tofile(f)

    # 写入huffman_codes
    with open(huffman_codes_path, "w") as f:
        for symbol, code in huffman_codes.items():
            f.write(f"{symbol} : {code}\n")

    return huffman_codes, shape


# 解压图片，哈夫曼方式
def decompress_image(encoded_path, huffman_codes, shape):

    encoded_data = bitarray()
    with open(encoded_path, "rb") as f:
        encoded_data.fromfile(f)  # 从文件中读取bit

    length = shape[0] * shape[1]
    decoded_data = huffman_decoding(encoded_data, huffman_codes, length)

    decoded_img = np.array(
        [int(pixel) for pixel in decoded_data], dtype=np.uint8
    ).reshape(shape)
    return decoded_img


# 计算RMSE,平均均方误差的平方根，对解压缩后的图像和原图像进行比较，并计算压缩比
def calculate_rmse(original, decompressed):
    mse = np.mean((original - decompressed) ** 2)
    rmse = np.sqrt(mse)
    return rmse


def task1():
    compressed_bits_path = "./task1_result/bridge_compressed.txt"
    huffman_codes_path = "./task1_result/bridge_huffman_codes.txt"

    img = cv.imread("./bridge.bmp", cv.IMREAD_UNCHANGED)
    # 记录压缩时间
    s_t = time.time()
    print("开始压缩")
    huffman_codes, shape = compress_image(img, compressed_bits_path, huffman_codes_path)
    compress_time = time.time() - s_t
    print(f"压缩时间：{compress_time:.4f}秒")

    # 记录解压缩时间
    s_t = time.time()
    print("开始解压缩")
    img_res = decompress_image(compressed_bits_path, huffman_codes, shape)
    decompress_time = time.time() - s_t
    print(f"解压缩时间：{decompress_time:.4f}秒")

    cv.imwrite("./task1_result/bridge_decompressed.bmp", img_res)

    # 计算RMSE
    rmse = calculate_rmse(img, img_res)
    print(f"RMSE: {rmse}")
    plt.figure(figsize=(10, 6))

    plt.tight_layout()
    plt.imshow(img_res, cmap="gray")
    plt.show()


if __name__ == "__main__":
    task1()
