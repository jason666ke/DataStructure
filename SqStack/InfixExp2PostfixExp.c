//
// Created by 86153 on 2023/7/2.
//

#include "InfixExp2PostfixExp.h"
#include "SqStack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void initCharStack(CharStack *stack) {
    stack->top = -1;
}

int stackEmpty(CharStack *stack) {
    return stack->top == -1;
}

int stackOverflowed(CharStack *stack) {
    return stack->top == MaxSize - 1;
}

void pushChar(CharStack *stack, char x) {
    if (stackOverflowed(stack)) {
        printf("Stack is full.\n");
        return;
    }
    stack->data[++stack->top] = x;
}

void popChar(CharStack *stack, char *x) {
    if (stackEmpty(stack)) {
        printf("Stack is empty.\n");
        return;
    }
    *x = stack->data[stack->top--];
}

// 获取栈顶元素
int getTopChar(CharStack *stack, char *value) {
    if (stackEmpty(stack)) {
        printf("Stack is empty.\n");
        return 0;
    }
    *value = stack->data[stack->top];
    return 1;
}

/**
 * 判断运算符优先级
 * @param op
 * @return
 */
int getPriority(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '(':
        case ')':
            return 0;
        default:
            return -1;
    }
}


/**
 * 用栈实现中缀表达式转后缀表达式
 * 从左到右扫描各个元素直到末尾
 * 1. 遇到操作数，直接加入后缀表达式
 * 2. 遇到界限符：
 *      1. 遇到 "(" 直接入栈
 *      2. 遇到 ")" 依次弹出站内运算符并加入后缀表达式，直到弹出 "(" 为止
 * 3. 遇到运算符：
 *      1. 依次弹出栈中优先级 >= 当前运算符的所有运算符，并加入后缀表达式
 *      2. 若遇到 "(" 或栈空则停止
 *      3. 把当前运算符入栈
 * 4. 处理完所有字符后，将剩余运算符依次弹出并加入后缀表达式
 * @param infixExp 输入的中缀表达式
 * @param postExp 输入的后缀表达式
 * @param length 中缀表达式长度
 */
void infix2Postfix(char *infixExp, char *postExp, int length) {
    // 初始化栈
    CharStack stack;
    initCharStack(&stack);
    // 后缀表达式指针
    int postIndex = 0;

    for (int i = 0; i < length; i++) {
        char ch = infixExp[i];
        if (ch >= '0' && ch <= '9') {
            // 遇到操作数直接加入后缀表达式
            postExp[postIndex++] = ch;
        } else if (ch == '(') {
            // 遇见左括号直接入栈
            pushChar(&stack, ch);
        } else if (ch == ')') {
            // 遇到 ")" 依次弹出站内运算符并加入后缀表达式，直到弹出 "(" 为止
            char topOp;
            while (!stackEmpty(&stack)) {
                popChar(&stack, &topOp);
                if (topOp == '(') break;
                else postExp[postIndex++] = topOp;
            }
        } else {
            // 遇到运算符
            int chPriority = getPriority(ch);
            char topOp;
            while (!stackEmpty(&stack)) {
                getTopChar(&stack, &topOp);
                int topOpPriority = getPriority(topOp);
                if (topOpPriority >= chPriority) {
                    popChar(&stack, &topOp);
                    postExp[postIndex++] = topOp;
                } else{
                    break;
                }
            }
            // 将当前运算符入栈
            pushChar(&stack, ch);
        }
    }
    // 处理完所有字符，依次将剩余运算符加入后缀表达式
    char topOp;
    while (!stackEmpty(&stack)) {
        popChar(&stack, &topOp);
        postExp[postIndex++] = topOp;
    }

    postExp[postIndex] = '\0';  // 加入终止符
}


/**
 * 用栈实现后缀表达式的计算
 * 1. 从左往右扫描元素直到处理完所有元素
 * 2. 扫描到操作数则压栈
 * 3. 扫描运算符则弹出两个栈顶元素，执行对应运算，运算结果压回栈顶
 * @param postfixExp 后缀表达式
 * @param length 表达式长度
 * @return
 */
int calPostfixExp(char *postfixExp, int length) {
    // 初始化栈
    SqStack stack;
    initStack(&stack);

    for (int i = 0; i < length; i++) {
        char ch = postfixExp[i];
        if (isdigit(ch)) {
            // 遇到操作数直接压栈
            push(&stack, ch - '0');
        } else {
            // 遇到运算符
            int leftOp, rightOp;
            pop(&stack, &rightOp);
            pop(&stack, &leftOp);
            int result;
            switch (ch) {
                case '+' :
                    result = leftOp  + rightOp;
                    break;
                case '-':
                    result = leftOp - rightOp;
                    break;
                case '*':
                    result = leftOp * rightOp;
                    break;
                case '/':
                    result = leftOp / rightOp;
                    break;
                default:
                    printf("Invalid operator: %c\n", ch);
                    return 0;
            }
            push(&stack, result);
        }
    }
    int result;
    pop(&stack, &result);
    return result;
}