#ifndef STRING_H
#define STRING_H
#include <iostream>
#include<cstring>
using namespace std;
template <typename T>
class String {
private:
	T* data;           // 维护动态数组的指针
	int this_size;     // 当前字符个数
	int this_capacity; // 当前容量

public:
	// 无参数的构造函数
	String() : data(nullptr), this_size(0), this_capacity(4096) {
		data = new T[this_capacity];
	}
	//使用字符串参数的构造函数
	String(const char* s) :this_size(strlen(s)), this_capacity(4096)
	{
		this_size = strlen(s);
		data = new T[this_capacity];
		for (int i = 0; i < this_size; i++)
		{
			data[i] = s[i];
		}
	}
	//使用参数size的构造函数
	String(const int size) : this_size(size), this_capacity(2 * size) {
		data = new T[this_capacity];
	}

	// 析构函数
	~String() {
		delete[] data;
	}

	// 复制构造函数
	String(const String& other) : this_size(other.this_size), this_capacity(other.this_capacity) {
		data = new T[this_capacity];
		for (int i = 0; i < this_size; ++i) {
			copy(other.data, other.data + this_size, data);
			//data[i] = other.data[i];
		}
	}

	// 赋值运算符重载
	String& operator=(const String& other) {
		if (this != &other) {
			delete[] data;
			this_size = other.this_size;
			this_capacity = other.this_capacity;
			data = new T[this_capacity];
			for (int i = 0; i < this_size; ++i) {
				data[i] = other.data[i];
			}
		}
		return *this;
	}

	// 返回 size
	int size() const {
		return this_size;
	}

	// 返回 capacity
	int capacity() const {
		return this_capacity;
	}

	// 运算符重载 []
	T& operator[](const int index) {
		if (index < 0 || index >= this_size) {
			throw out_of_range("下标越界");
		}
		return data[index];
	}

	// 运算符重载 ==
	bool operator==(const String& other) const {
		if (this_size != other.this_size) {
			return false;
		}
		for (int i = 0; i < this_size; ++i) {
			if (data[i] != other.data[i]) {
				return false;
			}
		}
		return true;
	}

	// 运算符重载 !=
	bool operator!=(const String& other) const {
		return !(*this == other);
	}

	//运算符重载+=
	String& operator+=(const String& other)
	{
		int temp = this_size;
		this_size += other.this_size;
		for (int i = temp; i < this_size; i++)
		{
			data[i] = other.data[i - temp];
		}
		return *this;
	}
	//运算符重载+
	String operator+(const String& other)
	{
		String<char> temp;
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

	// resize函数，扩展或缩小容量至至少new_capacity大小，并修改size
	void resize(int new_capacity) {
		int new_capacity_actual = 1;
		while (new_capacity_actual < new_capacity) {
			new_capacity_actual *= 2;
		}
		if (new_capacity_actual != this_capacity) {
			T* new_data = new T[new_capacity_actual];
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
			T* new_data = new T[new_capacity_actual];
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

	// reverse函数：反转字符串
	void reverse() {
		T* new_data = new T[this_capacity];
		for (int i = 0; i < this_size; ++i) {
			new_data[i] = data[this_size - 1 - i];
		}
		delete[] data;
		data = new_data;
	}

	// 在末尾添加字符
	void push_back(const T& value) {
		if (this_size == this_capacity) {
			reserve(this_capacity * 2); // 如果容量不够，扩展容量
		}
		this_size++;
		data[this_size - 1] = value;
	}

	// 在开头添加字符
	void push_front(const T& value) {
		if (this_size == this_capacity) {
			reserve(this_capacity * 2);
		}
		this_size++;
		for (int i = this_size; i > 0; --i) {
			data[i] = data[i - 1];
		}
		data[0] = value;
	}

	// 删除末字符
	void pop_back() {
		if (this_size > 0) {
			--this_size;
		}
	}

	// 删除开头字符
	void pop_front() {
		if (this_size > 0) {
			for (int i = 0; i < this_size - 1; ++i) {
				data[i] = data[i + 1];
			}
			--this_size;
		}
	}

	// 在指定位置插入字符
	void insert(int index, const T& value) {
		if (index < 0 || index > this_size) {
			throw out_of_range("下标越界");
		}
		if (this_size == this_capacity) {
			reserve(this_capacity * 2);
		}
		this_size++;
		for (int i = this_size; i > index; --i) {
			data[i] = data[i - 1];
		}
		data[index] = value;
	}

	// 删除指定位置的字符
	void erase(int index) {
		if (index < 0 || index >= this_size) {
			throw out_of_range("下标越界");
		}
		for (int i = index - 1; i < this_size - 1; ++i) {
			data[i] = data[i + 1];
		}
		--this_size;
	}

	// 清空字符串
	void clear() {
		delete[] data;
		data = nullptr;
		this_size = 0;
		this_capacity = 0;
	}

	// 检查字符串是否为空
	bool empty() const {
		return this_size == 0;
	}

	// 返回第一个字符的引用
	T& front() {
		if (this_size == 0) {
			throw out_of_range("字符串为空");
		}
		return data[0];
	}

	// 返回最后一个字符的引用
	T& back() {
		if (this_size == 0) {
			throw out_of_range("字符串为空");
		}
		return data[this_size - 1];
	}

	// 重载 << 运算符，用于输出 String 对象
	friend ostream& operator<<(ostream& os, const String& v) {
		for (int i = 0; i < v.this_size; ++i) {
			os << v.data[i];
		}
		return os;
	}

	// 重载 >> 运算符，用于输入 String 对象
	friend istream& operator>>(istream& is, String& v) {
		// 清空原有数据
		if (v.data != nullptr)
		{
			delete[] v.data;
			v.data = nullptr;
			v.this_size = 0;
			v.this_capacity = 0;
		}
		T value;
		while (is >> value && value != '.')
		{
			v.push_back(value);
		}
		return is;
	}
};


#endif
