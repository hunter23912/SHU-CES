#ifndef BOOKER_H
#define BOOKER_H
#include "LinkList.h"
#include <iomanip>

class Booker;

class BK
{
public:
	BK(int Year = 2020, int Month = 1, int Day = 1, double Money = 0, string Bkname = "西游记");
	void Set(int Year, int Month, int Day, double Money, string bkname);
	operator double() const;
	friend ostream& operator<<(ostream& out, const BK& b);
	friend class Booker;

private:
	int year, month, day;
	double money;
	string bkname;
};

class Booker
{
public:
	Booker(const char* ID = "00003721", const char* Name = "NoName");
	void Set(const char* ID, const char* Name);
	operator string() const;
	void AppendBK(const BK& b);
	void Show(ostream& out) const;
	friend ostream& operator<<(ostream& out, const Booker& u);

private:
	string id, name;		// 学号、姓名
	LinkList<BK> link;		// 链表(该借书人的借阅记录)
};
int checkdays(int year, int month);

#endif

