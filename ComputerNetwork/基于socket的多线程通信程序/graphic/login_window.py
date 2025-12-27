from library import tk, messagebox, tkFont
from chat_window import ChatWindow

USERNAME = "admin"
PASSWORD = "123"

users = {
    "admin": "123",
    "admin2": "1234",
    "admin3": "12345",
}


# 这里实现socket客户端登录到服务器的验证逻辑
class LoginWindow:
    def __init__(self, root):
        # 设置全局字体
        default_font = tkFont.Font(family="Microsoft YaHei", size=12)
        root.option_add("*Font", default_font)

        self.root = root
        self.root.title("登录窗口")

        # 设置窗口大小和位置
        width = 300
        height = 200
        top = 400
        left = 700

        # 设置窗口的大小和位置
        self.root.geometry(f"{width}x{height}+{left}+{top}")

        tk.Label(root, text="用户名:").pack(pady=5)
        self.username_entry = tk.Entry(root)
        self.username_entry.pack(pady=3)
        self.username_entry.focus_set()

        tk.Label(root, text="密码:").pack(pady=5)
        self.password_entry = tk.Entry(root, show="*")
        self.password_entry.pack(pady=3)

        login_button = tk.Button(
            root, text="登录", command=self.login, width=6, bd=3
        ).pack(pady=15)
        # 绑定回车键到根窗口，触发登录按钮命令
        self.root.bind("<Return>", lambda event: self.login())
        self.root.bind("<Escape>", lambda event: self.root.destroy())

    def login(self):
        username = self.username_entry.get()
        password = self.password_entry.get()
        server_ip = "127.0.0.1"
        server_port = 6666
        if users.get(username) == password:
            self.root.destroy()
            root = tk.Tk()
            chat_window = ChatWindow(root, username, server_ip, server_port)
            root.mainloop()
        else:
            messagebox.showerror("提示", "用户名或密码错误！")
