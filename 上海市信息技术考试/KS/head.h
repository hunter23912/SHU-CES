#pragma once
#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

/*学生个人信息结点定义*/
typedef struct Student {
    char no[5];                         /* 学号 */
    char name[20];                      /* 姓名 */
    float score;                        /* 分数 */
    struct Student *next;               /* 下一结点指针 */
} sNode;
