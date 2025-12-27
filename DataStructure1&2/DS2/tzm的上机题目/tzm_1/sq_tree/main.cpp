#include "sqtree.h"
int main()
{
    char elems[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};
    int parents[] = {-1, 0, 0, 0, 2, 4, 5};
    int n = sizeof(parents) / sizeof(parents[0]);
    cout << "树的信息：\n";
    for (int i = 0; i < n; i++)
        printf("%-3d %-3c %3d\n", i, elems[i], parents[i]);
    sqtree<char> t(elems, parents, n);
    cout << "展示树：\n";
    t.show();
    cout << "\n树的度:" << t.degree() << endl;
    cout << "叶子节点数：" << t.leaves() << endl;
    cout << "树的高：" << t.height() << endl;
    return 0;
}