//
// Created by 86153 on 2023/7/10.
//

#include "TreeStack.h"
#include <stddef.h>
#include <stdio.h>
#include "BiTNode.h"


// 初始化树栈
void initTreeStack(TreeStack *stack) {
    stack->top = -1;
}

// 判断树栈是否为空
int isTreeStackEmpty(TreeStack *stack) {
    return stack->top == -1;
}

// 判断树栈是否已满
int isTreeStackFull(TreeStack *stack) {
    return stack->top == MaxSize - 1;
}

// 入栈
int pushTreeStack(TreeStack *stack, BiTNode *value) {
    if (isTreeStackFull(stack)) {
        printf("TreeStack is full. Cannot push element.\n");
        return 0;
    }
    stack->top++;
    stack->data[stack->top] = value;
    return 1;
}

// 出栈
int popTreeStack(TreeStack *stack, BiTNode **value) {
    if (isTreeStackEmpty(stack)) {
        printf("TreeStack is empty. Cannot pop element.\n");
        return 0;
    }
    *value = stack->data[stack->top];
    stack->top--;
    return 1;
}

// 获取栈顶元素
int getTopTreeStack(TreeStack *stack, BiTNode **value) {
    if (isTreeStackEmpty(stack)) {
        printf("TreeStack is empty. Cannot get top element.\n");
        return 0;
    }
    *value = stack->data[stack->top];
    return 1;
}

// 修改栈顶元素
int modifyTopTreeStack(TreeStack *stack, BiTNode *newValue) {
    if (isTreeStackEmpty(stack)) {
        printf("TreeStack is empty. Cannot modify top element.\n");
        return 0;
    }
    stack->data[stack->top] = newValue;
    return 1;
}
