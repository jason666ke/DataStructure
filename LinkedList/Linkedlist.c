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


/**
 * 判断B是否为A的子序列
 * @param A
 * @param B
 * @return
 */
int isSubsequence(Linklist A, Linklist B) {
    LNode *curNode = A->next;
    LNode *pA, *pB;
    while (curNode) {
        pA = curNode;
        pB = B->next;
        while (pA && pB && pA->data == pB->data) {
            pA = pA->next;
            pB = pB->next;
        }
        if (pB == NULL) return 1;
        else curNode = curNode->next;
    }
    return 0;
}

/**
 * 将循环单链表L2链接到循环单链表L1之后
 * @param L1 循环单链表L1
 * @param L2 循环单链表L2
 */
void connectTwoLinklist(Linklist L1, Linklist L2) {
    LNode *p1 = L1->next;
    LNode *p2 = L2->next;
    while (p1->next != L1) p1 = p1->next;
    p1->next = p2;
    while (p2->next != L2) p2 = p2->next;
    p2->next = L1;
    free(L2);
}

/**
 * 反复找出单链表中结点值最小的结点并输出
 * 然后删除该结点，直到单链表为空
 * 释放头节点
 * @param L 带头节点的循环单链表
 */
void deletePrintMin(Linklist L) {
    LNode *preMin = L;
    LNode *min = preMin->next;
    LNode *pre = L;
    LNode *p = pre->next;
    while (L->next != L) {
        // 更新最小值结点
        preMin = L;
        min = preMin->next;
        // 更新指针
        pre = L;
        p = pre->next;
        // 遍历整个链表，找到最小值所在结点
        while (p->next != L) {
            if (p->data < min->data) {
                preMin = pre;
                min = p;
            }
            pre = p;
            p = p->next;
        }
        // 打印输出最小值
        printf("最小值为 %d", min->data);
        // 删除最小值结点
        preMin->next = min->next;
        free(min);
    }
    // 整个链表为空时，释放头节点
    free(L);
}

/**
 * 单链表环的检测算法
 * @param head 单链表
 * @return 环的入口点
 */
LNode *findLoopStart(Linklist head) {
    LNode *fast = head, *slow = head;
    // 判断是否存在环
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) break;
    }
    if (fast == NULL || fast->next == NULL) return NULL;
    LNode *p1 = head, *p2 = slow;
    while (p1 != p2) {
        p1 = p1->next;
        p2 = p2->next;
    }
    // 返回环的入口点
    return p1;
}

/**
 * 查找链表中倒数第k个位置的结点并输出其data
 * @param head 链表头指针
 * @param k 序数
 * @return
 */
int getLastKthNode(Linklist head, int k) {
    printf("查找倒数第%d个结点的值", k);
    LNode *p = head;
    int length = 0;
    while (p->next) {
        p = p->next;
        length++;
    }
    if (k > length) return 0;
    else {
        int step = length - k + 1;
        p = head;
        while (step) {
            p = p->next;
            step--;
        }
        printf("%d\n", p->data);
        return 1;
    }
}

/**
 * 假定两个链表的公共后缀共享公共空间
 * 该算法用以找到公共后缀的起始位置
 * @param A
 * @param B
 * @return
 */
LNode *findCommonSuffixStart(Linklist A, Linklist B) {
    int len1 = 0, len2 = 0;
    LNode *p1 = A->next, *p2 = B->next;
    // 计算链表A和链表B的长度
    while (p1) {
        len1++;
        p1 = p1->next;
    }
    while (p2) {
        len2++;
        p2 = p2->next;
    }
    // 将链表A和链表B的内容分别复制到数组中
    int A_copy[len1], B_copy[len2];
    p1 = A->next;
    p2 = B->next;
    for (int i = 0; i < len1; i++){
        A_copy[i] = p1->data;
        p1 = p1->next;
    }
    for (int i = 0; i < len2; i++) {
        B_copy[i] = p2->data;
        p2 = p2->next;
    }
    // 计算最长后缀长度
    int maxSuffixLength = len1 < len2 ? len1 : len2;
    int suffixLength = 0;
    for (int i = 0; i < maxSuffixLength; i++) {
        if (A_copy[len1 - 1 - i] == B_copy[len2 - 1 - i]) suffixLength++;
        else break;
    }
    // 找到公共首结点
    p1 = A->next;
    int preSuffixLength = len1 - suffixLength;
    while (preSuffixLength--) p1 = p1->next;
    return p1;
}