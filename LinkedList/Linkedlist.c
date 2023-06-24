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
 * 计算链表长度
 * @param head
 * @return
 */
int getLinklistLength(Linklist head) {
    int length = 0;
    LNode *currentNode = head->next;

    while (currentNode != NULL) {
        length++;
        currentNode = currentNode->next;
    }

    return length;
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
 * 用一个函数实现的链表原地升序
 * @param head
 */
void ascendingOrder2(Linklist head) {
    printf("升序排列链表\n");
    LNode * pre;
    LNode * p;
    LNode * curNode = head->next;
    head->next = NULL;
    while (curNode != NULL) {
        pre = head;
        p = pre->next;
        LNode * nextNode = curNode->next;
        curNode->next = NULL;
        // 找到第一个data大于curNode的结点
        // 用p记录该位置，pre和p之间就是当前结点需要插入的位置
        while (p != NULL && p->data <= curNode->data) {
            pre = p;
            p = p->next;
        }
        curNode->next = p;
        pre->next = curNode;
        curNode = nextNode;
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


/**
 * 将原链表划分成奇链表和偶链表
 * @param origin
 * @param odd
 * @param even
 */
void divideOddAndEven (Linklist origin, Linklist odd, Linklist even) {
    printf("将原链表划分成奇链表和偶链表\n");
    LNode *p = origin->next;
    LNode *tailOdd = odd;
    LNode *tailEven = even;
    int oddFlag = 1;
    while (p != NULL) {
        LNode *nextNode = p->next;
        p->next = NULL;
        if (oddFlag) {
            tailOdd->next = p;
            tailOdd = tailOdd->next;
            oddFlag = 0;
        } else {
            tailEven->next = p;
            tailEven = tailEven->next;
            oddFlag = 1;
        }
        p = nextNode;
    }
    tailOdd->next = NULL;
    tailEven->next = NULL;
    printf("奇链表为: ");
    printLinklist(odd);
    printf("偶链表为: ");
    printLinklist(even);
}


/**
 * 删除链表中的重复元素
 * @param head
 */
void deleteSameElement(Linklist head) {
    printf("删除链表中的重复元素\n");
    LNode *p = head->next;
    while (p != NULL) {
        if (p->next == NULL) break;
        else {
            LNode *nextNode = p->next;
            if (nextNode->data == p->data) {
                p->next = nextNode->next;
                free(nextNode);
            } else {
                p = p->next;
            }
        }
    }
}

