#include <iostream>

using namespace std;

template <class Type>
inline void Swap(Type &a, Type &b)
{
    Type temp = a;
    a = b;
    b = temp;
}

// 全排列算法
template <class Type>
void Perm(Type list[], int k, int m) // 产生list[k:m]的全排列
{
    if (k == m)
    {
        for (int i = 0; i <= m; i++)
            cout << list[i];
        cout << endl;
    }
    else
    {
        for (int i = k; i <= m; i++)
        {
            Swap(list[k], list[i]);
            Perm(list, k + 1, m);
            Swap(list[k], list[i]);
        }
    }
}

// 整数划分
int q(int n, int m)
{
    if (n < 1 || m < 1)
        return 0;
    if (n == 1 || m == 1)
        return 1;
    if (n < m)
        return q(n, n);
    if (n == m)
        return q(n, m - 1) + 1;
    return q(n, m - 1) + q(n - m, m);
}

// Hanoi塔问题
int hanoi(int n, int a, int b, int c)
{
    int cnt = 0;
    if (n > 0)
    {
        hanoi(n - 1, a, c, b);
        cnt++;
        hanoi(n - 1, c, b, a);
    }
    return cnt;
}

int main()
{
    cout << "结果是: " << hanoi(100, 1, 2, 3);
    return 0;
}