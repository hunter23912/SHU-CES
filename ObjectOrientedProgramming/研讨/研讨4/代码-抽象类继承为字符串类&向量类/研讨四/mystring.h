#ifndef MYSTRING_H
#define MYSTRING_H
#include "Abs.h"
class mystring :public Abs<char>
{
public:

	//默认构造函数
	mystring() :Abs() {}

	//使用size的构造函数
	mystring(int size) :Abs<char>(size) {}

	//使用字符串参数的构造函数
	mystring(const char* s)
	{
		this_size = strlen(s);
		data = new char[this_capacity];
		for (int i = 0; i < this_size; i++)
		{
			data[i] = s[i];
		}
	}

	//运算符重载+
	mystring operator+(const mystring& other)
	{
		mystring temp;
		temp.this_size = this_size + other.this_size;
		for (int i = 0; i < this_size; i++)
		{
			temp.data[i] = data[i];
		}
		for (int i = this_size; i < temp.this_size; i++)
		{
			temp.data[i] = other.data[i - this_size];
		}
		return temp;
	}

	//运算符重载+=
	mystring& operator+=(const mystring& other)
	{
		int temp = this_size;
		this_size += other.this_size;
		for (int i = temp; i < this_size; i++)
		{
			data[i] = other.data[i - temp];
		}
		return *this;
	}

	// 重载 >> 运算符，用于输入 mystring 对象
	friend istream& operator>>(istream& is, mystring& v)
	{
		if (v.data != nullptr)
		{
			delete[] v.data;
			v.data = nullptr;
			v.this_size = 0;
			v.this_capacity = 0;
		}
		char value;
		while (is >> value && value != '.')
		{
			v.push_back(value);
		}
		return is;
	}

	// 重载 << 运算符，用于输出 mystring 对象
	friend ostream& operator<<(ostream& os, const mystring& v)
	{
		for (int i = 0; i < v.this_size; ++i) {
			os << v.data[i];
		}
		return os;
	}

	//纯虚函数定义
	//返回size
	int size() const
	{
		return this_size;
	}

	//返回capacity
	int capacity() const
	{
		return this_capacity;
	}

	// resize函数，扩展或缩小容量至至少new_capacity大小，并修改size
	void resize(int new_capacity)
	{
		int new_capacity_actual = 1;
		while (new_capacity_actual < new_capacity) {
			new_capacity_actual *= 2;
		}
		if (new_capacity_actual != this_capacity) {
			char* new_data = new char[new_capacity_actual];
			for (int i = 0; i < new_capacity_actual; ++i) {
				new_data[i] = 0;
			}
			for (int i = 0; i < min(this_size, new_capacity); ++i) {
				new_data[i] = data[i];
			}
			delete[] data;
			data = new_data;
			this_size = new_capacity;
			this_capacity = new_capacity_actual;
		}
	}

	// reserve函数，扩展或缩小容量至至少new_capacity大小，不修改size
	void reserve(int new_capacity) {
		int new_capacity_actual = 1;
		while (new_capacity_actual < new_capacity) {
			new_capacity_actual *= 2;
		}

		if (new_capacity_actual != this_capacity) {
			char* new_data = new char[new_capacity_actual];
			for (int i = 0; i < new_capacity_actual; ++i) {
				new_data[i] = 0;
			}
			for (int i = 0; i < min(this_size, new_capacity); ++i) {
				new_data[i] = data[i];
			}
			delete[] data;
			data = new_data;
			this_capacity = new_capacity_actual;
		}
	}

	//反转字符串
	void reverse() {
		char* new_data = new char[this_capacity];
		for (int i = 0; i < this_size; ++i) {
			new_data[i] = data[this_size - 1 - i];
		}
		delete[] data;
		data = new_data;
	}

	//删除尾字符
	void pop_back()
	{
		if (this_size > 0) {
			--this_size;
		}
	}

	//删除首字符
	void pop_front()
	{
		if (this_size > 0) {
			for (int i = 0; i < this_size - 1; ++i) {
				data[i] = data[i + 1];
			}
			--this_size;
		}
	}

	// 删除指定位置的字符
	void erase(int index)
	{
		if (index < 0 || index >= this_size) {
			throw out_of_range("下标越界");
		}
		for (int i = index - 1; i < this_size - 1; ++i) {
			data[i] = data[i + 1];
		}
		--this_size;
	}

	//清空字符串
	void clear()
	{
		delete[] data;
		data = nullptr;
		this_size = 0;
		this_capacity = 0;
	}

	//判断字符串是否为空
	bool empty() const
	{
		return this_size == 0;
	}
};
#endif // !MYSTRING_H
