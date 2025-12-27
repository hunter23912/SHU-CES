#ifndef TEST_H
#define TEST_H
#include "Vector.h"
void test1() {
	//测试两种构造函数
	Vector <int> a, b(5), c;
	//输入功能测试
	cout << "输入功能测试" << endl;
	cout << "请输入vector，形如[3,4,6,7]：";

	cin >> a;
	//测试复制构造函数与赋值操作
	c = a;
	Vector <int> d(a);
	//输出功能/返回维数/容量测试
	cout << endl << "输出向量/构造/复制构造/赋值功能测试:" << endl;
	cout << "您输入的向量为:" << a << endl;
	cout << "使用构造函数，创建五维向量b，并显示b的维数:" << b.size() << endl;
	cout << "提供复制构造函数:Vector<int> d(a)得到的d为：" << d << endl;
	cout << "提供赋值操作c=a,得到的c为：" << c << endl;

}

void test2() {
	cout << "运算符重载测试" << endl;
	Vector<int> e(3);
	// 测试运算符重载 []
	e[0] = 1;
	e[1] = 2;
	e[2] = 3;
	Vector<int> f(3);
	f[0] = 4;
	f[1] = 5;
	f[2] = 6;

	// 输出e和f
	cout << endl << "测试重载运算符[]:" << endl;
	cout << "创建三维向量e, 并通过[]写入e[0]=1,e[1]=2,e[3]=3" << endl;
	cout << "e: " << e << endl;
	cout << "创建三维向量f, 并通过[]写入f[0]=4,f[1]=5,f[3]=6" << endl;
	cout << "f: " << f << endl;

	// 测试运算符重载 +
	Vector<int> g = e + f;
	cout << endl << "测试重载运算符+:" << endl;
	cout << "e=[1,2,3],f=[4,5,6]" << endl << "g = e + f " << endl;
	cout << "g: " << g << endl;

	// 测试运算符重载 +=
	e += f;
	cout << endl << "测试重载运算符+=:" << endl;
	cout << "进行e += f操作后结果为: " << e << endl;

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

void test3() {
	Vector<int> vec;

	// 测试push_back和push_front函数
	vec.push_back(11);
	vec.push_back(12);
	vec.push_front(9);
	vec.push_front(8);

	// 测试reverse函数
	cout << "创建了空向量vec" << endl
		<< "测试push_back函数，在vec尾部加入元素11" << endl
		<< "测试push_back函数，在vec尾部加入元素12" << endl
		<< "测试push_front函数，在vec首部加入元素9" << endl
		<< "测试push_front函数，在vec首部加入元素8" << endl
		<< "操作完成，vec:" << vec << endl;
	vec.reverse();
	cout << "测试reverse函数，翻转vec元素后，vec :" << vec << endl;

	// 测试front函数和back函数
	cout << "测试front函数，输出vec首元素:" << vec.front() <<
		endl <<"测试back函数， 输出vec末元素:" << vec.back() << endl;

	// 测试pop_back和pop_front函数
	vec.pop_front();
	cout << "测试pop_front函数，删除首元素，vec:" << vec << endl;
	vec.pop_back();
	cout << "测试pop_back函数，删除末元素，vec:" << vec << endl;

	// 测试insert函数
	vec.insert(2, 10);
	cout << "测试insert函数，在第二个元素后插入元素10，vec:";
	cout << vec << endl;

	// 测试erase函数
	vec.erase(1);
	cout << "测试erase函数，擦除第一个元素，vec:";
	cout << vec << endl;

	// 测试resize函数
	vec.resize(10);
	cout << "调用resize(10)后，修改size和capacity后，Vector 大小为：" << vec.size() << " 容量为：" << vec.capacity() << endl;

	// 测试reserve函数
	vec.reserve(17);
	cout << "调用reserve(17)后，只修改capacity,不修改size后,Vector 大小为：" << vec.size() << " 容量为：" << vec.capacity() << endl;


	// 测试clear函数和empty函数
	vec.clear();
	cout << "测试clear函数，清空vec，现在vec维数为：" << vec.size() << endl
		<< "测试empty函数，判断vec是否为空， 是(1)/否(0):" << vec.empty() << endl;
}

void test4() {
	cout << "向量相加维数异常测试" << endl;
	try {
		Vector<int> a, b;
		a.push_back(1);
		b.push_back(2);
		b.push_back(3);
		cout << "尝试使用[1]+[2,3]" << endl;
		a += b;
	}
	catch (const exception& e) {
		cerr << "发生错误: " << e.what() << endl;
	}
}

void test5() {
	cout << "访问越界测试" << endl;
	try {
		Vector<int> a(3);
		cout << "尝试对三维向量a,使用'a[10] = 5'命令" << endl;
		a[10] = 5;
	}
	catch (const exception& e) {
		cerr << "发生错误: " << e.what() << endl;
	}
	try {
		Vector<int> a;
		cout << "尝试对空向量a访问首元素" << endl;
		cout << a.front() << endl;
	}
	catch (const exception& e) {
		cerr << "发生错误: " << e.what() << endl;
	}
	try {
		Vector<int> a;
		a.push_back(2);
		cout << "尝试对一维向量[2]，删除第三个元素" << endl;
		a.erase(3);
	}
	catch (const exception& e) {
		cerr << "发生错误: " << e.what() << endl;
	}
	try {
		Vector<int> a;
		a.push_back(2);
		cout << "尝试对一维向量[2]，第三个元素后插入元素2" << endl;
		a.insert(3, 2);
	}
	catch (const exception& e) {
		cerr << "发生错误: " << e.what() << endl;
	}
}
#endif