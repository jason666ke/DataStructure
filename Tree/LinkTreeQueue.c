//
// Created by 86153 on 2023/7/10.
//

#include "LinkTreeQueue.h"
#include <stdio.h>
#include <stdlib.h>

// 初始化链式树队列
void initLinkTreeQueue(LinkTreeQueue *queue) {
    queue->front = NULL;
    queue->rear = NULL;
}

// 判断链式树队列是否为空
int isLinkTreeQueueEmpty(LinkTreeQueue *queue) {
    return queue->front == NULL;
}

// 入队操作
void enLinkTreeQueue(LinkTreeQueue *queue, BiTNode *tNode) {
    LinkTreeNode *newNode = (LinkTreeNode *)malloc(sizeof(LinkTreeNode));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    newNode->tNode = tNode;
    newNode->next = NULL;

    if (isLinkTreeQueueEmpty(queue)) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

// 出队操作
int deLinkTreeQueue(LinkTreeQueue *queue, BiTNode **tNode) {
    if (isLinkTreeQueueEmpty(queue)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return 0;
    }

    LinkTreeNode *frontNode = queue->front;
    *tNode = frontNode->tNode;

    queue->front = frontNode->next;
    if (queue->front == NULL) {
        queue->rear = NULL;
    }

    free(frontNode);
    return 1;
}

// 清空链式树队列
void clearLinkTreeQueue(LinkTreeQueue *queue) {
    LinkTreeNode *current = queue->front;
    while (current != NULL) {
        LinkTreeNode *temp = current;
        current = current->next;
        free(temp);
    }
    queue->front = NULL;
    queue->rear = NULL;
}

// 打印链式树队列
void printLinkTreeQueue(LinkTreeQueue *queue) {
    if (isLinkTreeQueueEmpty(queue)) {
        printf("Queue is empty.\n");
        return;
    }

    LinkTreeNode *current = queue->front;
    printf("Front -> ");
    while (current != NULL) {
        printf("%d ", current->tNode->data);
        current = current->next;
    }
    printf("<- Rear\n");
}
