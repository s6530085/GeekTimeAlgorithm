//
//  08_stack.c
//  GeekTimeAlgorithm
//
//  Created by study_sun on 2018/11/11.
//  Copyright © 2018 study_sun. All rights reserved.
//

#include "08_stack.h"


SMStack* createStack(size_t count)
{
    assert(count > 0);
    SMStack *stack = (SMStack *)malloc(sizeof(SMStack));
    assert(stack!=NULL);
    stack->capacity = count;
    stack->data = (int *)malloc(count * sizeof(int));
    assert(stack->data!=NULL);
    stack->count = 0;
    return stack;
}


void freeStack(SMStack *stack)
{
    assert(stack!=NULL);
    free(stack->data);
    free(stack);
}


bool isEmpty(SMStack *stack)
{
    assert(stack!=NULL);
    return stack->count==0;
}

bool isFull(SMStack *stack)
{
    assert(stack!=NULL);
    return stack->capacity==stack->count;
}

void push(SMStack *stack, int value)
{
    assert(stack!=NULL);
    if (!isFull(stack)) {
        stack->data[stack->count++] = value;
    }
}


int pop(SMStack *stack)
{
    assert(stack!=NULL);
    if (!isEmpty(stack)) {
        return stack->data[--stack->count];
    }
    abort();
    return 0;
}


int calc(char* format)
{
    assert(format!=NULL);
    SMStack *nStack = createStack(10);
    SMStack *opStack = createStack(10);
    assert(nStack!=NULL && opStack!=NULL);
    
    size_t l = strlen(format);
    for (size_t i = 0; i < l; i++) {
        char c = format[i];
        if (c == ' ') {
            continue;
        }
        else if (c >= '0' && c <= '9') {
            push(nStack, c-'0');
            // 最后一个数字的时候要清栈哦
            if (i == l - 1) {
                // 此时最多两次操作
                while (!isEmpty(opStack)) {
                    int op = pop(opStack);
                    int od2 = pop(nStack);
                    int od1 = pop(nStack);
                    if (op == '+') {
                        push(nStack, od1 + od2);
                    }
                    else if (op == '-') {
                        push(nStack, od1 - od2);
                    }
                    else if (op == '*') {
                        push(nStack, od1 * od2);
                    }
                    else {
                        push(nStack, od1 / od2);
                    }
                }
            }
        }
        else if (c == '*' || c == '/' || c == '+' || c == '-') {
            if (isEmpty(opStack)) {
                push(opStack, c);
            }
            else {
                int op = pop(opStack);
                // 前一个操作符如果是*/，则直接操作
                if (op == '*' || op == '/') {
                    int od2 = pop(nStack);
                    int od1 = pop(nStack);
                    if (op == '*') {
                        push(nStack, od1 * od2);
                    }
                    else {
                        push(nStack, od1 / od2);
                    }
                    push(opStack, c);
                }
                else {
                    // 前一个操作数是+-，那要看现在的，如果现在的也是+-，则先运算后压栈，如果现在的是*/则直接压栈
                    if (c == '+' || c == '-') {
                        int od2 = pop(nStack);
                        int od1 = pop(nStack);
                        if (op == '+') {
                            push(nStack, od1 + od2);
                        }
                        else {
                            push(nStack, od1 - od2);
                        }
                    }
                    else {
                        push(opStack, op);
                    }
                    push(opStack, c);
                }
            }
        }
        else {
            printf("unhander char");
            abort();
        }
    }
    // 其实可能表达式不对，栈里还有元素，这里不考虑了
    int result = pop(nStack);
    freeStack(nStack);
    freeStack(opStack);
    return result;
}
