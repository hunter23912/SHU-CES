#include "binarysorttree.h"

/*
39 68 11 23 46 34 75 86 8 71
*/
int main()
{
    bstree<int> tree;
    int elems[] = {39, 68, 11, 23, 46, 34, 75, 86, 8, 71};
    /*
    int *elems;
    int n;
    cin >> n;
    elems = new int[n];
    for(int i=0;i<n;i++)
        cin >> elems[i];
    */
    int n = sizeof(elems) / sizeof(int);
    for (int i = 0; i < n; i++)
        tree.insert(elems[i]);
    // do
    // {
    //     int elem;
    //     cin >> elem;
    //     tree.insert(elem);
    // } while (getchar() != '\n');
    tree.show(tree.root, 1);
    cout << "请输入关键字x,将输出所有不小于x的数据元素:\n";
    int x;
    cin >> x;
    tree.print_number(tree.root, x);
    return 0;
}
/*

*/