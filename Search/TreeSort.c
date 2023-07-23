//
// Created by 86153 on 2023/7/23.
//

#include <math.h>
#include <stdio.h>
#include "TreeSort.h"

/**
 * 判断一棵树是否为二叉排序树
 * @param root
 * @return
 */
int isBinarySortTree(BiTree root) {
    if (!root) return 1;
    int left = isBinarySortTree(root->lchild);
    if (!left || pre >= root->data) return 0;
    pre = root->data;
    int right = isBinarySortTree(root->rchild);
    return right;
}

/**
 * 获取结点p在二叉排序树中的层次
 * @param root
 * @param p
 * @return
 */
int getLevel(BiTree root, BiTNode *p) {
    int level = 1;
    if (root == p) return level;
    while (root && root != p) {
        if (root->data > p->data) {
            root = root->lchild;
            level++;
        }
        else if (root->data < p->data) {
            root = root->rchild;
            level++;
        }
        else return level;
    }
    return -1;
}

/**
 * 判断一颗二叉树是否二叉排序树
 * @param root
 * @return
 */
int isBinaryBalanceTree(BiTree root) {
    if (!root) return 1;
    int lBalance = isBinaryBalanceTree(root->lchild);
    int rBalance = isBinaryBalanceTree(root->rchild);
    if (lBalance && rBalance) {
        int lHeight = getHeight(root->lchild);
        int rHeight = getHeight(root->rchild);
        int hDiff = abs(lHeight - rHeight);
        if (hDiff < 2) return 1;
    }
    return 0;
}

/**
 * 获取二叉排序树中最大和最小的结点
 * @param root
 * @param min
 * @param max
 */
void getMinMax(BiTree root, int *min, int *max) {
    BiTNode *p = root, *q = root;
    while (p->lchild) p = p->lchild;
    while (q->rchild) q = q->rchild;
    *min = p->data;
    *max = q->data;
}

/**
 * 打印二叉排序树中 >= k的结点，并且以降序打印
 * @param root
 * @param k
 */
void printK(BiTree root, int k) {
    if (!root) return;
    printK(root->rchild, k);
    if (root->data >= k) printf("%d ", root->data);
    printK(root->lchild, k);
}

/**
 * 获取二叉排序树中第K个结点
 * count为新加入字段，记录以当前结点为根的树的结点数
 * @param root
 * @param k
 * @return
 */
BiTNodeWithCount *getKthNode(BiTreeWithCount root, int k) {
    if (k < 1 || k > root->count) return NULL;
    if (!root->lchild) {
        if (k == 1) return root;
        else return getKthNode(root->rchild, k - 1);
    }
    int leftNum = root->lchild->count;
    if (leftNum == k - 1) return root;
    else if (leftNum > k - 1) return getKthNode(root->lchild, k);
    else return getKthNode(root->rchild, k - (leftNum + 1));
}

