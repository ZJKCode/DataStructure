//
//  discreteEvent.c
//  SweetC
//
//  Created by apple on 2017/8/29.
//  Copyright © 2017年 apple. All rights reserved.
//

// 离散事件模拟，模拟银行营业时的排队情况
// 不考虑顾客中途离开，顾客到达事件随机，业务办理事件，长度随机
// 选择最短的对排队，不再换队
#include "discreteEvent.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "Define.h"

typedef struct Event{ // 数据类型
    int OccurTime; // 事件发生时刻
    int NType; // 事件类型，0表示到达事件，1至4表示4个窗口的离开事件
    struct Event *next;
}Event, ElemType;

typedef struct { // 单向链表结构
    ElemType *head; // 头指针
    ElemType *tail; // 尾指针
    int len;
}LinkList;

typedef LinkList EventList; // 事件链接

typedef struct QElemType{ // 队列元素
    int ArriveTime; // 到达时间
    int Duration; // 办理业务所需时间
    struct QElemType *next;

}QElemType;

typedef struct { // 队列结构
    QElemType *head; // 头指针
    QElemType *tail; // 尾指针
}LinkQueue;

Event NewEnvent(int occurT, int nType);

// 链表
Status InitList(LinkList *L);

Status OrderInsert(LinkList *L,Event e);

Status ListEmpty(LinkList *L);

Status DelFirst(LinkList *L,ElemType *e);

Status ListTraverse(LinkList *L);

// 队列

Status InitQueue(LinkQueue *Q);

Status EmptyQueue(LinkQueue *Q);

Status DelQueue (LinkQueue *Q, QElemType *e);

Status EnQueue(LinkQueue *Q, QElemType e);

int QueueLength(LinkQueue Q);

Status GetHead(LinkQueue *Q, QElemType *e);

Status QueueTraverse(LinkQueue *Q);

//
int Min(int a[],int n); // 返回长度为n的数组a第一个最小值的下标，从1开始
int ShortestQueue(); // 获取最短队列的编号
void OpenForDay();  // 初始化操作
void CustomerArrived(); // 顾客到达事件
void CustomerDepature(); // 顾客离开事件
void PrintEventList(); // 输出事件队列
void PrintQueue(); // 打印当前队列

//---全局变量---//
EventList ev;
Event en;
LinkQueue q[5];
QElemType customer;
int TotalTime,CustomerNum;
int CloseTime = 50; //关闭时间，即营业时间长度

// 模拟排队
void OpenForDay(){
    int i;
    TotalTime = 0;
    CustomerNum = 0;
    InitList(&ev);
    en.OccurTime = 0;
    en.NType = 0;
    OrderInsert(&ev, en);
    for (i = 1; i<=4; i++) {
        InitQueue(&q[i]);
    }
}// 初始化操作

void CustomerArrived(){
    int durTime,interTime,i,t;
    QElemType e;
    ++CustomerNum;
    interTime=rand()%5+1;
    durTime=rand()%30+1;
    t=en.OccurTime+interTime;
    if (t<CloseTime) { // 银行尚未关门
        printf("A new customer will arrive at:%d\n",en.OccurTime);
        OrderInsert(&ev, NewEnvent(t, 0)); // 链表插入新的事件
        i = ShortestQueue();// 最短队列
        e.ArriveTime=en.OccurTime;
        e.Duration = durTime;
        EnQueue(&q[i], e);
        if (QueueLength(q[i])==1) {
            // 客户将要离开的事件
            OrderInsert(&ev, NewEnvent(en.OccurTime+durTime, i));
        }
    }
}// 顾客到达事件
void CustomerDepature(){
    int i = en.NType;
    DelQueue(&q[i], &customer); // 将事件从队列中删除
    printf("A customer leaves at:%d\n",en.OccurTime);
    TotalTime += en.OccurTime - customer.ArriveTime;
    if (!EmptyQueue(&q[i])) {
        GetHead(&q[i], &customer);
        OrderInsert(&ev, NewEnvent(en.OccurTime+customer.Duration, i));
    }
}// 顾客离开事件
void Bank_Simulation(){
    OpenForDay();
    srand((unsigned)time(NULL));
    while (!ListEmpty(&ev)) {
        DelFirst(&ev, &en);
        if (en.NType==0) {
            CustomerArrived();
        }else{
            CustomerDepature();
        }
        PrintQueue();
    }
    printf("\nTotal time is: %d min,average time is: %g min.\n",TotalTime,(float)TotalTime/CustomerNum);
}// 银行排队模拟
void PrintEventList(){
    //输出事件队列
    printf("Current Eventlist is：\n");
    ListTraverse(&ev);
}// 输出事件队列
void PrintQueue(){
    // 打印当前队列
    int i ;
    for (i=1; i<=4; i++) {
        printf("Queue %d have %d customer(s):",i,QueueLength(q[i]));
        QueueTraverse(&q[i]);
    }
    printf("\n");
}// 打印当前队列
int Min(int a[],int n){
    int i,tmp,ind = 0;
    tmp = a[0];
    for (i=1; i<n; i++) {
        if (a[i]<tmp) {
            tmp=a[i];
            ind=i;
        }
    }
    return ind;
}// 返回长度为n的数组a第一个最小值的下标，从1开始
int ShortestQueue(){
    int i, a[4];
    for (i=1; i<=4; i++) {
        a[i-1]=QueueLength(q[i]);
        //printf("队%d的长度为%d\n",i,QueueLength(q[i]));
    }
    return Min(a, 4)+1;
}// 获取最短队列的编号

