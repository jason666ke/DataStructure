//
// Created by 86153 on 2023/6/28.
//
#define MaxSize 50
typedef struct {
    int data[MaxSize];
    int top;
}SqStack;

void initStack(SqStack *stack);
int isEmpty(SqStack *stack);
int isFull(SqStack *stack);
int push(SqStack *stack, int value);
int pop(SqStack *stack, int *value);
int getTop(SqStack *stack, int *value);
int modifyTop(SqStack *stack, int newValue);
#ifndef UNTITLED_SQSTACK_H
#define UNTITLED_SQSTACK_H

#endif //UNTITLED_SQSTACK_H
