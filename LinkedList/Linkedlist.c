//
// Created by 86153 on 2023/6/23.
//
#include <malloc.h>
#include <stdio.h>
#include "Linkedlist.h"

/**
 * 链表初始化
 * @return
 */
Linklist initLinklist() {
    // 创建头节点
    Linklist head = (Linklist) malloc(sizeof (LNode));
    if (head == NULL) {
        printf("内存分配失败\n");
        return NULL;
    }
    // 头节点的指针域置空，表明链表为空
    head->next = NULL;
    return head;
}

/**
 * 头插法创建新节点
 * @param head
 * @param value
 */
void insertNode(Linklist head, int value) {
    // 创建新节点
    LNode *newNode = (LNode *)malloc(sizeof(LNode));
    if (newNode == NULL) {
        printf("内存分配失败\n");
        return;
    }
    // 设置新节点的数据域
    newNode->data = value;
    // 将新节点插入链表的头部
    newNode->next = head->next;
    head->next = newNode;
}

/**
 * 头插法插入结点
 * @param head
 * @param p
 */
void headInsert(Linklist head, LNode *p) {
    p->next = head->next;
    head->next = p;
}

/**
 * 链表逆置
 * @param head
 */
void reverseLinklist(Linklist head) {
    printf("逆置链表\n");
    LNode *p = head->next;
    LNode *q;
    head->next = NULL;  // 将头节点的指针域置空，用于作为新链表的尾部
    while (p != NULL) {
        q = p;
        p = p->next;
        headInsert(head, q);
    }
}

/**
 * 打印链表元素
 * @param head
 */
void printLinklist(Linklist head) {
    Linklist currentNode = head->next;

    printf("链表元素: ");

    while (currentNode != NULL) {
        printf("%d ", currentNode->data);
        currentNode = currentNode->next;
    }

    printf("\n");
}

/**
 * 找到第一个大于p.data的结点的前序结点
 * @param head 头节点
 * @param p 待插入的结点
 */
LNode *findFirstLargePreNode(Linklist head, LNode *p) {
    LNode *q = head->next;
    LNode *pre = head;
    while (q != NULL) {
        if (q->data > p->data) {
            return pre;
        } else {
            pre = q;
            q = q->next;
        }
    }
    // 若找遍整个表都没有比其大的结点，则返回表尾结点
    return pre;
}

/**
 * 将链表进行升序排列
 * @param head
 */
void ascendingOrder(Linklist head) {
    printf("链表升序排列\n");
    LNode *p = head->next;
    head->next = NULL;  // 头节点的指针域置空，用于构造新链表
    while (p != NULL) {
        // 找到正确的插入位置
        LNode *preNode = findFirstLargePreNode(head, p);
        LNode *nextNode = p->next;
        p->next = preNode->next;
        preNode->next = p;
        p = nextNode;
    }
}

/**
 * 删除介于Min和max之间的所有结点
 * @param head
 * @param min
 * @param max
 */
void deleteFromA2B(Linklist head, int min, int max) {
    printf("删除介于 %d 到 %d 的所有结点\n", min, max);
    LNode *pre = head;
    LNode *p = pre->next;
    while (p != NULL) {
        if (p->data > min && p->data < max) {
            pre->next = p->next;
            free(p);
            p = pre->next;
        } else {
            pre = p;
            p = p->next;
        }
    }
}


