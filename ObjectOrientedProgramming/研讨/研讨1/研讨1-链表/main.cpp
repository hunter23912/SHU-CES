#include "LinkList.h"
#include <cstring> 
#include <conio.h>
int Pos(char ch, const char* str)			// 返回指定字符ch在字符串str中的下标。不存在时返回-1
{
	int i;
	for (i = 0; str[i] != '\0'; i++)
		if (ch == str[i])
			return i;
	return -1;
}
int Choice(const char* prompt, const char* options = "");	// 函数声明
int Choice(const char* prompt, const char* options)		// 函数定义。输出提示信息prompt，输入选择的字符并返回。
{
	int key;
	cout << prompt << "{";
	for (int i = 0; options[i] != '\0'; i++)
	{
		if (' ' < (options[i] & 0x7f) && (options[i] & 0x7f) < 127)	// 选项options中的可打印字符
			cout << options[i] << ' ';
		else														// 选项options中的部分控制字符
		{
			switch (options[i])
			{
			case '\t':   cout << "[Tab] ";   break;					// 选项中的Tab字符'\t'（即ASCII编码9）
			case '\x1b': cout << "[Esc] ";   break;					// 选项中的Esc字符'\x1b'（即ASCII编码27）
			case ' ':    cout << "[Space] "; break;					// 选项中的空格字符' '（即ASCII编码32）
			}
		}
	}
	cout << "\b}: ";					// '\b'退格。先退一格，在输出右花括号
	do
	{
		key = getch();
	} while (options[0] != '\0' && Pos(key, options) < 0); // 若options为空长度为0的字符串，则输入无限制；否则输入项应该在optins中。
	cout << endl;
	return key;
}




int main()
{
	void  BookLinkTest(), BookerTest();
	int key;
	while (true)
	{
		cout << "\n\n\t图书登记程序测试" << endl;
		cout << "\n\t1----图书借阅登记" << endl;
		cout << "\t2----图书归还信息链表" << endl;
		key = Choice("\n\t请选择", "12\x1b");
		cout << "\n\n";
		if (key == 27)
			break;
		switch (key)
		{
		case '1':	BookerTest();		break;
		case'2':BookLinkTest(); break;
		}
	}
	return 0;
}
