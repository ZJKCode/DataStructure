//
//  OpQueue.c
//  SweetC
//
//  Created by apple on 2017/8/29.
//  Copyright © 2017年 apple. All rights reserved.
//

#include "OpQueue.h"

void dealtMain(){
    char option;
    LinkQueue queue;
    InitQueue(&queue);
    PrintMenu();
    option=getOption();
    while(option!='Q'){
        switch(option){
            case 'E'://元素入队
                NewNodeEnQueue(&queue);
                break;
            case 'D'://元素出队
                DeleteNode(&queue);
                break;
            case 'S'://遍历整个队列
                QueueTraverse2(queue);
                break;
            case 'H':
                ShowHeadNode(&queue);
                break;
            case 'L':
                ShowLength(&queue);
                break;
            case 'A':
                printf("Invalid input.\n");
            default:
                break;
        }
        option=getOption();
    }
    ShowBye();
}
//-------------交互处理-----------------//
void PrintMenu(){
    //显示菜单提示
    printf("------Welcome------\n");
    printf(" Please input your choice:\n");
    printf(" E: New element enqueue.\n");
    printf(" D: Delete an element from the Queue.\n");
    printf(" S: Show all elements in the Queue.\n");
    printf(" H: Get the first element in the Queue.\n");
    printf(" L: Get the length of the Queue.\n");
    printf(" Q: Quit.\n");
    printf(" ohters: do nothing.\n");
}

void ShowBye(){
    //显示结束
    printf("------Bye bye------\n");
}

char getOption(){
    //获取用户输入
    char *input,*op;
    input=(char *)malloc(sizeof(char)*256);
    printf(">>");
    gets(input);
    op=input;
    if(*(op+1)!='\0'){
        return 'A';
    }
    else
        return toupper(*op);
}

void NewNodeEnQueue(LinkQueue *Q){
    //根据用户输入，将新元素入队
    char *p;
    p=(char *)malloc(sizeof(char)*256);
    printf("Please input a char(only one):");
    gets(p);
    if((*p>='a')&&(*p<='z')||(*p>='A')&&(*p<='Z')){
        EnQueue(Q,*p);
        printf("New element \'%c\' enqueu.\n",*p);
    }else
        printf("Sorry, your input is not accepted.\n");
}

void DeleteNode(LinkQueue *Q){
    //元素出队，并显示剩余队中元素
    QElemType e;
    if(TRUE==QueueEmpty(*Q)){
        printf("The Queue is empty.\n");
        return;
    }
    DeQueue(Q,&e);
    printf("%c delete from the Queue,",e);
    if(QueueEmpty(*Q)==TRUE)
        printf("The Queue is empty now.\n");
    else
        //printf("Current Queue is:");
        QueueTraverse2(*Q);
    
}

void ShowHeadNode(LinkQueue *Q){
    //显示队首元素
    QElemType e;
    if(QueueEmpty(*Q)){
        printf("The Queue is empty.\n");
        return;
    }else{
        GetHead(*Q,&e);
        printf("The first element of the Queue is:%c\n",e);
    }
}

void ShowLength(LinkQueue *Q){
    //显示队列元素个数
    if(QueueEmpty(*Q)==TRUE){
        printf("The count of element is 0.\n");
    }else{
        printf("The count of element is：%d\n",QueueLength(*Q));
    }
}
