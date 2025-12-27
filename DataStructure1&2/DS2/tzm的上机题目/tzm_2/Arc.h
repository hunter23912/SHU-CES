#pragma once
#include <iostream>
template <class W>
struct Arc
{
    int to_vex;   // 弧指向的顶点下标
    W weight;     // 边的权值
    Arc<W> *next; // 下条弧

    Arc();
    Arc(int v, W w, Arc<W> *nextarc = NULL);
};

template <class W>
Arc<W>::Arc()
{
    to_vex = -1;
}

template <class W>
Arc<W>::Arc(int v, W w, Arc<W> *nextarc)
{
    to_vex = v;
    weight = w;
    next = nextarc;
}