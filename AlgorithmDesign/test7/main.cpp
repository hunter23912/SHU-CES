#include <iostream>
#include <cstring>
using namespace std;

// 装载问题，使用子集树方式解决

const int N = 1e5 + 10;
int n;
int a[N];  // 记录每个物品的重量
int st[N]; // 1表示装在左边，0表示装在右边
bool flag; // 记录是否找到答案
int cnt = 0;
// u表示当前处理的物品，lf表示左边的重量，rf表示右边的重量
void dfs(int u, int lf, int rf)
{
    if (flag)
        return;
    if (u == n + 1)
    {
        flag = 1;
        int x = 0;  // 记录第一艘船装的重量
        string ans; // 记录装载方案，1表装左边，0表示装右边
        for (int i = 1; i <= n; i++)
        {
            if (st[i])
                x += a[i];
            ans += to_string(st[i]);
        }
        cout << x << " " << ans << endl;
        return;
    }
    if (lf >= a[u])
    {
        st[u] = 1;
        dfs(u + 1, lf - a[u], rf);
    }
    else if (rf >= a[u])
    {
        st[u] = 0;

        dfs(u + 1, lf, rf - a[u]);
    }
}
/*
3
10 40 40
50 50

3
20 40 40
50 50

*/
int main()
{
    int k = 1;
    while (cin >> n)
    {
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            st[i] = 1; // 初始化为1,表示装在左边
        }
        int lf, rf;
        cin >> lf >> rf;
        flag = 0;
        cout << "Case " << k++ << endl;
        dfs(1, lf, rf);
        if (!flag) // 没有找到答案
            cout << "No" << endl;
    }
    return 0;
}