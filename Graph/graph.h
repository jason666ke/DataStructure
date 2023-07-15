//
// Created by 86153 on 2023/7/15.
//

#ifndef UNTITLED_GRAPH_H
#define UNTITLED_GRAPH_H

#define MaxVertexNum 100    // 图的最大结点数
typedef char VertexType;    // 结点的数据类型
typedef int EdgeType;       // 边的权值的数据类型

// 邻接矩阵存储法
typedef struct {
    VertexType vex[MaxVertexNum];               // 顶点表
    EdgeType edge[MaxVertexNum][MaxVertexNum];  // 边表
    int vexNum, edgeNum;    // 结点数和边数
}MGraph;

// 弧结点
typedef struct ArcNode {
    int adjVex;             // 该弧所指向的结点位置
    struct ArcNode *next;   // 下一条弧的指针
}ArcNode;

// 顶点结点
typedef struct VNode {
    VertexType data;
    ArcNode *first;     // 指向该结点的第一条出边
}VNode, AdjList[MaxVertexNum];

// 邻接表存储发
typedef struct {
    AdjList vertices;   // 邻接表
    int vexNum, arcNum; // 顶点数，边数
}ALGraph;

#endif //UNTITLED_GRAPH_H
