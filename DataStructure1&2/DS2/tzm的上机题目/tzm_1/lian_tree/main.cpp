#include "tree.h"
int main()
{
    char pre[] = {'a', 'b', 'c', 'e', 'f', 'd'};
    char in[] = {'b', 'f', 'e', 'c', 'd', 'a'};
    int n = sizeof(pre) / sizeof(pre[0]);
    tree<char> t1(pre, in, n);
    cout << "先序序列： ";
    for (int i = 0; i < n; i++)
        cout << pre[i] << " ";
    cout << endl;
    cout << "中序序列： ";
    for (int i = 0; i < n; i++)
        cout << in[i] << " ";
    cout << endl;
    cout << "\n树的孩子兄弟表示法为：\n";
    show(t1);
    cout << "节点数为：" << n << endl;
    cout << "树的高度：" << t1.Height(t1.root) << endl;
    cout << "叶子节点数：" << t1.Leaves(t1.root) << endl;
    cout << "树的度：" << t1.Degree(t1.root) << endl;
    return 0;
}