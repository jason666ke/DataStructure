//
// Created by 86153 on 2023/6/25.
//
typedef struct DLNode {
    int data;                // 数据域
    struct DLNode *prev;     // 指向前驱节点的指针
    struct DLNode *next;     // 指向后继节点的指针
} DLNode, *DLinklist;

DLinklist initDLinklist();
void insertDNode(DLinklist head, int position, int data);
void deleteNode(DLinklist head, int position);
void printDLinklist(DLinklist head);
void freeDLinklist(DLinklist head);
int isSymmetric(DLinklist L);
#ifndef UNTITLED_DLINKLIST_H
#define UNTITLED_DLINKLIST_H

#endif //UNTITLED_DLINKLIST_H
