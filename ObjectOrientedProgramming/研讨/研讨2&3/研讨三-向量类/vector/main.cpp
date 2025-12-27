#include "Vector.h"
#include "test.h"
int main() {
	bool exitProgram = false;

	while (!exitProgram) {
		cout << "==== Vector功能测试 ====" << endl;
		cout << "1. 输出向量/构造/复制构造/赋值功能测试" << endl;
		cout << "2. 运算符重载测试" << endl;
		cout << "3. 功能函数测试" << endl;
		cout << "4. 向量相加维数不等测试" << endl;
		cout << "5. 访问越界测试" << endl;
		cout << "6. 退出程序" << endl;
		cout << "请输入您的选择: ";

		int mainChoice;
		cin >> mainChoice;

		switch (mainChoice) {
		case 1: {test1(); break; }
		case 2: {test2(); break; }
		case 3: {test3(); break; }
		case 4: {test4(); break; }
		case 5: {test5(); break; }
		case 6: {
			cout << "退出程序" << endl;
			exitProgram = true;
			break;
		}
		default:
			cout << "输入有误，请重新输入" << endl;
		}
		cout << endl;
	}

	return 0;
}