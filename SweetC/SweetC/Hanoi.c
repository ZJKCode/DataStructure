//
//  Hanoi.c
//  SweetC
//
//  Created by apple on 2017/8/28.
//  Copyright © 2017年 apple. All rights reserved.
//

#include "Hanoi.h"

// 调用函数和被调用函数之间之间的链接以及信息交换需要通过栈来进行。
void hanoi (int n,char x, char y, char z) {

    if (n == 1) {
       // move(x,1, z);
      printf("圆盘编号 %d :从 %c 移动到 %c\n",n,x,z);
    }else {
        hanoi(n-1, x, z, y); // 将x上编号1到n-1移到y,z作为辅助塔
//        move(x, n, z) // 将x上编号为n的移到z
 
        printf("圆盘编号 %d:从 %c 移动到 %c\n",n,x,z);
        hanoi(n-1, y, x, z); // 将y上编号1到n-1移到x，z作为辅助塔
    }
}
