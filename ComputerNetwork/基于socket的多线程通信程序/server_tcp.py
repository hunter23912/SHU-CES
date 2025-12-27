import socket, threading
import time

USERNAME = "admin"
PASSWORD = "123456"

# 存储所有已连接的客户端
connected_clients = {}

# 存储每个客户端的目标客户端
client_targets = {}

# 处理登录请求
def login(sock, addr):
    print("客户端" + str(addr[1]) + "正在登录...")
    # 要求客户端提供用户名
    sock.send("请输入用户名:".encode("utf8"))
    username = sock.recv(1024).decode("utf8")

    # 要求客户端提供密码
    sock.send("请输入密码:".encode("utf8"))
    password = sock.recv(1024).decode("utf8")

    if username == USERNAME and password == PASSWORD:
        sock.send(f"登录成功!".encode("utf8"))
        print("客户端" + str(addr[1]) + "登录成功")
        return 1
    else:
        sock.send("用户名或密码错误!".encode("utf8"))
        print("客户端" + str(addr[1]) + "用户名或密码错误,登录失败")
        return 0


# 寻找目标客户端
def find_target_client(target_port):
    for client_addr, client_sock in connected_clients.items():
        if client_addr[1] == target_port:
            return client_sock
    return None


# 接受客户端的连接，创建socket连接对象，并返回客户端的连接地址信息
def handle_socket(sock, addr):
    try:
        # 处理登录请求
        cnt = 1
        while cnt <= 3:
            print(f"客户端" + str(addr[1]) + f"第{cnt}次登录:")
            if login(sock, addr) == 1:
                break
            cnt += 1
            if cnt > 3:
                print("登录失败次数过多,3秒后客户端" + str(addr[1]) + "将强制关闭")
                time.sleep(3)
                print("客户端" + str(addr[1]) + "已关闭")
                return

        connected_clients[addr] = sock
        print("客户端" + str(addr[1]) + "已连接")

        # 处理客户端的消息
        while True:
            data = sock.recv(1024)
            if data == "886".encode("utf8"):
                print("客户端" + str(addr[1]) + "已下线")
                del connected_clients[addr]
                del client_sockets[addr]
            # print("客户端" + str(addr[1]) + "发来消息:" + data.decode())
            elif data.startswith(b"to "):
                # 客户端选择目标客户端
                target_port = int(data.decode().split(" ")[1])
                client_targets[addr] = target_port
                sock.send(f"sending to:{target_port}".encode())

                # 通知目标客户端连接到当前客户端
                target_sock = find_target_client(target_port)
                if target_sock:
                    target_sock.send(f"receiving from:{addr[1]}".encode())
                else:
                    sock.send("目标客户端不存在".encode())
            else:
                # 客户端发送消息给指定客户端
                target_port = client_targets.get(addr)
                if target_port:
                    target_sock = find_target_client(target_port)
                    if target_sock:
                        target_sock.send(f"{addr[1]}:{data.decode()}".encode())
                    else:
                        sock.send("目标客户端不存在".encode())
                else:
                    sock.send("请先选择目标客户端(如:to 12345)".encode())
    except OSError:
        return


# 监听输入，如果输入quit则关闭服务器
def input_listening(server):
    while True:
        cmd = input()
        if cmd == "quit":
            print("服务器即将关闭...")
            for sock in client_sockets:
                sock.close()
            time.sleep(1)
            server.close()
            break


# main
try:
    server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server.bind(("0.0.0.0", 6666))
    server.listen()
    print("服务器启动成功,监听端口:6666")
except socket.error as e:
    print(f"创建socket服务失败: {e}")
    exit(0)

# 监听输入
input_thread = threading.Thread(target=input_listening, args=(server,))
input_thread.daemon = True
input_thread.start()

client_sockets = {}

while True:
    try:
        sock, addr = server.accept()
        client_sockets[addr] = sock
        client_thread = threading.Thread(target=handle_socket, args=(sock, addr))
        client_thread.start()
    except OSError:
        break
print("服务器已关闭")
