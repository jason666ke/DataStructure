//
// Created by 86153 on 2023/7/7.
//
// 二叉树
typedef struct BiTNode {
    int data;
    struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

// 线索二叉树
typedef struct ThreadNode {
    int data;
    struct ThreadNode *lchild, *rchild; // 左右孩子指针
    int ltag, rtag; // 左右线索标志
}ThreadNode, *ThreadTree;

// 访问结点函数
void visit(BiTNode *p);

// 先序、中序、后序和层次遍历
void preOrder(BiTree tree);
void inOrder(BiTree tree);
void postOrder(BiTree tree);
void levelOrder(BiTree tree);

// 先序、中序、后序二叉树的线索化
void preThread(ThreadNode *p, ThreadNode *pre);
void inThread(ThreadNode *p, ThreadNode *pre);
void postThread(ThreadNode *p, ThreadNode *pre);

// 先序、中序、后续线索化的主方法体
void createPreThread(ThreadTree tree);
void createInThread(ThreadTree tree);
void createPostThread(ThreadTree tree);

// 先序序列下第一个结点
ThreadNode *firstPreNode(ThreadNode *p);
// 中序序列下第一个结点
ThreadNode *firstInNode(ThreadNode *p);
// 后序序列下第一个结点
ThreadNode *firstPostNode(ThreadNode *p);

// 前序序列下最后一个结点
ThreadNode *lastPreNode(ThreadNode *p);
// 中序序列下最后一个结点
ThreadNode *lastInNode(ThreadNode *p);
// 后序序列下最后一个结点
ThreadNode *lastPostNode(ThreadNode *p);

// 先序序列下的前驱结点
ThreadNode *prePreNode(ThreadNode *p);
// 先序序列下的后继结点
ThreadNode *nextPreNode(ThreadNode *p);

// 中序序列下的前驱结点
ThreadNode *preInNode(ThreadNode *p);
// 中序序列下的后继结点
ThreadNode *nextInNode(ThreadNode *p);

// 后序序列下的前驱结点
ThreadNode *prePostNode(ThreadNode *p);
// 后序序列下的后继结点
ThreadNode *nextPostNode(ThreadNode *p);


#ifndef UNTITLED_BITNODE_H
#define UNTITLED_BITNODE_H

#endif //UNTITLED_BITNODE_H
