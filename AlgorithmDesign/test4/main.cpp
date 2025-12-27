#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 节点结构体
struct node
{
    int l, r, w;
    int id;
    string code;
    bool operator<(const node &a) const
    {
        if (w == a.w)
            return id < a.id; // 先输入权值的后处理
        return w > a.w;       // 构造最小堆
    }
};

class tree
{
public:
    int cnt; // 记录当前节点id
    int n;   // 开辟空间大小，2*num数量
    node *head;

    // 构造函数
    tree(int num) : cnt(0), n(2 * num)
    {
        head = new node[n];
    };

    // 插入操作，左右孩子、权值、id
    void insert(int lchild, int rchild, int weight)
    {
        head[cnt].l = lchild;
        head[cnt].r = rchild;
        head[cnt].w = weight;
        head[cnt].id = cnt;
        cnt++;
    }

    // 合并两个节点，并将新节点加到head中
    void union_node(int a, int b)
    {
        insert(a, b, head[a].w + head[b].w);
    }

    // 析构函数
    ~tree()
    {
        delete[] head;
    }

    // 生成哈夫曼编码
    void dfs(int u, string s)
    {
        if (u == -1)
            return;
        head[u].code = s;        // 保存编码
        dfs(head[u].l, s + "0"); // 左子树编码为0
        dfs(head[u].r, s + "1"); // 右子树编码为1
    }

    // 构造哈夫曼树
    void solve()
    {
        // 最小堆，按照w从小到大排序
        priority_queue<node> q;
        for (int i = 0; i < cnt; i++)
            q.push(head[i]);

        // 构造哈夫曼树，每次取出两个最小的节点合并
        while (q.size() > 1)
        {
            // a为权值最小的节点，b为权值次小的节点
            node a = q.top();
            q.pop();
            node b = q.top();
            q.pop();
            union_node(b.id, a.id); // 只添加了合并的非叶子节点，将较大节点放哈夫曼树中左边
            q.push(head[cnt - 1]);
        }
        // 最终队列中只剩下一个根节点
        int c = q.top().id;
        dfs(c, ""); // 从根节点开始dfs
    }
};
/*
2
6
9 8 3 4 1 2
8
60 20 5 5 3 3 3 1

*/
int main()
{
    ios::sync_with_stdio(0);
    int T;
    cin >> T;
    int k = 1;

    // 处理T组数据
    while (k <= T)
    {
        int n;
        cin >> n;
        tree tr(n + 1);

        // 将n个点放入head数组
        for (int i = 1; i <= n; i++)
        {
            int x;
            cin >> x;

            // 当前每个节点为孤立节点
            tr.insert(-1, -1, x);
        }

        // 构造哈夫曼树
        tr.solve();
        cout << "Case " << k++ << endl;
        // 输出哈夫曼节点权值和编码
        for (int i = 0; i < n; i++)
            cout << tr.head[i].w << " " << tr.head[i].code << endl;
    }
    return 0;
}