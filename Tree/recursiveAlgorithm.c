//
// Created by 86153 on 2023/7/15.
//

#include <stddef.h>
#include <malloc.h>
#include <stdio.h>
#include "recursiveAlgorithm.h"

/**
 * 统计二叉树中度为0的结点
 * @param root
 * @return
 */
int countDegree_0(BiTree root) {
    if (!root) return 0;

    int left = countDegree_0(root->lchild);
    int right = countDegree_0(root->rchild);

    if (!root->lchild && !root->rchild)
        return left + right + 1;
    else
        return left + right;
}

/**
 * 统计二叉树中度为1的结点
 * @param root
 * @return
 */
int countDegree_1(BiTree root) {
    if (!root) return 0;

    int left = countDegree_1(root->lchild);
    int right = countDegree_1(root->rchild);

    if ((root->lchild && !root->rchild) || (!root->lchild && root->rchild)) {
        return left + right + 1;
    } else {
        return left + right;
    }
}

/**
 * 统计二叉树中度为2的结点
 * @param root
 * @return
 */
int countDegree_2(BiTree root) {
    if (!root) return 0;

    int left = countDegree_2(root->lchild);
    int right = countDegree_2(root->rchild);

    if (root->lchild && root->rchild)
        return left + right + 1;
    else
        return left + right;
}

/**
 * 统计树的高度
 * @param root
 * @return
 */
int getHeight(BiTree root) {
    if (!root) return 0;

    int left = getHeight(root->lchild);
    int right = getHeight(root->rchild);

    return left > right ? left + 1 : right + 1;
}

/**
 * 统计树的宽度
 * @param root
 * @return
 */
int getWidth(BiTree root) {
    if (!root) return 0;
    int height = getHeight(root);
    // 利用辅助数组count记录每一层的节点数
    int count[height + 1];
    // 统计每一层的节点数
    findWidth(root, 1, count);
    // 找到节点数的最大值
    int max = 0;
    for (int i = 1; i < height + 1; i++)
        max = count[i] > max ? count[i] : max;
    return max;
}

/**
 * 利用辅助数组count计算每一层的结点数
 * @param root
 * @param depth
 * @param count
 */
void findWidth(BiTree root, int depth, int *count) {
    if (root == NULL) return;
    // 先序遍历的模板
    count[depth]++; // 当前结点的count++

    findWidth(root->lchild, depth + 1, count);
    findWidth(root->rchild, depth + 1, count);
}

/**
 * 删除所有的叶子结点
 * @param root
 */
void delLeafs(BiTree root) {
    if (!root) return;
    delLeafs(root->lchild);
    delLeafs(root->rchild);
    if (!root->lchild && !root->rchild) free(root);
}

/**
 * 获取结点P的所在层次
 * 若P不在该树中则返回-1
 * @param root
 * @param p
 * @param depth
 * @return
 */
int getPLevel(BiTree root, BiTNode *p, int depth) {
    if (!root) return -1; // 代表没找到

    if (root == p) return depth;

    // 先找左子树
    int level = getPLevel(root->lchild, p, depth + 1);
    if (level == -1) {
        // 左子树中没有则找右子树
        level = getPLevel(root->rchild, p, depth + 1);
    }

    return level;
}

/**
 * 获取各节点中最大的元素值
 * @param root
 * @return
 */
int getMaxNode(BiTree root) {
    if (!root) return 0;

    int left = getMaxNode(root->lchild);
    int right = getMaxNode(root->rchild);

    int max = root->data;
    if (left > max) max = left;
    else if (right > max) max = right;

    return max;
}

/**
 * 交换结点的两个子女
 * @param root
 */
void swapKid(BiTree root) {
    if (!root) return;

    // 左右子树进行交换
    swapKid(root->lchild);
    swapKid(root->rchild);

    // 根节点交换
    BiTNode *p = root->lchild;
    root->lchild = root->rchild;
    root->rchild = p;
}

/**
 * 以先序次序输出二叉树中所有结点的数据值和层次
 * @param root
 */
void prePrint(BiTree root) {
    printDataLevel(root, 1);
}

/**
 * 先序次序输出当前二叉树所有结点的数据值和层次
 * @param root
 * @param depth
 */
void printDataLevel(BiTree root, int depth) {
    if (!root) return;

    printf("data: %d, depth: %d", root->data, depth);
    printDataLevel(root->lchild, depth + 1);
    printDataLevel(root->rchild, depth + 1);
}






