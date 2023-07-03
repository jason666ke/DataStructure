//
// Created by 86153 on 2023/7/3.
//
#include <stdio.h>

#define MaxSize 50
typedef struct {
    int data[MaxSize];
    int top;
}SqStack;

/**
 * 一个可以在o(1)时间复杂度内实现push，pop和min操作的栈
 */
typedef struct {
    SqStack stack_main;
    SqStack stack_min;
}StackWithMin;

// 初始化栈
void initStack(StackWithMin *stack) {
    stack->stack_main.top = -1;
    stack->stack_min.top = -1;
}

// 判断栈是否为空
int isEmpty(StackWithMin *stack) {
    return stack->stack_main.top == -1;
}

// 判断栈是否已满
int isFull(StackWithMin *stack) {
    return stack->stack_main.top == MaxSize - 1;
}

// 判断单独栈为空
int stackEmpty(SqStack *stack) {
    return stack->top == -1;
}

// 入栈
int push(StackWithMin *stack, int value) {
    if (isFull(stack)) {
        printf("Stack is full. Cannot pushChar element.\n");
        return 0;
    }
    // 主栈入栈
    stack->stack_main.top++;
    stack->stack_main.data[stack->stack_main.top] = value;
    // 辅助栈入栈
    if (stackEmpty(&stack->stack_min)) {
        stack->stack_min.top++;
        stack->stack_min.data[stack->stack_min.top] = value;
    }
    else {
        int min = stack->stack_min.data[stack->stack_min.top];
        stack->stack_min.top++;
        stack->stack_min.data[stack->stack_min.top] = value < min ? value : min;
    }
    return 1;
}

// 出栈
int pop(StackWithMin *stack, int *value) {
    if (isEmpty(stack)) {
        printf("Stack is empty. Cannot popChar element.\n");
        return 0;
    }
    *value = stack->stack_main.data[stack->stack_main.top];
    stack->stack_main.top--;
    stack->stack_min.top--;
    return 1;
}


