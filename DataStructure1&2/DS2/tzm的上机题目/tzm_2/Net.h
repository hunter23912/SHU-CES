#pragma once
#include "Arc.h"
#include "Vex.h"
#include <iostream>
#include <queue>
using namespace std;

template <class T, class W>
class Net
{
protected:
    int vexnum, vexmaxnum = 1000, arcnum;
    Vex<T, W> *vextable; // 数据组

public:
    Net(T es[], int vertexnum);
    void Insertarc(int v1, int v2, W w);
    void show();
    int search_path(char way, T vi, T vj); // 是否有从vextable[i]到vextable[j]的路径
    void dfs(int v);                       // 深度优先搜索
    void bfs(int v);                       // 广度优先搜索
    int find(T e);
    int max_degree(); // 计算图的度
};

template <class T, class W>
int Net<T, W>::find(T e)
{
    for (int i = 0; i < vexnum; i++)
        if (vextable[i].data == e)
            return i;
    return -1;
}

template <class T, class W>
Net<T, W>::Net(T t[], int vertexnum)
{
    if (vertexnum < 0)
    {
        cout << "顶点数不能为负数" << endl;
        return;
    }
    vexnum = vertexnum;
    arcnum = 0;

    vextable = new Vex<T, W>[vexmaxnum];

    for (int v = 0; v < vexnum; v++)
    {
        vextable[v].data = t[v];
        vextable[v].firstarc = NULL;
    }
}

template <class T, class W>
void Net<T, W>::Insertarc(int r, int c, W w) // 插入从r到c，权值为w
{
    Arc<W> *p;
    p = vextable[r].firstarc;
    vextable[r].firstarc = new Arc<W>(c, w, p); // 头插法
    arcnum++;
}

template <class T, class W>
void Net<T, W>::show()
{
    for (int v = 0; v < vexnum; v++)
    {
        cout << v << ":  " << vextable[v].data;
        for (Arc<W> *p = vextable[v].firstarc; p != NULL; p = p->next)
        {
            printf(" -> (%d,", p->to_vex);
            cout << p->weight << ")";
        }
        cout << " -> NULL" << endl;
    }
}

template <class T, class W>
int Net<T, W>::search_path(char way, T vi, T vj)
{
    int i = find(vi), j = find(vj);
    if (way == 'd')
        dfs(i);
    else
        bfs(i);
    cout << endl;

    int flag = (vextable[j].tag == 1);

    for (int i = 0; i < vexnum; i++)
        vextable[i].tag = 0;

    return flag;
}

template <class T, class W>
void Net<T, W>::dfs(int v)
{
    Arc<W> *p = vextable[v].firstarc;
    vextable[v].tag = 1;
    cout << vextable[v].data << "  ";
    while (p != NULL)
    {
        if (vextable[p->to_vex].tag == 0)
            dfs(p->to_vex);
        p = p->next;
    }
}

template <class T, class W>
void Net<T, W>::bfs(int v)
{
    queue<int> q;
    cout << vextable[v].data << "  ";
    q.push(v);
    vextable[v].tag = 1;
    while (!q.empty())
    {
        int e = q.front();
        q.pop();
        Arc<W> *p = vextable[e].firstarc;
        for (; p != NULL; p = p->next)
        {
            if (vextable[p->to_vex].tag == 0)
            {
                cout << vextable[p->to_vex].data << "  ";
                q.push(p->to_vex);
                vextable[p->to_vex].tag = 1;
            }
        }
    }
}

template <class T, class W>
int Net<T, W>::max_degree()
{
    int degree[vexnum + 10] = {0};
    int MaxDegree = 0;
    for (int i = 0; i < vexnum; i++)
    {
        Arc<W> *p = vextable[i].firstarc;
        for (; p != NULL; p = p->next)
        {
            int j = p->to_vex;
            degree[i]++;
            degree[j]++;
            MaxDegree = max(MaxDegree, max(degree[j], degree[i]));
        }
    }
    return MaxDegree;
}