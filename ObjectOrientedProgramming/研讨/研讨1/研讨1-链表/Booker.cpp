#include "Booker.h"
#include <iomanip>

BK::BK(int Year, int Month, int Day, double Money, string Bkname) : year(Year), month(Month), day(Day), money(Money), bkname(Bkname)
{
}

void BK::Set(int Year, int Month, int Day, double Money, string Bkname)
{
	year = Year;
	month = Month;
	day = Day;
	bkname = Bkname;
	money = Money;
}

BK::operator double() const
{
	return money;
}

ostream& operator<<(ostream& out, const BK& b)
{
	out << setfill('0');
	out << b.year << '-' << setw(2) << b.month << '-' << b.day << '\t';
	out << b.money << '\t' << '\t';
	out << b.bkname << setfill(' ');
	return out;
}
/////////////////////////////////////

Booker::Booker(const char* ID, const char* Name) : id(ID), name(Name)
{
}

void Booker::Set(const char* ID, const char* Name)
{
	id = ID;
	name = Name;
}

Booker::operator string() const
{
	return id;
}

void Booker::AppendBK(const BK& b)
{
	double x;
	BK y(b);
	if (link.NumNodes() == 0)
		x = 0;
	else
	{
		link.GoBottom();
	}
	link.Append(y);				// 添加一条借书记录
}

void Booker::Show(ostream& out) const
{
	out << "学号：" << id << "\t姓名：" << name << endl;
}

ostream& operator<<(ostream& out, const Booker& u)
{
	u.Show(out);
	out << "    日期\t书籍定价\t书名" << endl;
	u.link.PutList(out);
	return out;
}
int checkdays(int year,int month) {
	int daysInMonth;
	switch (month) {
	case 2: // 二月
		daysInMonth = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) ? 29 : 28;
		break;
	case 4: case 6: case 9: case 11: // 四、六、九、十一月
		daysInMonth = 30;
		break;
	default: // 其他月份
		daysInMonth = 31;
		break;
	}
	return daysInMonth;
}
