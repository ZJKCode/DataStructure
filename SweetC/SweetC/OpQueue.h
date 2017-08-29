//
//  OpQueue.h
//  SweetC
//
//  Created by apple on 2017/8/29.
//  Copyright © 2017年 apple. All rights reserved.
//

#ifndef OpQueue_h
#define OpQueue_h

#include <stdio.h>
#include "Queue.h"

void PrintMenu();
//显示菜单提示
char getOption();
//获取用户输入
void NewNodeEnQueue(LinkQueue *Q);
//根据用户输入，将新元素入队
void DeleteNode(LinkQueue *Q);
//元素出队，并显示剩余队中元素
void ShowHeadNode(LinkQueue *Q);
//显示队首元素
void ShowBye();
//显示结束
void ShowLength(LinkQueue *Q);

void dealtMain();
#endif /* OpQueue_h */
