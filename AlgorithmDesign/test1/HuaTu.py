# 使用turtle库绘制棋盘覆盖问题
import turtle


# 读取矩阵
def read_matrix(file_path):
    matrix = []
    with open(file_path, "r") as file:
        for line in file:
            row = line.strip().split()
            # 去除空白字符，和换行符，然后按空格分割，再按空格分割成一个列表
            row = [int(x) if x.isdigit() else x for x in row]
            matrix.append(row)
    return matrix


cpp_output_matrix = read_matrix("output/Matrix.txt")

# 定义颜色映射
color_map = {
    0: "red",
    1: "yellow",
    2: "blue",
    3: "tan",
    4: "green",
    5: "purple",
    6: "orange",
    7: "silver",
    8: "pink",
    9: "gray",
    10: "cyan",
    11: "magenta",
    12: "gold",
    13: "navy",
    14: "lime",
    15: "aqua",
    16: "olive",
    17: "wheat",
    18: "teal",
    19: "brown",
    20: "orchid",
    21: "coral",
    22: "maroon",
    23: "khaki",
    24: "salmon",
    25: "plum",
    26: "violet",
    27: "indigo",
    "#": "black",
}

# 设置屏幕
turtle.setup(800, 800)

# 创建turtle对象
board_turtle = turtle.Turtle()
board_turtle.speed(0)  # 设置绘制速度为最快

# 计算格子大小
rows, cols = len(cpp_output_matrix), len(cpp_output_matrix[0])
square_size = 200 // max(rows, cols)

# 计算偏移量(中心为0，0)
offset_x = -cols * square_size // 2
offset_y = rows * square_size // 2


# 绘制单个格子的函数
def draw_square(x, y, color):  # j i
    board_turtle.penup()
    board_turtle.goto(x * square_size + offset_x, -y * square_size + offset_y)
    board_turtle.pendown()

    board_turtle.fillcolor(color)
    # 设置填充颜色为指定的color

    board_turtle.begin_fill()

    for _ in range(4):
        board_turtle.forward(square_size)
        # 向前移动画笔，绘制一条边

        board_turtle.right(90)
        # 将画笔向左转90度，准备绘制下一条边

    board_turtle.end_fill()


# 绘制整个棋盘的函数
def draw_chessboard(matrix):
    for i, row in enumerate(matrix):
        for j, tile_id in enumerate(row):
            if tile_id != "#":
                color = color_map[tile_id % 27]
            else:
                color = "black"
            draw_square(j, i, color)


# 绘制棋盘
draw_chessboard(cpp_output_matrix)

# 隐藏turtle
board_turtle.hideturtle()

# 保持窗口打开直到被点击
turtle.exitonclick()
