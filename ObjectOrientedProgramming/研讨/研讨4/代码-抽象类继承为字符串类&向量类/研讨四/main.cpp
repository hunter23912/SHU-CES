#include "teststring.h"
#include "testvector.h"
int main() {
	bool ifexit = false;
	while (!ifexit)
	{
		cout << "====抽象向量类模板及其派生类功能测试====" << endl;
		cout << "1.向量派生类测试" << endl;
		cout << "2.字符串派生类测试" << endl;
		cout << "3.退出程序" << endl;
		cout << " 请输入您的选择：" << endl;
		int choice;
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			bool exitVector = false;
			while (!exitVector)
			{
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

				switch (mainChoice)
				{
				case 1: {testvector1(); break; }
				case 2: {testvector2(); break; }
				case 3: {testvector3(); break; }
				case 4: {testvector4(); break; }
				case 5: {testvector5(); break; }
				case 6:
				{
					cout << "退出程序" << endl;
					exitVector = true;
					break;
				}
				default:
					cout << "输入有误，请重新输入" << endl;
				}
				cout << endl;
			}
			break;
		}
		case 2:
		{
			bool exitString = false;
			while (!exitString) {
				cout << "==== 字符串类功能测试 ====" << endl;
				cout << "1. 输出字符串/构造/复制构造/赋值功能测试" << endl;
				cout << "2. 运算符重载测试" << endl;
				cout << "3. 功能函数测试" << endl;
				cout << "4. 访问越界测试" << endl;
				cout << "5. 退出程序" << endl;
				cout << "请输入您的选择: ";

				int mainChoice;
				cin >> mainChoice;

				switch (mainChoice) {
				case 1: {teststring1(); break; }
				case 2: {teststring2(); break; }
				case 3: {teststring3(); break; }
				case 4: {teststring4(); break; }
				case 5:
				{
					cout << "退出程序" << endl;
					exitString = true;
					break;
				}

				default:
					cout << "输入有误，请重新输入" << endl;
				}
				cout << endl;
			}
			break;
		}
		case 3:
		{
			cout << "退出程序" << endl;
			ifexit = true;
			break;
		}
		}

	}
	return 0;
}