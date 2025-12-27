// 最长公共子序列问题
#include <iostream>
#include <vector>

using namespace std;

const int N = 1010;

int T;
int n, m;
char x[N], y[N];
int c[N][N], b[N][N];
vector<string> ans;
string str;

/*
2
7 6
ABCBDAB
BDCABA
8 9
baababab
ababbabba

*/

/*
b表中，
1表示x[i] ==  y[j]
2表示c[i - 1][j] > c[i][j - 1]
3表示c[i][j - 1] > c[i - 1][j]
4表示c[i - 1][j] == c[i][j - 1]
*/
// 求出最长公共子序列长度和其来源
void LCSLength()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (x[i] == y[j])
            {
                c[i][j] = c[i - 1][j - 1] + 1;
                b[i][j] = 1;
            }
            else if (c[i - 1][j] >= c[i][j - 1])
            {
                c[i][j] = c[i - 1][j];
                b[i][j] = 2;
                if (c[i - 1][j] == c[i][j - 1])
                    b[i][j] = 4;
            }
            else
            {
                c[i][j] = c[i][j - 1];
                b[i][j] = 3;
            }
        }
    }
}

// 找出所有最长 公共子序列并存到ans中
void LCS(int i, int j)
{
    if (i == 0 || j == 0)
    {
        ans.push_back(str);
        return;
    }
    if (b[i][j] == 1)
    {
        str = x[i] + string(" ") + str;
        LCS(i - 1, j - 1);
        str.erase(str.begin(), str.begin() + 2);
    }
    else
    {
        if (b[i][j] == 4 || b[i][j] == 2)
        {
            LCS(i - 1, j);
        }
        if (b[i][j] == 4 || b[i][j] == 3)

        {
            LCS(i, j - 1);
        }
    }
}

int main()
{
    cin >> T;
    int k = 1;
    while (k <= T)
    {
        cin >> n >> m;
        cin >> (x + 1) >> (y + 1);

        // 求c，b表
        LCSLength();
        printf("Case %d\n最长公共子序列长度: %d\nLCS(X,Y):\n", k++, c[n][m]);

        // 找出所有最长公共子序列
        LCS(n, m);
        for (auto &s : ans)
            cout << s << endl;
        cout << endl;

        // 输出c表
        cout << "输出c表" << endl;
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= m; j++)
            {
                cout << c[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;

        // 输出b表
        cout << "输出b表" << endl;
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= m; j++)
            {
                cout << b[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;

        // 清空ans，以备下一组数据使用
        ans.clear();
    }
    return 0;
}