//
// Created by 86153 on 2023/7/23.
//

#ifndef UNTITLED_TREESORT_H
#define UNTITLED_TREESORT_H

#include "../Tree/BiTNode.h"
#include "../Tree/recursiveAlgorithm.h"

typedef struct BiTNodeWithCount{
    int data;
    struct BiTNodeWithCount *lchild, *rchild;
    int count;
}BiTNodeWithCount, *BiTreeWithCount;


int pre = -32767;

int isBinarySortTree(BiTree root);

int getLevel(BiTree root, BiTNode *p);

int isBinaryBalanceTree(BiTree root);

void getMinMax(BiTree root, int *min, int *max);

void printK(BiTree root, int k);

BiTNodeWithCount *getKthNode(BiTreeWithCount root, int k);
#endif //UNTITLED_TREESORT_H
