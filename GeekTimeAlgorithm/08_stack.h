//
//  08_stack.h
//  GeekTimeAlgorithm
//
//  Created by study_sun on 2018/11/11.
//  Copyright © 2018 study_sun. All rights reserved.
//

#ifndef _8_stack_h
#define _8_stack_h

// c语言写容器或者泛型太蛋疼了，就那int放数据吧，反正char也可以放的下
typedef struct SMStack {
    size_t capacity; // 总容量，也是data的长度，暂时不支持扩容吧
    int *data;
    size_t count;//实际装载数目
}SMStack;

SMStack* createStack(size_t count);
void freeStack(SMStack *stack);
bool isEmpty(SMStack *stack);
bool isFull(SMStack *stack);
void push(SMStack *stack, int value);
int pop(SMStack *stack);

// 仅支持十以内整数加减乘除，可以有空格,懒得交验表达式是否合法了哦
int calc(char *foo);

#endif /* _8_stack_h */
