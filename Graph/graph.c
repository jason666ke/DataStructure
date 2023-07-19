//
// Created by 86153 on 2023/7/15.
//

#include <malloc.h>
#include <stdio.h>
#include "graph.h"

// 辅助函数：在调用 existPathDFS 之前初始化 visited 数组
void initializeVisitedArray() {
    for (int i = 0; i < MaxVertexNum; i++) {
        visited[i] = 0;
    }
}

int firstNeighbor(MGraph g, int x) {
    for (int i = 0; i < g.vexNum; i++) {
        if (g.edge[x][i] == 1) return i;
    }
    return -1;
}

int nextNeighbor(MGraph g, int x, int y) {
    for (int i = y + 1; i < g.vexNum; i++) {
        if (g.edge[x][i] == 1) return i;
    }
    return -1;
}

void BFSTraverse(MGraph g) {
    for (int i = 0; i < MaxVertexNum; i++) {
        visited[i] = 0;
    }
    for (int i = 0; i < g.vexNum; i++) {
        BFS(g, i);
    }
}

void BFS(MGraph g, int v) {
    visit(v);
    visited[v] = 1;
    LinkQueue queue;
    initLinkQueue(&queue);
    enLinkQueue(&queue, v);
    int front;
    int next;
    while (!isLinkQueueEmpty(&queue)) {
        deLinkQueue(&queue, &front);
        for (next = firstNeighbor(g, front); next >= 0; next = nextNeighbor(g, front, next)) {
            if (!visited[next]) {
                visit(next);
                visited[next] = 1;
                enLinkQueue(&queue, next);
            }
        }
    }
}

void DFSTraverse(MGraph g) {
    for (int i = 0; i < MaxVertexNum; i++) {
        visited[i] = 0;
    }
    for (int i = 0; i < MaxVertexNum; i++) {
        if (!visited[i]) {
            DFS(g, i);
        }
    }
}

void DFS(MGraph g, int v) {
    visit(v);
    visited[v] = 1;
    for (int next = firstNeighbor(g, v); next >= 0; next = nextNeighbor(g, v, next)) {
        if (!visited[next]) {
            DFS(g, next);
        }
    }
}

/**
 * 判断是否存在从结点i到结点j的路径
 * @param g
 * @param i
 * @param j
 * @return
 */
int existPathDFS(MGraph g, int i, int j) {
    visited[i] = 1;
    for (int k = firstNeighbor(g, i); k >= 0; k = nextNeighbor(g, i, k)) {
        if (k == j) return 1;
        else {
            if (!visited[k]) {
                existPathDFS(g, k, j);
            }
        }
    }
    return 0;
}

int existPathBFS(MGraph g, int i, int j) {
    LinkQueue queue;
    initLinkQueue(&queue);
    enLinkQueue(&queue, i);
    visited[i] = 1;
    int front;
    while (!isLinkQueueEmpty(&queue)) {
        deLinkQueue(&queue, &front);
        for (int k = firstNeighbor(g, front); k >= 0; k = nextNeighbor(g, front, k)) {
            if (k == j) return 1;
            else {
                if (!visited[k]) {
                    enLinkQueue(&queue, k);
                    visited[k] = 1;
                }
            }
        }
    }
    return 0;
}

/**
 * 判断图是否为一棵树
 * 使用的判断条件：G为无回路的连通图
 * @param g
 * @param i
 * @return
 */
int isTreeBFS(MGraph g, int i) {
    LinkQueue queue;
    initLinkQueue(&queue);

    enLinkQueue(&queue, i);
    visited[i] = 1;
    int front;
    while (!isLinkQueueEmpty(&queue)) {
        deLinkQueue(&queue, &front);
        for (int k = firstNeighbor(g, front); k >= 0; k = nextNeighbor(g, front, k)) {
            if (!visited[k]) {
                enLinkQueue(&queue, k);
                visited[k] = 1;
            } else {
                return 0;
            }
        }
    }
    for (int k = 0; k < g.vexNum; k++) {
        if (visited[k] == 0) return 0;
    }
    return 1;
}

void countV_D_DFS(MGraph g, int v, int *vNum, int *eNum) {
    visited[v] = 1;
    *vNum++;
    for (int k = firstNeighbor(g, v); k >= 0; k = nextNeighbor(g, v, k)) {
        if (!visited[k]) {
            *eNum++;
            countV_D_DFS(g, k, vNum, eNum);
        }
    }
}

/**
 * 判断一个图是否为树
 * @param g
 * @return
 */
int isTreeDFS(MGraph g) {
    initializeVisitedArray();
    int vNum = 0, eNum = 0;
    countV_D_DFS(g, 0, &vNum, &eNum);
    if (vNum == g.vexNum && eNum == vNum - 1) return 1;
    return 0;
}

/**
 * 找到图中从i到j的所有简单路径
 * @param g
 * @param i
 * @param j
 * @param path
 * @param pathLength
 */
void findPath(MGraph g, int i, int j, int path[], int pathLength) {
    visited[i] = 1;
    path[pathLength] = i;
    pathLength++;
    if (i == j) {
        for (int k = 0; k < pathLength; k++) {
            printf("%d ", path[k]);
        }
    }
    for (int k = firstNeighbor(g, i); k >= 0; k = nextNeighbor(g, i, k)) {
        if (!visited[k]) {
            findPath(g, k, j, path, pathLength);
        }
    }
    visited[i] = 0;
    pathLength--;   // 回溯时需要将路径长度-1，以便上一层函数可以正确表述路径
}

