//
// Created by 86153 on 2023/6/25.
//
#include <malloc.h>
#include <stdio.h>
#include "DLinklist.h"


/**
 * 初始化循环双链表
 * @return 返回指向循环双链表的头节点指针
 */
DLinklist initDLinklist() {
    DLinklist head = (DLinklist)malloc(sizeof(DLNode));
    head->prev = head;
    head->next = head;
    return head;
}

/**
 * 在循环双链表的指定位置插入新节点
 * @param head 循环双链表的头节点指针
 * @param position 目标位置
 * @param data 插入的数据
 */
void insertDNode(DLinklist head, int position, int data) {
    // 创建新节点
    DLNode *newNode = (DLNode*)malloc(sizeof(DLNode));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;

    DLNode *p = head->next;
    int i = 1;
    while (p != head && i < position) {
        p = p->next;
        i++;
    }

    if (i != position) {
        printf("Invalid position.\n");
        free(newNode);
        return;
    }

    newNode->next = p->next;
    newNode->prev = p;
    p->next->prev = newNode;
    p->next = newNode;
}

/**
 * 删除循环双链表中指定位置的节点
 * @param head 循环双链表的头节点指针
 * @param position 目标位置
 */
void deleteNode(DLinklist head, int position) {
    DLNode *p = head->next;
    int i = 1;
    while (p != head && i < position) {
        p = p->next;
        i++;
    }

    if (i != position || p == head) {
        printf("Invalid position.\n");
        return;
    }

    p->prev->next = p->next;
    p->next->prev = p->prev;
    free(p);
}

/**
 * 打印循环双链表中的所有节点数据
 * @param head 循环双链表的头节点指针
 */
void printDLinklist(DLinklist head) {
    DLNode *p = head->next;
    while (p != head) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

/**
 * 释放循环双链表的所有节点内存
 * @param head 循环双链表的头节点指针
 */
void freeDLinklist(DLinklist head) {
    DLNode *p = head->next;
    DLNode *temp;
    while (p != head) {
        temp = p->next;
        free(p);
        p = temp;
    }
    free(head);
}


/**
 * 判断这个带头节点的循环双链表是否对称
 * @param L
 * @return
 */
int isSymmetric(DLinklist L) {
    DLNode *pre = L->prev;
    DLNode *next = L->next;
    while (pre != next && pre->next != next) {
        if (pre->data != next->data) return 0;
        pre = pre->prev;
        next = next->next;
    }
    return 1;
}



