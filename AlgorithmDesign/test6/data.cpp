// 构造跳马测试数据
#include <iostream>
#include <fstream>
using namespace std;

string s(int x)
{
    int k = (x - 1) / 8;
    char a = k + 'a';
    char b = (x - 1) % 8 + 1 + '0'; // 这种取余方法避免了0的情况
    string res;
    res += a;
    res += b;
    return res;
}

int main()
{
    ofstream w;
    w.open("../in.in", ios::out);
    // 8行8列的棋盘
    for (int i = 1; i <= 64; i++)
        for (int j = 1; j <= 64; j++)
            w << s(i) << " " << s(j) << endl;
    w.close();
    return 0;
}