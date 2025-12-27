import socket, threading

USERNAME = "admin"
PASSWORD = "123456"

# 存储所有已连接的客户端
connected_clients = {}

# 存储目标端口号
client_targets = {}


# 寻找目标客户端
def find_target_client(target_port):
    for addr, sock in connected_clients.items():
        if addr[1] == int(target_port):
            return sock
    return None


# 接受客户端的连接，创建socket连接对象，并返回客户端的连接地址信息
def handle_socket(sock, addr):
    try:
        connected_clients[addr] = sock
        print("客户端" + str(addr[1]) + "已连接")

        # 处理客户端的消息
        while True:
            data = sock.recv(1024).decode()
            if data == "close connection":
                print("客户端" + str(addr[1]) + "已下线")
                del connected_clients[addr]
            elif data.startswith("to "):
                # 客户端选择目标客户端
                target_port = data.split(" ")[1]
                client_targets[addr] = target_port
                sock.send(f"sending to:{target_port}".encode())

                # 通知目标客户端连接到当前客户端
                target_sock = find_target_client(target_port)
                if target_sock:
                    target_sock.send(f"receiving from:{addr[1]}".encode())
                else:
                    sock.send(f"目标客户端不存在,无法连接:{target_port}".encode())
            else:
                # 客户端发送消息给指定客户端
                target_port = client_targets.get(addr)
                if target_port:
                    target_sock = find_target_client(target_port)
                    if target_sock:
                        target_sock.send(f"{addr[1]}:{data}".encode())
                    else:
                        sock.send(f"目标客户端不存在，无法发送:{target_port}".encode())
                else:
                    sock.send("请先选择目标客户端".encode())
    except OSError:
        return


# 将新建立的socket连接对象的端口加入到已连接的客户端列表中
def add_client(port):
    info = f"new client:{port}"
    try:
        if connected_clients:
            for sock in connected_clients.values():
                sock.send(info.encode())
    except socket.error as e:
        print(f"添加新端口失败: {e}")
    return


# 监听输入，如果输入quit则关闭服务器
def input_listening(server):
    while True:
        cmd = input()
        if cmd == "quit":
            print("服务器即将关闭...")
            for sock in connected_clients.values():
                sock.close()
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
        add_client(addr[1])
    except OSError:
        break
print("服务器已关闭")
