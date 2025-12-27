// 跳马问题
#include <cstring>
#include <fstream>
#include <iostream>
#include <queue>

#define PII pair<int, int>
#define x first
#define y second

#define rep(a, b) for (int i = (a); i < (b); i++)

using namespace std;

// 8个方向, 逆时针,横x,纵y
int dx[] = {2, 1, -1, -2, -2, -1, 1, 2};
int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
int st[9][9]; // 表示棋盘

// 广度优先遍历
void bfs(int &sx, int &sy)
{
    queue<PII> q;
    q.push({sx, sy}); // 起点入队

    // bfs
    while (!q.empty())
    {
        int ux = q.front().x, uy = q.front().y;
        q.pop();
        // 枚举8个方向
        rep(0, 8)
        {
            int vx = ux + dx[i], vy = uy + dy[i];
            if (vx <= 0 || vy <= 0 || vx > 8 || vy > 8)
                continue;
            if (st[vx][vy] > st[ux][uy] + 1)
            {
                st[vx][vy] = st[ux][uy] + 1;
                q.push({vx, vy});
            }
        }
    }
}

// 深度优先遍历
void dfs(int ux, int uy)
{
    rep(0, 8)
    {
        int vx = ux + dx[i], vy = uy + dy[i];
        if (vx <= 0 || vy <= 0 || vx > 8 || vy > 8)
            continue;
        if (st[vx][vy] > st[ux][uy] + 1)
        {
            st[vx][vy] = st[ux][uy] + 1;
            dfs(vx, vy);
        }
    }
}

// 主函数
int main()
{
    ifstream r;
    r.open("../in.in", ios::in);
    ofstream w;
    w.open("../out_dfs.out", ios::out);
    clock_t start;
    start = clock();
    string s, t;
    while (r >> s >> t)
    {
        // 坐标转化，如"a1",将a转为1，字符'1'转为数字1
        int sx = s[0] - 'a' + 1, sy = s[1] - '0'; // s表起点的x,y坐标
        int tx = t[0] - 'a' + 1, ty = t[1] - '0'; // t表终点的x,y坐标
        memset(st, 0x3f, sizeof(st));
        st[sx][sy] = 0;
        bfs(sx, sy);
        // w << s << "==>" << t << ": " << st[tx][ty] << "moves" << endl;
    }

    // 输出运行时间
    // w << "运行时间为：" << double(clock() - start) << "ms" << endl;
    r.close();
    w.close();
    return 0;
}