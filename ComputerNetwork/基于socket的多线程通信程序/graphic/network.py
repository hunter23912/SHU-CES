from library import socket


# 该文件用于实现基于tcp方式的socket客户端socket通信逻辑
class ClientSocket:
    def __init__(self, server_ip, server_port):
        self.server_ip = server_ip
        self.server_port = server_port
        self.client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.client_socket.connect((self.server_ip, self.server_port))
        self.port = self.client_socket.getsockname()[1]

    # 发送消息
    def send_message(self, message):
        self.client_socket.send(message.encode())

    # 接收消息
    def receive_message(self):
        return self.client_socket.recv(1024).decode()

    # 关闭连接
    def close(self):
        self.client_socket.close()
        return
