//
// Created by 86153 on 2023/7/15.
//

#ifndef UNTITLED_RECURSIVEALGORITHM_H
#define UNTITLED_RECURSIVEALGORITHM_H

#include "BiTNode.h"

int countDegree_0(BiTree root);
int countDegree_1(BiTree root);
int countDegree_2(BiTree root);

int getHeight(BiTree root);

int getWidth(BiTree root);
void findWidth(BiTree root, int depth, int *count);

void delLeafs(BiTree root);
int getPLevel(BiTree root, BiTNode *p, int depth);

int getMaxNode(BiTree root);

void swapKid(BiTree root);

void prePrint(BiTree root);

void printDataLevel(BiTree root, int depth);

void printPathsSum(BiTree root, int data, int path[], int pathLength, int sum);
#endif //UNTITLED_RECURSIVEALGORITHM_H
