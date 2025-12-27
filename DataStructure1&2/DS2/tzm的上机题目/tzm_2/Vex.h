#pragma once
#include <iostream>
template <class T, class W>
struct Vex
{
    T data;//顶点数据
    Arc<W> *firstarc;//邻接表
    int tag = 0;
    Vex();
    Vex(T data, Arc<W> *adj = NULL);
};

template <class T, class W>
Vex<T, W>::Vex()
{
    firstarc = NULL;
}

template <class T, class W>
Vex<T, W>::Vex(T val, Arc<W> *adj)
{
    data = val;
    firstarc = adj;
}
