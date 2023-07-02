//
// Created by 86153 on 2023/7/2.
//

#include "SqQueue.h"

#include <stdio.h>
#include <stdlib.h>



// 初始化链队列
void initLinkQueue(LinkQueue *queue) {
    queue->front = queue->rear = (LinkNode *)malloc(sizeof(LinkNode));
    queue->front->next = NULL;
}

// 判断链队列是否为空
int isLinkQueueEmpty(LinkQueue *queue) {
    return queue->front == queue->rear;
}

// 入队
void enLinkQueue(LinkQueue *queue, int value) {
    LinkNode *newNode = (LinkNode *)malloc(sizeof(LinkNode));
    newNode->data = value;
    newNode->next = NULL;

    queue->rear->next = newNode;
    queue->rear = newNode;
}

// 出队
int deLinkQueue(LinkQueue *queue, int *value) {
    if (isLinkQueueEmpty(queue)) {
        printf("Error: Queue is empty.\n");
        return 0;
    }

    LinkNode *node = queue->front->next;
    *value = node->data;
    queue->front->next = node->next;

    // 如果出队后队列为空，需要更新队尾指针
    if (node->next == NULL) {
        queue->rear = queue->front;
    }

    free(node);
    return 1;
}

// 清空链队列
void clearLinkQueue(LinkQueue *queue) {
    while (!isLinkQueueEmpty(queue)) {
        int value;
        deLinkQueue(queue, &value);
    }
}

// 打印链队列
void printLinkQueue(LinkQueue *queue) {
    if (isLinkQueueEmpty(queue)) {
        printf("Queue is empty.\n");
        return;
    }

    LinkNode *node = queue->front->next;
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}


/**
 * 渡口管理算法
 * 假设过江渡船每次能载10辆车过江
 * 过江车辆分为：客车类和货车类，用1代表客车，2代表货车
 * 算法要求：
 * 1. 同类车先到先上船
 * 2. 客车先于货车上船
 * 3. 每上四辆客车才允许放上一辆货车；等待客车不足四辆，可以用货车代替
 * 4. 若无货车等待，则允许客车都上船
 * @param passCars 车辆通过序列
 * @param truckQueue 货车等待序列
 * @param busQueue 客车等待序列
 */
void ferryManage(int *passCars, LinkQueue truckQueue, LinkQueue busQueue) {
    int maxSize = 10;
    // 记录总上船车数
    int passNum = 0;
    // 记录客车上船数
    int passBusNum = 0;
    while (passNum < maxSize) {
        int pass;   // 此轮所上车辆
        if (isLinkQueueEmpty(&busQueue)) {
            // 客车等待队列为空
            if (isLinkQueueEmpty(&truckQueue)) break;    // 若两条等待队列均为空，则退出循环
            deLinkQueue(&truckQueue, &pass);
        } else {
            // 客车等待队列非空
            if (isLinkQueueEmpty(&truckQueue)) { // 货车队列为空，客车全上
                deLinkQueue(&busQueue, &pass);
            } else {    // 货车队列非空
                // 上了四辆客车后需要上一辆货车
                if (passBusNum == 4) {
                    deLinkQueue(&truckQueue, &pass);
                    passBusNum = 0;
                } else {
                    deLinkQueue(&busQueue, &pass);
                    passBusNum++;
                }
            }
        }
        passCars[passNum++] = pass;
    }
}
