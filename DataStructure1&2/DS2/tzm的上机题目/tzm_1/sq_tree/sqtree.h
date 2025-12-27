#pragma once
#include <iostream>
#include <cstring>
using namespace std;

template <class T>
class sqtree
{
public:
    int size;
    T *data;
    int *parents;

    sqtree(T data[], int parents[], int n);
    int degree();
    int leaves();
    int height();
    void show();
    void show(int p, int level);
};

// 构造函数
template <class T>
sqtree<T>::sqtree(T elems[], int p[], int n)
{
    size = n;
    data = new T[size];
    parents = new int[size];
    for (int i = 0; i < size; i++)
    {
        data[i] = elems[i];
        parents[i] = p[i];
    }
}

// 打印树
template <class T>
void sqtree<T>::show()
{
    show(0, 0);
}

// 打印方法
template <class T>
void sqtree<T>::show(int p, int level)
{
    for (int i = 1; i <= level; i++)
        cout << "-";
    cout << data[p] << endl;

    // 每次循环打印同一竖列
    for (int i = 0; i < size; i++)
    {
        // 如果该节点的父亲节点是p，打印以该节点为根的子树
        if (parents[i] == p)
            show(i, level + 1);
    }
}

// 获取高度
template <class T>
int sqtree<T>::height()
{
    int ans = 0, cur;

    // 遍历每个节点，计算每个节点的高度，取最大值
    for (int i = 0; i < size; i++)
    {
        int height = 1;
        cur = parents[i];

        // 回溯到根结点
        while (cur != -1)
        {
            cur = parents[cur];
            height++;
        }
        ans = max(height, ans);
    }
    return ans;
}

// 获取叶子
template <class T>
int sqtree<T>::leaves()
{
    int tag[size + 1]; // 开size+1，将根节点索引变为0
    memset(tag, 0, sizeof(tag));
    for (int i = 0; i < size; i++)
    {
        // 将该节点的父亲节点x的tag标为1，表示x不是叶子节点
        if (tag[parents[i] + 1] == 0)
            tag[parents[i] + 1] = 1;
    }

    int num = 0; // num记录叶子节点数

    // 遍历每个节点，判断是否为孩子节点
    for (int i = 1; i <= size; i++)
    {
        // 如果tag[i]为0，表示没有孩子节点
        if (tag[i] == 0)
            num++;
    }
    return num;
}

// 获取树度
template <class T>
int sqtree<T>::degree()
{
    int a[size + 1]; // 用a数组计算每个节点的度，开size+1，将根结点索引变为0
    memset(a, 0, sizeof(a));
    int m = 0;

    // 遍历每个节点，计算每个节点的度
    for (int i = 0; i < size; i++)
    {
        a[parents[i] + 1]++;
        m = max(m, a[parents[i] + 1]);
    }
    return m;
}
