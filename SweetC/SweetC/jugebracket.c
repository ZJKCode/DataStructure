//
//  jugebracket.c
//  SweetC
//
//  Created by apple on 2017/8/24.
//  Copyright © 2017年 apple. All rights reserved.
//

#include "jugebracket.h"
#include "Stack2.h"
Status judge(const char *str);
// 期待的紧迫程度
void testStack2(){
    char st[20],*ps;
    ps = st;
    printf("input string:\n");
    scanf("%s",ps);
    int result = judge(ps);
    if (result == OK) {
        printf("括号匹配");
    }else {
        printf("不匹配");
    }
}

char getType(const char c) {
    char bracketSet[]="([{}])";
    int i ;
    for (i=0; i<6; i++) {
        if (bracketSet[i]==c) {
            break;
        }
    }
    
    if (i<3) {
        return 'l';
    } else if (i<6){
        return 'r';
    }else
        return 'n';
}

Status match(const char cL, const char cR) {
    if (cL == '(') {
        return cR == ')'?OK:ERROR;
    }else
        return cR==cL+2?OK:ERROR;
}

Status judge(const char *str) {
    int i = 0;
    SStack S;

    InitSStack(&S);
    char brackType;
    for (i = 0; str[i]!='\0'; i++) {
        brackType = getType(str[i]);
        if (brackType == 'l') {
            // 遇到做括号，推入到栈中
            PushS(&S, str[i]);
            
        }else if (brackType == 'r'){
            // 遇到右括号，与顶栈比较，若匹配释放顶层元素
            char ls;
            GetTopS(S, &ls);
            if (match(ls, str[i])) {
                PopS(&S, &ls);
            }else return ERROR;
        }
    }
    
    if (SStackEmpty(&S)) {
        return OK;
    }else

    return ERROR;
}
