//
//  Stack2.c
//  SweetC
//
//  Created by apple on 2017/8/24.
//  Copyright © 2017年 apple. All rights reserved.
//

#include "Stack2.h"
#include <malloc/malloc.h>
#include <stdio.h>
#include <stdlib.h>
Status InitSStack(SStack *S) {
    S->base = (char *)malloc(sizeof(char)*STACK_INIT_SIZE);
    if (!S->base) exit(OVERFLOW);
    S->top = S->base;
    S->stackzie = STACK_INIT_SIZE;
    return OK;
}
Status DestroySStack(SStack *S){
    free(S->base);
    S->base = NULL;
    S->top = NULL;
    S->stackzie = 0;
    return OK;
}
Status ClearSStack(SStack *S){
    S->top = S->base;
    return OK;
}
Status SStackEmpty(SStack *S) {
    if (S->top == S->base) {
        return OK;
    }
    return ERROR;
}
long SStackLength(SStack S) {
    return S.top - S.base;
};
Status GetTopS(SStack S, char *e){
    if (S.top == S.base) {
        return ERROR;
    }
    *e = *(S.top-1);
    return OK;
}
Status PushS(SStack *S,char e) {
    if (S->top - S->base >= S->stackzie) {
        S->base = (char *)realloc(S->base,(S->stackzie + STACKINCREMENT)*sizeof(char));
        if (!S->base) exit(OVERFLOW);
        S->top = S->base + S->stackzie;
        S->stackzie += STACKINCREMENT;
    }
    *S->top ++=e;
    
    return OK;
}
Status PopS(SStack *S,char *e) {
    if (S->top == S->base) {
        return ERROR;
    }
    *e = *--S->top;
    return OK;
}
Status SStackTraverse(SStack S,Status(*visit)()){
    while(S.top > S.base) {
        visit(*S.base++);
    }
    printf("\n");
    return OK;
}

Status visit(char e){
    printf("%c",e);
    return OK;
}
