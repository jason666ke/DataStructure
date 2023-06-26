//
// Created by 86153 on 2023/6/23.
//
typedef struct LNode {
    int data;//代表数据域
    struct LNode *next;//代表指针域，指向直接后继元素
}LNode, *Linklist; //link为节点名，每个节点都是一个 link 结构体

Linklist initLinklist();
void insertNode(Linklist head, int value);
void printLinklist(Linklist head);
void reverseLinklist(Linklist head);
void headInsert(Linklist head, LNode *p);
void ascendingOrder(Linklist head);
void ascendingOrder2(Linklist head);
LNode *findFirstLargePreNode(Linklist head, LNode *p);
void deleteFromA2B(Linklist head, int min, int max);
void divideOddAndEven (Linklist origin, Linklist odd, Linklist even);
void deleteSameElement(Linklist head);
int isSubsequence(Linklist A, Linklist B);
int getLastKthNode(Linklist head, int k);
LNode *findCommonSuffixStart(Linklist A, Linklist B);

#ifndef UNTITLED_LINKEDLIST_H
#define UNTITLED_LINKEDLIST_H

#endif //UNTITLED_LINKEDLIST_H
