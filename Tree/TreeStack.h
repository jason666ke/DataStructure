//
// Created by 86153 on 2023/7/10.
//
#include "BiTNode.h"
#ifndef UNTITLED_TREESTACK_H
#define UNTITLED_TREESTACK_H

#define MaxSize 50
typedef struct {
    BiTNode *data[MaxSize];
    int top;
}TreeStack;

void initTreeStack(TreeStack *stack);
int isTreeStackEmpty(TreeStack *stack);
int isTreeStackFull(TreeStack *stack);
int pushTreeStack(TreeStack *stack, BiTNode *value);
int popTreeStack(TreeStack *stack, BiTNode **value);
int getTopTreeStack(TreeStack *stack, BiTNode **value);
int modifyTopTreeStack(TreeStack *stack, BiTNode *newValue);

#endif //UNTITLED_TREESTACK_H
