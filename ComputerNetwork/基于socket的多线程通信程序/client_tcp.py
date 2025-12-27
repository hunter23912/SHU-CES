import socket, time, threading, getpass

client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# 连接服务器
try:
    client.connect(("127.0.0.1", 6666))
    print("连接服务器成功")
except socket.error as e:
    print(f"连接服务器失败: {e}")
    exit(0)


def login_to_server():
    data = client.recv(1024)
    if data == "请输入用户名:".encode("utf-8"):
        username = input("请输入用户名: ")
        client.send(username.encode("utf8"))
    data = client.recv(1024)
    if data == "请输入密码:".encode("utf-8"):
        password = getpass.getpass("请输入密码: ")
        client.send(password.encode("utf8"))
    data = client.recv(1024)
    if data == "登录成功!".encode("utf-8"):
        ip, port = client.getsockname()
        print(f"登录成功!端口号:{port}")
        return 1
    else:
        print("登录失败!")
        return 0


# 接受来自服务器的消息
def receive():
    while True:
        try:
            data = client.recv(1024)
            print(data.decode())
        except OSError:
            break


# 主函数：

# 登录服务器
cnt = 1
while cnt <= 3:
    print(f"第{cnt}次登录:")
    if login_to_server() == 1:
        break
    cnt += 1
    if cnt > 3:
        print("登录失败次数过多,3秒后程序将自动退出")
        time.sleep(3)
        exit(0)

# 启动接受线程
send_receive_thread = threading.Thread(target=receive)
send_receive_thread.start()

# 发送数据
while True:
    to_data = input()
    if to_data == "886":
        client.send(to_data.encode("utf8"))
        print("下线成功")
        break
    client.send(to_data.encode("utf8"))

# 关闭客户端
client.close()
print("客户端已关闭")
