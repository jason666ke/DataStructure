//
// Created by 86153 on 2023/7/10.
//
#include "BiTNode.h"
typedef struct LinkTreeNode {
    BiTNode *tNode;
    struct LinkTreeNode *next;
} LinkTreeNode;

typedef struct {
    LinkTreeNode *front; // 队头指针
    LinkTreeNode *rear;  // 队尾指针
} LinkTreeQueue;

void initLinkTreeQueue(LinkTreeQueue *queue);
int isLinkTreeQueueEmpty(LinkTreeQueue *queue);
void enLinkTreeQueue(LinkTreeQueue *queue, BiTNode *tNode);
int deLinkTreeQueue(LinkTreeQueue *queue, BiTNode **tNode);
void clearLinkTreeQueue(LinkTreeQueue *queue);
void printLinkTreeQueue(LinkTreeQueue *queue);

#ifndef UNTITLED_LINKTREEQUEUE_H
#define UNTITLED_LINKTREEQUEUE_H

#endif //UNTITLED_LINKTREEQUEUE_H
