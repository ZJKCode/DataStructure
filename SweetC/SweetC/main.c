//
//  main.c
//  SweetC
//
//  Created by apple on 2017/5/23.
//  Copyright © 2017年 apple. All rights reserved.
//

#include <stdio.h>
#include <stdatomic.h>
#include "Stack.h"
#include "jugebracket.h"
#include "LineEdit.h"
#include "Evaluate.h"
#include "Hanoi.h"

// 基本操作的算法描述不部分


int dealFun2(char s, int fun){
    
    return 100;
}

void swip(int a, int b) {
    int x;
    x = a;
    a = b;
    b = x;
    
    printf("a = %d, b = %d\n",a,b);
    
    
}
void swip2(int *a, int *b) { // 参数需要是指针参数
   int x = *a;
    *a = *b;
    *b = x;
}

struct UserInfo {

    int age;
    char *name;
    char *birth;
    int height;
};

void test_char_point() {
    char st[20],*ps;
    int i;
    printf("intput a string:\n");
    ps = st;
    scanf("%s",ps);
    for (i = 0; ps[i]!='\0'; i++) {
        if (ps[i] == 'k') {
            printf("there is 'k' in the string \n");
            break;
        }
        
    }
    
    if (ps[i] == '\0') {
        printf("there is no 'k' in the string \n");
    }
    
    

}
void test_two_dimensional_array() {

    static int a[3][4] = {0,1,2,3,4,5,6,7,8,9,10,11};
    char *PF;
    PF = "%d, %d, %d,%d,%d \n";
    
    printf(PF,a,*a,a[0],&a[0],&a[0][0]);
    printf(PF,a+1,*(a+1),a[1],&a[1],&a[1][0]);
    printf(PF,a+2,*(a+2),a[2],&a[2],&a[2][0]);
    
}

/**
 栈的应用举例 将10进制数转为8进制
 */
void conversion () {
    int N;
    SqStack S;
    InitStack(&S);
    scanf("%d",&N);
    while (N) {
        Push(&S, N%8);
        N = N/8;
    }
    int M;
    
    while (!StackEmpty(&S)) {
        Pop(&S, &M);
        printf("%d",M);
    }
}

void conversion2(){
    int N;
    SqStack S;
    InitStack(&S);
    scanf("%d",&N);
    while (N) {
        Push(&S, N%2);
        N = N/2;
    }
    int M;
    
    while (!StackEmpty(&S)) {
        Pop(&S, &M);
        printf("%d",M);
    }
}

struct UserInfo *userInfo;

int main(int argc, const char * argv[]) {

    int a = 10;
    int *p = &a;
    
    printf("*p : %d \n",*p); // 10
    printf("p: %p \n",&a); // 0x7fff5fbff73c
    if (p == &a) {
        // 成立
        printf("p == &a = %p \n",&a);
    }
    
    if (*p == a) {
        // 成立
        printf("*p == a = %d\n",*p);
    }
    
    // *p 的值是a的值 10
    // p 的值是地址值 0x7fff5fbff73c
    // p 是指针地址 是指向int的指针地址

    // 那么一般的使用流程是怎样的？
    
    // 对数据做过运算之后，地址的值会发生变化吗
    *p = *p + 10;
    
    printf("*p : %d \n",*p); // 20
    printf("p: %p \n",p); // 0x7fff5fbff73c
    printf("a :%d \n",a); //20
    printf("&a:%p\n",&a); // 0x7fff5fbff73c
    // 结论是：变量发生变化，指针的变量不会发生变化
    
    // 如果对&a进行操作了呢
    int *ip = &a + 1;
    printf("ip : %p \n",ip); // 0x7fff5fbff740
    printf("*ip: %d\n",*ip); // 1606416240  //相差甚远
    printf("a: %d\n",a); // 20
    printf("&a: %p\n",&a); //0x7fff5fbff73c
    // 结论是： 地址发生了变化
    int *p1;
    p1 = &a;
    printf("*p1 : %d \n",*p1);
    printf("p1: %p \n",p1);
    int *p2;
    p2 = p1;
    printf("*p2 : %d \n",*p2);
    printf("p2: %p \n",p2);
    
    int b[10];
    b[1]= 1;
    b[2]= 2;
    
    int *bp;
    bp = &b[0];
    
    printf("bp: %p \n",bp);
    printf("*bp:%d\n",*bp);// 0x7fff5fbff720
    printf("*(bp+1): %d \n",*(bp+1)); //1
    printf("b[1]: %p \n",&(*(bp+1))); //0x7fff5fbff724
    printf("bp[1]: %d \n",bp[1]); //1
    printf("@bp[1]:%p \n",&bp[1]); // 0x7fff5fbff724
    
    int m = 30;
    int n = 20;
    
    swip(m, n);
    // 交换两个数的值
    swip2(&m, &n);
    printf("m = %d, n = %d \n",m,n);
    
    // 指针变量的值既然是一个地址，那么这个地址不仅仅可以是变量的地址，也可以是其他数据结构的地址

    char name = 'C';
    char birth = 'B';
    struct UserInfo user;
    user.age = 100;
    user.name = &name;
    user.birth = &birth;
    user.height = 170;
    
    struct UserInfo *userInfo = &user;
    printf("userInfo_IP : %p\n",userInfo);
    printf("user.name %c\n",*user.name);
    user.name = &birth;
    printf("user.name %c\n",*user.name);
    
    char *c = "C language";
    printf("c %p \n",c);
    printf("*c %c \n",*c);
    
    static int A[3][4] = {0,1,2,3,4,5,6,7,8,9,10,11};
    int (*pA)[4];
    int i,j;
    pA = A;
    for (i=0; i<3; i++) {
        for (j=0; j<4; j++) {
            printf("%2d\n",*(*(pA+i)+j));
        }
    }
    
    char *ps ;
    ps = "C Language";
    
    printf("ps : %s\n",ps); // ps : C Language
    printf("ps : %c\n",*ps); // ps : C
    printf("ps : %p\n",ps); // 0x100000f8a
    ps = "this is a book";
    int n1 = 10;
    ps = ps+n1;
    printf("ps : %s\n",ps); // ps : book
    printf("ps : %c\n",*ps); // ps : b
    printf("ps : %p\n",ps); // 0x100000faa

    
//    test_char_point();
//    test_two_dimensional_array();
    
//    conversion();
    printf("\n");

//    conversion2();
    
//    printf("\n");
    
//    testStack2();
    
//    LineEdit();
    printf("\n");
//    testEvl();
    char ch1 = 'A';
    char ch2 = 'B';
    char ch3 = 'C';
    int num;
    printf("请输入圆盘的个数:");
    scanf("%d",&num);
    hanoi(num, ch1, ch2, ch3);
    return 0;
}


int max (int x, int y){

    int z;
    if (x>y) {
        z=x;
    }else {
        z = y;
    };
    return (z);
}






