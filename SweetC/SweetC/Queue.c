//
//  Queue.c
//  SweetC
//
//  Created by apple on 2017/8/29.
//  Copyright © 2017年 apple. All rights reserved.
//

#include "Queue.h"
#include <malloc/malloc.h>
#include <stdio.h>
#include <stdlib.h>

Status InitQueue(LinkQueue *Q){
    Q->front = Q->real = (QueuePtr)malloc(sizeof(QNode));
    if(!Q->front) exit(OVERFLOW);
    Q->front->next = NULL;
    return OK;
}

// 销毁队列Q，Q不再存在
Status DestroyQueue(LinkQueue *Q){
    while (Q->front) {
        Q->real = Q->front->next;
        free(Q->front);
        Q->front = Q->real;
    }
    return OK;
}

// 将Q清为空队列
Status ClearQueue(LinkQueue *Q){
    QueuePtr p;
    Q->real = Q->front->next;
    while (Q->real) {
        p=Q->real->next;
        free(Q->real);
        Q->real = p;
    }
    Q->real = Q->front;
    return OK;
}

// 若队列为空队列，则返回TRUE
Status QueueEmpty(LinkQueue Q)
{
    if(Q.front==Q.real&&Q.front!=NULL) return OK;
    return ERROR;
}

// 返回Q的元素个数
int QueueLength(LinkQueue Q){
    QueuePtr p;
    int count = 0;
    p = Q.front->next;
    while (p!=NULL) {
        p = p->next;
        count ++;
    }
    return count;
}

// 若队列不空，用e返回队列Q的头元素，并返回OK；否则返回Error
Status GetHead(LinkQueue Q, QElemType *e){
    if(Q.front==Q.real) return ERROR;
    *e = Q.front->next->data;
    return OK;
}

// 插入元素e为新的队尾元素
Status EnQueue(LinkQueue *Q, QElemType e) {
    QueuePtr p = (QueuePtr)malloc(sizeof(QNode));
    if(!p) exit(OVERFLOW);
    p->data = e;
    p->next = NULL;
    Q->real->next = p;
    Q->real = p;
    
    return OK;
}

// 若队列不空，则删除0的对头元素，用e返回其值，并返回OK
Status DeQueue(LinkQueue *Q, QElemType *e) {
    if (Q->front == Q->real) {
        return ERROR;
    }
    QueuePtr p = Q->front->next;
    e = &p->data;
    Q->front->next=p->next;
    if(Q->real == p) Q->real = Q->front;
    free(p);
    return OK;
}

Status QueueTraverse2(LinkQueue Q){
    QueuePtr p;
    p = Q.front->next;
    if(p==NULL) return ERROR;
    while (p!=NULL) {
        visit2(p->data);
        p=p->next;
    }
    return OK;
}
void visit2(QElemType e){
    printf("%c",e);
}
