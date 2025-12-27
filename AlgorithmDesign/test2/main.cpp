#include <iostream>
#include <cstring>
/*
矩阵连乘的最少乘法次数
给定n个矩阵{A1,A2,...,An}，其中Ai与Ai+1是可乘的，i=1,2,...,n-1。矩阵Ai的规模为pi-1*pi，i=1,2,...,n。求完全括号化方案，使得计算矩阵连乘积所需标量乘法次数最少。
f[i][j]表示Ai到Aj的矩阵连乘的最少乘法次数
f[i][j]=min{f[i][k]+f[k+1][j]+row[i]*col[x]*col[j]}
其中i<=k<j,x为i,k矩阵相乘后的矩阵的列数,k+1,j矩阵相乘后的矩阵的行数

例如：
3个矩阵A1，A2，A3，阶分别为10×100、100×5、5×50，
计算连乘积A1A2A3时按（A1A2）A3所需的元素乘法次数达到最少，为(5000+2500)=7500次。

3
10 100 5 50
7500

4
50 10 40 30 5
10500

4
10 30 5 60 8
4300

*/
using namespace std;
typedef long long LL;
const int N = 200;
LL a[N], f[N][N];
string ans;

// 使用深度优先搜索输出括号化方案
void dfs(int l, int r)
{
    if (l == r)
    {
        ans += "A";
        ans += char(r + '0');
        return;
    }
    ans += '(';
    for (int i = l; i < r; i++)
    {
        // 找到分界点
        if (f[l][r] == f[l][i] + f[i + 1][r] + a[l - 1] * a[i] * a[r])
        {
            dfs(l, i);
            dfs(i + 1, r);
            break;
        }
    }
    ans += ')';
}

void solution()
{
    int n, t = 0;
    while (cin >> n)
    {
        if (n == 0)
            break;

        // 输入数据
        for (int i = 0; i <= n; i++)
            cin >> a[i];

        // 初始化状态函数
        memset(f, 0x3f, sizeof(f));

        // 矩阵自身相乘次数为0
        for (int i = 1; i <= n; i++)
        {
            f[i][i] = 0;
            // f[i][i+1] = a[i-1]*a[i]*a[i+1];
        }

        // 状态转移方程
        for (int len = 1; len < n; len++)
            for (int i = 1; i + len <= n; i++)
                for (int j = i; j < i + len; j++)
                    f[i][i + len] = min(f[i][i + len], f[i][j] + f[j + 1][i + len] + a[i - 1] * a[j] * a[i + len]);
        // 以j为分界点，左边i到j，右边j+1到i+len
        // 输出结果
        cout << "Case " << ++t << endl;
        cout << f[1][n] << " ";
        ans.clear();
        dfs(1, n);
        for (int i = 1; i < ans.size() - 1; i++) // 去掉最外层的括号
            cout << ans[i];
        cout << endl
             << endl;
    }
}

int main()
{
    solution();
    return 0;
}