//
//  Stack2.h
//  SweetC
//
//  Created by apple on 2017/8/24.
//  Copyright © 2017年 apple. All rights reserved.
//

#ifndef Stack2_h
#define Stack2_h
#include "Define.h"
#include <stdio.h>

#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10

typedef struct {
    char *base;
    char *top;
    int stackzie;
}SStack;

// 算法迷宫
typedef struct {
    float x;
    float y;
}Postype;

typedef struct {
    int ord;
    Postype seat;
    int di;
} SElemType; // 元素类型

Status InitSStack(SStack *S);
Status DestroySStack(SStack *S);
Status ClearSStack(SStack *S);
Status SStackEmpty(SStack *S);
long SstackLength(SStack S);
Status GetTopS(SStack S, char *e);
Status PushS(SStack *S,char e);
Status PopS(SStack *S,char *e);
Status SStackTraverse(SStack S,Status(*visit)());
Status visit(char e);

#endif /* Stack2_h */
