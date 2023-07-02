//
// Created by 86153 on 2023/7/2.
//
typedef struct LinkNode {
    int data;
    struct LinkNode *next;
} LinkNode;

typedef struct {
    LinkNode *front; // 队头指针
    LinkNode *rear;  // 队尾指针
} LinkQueue;

void ferryManage(int *passCars, LinkQueue truckQueue, LinkQueue busQueue);
void initLinkQueue(LinkQueue *queue);
int isLinkQueueEmpty(LinkQueue *queue);
void enLinkQueue(LinkQueue *queue, int value);
int deLinkQueue(LinkQueue *queue, int *value);
void clearLinkQueue(LinkQueue *queue);
void printLinkQueue(LinkQueue *queue);

#ifndef UNTITLED_SQQUEUE_H
#define UNTITLED_SQQUEUE_H

#endif //UNTITLED_SQQUEUE_H
