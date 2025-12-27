#pragma once
#include <iostream>
using namespace std;
template <class T>
struct node
{
    T data;                // 数据域
    node<T> *child = NULL; // 指向首孩子指针域
    node<T> *right = NULL; // 指向右兄弟指针域

    node(T val, node<T> *child1 = NULL, node<T> *right1 = NULL);
};

template <class T>
node<T>::node(T val, node<T> *child1, node<T> *right1)
{
    data = val;
    child = child1;
    right = right1;
}