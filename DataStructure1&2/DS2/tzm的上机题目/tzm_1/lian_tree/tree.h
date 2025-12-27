#pragma once
#include "node.h"
template <class T>
class tree
{
public:
    // 成员
    node<T> *root = NULL;
    // 构造部分
    tree(node<T> *r) : root(r) {}

    // 用双亲数组构造孩子兄弟表示法的二叉树
    tree(T elems[], int parents[], int n);
    node<T> *create(T elems[], int parents[], int r, int n);
    void create(node<T> *&r, T pre[], T in[], int preleft, int preright, int inleft, int inright);
    // 二叉树的先序和中序系列构造
    tree(T pre[], T in[], int n);

    // 获取树的高度
    int Height(node<T> *r);

    // 获取叶子节点数
    int Leaves(node<T> *r);

    // 获取树的度
    int Degree(node<T> *r);
};

/***成员函数***/

template <class T>
void tree<T>::create(node<T> *&r, T pre[], T in[], int preleft, int preright, int inleft, int inright)
{
    if (inleft > inright)
        r = NULL;
    else
    {
        r = new node<T>(pre[preleft]);
        int mid = inleft;
        while (in[mid] != pre[preleft])
            mid++;
        // 生成左子树
        create(r->child, pre, in, preleft + 1, preleft + mid - inleft, inleft, mid - 1);
        create(r->right, pre, in, preleft + mid - inleft + 1, preright, mid + 1, inright);
        // 生成右子树
    }
}

// 构造函数
template <class T>
tree<T>::tree(T pre[], T in[], int n)
{
    node<T> *r = NULL;
    create(r, pre, in, 0, n - 1, 0, n - 1);
    root = r;
}

// 获取树的度
template <class T>
int tree<T>::Degree(node<T> *r)
{
    // cout << "调用degree函数, " << "r->data=" << r->data << endl;
    int num = 0, ans = 0;
    node<T> *p;
    for (p = r->child; p != NULL; p = p->right)
    {
        num++;                     // 计算当前层父亲节点r的度
        ans = max(Degree(p), ans); // 计算以p为根的子树的度，并更新度
    }
    ans = max(ans, num);
    // cout <<" num:" << num << " ans:" << ans << endl;
    return ans;
}

// 获取叶子节点数
template <class T>
int tree<T>::Leaves(node<T> *r)
{
    if (r->child == NULL)
        return 1;
    int num = 0;
    node<T> *p;
    // 遍历r的孩子，计算以每个孩子为根结点的子树的叶子节点数
    for (p = r->child; p != NULL; p = p->right)
        num += Leaves(p);
    return num;
}

// 获取树的高
template <class T>
int tree<T>::Height(node<T> *r)
{
    // cout << "调用Height函数, " << "r->data=" << r->data << endl;
    node<T> *p;
    int maxh = 0, h;
    for (p = r->child; p != NULL; p = p->right)
    {
        h = Height(p);
        maxh = max(maxh, h);
    }
    // cout << maxh+1 << endl;
    return maxh + 1;
}

// 显示树（内部实现）
template <class T>
void show(tree<T> &t, node<T> *r, int level)
{
    // cout << "in internal show function\n";
    // 设根结点为第一层
    node<T> *p;
    if (r != NULL)
    {
        for (int i = 1; i < level; i++)
            cout << '-';
        cout << r->data << endl;
        // 递归显示子树
        for (p = r->child; p != NULL; p = p->right)
            show(t, p, level + 1);
    }
}

// 显示树(供外部调用)
template <class T>
void show(tree<T> &t)
{
    if (t.root == NULL)
        cout << "empty tree\n";
    else
    {
        // cout << "in out show function\n";
        show(t, t.root, 1);
        cout << endl;
    }
}

// 构造函数
template <class T>
tree<T>::tree(T elems[], int parents[], int n)
{
    root = create(elems, parents, 0, n);
}

// 构造树
template <class T>
node<T> *tree<T>::create(T elems[], int parents[], int r, int n)
{
    if (r >= 0 && r < n)
    {
        node<T> *rt = new node<T>(elems[r]); // r为当前节点索引
        node<T> *subroot, *cur;

        for (int i = 0; i < n; i++)
        {
            if (parents[i] == r)
            {
                subroot = create(elems, parents, i, n);
                // 接树操作
                if (rt->child == NULL) // 将subroot接到rt首孩子上。
                {
                    rt->child = subroot;
                    cur = subroot;
                }
                else // 将后续找到的子节点接到兄弟节点上
                {
                    cur->right = subroot;
                    cur = subroot;
                }
            }
        }
        return rt; // 若遍历完没找到子节点，返回
    }
    else
        return NULL; // r非法，建立空树
}
