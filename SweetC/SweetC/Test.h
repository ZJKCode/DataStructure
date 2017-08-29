//
//  Test.h
//  SweetC
//
//  Created by apple on 2017/5/23.
//  Copyright © 2017年 apple. All rights reserved.
//

#ifndef Test_h
#define Test_h

#include <stdio.h>
#include <CoreFoundation/CFBase.h>
#include <CoreFoundation/CFArray.h>
#include <CoreFoundation/CFDate.h>
#include <CoreFoundation/CFString.h>

typedef struct {

    CFIndex version;
    void * info;
    const void *(*retain)(const void *info);
    void (*release)(const void *info);
    
    
}SweetCReact;

extern int sort(int *array);

void SWArrayAppendArray(CFMutableArrayRef theArray, CFArrayRef otherArray, CFRange otherRange);

static void eniont();
#endif /* Test_h */
