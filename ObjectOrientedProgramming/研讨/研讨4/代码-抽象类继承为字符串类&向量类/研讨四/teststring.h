#ifndef TESTSTRING_H
#define TESTSTRING_H
#include "mystring.h"
void teststring1() {
	//测试两种构造函数
	mystring  a, c;
	//输入功能测试
	cout << "输入功能测试" << endl;
	cout << "请输入字符串，以'.'结尾(如hello.):" << endl;

	cin >> a;
	//测试复制构造函数与赋值操作
	c = a;
	mystring  d(a);
	//输出功能/返回维数/容量测试
	cout << endl << "输出字符串/构造/复制构造/赋值功能测试:" << endl;
	cout << "您输入的字符串为:" << a << endl;
	cout << "提供复制构造函数 d(a)得到的d为：" << d << endl;
	cout << "提供赋值操作c=a,得到的c为：" << c << endl;

}

void teststring2() {
	cout << "运算符重载测试" << endl;

	//测试运算符重载+
	cout << "测试重载运算符+:" << endl;
	mystring a("hello"), b("world");
	cout << "a:" << a << endl << "b:" << b << endl;
	cout << "a+b:" << a + b << endl << endl;//
	cout << "测试重载运算符+=:" << endl;
	cout << "a+=b:";
	a += b;
	cout << a << endl;

	mystring e(3);
	// 测试运算符重载 []
	e[0] = 'e';
	e[1] = 'y';
	e[2] = 'e';
	mystring  f(3);
	f[0] = 'e';
	f[1] = 'a';
	f[2] = 'r';

	// 输出e和f
	cout << endl << "测试重载运算符[]:" << endl;
	cout << "通过[]，将eye连续以单个字符写入字符串e:" << endl;
	cout << e << endl;
	cout << "通过[]，将ear连续以单个字符写入字符串f:" << endl;
	cout << f << endl;

	// 测试运算符重载 ==
	cout << endl << "测试重载运算符==:" << endl;
	cout << "执行e==f语句，结果为:";
	if (e == f) {
		cout << "e == f" << endl;
	}
	else {
		cout << "e != f" << endl;
	}

	// 测试运算符重载 !=
	cout << endl << "测试重载运算符!=:" << endl;
	cout << "执行e!=f语句，结果为:";
	if (e != f) {
		cout << "e != f" << endl;
	}
	else {
		cout << "e == f" << endl;
	}
}

void teststring3() {
	mystring  str;

	// 测试push_back和push_front函数
	str.push_back('l');
	str.push_back('e');
	str.push_back('h');
	str.push_front('l');
	str.push_front('o');
	// 测试reverse函数
	cout << "创建了空字符串str" << endl
		<< "测试push_back函数，在str尾部添加字符l" << endl
		<< "测试push_back函数，在str尾部添加字符e" << endl
		<< "测试push_back函数，在str尾部添加字符h" << endl
		<< "测试push_front函数，在str首部添加字符l" << endl
		<< "测试push_front函数，在str首部加入元素o" << endl
		<< "操作完成，str:" << str << endl;
	str.reverse();
	cout << "测试reverse函数，翻转字符串后，str :" << str << endl;

	// 测试front函数和back函数
	cout << "测试front函数，输出首字符:" << str.front() <<
		endl << "测试back函数， 输出末字符:" << str.back() << endl;

	// 测试pop_back和pop_front函数
	str.pop_front();
	cout << "测试pop_front函数，删除首字符，str:" << str << endl;
	str.pop_back();
	cout << "测试pop_back函数，删除末字符，str:" << str << endl;

	// 测试insert函数
	str.insert(2, 'H');
	cout << "测试insert函数，在第二个字符后插入字符H，str:";
	cout << str << endl;

	// 测试erase函数
	str.erase(1);
	cout << "测试erase函数，擦除第一个字符，str:";
	cout << str << endl;

	// 测试resize函数
	str.resize(10);
	cout << "调用resize(10)后，修改size和capacity后，str 大小为：" << str.size() << " 容量为：" << str.capacity() << endl;

	// 测试reserve函数
	str.reserve(17);
	cout << "调用reserve(17)后，只修改capacity,不修改size后,str 大小为：" << str.size() << " 容量为：" << str.capacity() << endl;


	// 测试clear函数和empty函数
	str.clear();
	cout << "测试clear函数，清空str，现在str字符个数为：" << str.size() << endl
		<< "测试empty函数，判断str是否为空， 是(1)/否(0):" << str.empty() << endl;
}

void teststring4() {
	cout << "访问越界测试" << endl;
	try {
		mystring  a(3);
		cout << "尝试对三个字符的字符串a,使用a[10] = 'G'命令" << endl;
		a[10] = 'G';
	}
	catch (const exception& e) {
		cerr << "发生错误: " << e.what() << endl;
	}
	try {
		mystring  a;
		cout << "尝试对空字符串a访问首字符" << endl;
		cout << a.front() << endl;
	}
	catch (const exception& e) {
		cerr << "发生错误: " << e.what() << endl;
	}
	try {
		mystring  a;
		a.push_back('g');
		cout << "尝试对单字符g，删除第三个字符" << endl;
		a.erase(3);
	}
	catch (const exception& e) {
		cerr << "发生错误: " << e.what() << endl;
	}
	try {
		mystring  a;
		a.push_back('g');
		cout << "尝试对单字符g，第三个字符后插入字符P" << endl;
		a.insert(3, 'P');
	}
	catch (const exception& e) {
		cerr << "发生错误: " << e.what() << endl;
	}
}

#endif
