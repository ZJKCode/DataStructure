//
//  Queue.h
//  SweetC
//
//  Created by apple on 2017/8/29.
//  Copyright © 2017年 apple. All rights reserved.
//

#ifndef Queue_h
#define Queue_h

#include <stdio.h>

#include "Define.h"

typedef int QElemType;

typedef struct QNode {
    QElemType data;
    struct QNode *next;
}QNode ,*QueuePtr;

typedef struct {
    QueuePtr front; // 队头指针
    QueuePtr real; // 队尾指针
}LinkQueue;

// 基本操作函数
// 构造一个空队列
Status InitQueue(LinkQueue *Q);

// 销毁队列Q，Q不再存在
Status DestroyQueue(LinkQueue *Q);

// 将Q清为空队列
Status ClearQueue(LinkQueue *Q);

// 若队列为空队列，则返回TRUE
Status QueueEmpty(LinkQueue Q);

// 返回Q的元素个数
int QueueLength(LinkQueue Q);

// 若队列不空，用e返回队列Q的头元素，并返回OK；否则返回Error
Status GetHead(LinkQueue Q, QElemType *e);

// 插入元素e为新的队尾元素
Status EnQueue(LinkQueue *Q, QElemType e);

// 若队列不空，则删除0的对头元素，用e返回其值，并返回OK
Status DeQueue(LinkQueue *Q, QElemType *e);

Status QueueTraverse2(LinkQueue Q);
void visit2(QElemType e);

#endif /* Queue_h */
