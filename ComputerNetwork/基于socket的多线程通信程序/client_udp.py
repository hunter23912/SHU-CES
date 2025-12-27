import socket

client = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

server_address = ("127.0.0.1", 6666)

# 主函数：
# 发送数据
while True:
    to_data = input("请输入要发送的内容: ")
    try:
        if to_data == "886":
            client.sendto(to_data.encode("utf8"), server_address)
            print("下线成功")
            exit(0)
        client.sendto(to_data.encode("utf8"), server_address)
        print("发送成功")
        data = client.recvfrom(1024)
        print(data[0].decode())
    except socket.error as e:
        print(f"接收服务端消息失败: {e}")
        print("程序已退出")
        break
