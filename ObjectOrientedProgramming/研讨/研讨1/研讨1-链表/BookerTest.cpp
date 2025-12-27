#include "LinkList.h"
#include "Booker.h"
#include <conio.h>

void BookerTest()
{
	int daysInMonth;
	LinkList<Booker> uLink;//
	Booker xBooker;
	Node<Booker>* pU;
	BK xBK;
	char id[80], name[80], str[80], bkname[80];
	int choice, year, month, day;
	double money;

	while (true)
	{
		cout << "\n请输入学号(n学号，直接回车则退出)：";
		cin.getline(id, 80);
		if (id[0] == '\0')
			break;
		if (id[0] == 'N' || id[0] == 'n')
		{
			cout << "请输入姓名：";
			cin.getline(name, 80);
			xBooker.Set(id + 1, name);
			uLink.Append(xBooker);
		}
		else
			xBooker.Set(id, "");
		pU = uLink.Locate(string(xBooker), true);
		if (pU == NULL)
		{
			cout << "学号输入错误！" << endl;
			continue;
		}

		while (true)
		{
			cout << endl;
			uLink.CurData().Show(cout);
			cout << "1 -- 借书登记" << endl;
			cout << "2 -- 查询" << endl;
			cout << "0 -- 返回" << endl;
			cout << "请选择：";
			choice = getche() - '0';
			cout << endl;
			if (choice <= 0) break;
			switch (choice)
			{
			case 1:
				cout << "请输入（年 月 日  书籍定价 书名）: ";
				cin >> year >> month >> day >> money >> bkname;
				cin.getline(str, 80);// 处理换行字符
				while (true) {
					if (year < 0 || month < 1 || month > 12 || day < 1||money<1)
					{
						cout << "输入错误，请正确输入" << endl;
						cin >> year >> month >> day >> money >> bkname;
						cin.getline(str, 80);// 处理换行字符
					}

					if (day > checkdays(year,month))
					{
						cout << "输入错误，请正确输入" << endl;
						cin >> year >> month >> day >> money >> bkname;
						cin.getline(str, 80);// 处理换行字符
					}
					else
						break;

				}
				xBK.Set(year, month, day, money, bkname);
				uLink.CurData().AppendBK(xBK);
				break;
			case 2:	cout << uLink.CurData() << endl; break;
			}
		}
	}
	cout << "\n自动调用析构函数释放所有结点，返回主函数。\n" << endl;
}
