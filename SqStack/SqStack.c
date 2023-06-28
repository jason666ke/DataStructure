//
// Created by 86153 on 2023/6/28.
//

#include "SqStack.h"
#include <stdio.h>

// 初始化栈
void initStack(SqStack *stack) {
    stack->top = -1;
}

// 判断栈是否为空
int isEmpty(SqStack *stack) {
    return stack->top == -1;
}

// 判断栈是否已满
int isFull(SqStack *stack) {
    return stack->top == MaxSize - 1;
}

// 入栈
int push(SqStack *stack, int value) {
    if (isFull(stack)) {
        printf("Stack is full. Cannot push element.\n");
        return 0;
    }
    stack->top++;
    stack->data[stack->top] = value;
    return 1;
}

// 出栈
int pop(SqStack *stack, int *value) {
    if (isEmpty(stack)) {
        printf("Stack is empty. Cannot pop element.\n");
        return 0;
    }
    *value = stack->data[stack->top];
    stack->top--;
    return 1;
}

// 获取栈顶元素
int getTop(SqStack *stack, int *value) {
    if (isEmpty(stack)) {
        printf("Stack is empty.\n");
        return 0;
    }
    *value = stack->data[stack->top];
    return 1;
}

// 修改栈顶元素
int modifyTop(SqStack *stack, int newValue) {
    if (isEmpty(stack)) {
        printf("Stack is empty. Cannot modify element.\n");
        return 0;
    }
    stack->data[stack->top] = newValue;
    return 1;
}
