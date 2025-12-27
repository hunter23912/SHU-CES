import socket, threading, time

# 全局变量，用于控制服务器是否关闭


# 处理客户端的消息
def handle_client(data, addr, server):
    # 处理客户端的消息
    if data.decode("utf8") == "886":
        print("客户端" + str(addr[1]) + "已下线")
    print("客户端" + str(addr[1]) + "发来消息:" + data.decode())
    re_data = "服务器已收到你的消息:" + data.decode()
    server.sendto(re_data.encode("utf8"), addr)


# 监听输入，如果输入quit则关闭服务器
def input_listening(server):
    while True:
        cmd = input()
        if cmd == "quit":
            print("服务器即将关闭...")
            time.sleep(1)
            server.close()
            break


# main
try:
    server = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    server.bind(("0.0.0.0", 6666))
    print("服务器启动成功,端口:6666")
except socket.error as e:
    print(f"创建socket服务失败: {e}")
    exit(0)

# 监听输入
input_thread = threading.Thread(target=input_listening, args=(server,))
input_thread.daemon = True
input_thread.start()

while True:
    try:
        data, addr = server.recvfrom(1024)
        handle_client(data, addr, server)
    except OSError:
        break
print("服务器已关闭")
