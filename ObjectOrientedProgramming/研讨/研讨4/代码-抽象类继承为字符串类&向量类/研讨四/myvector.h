#ifndef MYVECTOR_H
#define MYVECTOR_H
#include "Abs.h"
class myvector :public Abs<int>
{
public:

	//默认构造函数
	myvector() :Abs<int>() {}

	//使用size的构造函数
	myvector(int size) :Abs<int>(size) {}

	//拷贝构造函数
	myvector(const myvector& other) :Abs<int>(other) {}

	// 运算符重载 +：将两个 myvector 的元素对应位相加
	myvector operator+(const myvector& other) const
	{
		if (this_size != other.this_size) {
			throw invalid_argument("向量维数不相等");
		}
		myvector result(*this);
		for (int i = 0; i < this_size; ++i) {
			result.data[i] += other.data[i];
		}
		return result;
	}

	// 运算符重载 +=：将另一个 myvector 的元素加到当前 myvector 对应位
	myvector& operator+=(const myvector& other)
	{
		if (this_size != other.this_size) {
			throw invalid_argument("向量维数不相等");
		}
		for (int i = 0; i < this_size; ++i) {
			data[i] += other.data[i];
		}
		return *this;
	}

	// 重载 >> 运算符，用于输入 myvector 对象
	friend istream& operator>>(istream& is, myvector& v)
	{
		delete[] v.data;
		v.data = nullptr;
		v.this_size = 0;
		v.this_capacity = 0;
		char ch;
		is >> ch; // 读取 '['
		while (ch != ']') {
			int value;
			is >> value;
			v.push_back(value);
			is >> ch; // 读取 ',' 或 ']'
		}
		return is;
	}

	// 重载 << 运算符，用于输出 myvector 对象
	friend ostream& operator<<(ostream& os, const myvector& v)
	{
		os << "[";
		for (int i = 0; i < v.this_size; ++i) {
			os << v.data[i];
			if (i < v.this_size - 1) {
				os << ", ";
			}
		}
		os << "]";
		return os;
	}

	//纯虚函数定义
	//返回size
	int size() const {
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
		while (new_capacity_actual < new_capacity)
		{
			new_capacity_actual *= 2;
		}
		if (new_capacity_actual != this_capacity) {
			int* new_data = new int[new_capacity_actual];
			for (int i = 0; i < new_capacity_actual; ++i) {
				new_data[i] = 0;
			}
			for (int i = 0; i < min(this_size, new_capacity); ++i)
			{
				new_data[i] = data[i];
			}
			delete[] data;
			data = new_data;
			this_size = new_capacity;
			this_capacity = new_capacity_actual;
		}
	}

	// reserve函数，扩展或缩小容量至至少new_capacity大小，不修改size
	void reserve(int new_capacity)
	{
		int new_capacity_actual = 1;
		while (new_capacity_actual < new_capacity) {
			new_capacity_actual *= 2;
		}

		if (new_capacity_actual != this_capacity) {
			int* new_data = new int[new_capacity_actual];
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

	//反转向量
	void reverse() {
		int* new_data = new int[this_capacity];
		for (int i = 0; i < this_size; ++i) {
			new_data[i] = data[this_size - 1 - i];
		}
		delete[] data;
		data = new_data;
	}

	//删除尾元素
	void pop_back()
	{
		if (this_size > 0) {
			--this_size;
		}
	}

	//删除首元素
	void pop_front()
	{
		if (this_size > 0) {
			for (int i = 0; i < this_size - 1; ++i) {
				data[i] = data[i + 1];
			}
			--this_size;
		}
	}

	// 删除指定位置的元素
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

	//清空向量
	void clear()
	{
		delete[] data;
		data = nullptr;
		this_size = 0;
		this_capacity = 0;
	}

	//判断向量是否为空
	bool empty() const
	{
		return this_size == 0;
	}
};
#endif // !MYVECTOR_H

