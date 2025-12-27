<!-- 说明文档 -->
## 说明文档
### 1.服务端程序：server_tcp.py
&emsp;&emsp;能够实现多客户端连接，将客户端A消息转发给特定客户端B，且能输入quit主动关闭服务器。
### 2.客户端程序：包括library.py,main.py,network.py,login_window.py,chat_window.py
- library.py 包含各种头文件.
- network.py socket相关函数封装.
- main.py 主函数，执行程序时运行该文件.
- login_window.py 登陆界面UI逻辑.
- chat_window.py 通信界面UI逻辑.
### 3.UDP文件夹:包含基于UDP方式的服务端程序server_udp.py和客户端程序client_udp.py
&emsp;&emsp;实现了客户端向指定ip地址和端口发送数据报.
### 5.文件夹.vscode,__pycache__
&emsp;&emsp;调试相关的配置文件。


