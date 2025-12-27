<!-- 说明文档 -->
## 说明文档
### 1.server_tcp.py
&emsp;&emsp;基于tcp连接方式的服务端socket通信程序。实现了验证客户端口令，接受并广播客户端消息，主动关闭服务器等功能。
### 2.client_tcp.py
&emsp;&emsp;基于tcp连接方式的客户端程序。实现了通过口令登录服务器、隐藏口令密码、多人聊天室等功能。
- tcp方式实现了登录、聊天室等功能。客户端需要口令登录服务器；当多个客户端登录到服务器后，可进行多客户端交流的功能，类似于聊天室功能；当客户端输入886，该客户端即可下线。此外，服务端也可以键入quit字符串以实现强制下线功能。
### 3.server_udp.py
&emsp;&emsp;基于udp方式的服务端程序。
### 4.client_udp.py
&emsp;&emsp;基于udp方式的客户端程序。
### 5.文件夹.vscode
&emsp;&emsp;文件夹中包含了调试配置文件，包括在集成终端或独立外部终端中运行等其他设置
### 6.文件夹graphic
&emsp;&emsp;文件夹是socket通信程序含图形界面版本.
- library.py 包含各种头文件
- network.py socket相关函数封装
- main.py 主函数，执行程序时运行该文件
- login_window.py 登陆界面UI逻辑
- chat_window.py 通信界面UI逻辑
- server_tcp.py 服务端程序 

