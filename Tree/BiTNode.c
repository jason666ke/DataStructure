//
// Created by 86153 on 2023/7/7.
//

#include <stddef.h>
#include "BiTNode.h"
#include "../Queue/SqQueue.h"

/**
 * 树的先序遍历
 * @param tree
 */
void preOrder(BiTree tree) {
    if (tree != NULL) { // root left right
        visit(tree);
        preOrder(tree->lchild);
        preOrder(tree->rchild);
    }
}

/**
 * 树的中序遍历
 * @param tree
 */
void inOrder(BiTree tree) {
    if (tree != NULL) {
        // left root right
        inOrder(tree->lchild);
        visit(tree);
        inOrder(tree->rchild);
    }

}

/**
 * 树的后序遍历
 * @param tree
 */
void postOrder(BiTree tree) {
    if (tree != NULL) {
        // left right root
        postOrder(tree->lchild);
        postOrder(tree->rchild);
        visit(tree);
    }
}

/**
 * 树的层次遍历
 * @param tree
 */
void levelOrder(BiTree tree) {
    // 用队列辅助
    LinkQueue queue;
    initLinkQueue(&queue);
    // 根节点入栈
    enLinkQueue(&queue, tree);
    BiTNode *tNode = NULL;
    while (!isLinkQueueEmpty(&queue)) {
        deLinkQueue(&queue, tNode);
        visit(tNode);
        if (tNode->lchild != NULL) enLinkQueue(&queue, tNode->lchild);
        if (tNode->rchild != NULL) enLinkQueue(&queue, tNode->rchild);
    }
}

/**
 * 二叉线索树的先序线索化
 * @param p
 * @param pre
 */
void preThread(ThreadNode *p, ThreadNode *pre) {
    if (p != NULL) {
        // root node threading
        if (p->lchild == NULL) {
            p->lchild = pre;
            p->ltag = 1;
        }
        if (pre != NULL && pre->rchild == NULL) {
            pre->rchild = p;
            pre->rtag = 1;
        }
        pre = p;
        // left child threading (prevent looping)
        if (p->ltag == 0) preThread(p->lchild, pre);
        // right child threading
        preThread(p->rchild, pre);
    }
}

/**
 * 创建二叉先序线索树
 * @param tree
 */
void createPreThread(ThreadTree tree) {
    ThreadNode *pre = NULL;
    if (tree != NULL) {
        preThread(tree, pre);
        pre->rchild = NULL;
        pre->rtag = 1;
    }
}

/**
 * 二叉线索树的中序线索化
 * @param p
 * @param pre
 */
void inThread(ThreadNode *p, ThreadNode *pre) {
    if (p != NULL) {
        // left threading
        inThread(p->lchild, pre);
        // root threading
        if (p->lchild == NULL) {
            p->lchild = pre;
            p->ltag = 1;
        }
        if (pre != NULL && pre->rchild == NULL) {
            pre->rchild = p;
            pre->rtag = 1;
        }
        pre = p;
        // right threading
        inThread(p->rchild, pre);
    }

}

/**
 * 构建二叉中序线索树
 * @param tree
 */
void createInThread(ThreadTree tree) {
    ThreadNode *pre = NULL;
    if (tree != NULL) {
        inThread(tree, pre);
        pre->rchild = NULL;
        pre->rtag = 1;
    }
}

/**
 * 二叉线索树的后序线索化
 * @param p
 * @param pre
 */
void postThread(ThreadNode *p, ThreadNode *pre) {
    if (p != NULL) {
        // left threading
        postThread(p->lchild, pre);
        // right threading
        postThread(p->rchild, pre);
        // root threading
        if (p->lchild == NULL) {
            p->lchild = pre;
            p->ltag = 1;
        }
        if (pre != NULL && pre->rchild == NULL) {
            pre->rchild = p;
            pre->rtag = 1;
        }
        pre = p;
    }
}

/**
 * 构建二叉后序线索树
 * @param tree
 */
void createPostThread(ThreadTree tree) {
    ThreadNode *pre = NULL;
    if (tree != NULL) {
        postThread(tree, pre);
        pre->rchild = NULL;
        pre->rtag = 1;
    }
}

/**
 * 求先序序列下的第一个结点
 * @param p
 * @return
 */
ThreadNode *firstPreNode(ThreadNode *p) {
    // root left right
    if (p->ltag == 0) return p->lchild;
    else return p->rchild;
}

/**
 * 求中序序列的第一个节点
 * @param p
 * @return
 */
ThreadNode *firstInNode(ThreadNode *p) {
    // left root right
    while (p->ltag == 0) p = p->lchild;
    return p;
}

/**
 * 求后序序列中的第一个结点
 * @param p
 * @return
 */
ThreadNode *firstPostNode(ThreadNode *p) {
    // left right root
    if (p->rtag == 1) return p->rchild;
    // unable to get next Node
    return NULL;
}

/**
 * 求先序序列的最后一个结点
 * @param p
 * @return
 */
ThreadNode *lastPreNode(ThreadNode *p) {
    // root left right
    if (p->ltag == 1) return p->lchild;
    // unable to get last pre Node
    return NULL;
}

/**
 * 求中序序列的最后一个结点
 * @param p
 * @return
 */
ThreadNode *lastInNode(ThreadNode *p) {
    // left root right
    while (p->rtag == 0) p = p->rchild;
    return p->rchild;
}

/**
 * 求后序序列的最后一个结点
 * @param p
 * @return
 */
ThreadNode *lastPostNode(ThreadNode *p) {
    // left right root
    if (p->rtag == 0) return p->rchild;
    else return p->lchild;
}

/**
 * 先序序列中找到第一个前驱
 * @param p
 * @return
 */
ThreadNode *prePreNode(ThreadNode *p) {
    // unable to get pre Node
    if (p->ltag == 0) return NULL;
    else return p->lchild;
}

/**
 * 先序序列中找到第一个后继
 * @param p
 * @return
 */
ThreadNode *nextPreNode(ThreadNode *p) {
    if (p->ltag == 0) return p->lchild;
    else return p->rchild;
}

/**
 * 中序序列中找到第一个前驱
 * @param p
 * @return
 */
ThreadNode *preInNode(ThreadNode *p) {
    if (p->ltag == 0) return lastInNode(p->lchild);
    else return p->lchild;
}

/**
 * 中序序列中找到第一个后继
 * @param p
 * @return
 */
ThreadNode *nextInNode(ThreadNode *p) {
    if (p->rtag == 0) return firstInNode(p->rchild);
    else return p->rchild;
}

/**
 * 后序序列的第一个前驱
 * @param p
 * @return
 */
ThreadNode *prePostNode(ThreadNode *p) {
    if (p->rtag == 0) return p->rchild;
    else return p->lchild;
}

/**
 * 后序序列的第一个后继
 * @param p
 * @return
 */
ThreadNode *nextPostNode(ThreadNode *p) {
    if (p->rtag == 1) return p->rchild;
    // unable to get first nextNode
    return NULL;
}










