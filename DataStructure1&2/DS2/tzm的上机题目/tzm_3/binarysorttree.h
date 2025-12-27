#pragma once
#include "node.h"
#include <queue>
using namespace std;
template <class T>
class bstree
{
public:
    Node<T> *root;
    bstree() { root = NULL; }
    Node<T> *find(const T &key, Node<T> *&f) const;
    bool insert(T &e);
    // bool isbstree(T &pre, Node<T> *p);
    void print_number(Node<T> *p, T x) const;
    void show(const Node<T> *r, int level);
};

template <class T>
void bstree<T>::show(const Node<T> *r, int level)
{
    if (r)
    {
        show(r->rightchild, level + 1);
        for (int i = 1; i < level; i++)
            cout << "--";
        cout << r->data << endl;
        show(r->leftchild, level + 1);
    }
}

template <class T>
Node<T> *bstree<T>::find(const T &key, Node<T> *&f) const
{
    Node<T> *p = root;
    f = NULL;
    // int num = 0;
    while (p != NULL && p->data != key)
    {
        if (p->data > key)
        {
            f = p;
            p = p->leftchild;
        }
        else
        {
            f = p;
            p = p->rightchild;
        }
        // num++;
    }
    return p;
}

template <class T>
bool bstree<T>::insert(T &e)
{
    Node<T> *f;
    if (!find(e, f))//如果没有找到e节点，则插入
    {
        Node<T> *p;
        p = new Node<T>(e);
        if (root == NULL)
            root = p;
        else if (f->data > e)
            f->leftchild = p;
        else
            f->rightchild = p;
        cout << "insert suceeded " << p->data << endl;
        return true;
    }
    else
    {
        cout << "insert failed " << e << " has already been found" << endl;
        return false;
    }
}

template<class T>
void bstree<T>::print_number(Node<T> *p, T x) const
{
    if(p)
    {
        print_number(p->rightchild, x);
        if(p->data < x)
            return;
        cout << p->data << " ";
        print_number(p->leftchild, x);
    }
}

// template <class T>
// bool bstree<T>::isbstree(T &pre, Node<T> *p)
// {
//     int flag = true;
//     if (p)
//     {
//         flag = istree(pre, p->leftchild);
//         if (!flag || p->data < pre)
//             return false;
//         pre = p->data;
//         flag = isbstree(pre, p->rightchild);
//     }
//     return flag;
// }
