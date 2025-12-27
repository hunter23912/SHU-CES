#ifndef ABS_H
#define ABS_H
#include <iostream>
#include<cstring>
using namespace std;
template <typename T>
class Abs {
protected:
	T* data;           // 维护动态数组的指针
	int this_size;     // 当前大小
	int this_capacity; // 当前容量
public:
	// 无参数的构造函数
	Abs() : data(nullptr), this_size(0), this_capacity(4096)
	{
		data = new T[this_capacity];
	}

	//使用参数size的构造函数
	Abs(const int size) : this_size(size), this_capacity(2 * size)
	{
		data = new T[this_capacity];
	}

	// 析构函数
	~Abs() {
		delete[] data;
	}

	// 复制构造函数
	Abs(const Abs& other) : this_size(other.this_size), this_capacity(other.this_capacity)
	{
		data = new T[this_capacity];
		for (int i = 0; i < this_size; ++i) {
			copy(other.data, other.data + this_size, data);
			//data[i] = other.data[i];
		}
	}

	// 赋值运算符重载
	Abs& operator=(const Abs& other)
	{
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

	// 运算符重载 []
	T& operator[](const int index)
	{
		if (index < 0 || index >= this_size) {
			throw out_of_range("下标越界");
		}
		return data[index];
	}

	// 运算符重载 ==
	bool operator==(const Abs& other) const
	{
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
	bool operator!=(const Abs& other) const
	{
		return !(*this == other);
	}

	// 在末尾添加元素
	void push_back(const T& value) {
		if (this_size == this_capacity) {
			reserve(this_capacity * 2); // 如果容量不够，扩展容量
		}
		this_size++;
		data[this_size - 1] = value;
	}

	// 在开头添加元素
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

	// 插入函数
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

	// 返回第一个元素的引用
	T& front() {
		if (this_size == 0) {
			throw out_of_range("字符串为空");
		}
		return data[0];
	}

	// 返回最后一个元素的引用
	T& back() {
		if (this_size == 0) {
			throw out_of_range("字符串为空");
		}
		return data[this_size - 1];
	}

	//纯虚函数声明
	//返回size
	virtual int size()const = 0;

	// 返回 capacity
	virtual int capacity() const = 0;

	// resize函数，扩展或缩小容量至至少new_capacity大小，并修改size
	virtual void resize(int new_capacity) = 0;

	// reserve函数，扩展或缩小容量至至少new_capacity大小，不修改size
	virtual void reserve(int new_capacity) = 0;

	// reverse函数：反转函数
	virtual void reverse() = 0;

	// 删除末元素
	virtual void pop_back() = 0;

	// 删除首元素
	virtual void pop_front() = 0;

	//删除指定位置元素
	virtual void erase(int index) = 0;

	// 清空函数
	virtual void clear() = 0;

	// 检查是否为空
	virtual bool empty()const = 0;
};
#endif



