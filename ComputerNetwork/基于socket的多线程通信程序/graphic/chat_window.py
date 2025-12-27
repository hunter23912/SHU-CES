# 导入自己写的库
from library import tk, messagebox, threading, socket
from network import ClientSocket
from library import tkFont


# 该文件用于实现基于tcp方式的socket客户端聊天窗口逻辑
class ChatWindow:
    def __init__(self, root, username, server_ip, server_port):

        # 设置全局字体
        default_font = tkFont.Font(family="Microsoft YaHei", size=12)
        root.option_add("*Font", default_font)

        # 创建窗口
        self.root = root
        self.root.title(f"通信窗口 - {username}")

        # 设置窗口位置
        top = 270
        left = 480

        # 设置窗口的大小和位置
        self.root.geometry(f"+{left}+{top}")

        self.username = username
        self.server_ip = server_ip
        self.server_port = server_port

        # 创建主框架
        main_frame = tk.PanedWindow(root, orient=tk.HORIZONTAL)
        main_frame.pack(fill=tk.BOTH, expand=True)

        # 创建好友列表框架
        friend_frame = tk.Frame(main_frame)
        main_frame.add(friend_frame)

        # 创建好友列表
        self.friend_list = tk.Listbox(friend_frame, width=20, height=10)
        self.friend_list.pack(side=tk.LEFT, fill=tk.Y)

        # 创建滚动条并绑定到好友列表
        self.friend_scrollbar = tk.Scrollbar(
            friend_frame, command=self.friend_list.yview
        )
        self.friend_scrollbar.pack(side=tk.RIGHT, fill=tk.Y)
        self.friend_list.config(yscrollcommand=self.friend_scrollbar.set)

        # 绑定好友列表选择事件
        self.friend_list.bind("<<ListboxSelect>>", self.on_friend_select)

        # 创建右侧框架
        right_frame = tk.Frame(main_frame)
        main_frame.add(right_frame)

        # 创建聊天记录显示区域，添加滚动条
        text_frame = tk.Frame(right_frame)
        text_frame.pack(expand=True, fill=tk.BOTH)

        self.text_display = tk.Text(
            text_frame, width=70, state=tk.DISABLED, wrap=tk.WORD
        )
        self.scrollbar = tk.Scrollbar(text_frame, command=self.text_display.yview)
        self.scrollbar.pack(side=tk.RIGHT, fill=tk.Y)

        self.text_display["yscrollcommand"] = self.scrollbar.set
        self.text_display.pack(side=tk.LEFT, expand=True, fill=tk.BOTH)

        # 创建消息输入框
        input_frame = tk.Frame(right_frame)
        input_frame.pack(fill=tk.X, expand=False)

        self.message_entry = tk.Entry(input_frame)
        self.message_entry.pack(side=tk.LEFT, padx=10, fill=tk.X, expand=True)
        self.message_entry.focus_set()

        # 创建发送按钮
        self.send_button = tk.Button(
            input_frame, text="发送", command=self.send_message
        ).pack(side=tk.LEFT)

        # 将回车与发送消息绑定
        self.message_entry.bind("<Return>", self.send_message_event)

        # 创建socket客户端
        self.client_socket = ClientSocket(self.server_ip, self.server_port)

        # 启动接收消息的线程
        threading.Thread(target=self.receive_message, daemon=True).start()

        # 设置窗口关闭事件处理
        self.root.protocol("WM_DELETE_WINDOW", self.on_closing)

        # 当前通信的目标端口
        self.current_target = None

    # 点击退出窗口后，发送下线消息，断开socket连接
    def on_closing(self):
        # 发送断开连接信息
        try:
            self.client_socket.send_message("close connection")
            self.client_socket.close()
        except socket.error as e:
            print(f"发送下线消息失败: {e}")

        # 销毁窗口
        self.root.destroy()

    def send_message(self):
        # 获取输入框中的消息
        message = self.message_entry.get()
        # 清空输入框
        self.message_entry.delete(0, tk.END)

        if message.startswith("add "):
            # 添加好友端口到好友列表
            port = message.split(" ")[1]
            if port == str(self.client_socket.port):
                messagebox.showerror("错误", "不能添加自己")
            else:
                self.add_friend(port)
        else:
            # 在聊天记录显示区域显示消息
            self.text_display.config(state=tk.NORMAL)  # 允许写入
            self.text_display.insert(tk.END, "本机: " + message + "\n")
            self.text_display.config(state=tk.DISABLED)  # 设置为只读
            self.text_display.see(tk.END)  # 滚动到最后一行

            # 该逻辑是先将消息转发到服务器，再由服务器转发到target
            if self.current_target:
                self.send_to_target(message)

    # 发送消息事件(不用看)
    def send_message_event(self, event):
        self.send_message()

    # 添加好友到好友列表
    def add_friend(self, friend):
        # 如果好友不在好友列表中，则添加到好友列表
        if friend not in self.friend_list.get(0, tk.END):
            # 如果firend是自己的端口，则添加本机+端口号到列表
            if friend == str(self.client_socket.port):
                friend = "本机:" + friend
            self.friend_list.insert(tk.END, friend)
            self.friend_list.see(tk.END)

    # 从好友列表中删除已关闭客户端的好友
    def remove_friend(self, port):
        try:
            for index in range(self.friend_list.size()):
                friend = self.friend_list.get(index)
                if friend == port:
                    self.friend_list.delete(friend)
                    print(f"删除好友:{port}")
                    break
        except ValueError:
            messagebox.showwarning("提示", f"好友{port}不在列表中")

    # 选择好友后，设置当前通信的目标端口
    def on_friend_select(self, event):
        # 获取选中的好友
        selection = event.widget.curselection()
        if selection:
            index = selection[0]
            friend = event.widget.get(index)
            if friend.startswith("本机:"):
                return  # 本机不允许通信
            self.current_target = friend
            self.send_to_target(f"to {friend}")

    def send_to_target(self, message):
        # 这里实现发送消息到目标端口的逻辑
        self.client_socket.send_message(message)

    # 接收消息逻辑
    def receive_message(self):
        while True:
            try:
                message = self.client_socket.receive_message()

                # 消息如果为new client:12345则添加到好友列表
                if message.startswith("new client:"):
                    port = message.split(":")[1]
                    self.add_friend(port)
                    continue
                elif message.startswith("receiving from:"):
                    # 如果接收到消息为receiving from:12345，则设置当前通信的目标端口为12345
                    port = message.split(":")[1]
                    self.current_target = port
                    self.add_friend(port)
                elif message.startswith("目标客户端不存在:"):
                    port = message.split(":")[1]
                    self.remove_friend(port)

                # 否则接收的为消息，显示在聊天记录显示区域
                else:
                    self.text_display.config(state=tk.NORMAL)  # 允许写入
                    self.text_display.insert(tk.END, f"{message}\n")
                    self.text_display.config(state=tk.DISABLED)  # 设置为只读
                    self.text_display.see(tk.END)
            except ConnectionError:
                break
