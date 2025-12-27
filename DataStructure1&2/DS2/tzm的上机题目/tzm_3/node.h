#pragma once
#include<iostream>
using namespace std;
template <class T>
class Node
{
public:
    T data;
    Node<T> *leftchild;
    Node<T> *rightchild;

    Node(const T &val,Node<T> *lchild = NULL,Node<T> *rchild = NULL)
    {
        data = val;
        leftchild = lchild;
        rightchild = rchild;
    };
};