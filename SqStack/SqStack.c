//
// Created by 86153 on 2023/6/28.
//

#include "SqStack.h"
#include <stdio.h>
#include "../LinkedList/Linkedlist.h"

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
        printf("Stack is full. Cannot pushChar element.\n");
        return 0;
    }
    stack->top++;
    stack->data[stack->top] = value;
    return 1;
}

// 出栈
int pop(SqStack *stack, int *value) {
    if (isEmpty(stack)) {
        printf("Stack is empty. Cannot popChar element.\n");
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

/**
 * 假定一个栈的操作序列被存在一个一维数组中，I代表入栈，O代表出栈
 * 栈的初态和终态需为空
 * 判断该操作序列是否合法，合法返回1，不合法返回0
 * @param operations
 * @param length
 * @return
 */
int isValidOperations(const char *operations, int length) {
    int elementInStack = 0;
    for (int i = 0; i < length; i++) {
        if (operations[i] == 'I') elementInStack++;
        else elementInStack--;
        if (elementInStack < 0) return 0;
    }
    if (elementInStack > 0) return 0;
    return 1;
}

/**
 * 判断一个链表是否为中心对称
 * @param head
 * @param length
 * @return
 */
int isCentroSymmetric(Linklist head, int length) {
    SqStack sqStack;
    initStack(&sqStack);
    LNode *p = head->next;
    for (int i = 0; i < length / 2; i++) {
        push(&sqStack, p->data);
    }
    if (length % 2 == 1) p = p->next;
    while (p) {
        int value;
        pop(&sqStack, &value);
        if (p->data == value) p = p->next;
        else return 0;
    }
    return 1;
}

/**
 * 用两个栈S1和S2模拟队列入队操作
 * @param s1
 * @param s2
 * @param x
 * @return
 */
int enQueue(SqStack *s1, SqStack *s2, int x) {
    int temp;
    // s1栈满且s2栈空，将所有数据从s1转移至s2
    if (isFull(s1) && isEmpty(s2)) {
        while (!isEmpty(s1)) {
            pop(s1, &temp);
            push(s2, temp);
        }
        return 0;
    }
    // s1满但s2不空，此时代表队满
    else if (isFull(s1) && !isEmpty(s2)) {
        return 0;
    }
    // 栈s1有空位，队列仍有容量，可装入x
    else {
        push(s1, x);
        return 1;
    }
}

/**
 * 用两个栈S1和S2模拟队列出队操作
 * @param s1
 * @param s2
 * @param x
 * @return
 */
int deQueue(SqStack *s1, SqStack *s2, int *x) {
    // S2不空，直接popS2中的元素
    if (!isEmpty(s2)) {
        pop(s2, x);
        return 1;
    }
    // S2为空
    else {
        // 若S1不空，将S1中的元素全部放到S2中
        int temp;
        while (!isEmpty(s1)) {
            pop(s1, &temp);
            push(s2, temp);
        }
        // 将S2的栈顶元素出队
        if (isEmpty(s2)) return 0;
        else{
            pop(s2, x);
            return 1;
        }
    }
}

/**
 * 用栈S1和S2模拟队列，判断队列是否为空
 * @param s1
 * @param s2
 * @return
 */
int queueEmpty(SqStack *s1, SqStack *s2) {
    // 两个栈全空时队列才为空
    return (isEmpty(s1) && isEmpty(s2));
}

/**
 * 用非递归的方式计算递归函数：
 * P_n(x) = {
 *      1. 1,   n = 0
 *      2. 2x,  n = 1
 *      3. 2 * x * P_{n-1}(x) - 2 * (n - 1) * p_{n - 2}(x)
 * @param n
 * @param x
 * @return
 */
double p(int n, double x) {
    struct stack{
        int no;
        double val;
    }st[100];
    int top = -1;
    // 初值
    double fv1 = 1, fv2 = 2 * x;
    // 将P(n)从2到n依次入栈
    for (int i = n; i >= 2; i--) {
        st[++top].no = i;
    }
    // 计算栈顶元素对应的多项式值
    // fv1表示前一个阶数的多项式值，即P_{n-2}, fv2表示当前阶数的多项式值，即P_{n-1}
    while (top >= 0) {
        st[top].val = 2 * x * fv2 - 2 * (st[top].no - 1) * fv1;
        fv1 = fv2;
        fv2 = st[top].val;
        top--;
    }
    if (n == 0) return fv1;
    return fv2;
}




