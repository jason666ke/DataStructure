//
// Created by 86153 on 2023/7/2.
//

#ifndef UNTITLED_INFIXEXP2POSTFIXEXP_H
#define UNTITLED_INFIXEXP2POSTFIXEXP_H

#define MaxSize 100

typedef struct {
    char data[MaxSize];
    int top;
} CharStack;

void initCharStack(CharStack *stack);
int stackEmpty(CharStack *stack);
int stackOverflowed(CharStack *stack);
void pushChar(CharStack *stack, char x);
void popChar(CharStack *stack, char *x);
int getPriority(char op);
void infix2Postfix(char *infixExp, char *postExp, int length);
int calPostfixExp(char *postfixExp, int length);

#endif //UNTITLED_INFIXEXP2POSTFIXEXP_H