// 队和链表操作
Event NewEnvent(int occurT, int nType){
    
    Event e;
    e.OccurTime = occurT;
    e.NType = nType;
    return e;
}

// 链表
Status InitList(LinkList *L){
    L->head=L->tail=(ElemType*)malloc(sizeof(ElemType));
    if(!L->head){
        printf("Apply for memory error.LinkList initialize failed.\n");
        exit(0);
    }
    L->head->next = NULL;
    return OK;
}

Status OrderInsert(LinkList *L,Event e){
    // 将事件e按发生时间顺序插入有序链表L中
    ElemType *p,*q,*newptr;
    newptr = (ElemType *)malloc(sizeof(ElemType));
    if (!newptr) {
        printf("Apply for memory error，new node can't insert intot the Eventlist.\n");
        exit(0);
    }
    *newptr = e;
    if (ListEmpty(L)==TRUE) {
        // 链表为空
        L->head->next = newptr;
        L->tail = newptr;
        L->tail->next = NULL;
        return OK;
    }
    q = L->head;
    p = L->head->next;
    while (p) {
        // 遍历整个链表
        if (p->OccurTime>=newptr->OccurTime) {
            break;
        }
        q=p;
        p=p->next;
        
    }
    q->next = newptr;
    newptr->next=p;
    if (!p) {
        L->tail = newptr;
    }
    return OK;
}

Status ListEmpty(LinkList *L){
    if ((L->head == L->tail)&&(L->head!=NULL)) {
        return TRUE;
    }else
        return FALSE;
}

Status DelFirst(LinkList *L,ElemType *e){
    ElemType *p = L->head->next;
    if (!p) {
        return ERROR;
    }
    L->head->next=p->next;
    *e=*p;
    free(p);
    if (L->head->next == NULL) {
        L->tail=L->head;
    }
    return OK;
}

Status ListTraverse(LinkList *L){
    // 遍历链表
    Event *p = L->head->next;
    if (!p) {
        printf("List is empty!");
        return ERROR;
    }
    
    while (p!=NULL) {
        printf("OccurTime:%d,Event Type:%d\n",p->OccurTime,p->NType);
        p=p->next;
    }
    printf("\n");
    return OK;
}

// 队列

Status InitQueue(LinkQueue *Q){
    Q->head = Q->tail = (QElemType*)malloc(sizeof(QElemType));
    if (!Q->head) {
        printf("Apply for memory error.LinkQueue initialize failed.\n");
        exit(0);
    }
    Q->head->next = NULL;
    return OK;
}

Status EmptyQueue(LinkQueue *Q){
    if (Q->head==Q->tail && Q->head!=NULL) {
        return TRUE;
    }else
        return FALSE;
}

Status DelQueue (LinkQueue *Q, QElemType *e){
    QElemType *p = Q->head->next;
    if (!p) {
        return ERROR;
    }
    *e = *p;
    Q->head->next = p->next;
    free(p);
    if (!Q->head->next) {
        //对空
        Q->tail = Q->head;
    }
    return OK;
}

Status EnQueue(LinkQueue *Q, QElemType e){

    // 节点e入队Q
    QElemType *p = (QElemType *)malloc(sizeof(QElemType));
    if (!p) {
        printf("Apply for memory error,new element can't enqueue.\n");
        exit(0);
    }
    *p = e;
    p->next = NULL;
    Q->tail->next = p;// 插入队尾
    Q->tail = p; // 修改队尾指针

    return OK;
}

int QueueLength(LinkQueue Q)  {
    int count = 0;
    QElemType *p = Q.head->next;
    while (p) {
        p=p->next;
        count++;
    }
    return count;
}

Status GetHead(LinkQueue *Q, QElemType *e) {
    if (EmptyQueue(Q)) {
        return ERROR;
    }
    
    *e = *Q->head->next;
    return OK;
}

Status QueueTraverse(LinkQueue *Q){

    QElemType *p = Q->head->next;
    if (!p) {
        printf("-- Is empty.\n");
        return ERROR;
    }
    while (p) {
        printf("(%d,%d) ",p->ArriveTime,p->Duration);
        p=p->next;
    }
    printf("\n");
    return OK;
}

