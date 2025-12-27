#include <vector>
#include <iostream>
using namespace std;
#define inf 99999
const int N = 1e6 + 5;
// Dijkstra算法求无向图任意两点最短路径

// 边结构体
struct edge
{
    int v, w;
};

int dist[N];         // dist[i]表示从源点s到i的最短距离
bool st[N];          // st[i]表示i是否已经被访问
vector<int> path[N]; // path[i]存放从源点s到i的最优路径,例如：path[i] = {s, a, b, c, i}，表示s->a->b->c->i
vector<edge> g[N];   // 图存储，g[i] = {v,w},存储i的所有邻接点v和权值w
int n, s, t;         // n表示点数，s表示源点，t表示终点

// 初始化，将dist全部置为inf，st全部置为0
void init()
{
    for (int i = 0; i <= n; i++)
    {
        dist[i] = inf; // 初始化为无穷大
        st[i] = 0;
        path[i].clear();
        path[i].push_back(i); // 路径初始化为自己，即i->i
        g[i].clear();
    }
}

// 添加边，u->v的权值为w
void add(int u, int v, int w)
{
    g[u].push_back({v, w});
}

// 比较两个路径的字典序，返回true表示a字典序大于b
bool cmp(const vector<int> &a, const vector<int> &b)
{
    //
    for (size_t i = 1; i < a.size() && i < b.size(); i++)
        if (a[i] > b[i])
            return true;
        else
            return false;
    return a.size() > b.size();
}

// Dijkstra算法，求最短路径，路径存储在path数组中，dist数组存储最短距离
void dijkstra()
{
    // 初始化u == s
    int u = s;
    dist[u] = 0;
    st[u] = true;

    // 求n次最短路径
    for (int i = 1; i <= n; i++)
    {
        // 更新u的所有邻接点，初始时u为源点
        for (auto x : g[u])
        {
            int v = x.v, w = x.w; // 取出邻接点和权值

            // 如果v已经被访问过，跳过
            if (st[v])
                continue;
            // u->v
            if (dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
                path[v] = path[u];    // 将更短的路径更新到path[v]中
                path[v].push_back(v); // 将v加入到路径中
            }
            // 路径权值和相等情况
            else if (dist[v] == dist[u] + w)
            {
                // 如果当前路段数较长，更新为较短路径
                if (path[v].size() > path[u].size() + 1)
                {
                    path[v] = path[u];
                    path[v].push_back(v);
                }
                // 如果当前路径长度相等，比较字典序
                else if (path[v].size() == path[u].size() + 1)
                {
                    path[v].pop_back();
                    // 如果path[v]字典序大于path[u]，返回true
                    if (cmp(path[v], path[u])) //
                        path[v] = path[u];
                    path[v].push_back(v);
                }
            }
        }

        // 更新完u的邻接点后，找未访问的点中，dist最小的点
        int li = inf, pos = 0;
        for (int j = 1; j <= n; j++)
        {
            // 如果已经被访问，跳过
            if (st[j])
                continue;

            // 找到最短的dist[j]
            if (dist[j] < li)
            {
                li = dist[j];
                pos = j;
            }
            // 如果找到两个dist[j]相等的点
            else if (dist[j] == li)
            {
                // 路段数更新为较少的
                if (path[j].size() < path[pos].size())
                {
                    li = dist[j];
                    pos = j;
                }
                // 如果路段数相同，比较字典序
                else if (path[j].size() == path[pos].size())
                {
                    // 更新为字典序较小的
                    if (cmp(path[pos], path[j]))
                    {
                        li = dist[j];
                        pos = j;
                    }
                }
            }
        }
        st[pos] = 1; // 标记pos已经被访问
        u = pos;     // 下一个最短路径
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int k = 1;
    // 输入点数
    while (cin >> n)
    {
        init();
        // 输入边
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                int w;
                cin >> w;
                if (w != -1)
                    add(i, j, w);
            }
        }

        // 输入源点和终点
        cin >> s >> t;
        // 求最短路径
        dijkstra();

        cout << "Case " << k++ << endl;
        cout << "The least disttance from " << s << "->" << t << " is " << dist[t] << endl;
        cout << "The path is ";

        // 输出最短路径
        for (size_t i = 0; i < path[t].size(); i++)
        {
            // 第一个不输出->
            if (i)
                cout << "->";
            cout << path[t][i];
        }
        cout << endl;
    }
    return 0;
}