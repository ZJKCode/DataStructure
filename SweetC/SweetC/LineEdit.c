//
//  LineEdit.c
//  SweetC
//
//  Created by apple on 2017/8/24.
//  Copyright © 2017年 apple. All rights reserved.
//

#include "LineEdit.h"
#include "Stack2.h"

void LineEdit() {
    // 行编辑程序
    SStack S;
    InitSStack(&S);
    char ch = getchar();
    while (ch != EOF ) { // EOF 为全文结束符
        while (ch != EOF && ch != '\n') {
            switch (ch) {
                case '#':PopS(&S, &ch);
                    
                    break;
                    
                case '@':ClearSStack(&S);
                    break;
                    
                default: PushS(&S, ch);
                    break;
            }
            ch = getchar();
        }
        SStackTraverse(S);
        ClearSStack(&S);
        if (ch != EOF) {
            ch= getchar();
        }
    }
    SStackTraverse(S);

    DestroySStack(&S);
}
