//
//  Stack.c
//  SweetC
//
//  Created by apple on 2017/8/24.
//  Copyright © 2017年 apple. All rights reserved.
//

#include "Stack.h"
#include "Define.h"


Status InitStack(SqStack *S) {

    S->base = (int*)malloc(sizeof(int) * STACK_INIT_SIZE);
    if (!S->base) {
        exit(OVERFLOW); // 存储空间分配失败
    }
    S->top = S->base;
    S->stackzie = STACK_INIT_SIZE;
    return OK;
}

Status GetTop(SqStack S, opndElem *e) {
  
    if (S.top == S.base) { // 栈为空栈
        return ERROR;
    }
    e = (S.top -1);
    *e = *(S.top-1);
    return OK;
}


Status Push(SqStack *S,opndElem e) {
    if (S->top -S->base >= S->stackzie) {
        S->base = (int*)realloc(S->base,(S->stackzie + STACKINCREMENT)*sizeof(int));
        if (!S->base) {
            exit(OVERFLOW);
        }
        S->top = S->base + S->stackzie;
        S->stackzie += STACKINCREMENT;
    }
    *S->top ++ = e;
    return OK;
}

Status Pop(SqStack *S,opndElem *e) {
    if(S->top == S->base) return ERROR;
    *e = *--S->top;
    return OK;
}

Status StackEmpty(SqStack *S){
    if(S->top == S->base) return OK;
    return ERROR;
}
