//
//  Stack.h
//  SweetC
//
//  Created by apple on 2017/8/24.
//  Copyright © 2017年 apple. All rights reserved.
//

#ifndef Stack_h
#define Stack_h

#include <stdio.h>
#include "Define.h"
typedef struct {
    int age;
    char *name;
} SELemType;

typedef int opndElem;  //操作数元素类型
// 栈结构体
typedef struct {
    opndElem *base; // 在栈构造之前和销毁之后，base的值为NULL
    opndElem *top; // 栈顶指针
    int stackzie; // 当前已分配的存储空间，以元素为单位
}SqStack; // 顺序栈

typedef int opndElem;  //操作数元素类型
typedef struct{//操作数栈结构定义
    opndElem *base;
    opndElem *top;
    int stacksize;
}OpndStack;


typedef char optrElem;//操作符元素类型
typedef struct{//操作符栈结构定义
    optrElem *base;
    optrElem *top;
    int stacksize;
}OptrStack;


#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
// 基本操作原型说明部分
Status InitStack(SqStack *S);
Status DestroyStack(SqStack *S);
Status ClearStack(SqStack *S);
Status StackEmpty(SqStack *S);
int StackLength(SqStack S);
Status GetTop(SqStack S, opndElem *e);
Status Push(SqStack *S,opndElem e);
Status Pop(SqStack *S,opndElem *e);
Status StackTraverse(SqStack S,Status(*visit)());

#endif /* Stack_h */
