//
// Created by 86153 on 2023/7/7.
//

#include <stddef.h>
#include <malloc.h>
#include <stdio.h>
#include <math.h>
#include "BiTNode.h"
#include "LinkTreeQueue.h"
#include "TreeStack.h"
// 构建完全二叉树
BiTree createCompleteBinaryTree(int *arr, int size, int index) {
    if (index >= size) {
        return NULL;
    }

    // 创建当前节点
    BiTree node = (BiTree)malloc(sizeof(BiTNode));
    node->data = arr[index];
    node->lchild = NULL;
    node->rchild = NULL;

    // 递归构建左子树和右子树
    node->lchild = createCompleteBinaryTree(arr, size, 2 * index + 1);
    node->rchild = createCompleteBinaryTree(arr, size, 2 * index + 2);

    return node;
}



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
    LinkTreeQueue queue;
    initLinkTreeQueue(&queue);
    // 根节点入栈
    enLinkTreeQueue(&queue, tree);
    BiTNode *tNode = NULL;
    while (!isLinkTreeQueueEmpty(&queue)) {
        deLinkTreeQueue(&queue, &tNode);
        visit(tNode);
        if (tNode->lchild != NULL) enLinkTreeQueue(&queue, tNode->lchild);
        if (tNode->rchild != NULL) enLinkTreeQueue(&queue, tNode->rchild);
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

/**
 * 对于每个元素值为x的结点，删除以他为根的子树并释放对应的空间
 * @param root
 * @param x
 */
void deleteXTree(BiTree root) {
    if (root) {
        deleteXTree(root->lchild);
        deleteXTree(root->rchild);
        free(root);
    }
}

void searchX(BiTree root, int x) {
    LinkTreeQueue queue;
    initLinkTreeQueue(&queue);
    if (root) {
        if (root->data == x) deleteXTree(root);
        enLinkTreeQueue(&queue, root);
    }
    BiTNode *p = NULL;
    while (!isLinkTreeQueueEmpty(&queue)) {
        deLinkTreeQueue(&queue, &p);
        if (p->lchild->data == x) {
            deleteXTree(p->lchild);
            p->lchild = NULL;
        }
        else enLinkTreeQueue(&queue, p->lchild);
        if (p->rchild->data == x) {
            deleteXTree(p->rchild);
            p->rchild = NULL;
        }
        else enLinkTreeQueue(&queue, p->rchild);
    }
}

/**
 * 打印值为x的结点的所有祖先
 * @param root
 * @param x
 * @return 1 if the node with value x is found, 0 otherwise
 */
int find_x(BiTree root, int x) {
    if (root == NULL) {
        return 0;
    }

    if (root->data == x) {
        return 1;
    }

    int foundInLeft = find_x(root->lchild, x);
    int foundInRight = find_x(root->rchild, x);

    if (foundInLeft || foundInRight) {
        printf("%d ", root->data);
        return 1;
    }

    return 0;
}

void visit(BiTNode *p) {
    printf("%d ", p->data);
}

/**
 * 后序遍历的非递归算法
 * @param root
 */
void nonRecursivePostOrder(BiTree root) {
    TreeStack stack;
    initTreeStack(&stack);

    BiTNode *p = root;
    BiTNode *r = NULL;

    while (p || !isTreeStackEmpty(&stack)) {
        if (p) {
            pushTreeStack(&stack, p);
            p = p->lchild;
        } else {
            getTopTreeStack(&stack, &p);
            if (p->rchild && p->rchild != r) p = p->rchild;
            else {
                popTreeStack(&stack, &p);
                visit(p);
                r = p;
                p = NULL;
            }
        }
    }
}

/**
 * 逆向层次遍历
 * @param root
 */
void reverseLevelOrder(BiTree root) {
    if (!root) return;
    TreeStack stack;
    initTreeStack(&stack);
    LinkTreeQueue queue;
    initLinkTreeQueue(&queue);

    enLinkTreeQueue(&queue, root);
    BiTNode *p = NULL;
    while (!isLinkTreeQueueEmpty(&queue)) {
        deLinkTreeQueue(&queue, &p);
        pushTreeStack(&stack, p);
        if (p->lchild) enLinkTreeQueue(&queue, p->lchild);
        if (p->rchild) enLinkTreeQueue(&queue, p->rchild);
    }
    while (!isTreeStackEmpty(&stack)) {
        popTreeStack(&stack, &p);
        visit(p);
    }
}

/**
 * 二叉树深度的非递归写法
 * @param root
 * @return
 */
int treeDepthNonRecursive(BiTree root) {
    if (!root) return 0;

    int level = 0;
    int last = 0;
    int front = -1, rear = -1;
    BiTNode *queue[MaxSize];
    queue[++rear] = root;
    BiTNode *p = NULL;
    while (front < rear) {
        p = queue[++front];
        if (p->lchild) queue[++rear] = p->lchild;
        if (p->rchild) queue[++rear] = p->rchild;
        if (front == last) {
            level++;
            last = rear;
        }
    }
    return level;
}

/**
 * 计算树高的递归写法
 * @param root
 * @return
 */
int treeDepthRecursive(BiTree root) {
    if (!root) return 0;
    int leftDepth = treeDepthRecursive(root->lchild);
    int rightDepth = treeDepthRecursive(root->rchild);
    return leftDepth > rightDepth ? leftDepth + 1 : rightDepth + 1;
}


/**
 * 根据先序序列和中序序列构造二叉树
 * @param A
 * @param B
 * @param start_1
 * @param end_1
 * @param start_2
 * @param end_2
 * @return
 */
BiTree preInCreate(BiTNode *A[], BiTNode *B[], int start_1, int end_1, int start_2, int end_2) {
    BiTree root = (BiTNode *) malloc(sizeof (BiTNode));
    root = A[start_1];
    // 中序序列中找到根节点的位置
    int i = 0;
    for (i = start_2; B[i] != root; i++);
    // 计算左右子树序列长度
    int leftLength = i - start_2;
    int rightLength = end_2 - i;
    // 构造左子树
    if (leftLength) root->lchild = preInCreate(A, B, start_1 + 1, start_1 + leftLength, start_2, start_2 + leftLength - 1);
    else root->lchild = NULL;
    // 构造右子树
    if (rightLength) root->rchild = preInCreate(A, B, end_1 - rightLength + 1, end_1, end_2 - rightLength + 1, end_2);
    else root->rchild = NULL;
    return root;
}

/**
 * 判断一棵树是否为完全二叉树
 * @param root
 * @return
 */
int isCompleteBinaryTree(BiTree root) {
    if (!root) return 1;
    LinkTreeQueue queue;
    initLinkTreeQueue(&queue);

    enLinkTreeQueue(&queue, root);
    BiTNode *p = NULL;
    while (!isLinkTreeQueueEmpty(&queue)) {
        deLinkTreeQueue(&queue, &p);
        if (p) {
            if (p->lchild) enLinkTreeQueue(&queue, p->lchild);
            if (p->rchild) enLinkTreeQueue(&queue, p->rchild);
        } else {
            while (!isLinkTreeQueueEmpty(&queue)) {
                deLinkTreeQueue(&queue, &p);
                if (p) return 0;
            }
        }
    }
    return 1;
}

/**
 * 计算双叉结点的个数
 * @param root
 * @return
 */
int countDoubleSonNodes(BiTree root) {
    if (!root) return 0;
    else if (root->lchild && root->rchild)
        return countDoubleSonNodes(root->lchild) + countDoubleSonNodes(root->rchild) + 1;
    else return countDoubleSonNodes(root->lchild) + countDoubleSonNodes(root->rchild);
}

/**
 * 交换二叉树所有的左右子树
 * @param root
 */
void swap(BiTree root) {
    if (root) {
        swap(root->lchild);
        swap(root->rchild);
        BiTNode *p = root->lchild;
        root->lchild = root->rchild;
        root->rchild = p;
    }
}

/**
 * 在先序序列中查找第k个结点
 * @param root
 * @param k
 * @return
 */
int i = 1;
int searchKinPreOrder(BiTree root, int k) {
    if (!root) return '#';
    if (i == k) return root->data;
    i++;
    int ch = searchKinPreOrder(root->lchild, k);
    if (ch != '#') return ch;
    ch = searchKinPreOrder(root->rchild, k);
    if (ch != '#') return ch;
}

/**
 * 递归算法找到p和q最近的公共祖先结点
 * @param root
 * @param p
 * @param q
 * @return
 */
BiTNode *ancestor(BiTree root, BiTNode *p, BiTNode *q) {
    if (root == NULL || root == p || root == q) return root;
    BiTNode *left = ancestor(root->lchild, p, q);
    BiTNode *right = ancestor(root->rchild, p, q);
    if (left == NULL && right == NULL) return root;
    else if (left != NULL) return left;
    else return right;
}


/**
 * 将中序表达式树转化为中序表达式
 * @param root
 * @param depth
 */
void BTreeToExp(BiTree root, int depth) {
    if (root == NULL) return;
    if (root->lchild == NULL && root->rchild == NULL) printf("%s", root->data);
    else {
        if (depth > 1) printf("(");
        BTreeToExp(root->lchild, depth + 1);
        printf("%s", root->data);
        BTreeToExp(root->rchild, depth + 1);
        printf(")");
    }
}


void B2Exp(BiTree root) {
    BTreeToExp(root, 1);
}

typedef struct {
    int data[MAXSIZE];  // 保存二叉树的节点值
    int length;         // 实际占用的数组元素个数
} SqBitTree;

/**
 * 判断一颗树是否为二叉排序树的递归算法
 * @param root
 * @param start
 * @param length
 * @return
 */
int judgeInOrderBST(int *root, int start, int length) {
    if (root[start] == -1) return 1;
    int lRootId = start * 2 + 1;    // 左子树根节点下标
    int rRootId = start * 2 + 2;    // 右子树根节点下标
//    int level = 1;
//    for (;(2^level - 1) < length; level++); // 计算当前树高

    int level = (int) log2(length + 1); // 计算当前树的层数

//    int lLength_1 = (2 ^ (level - 1) - 1) / 2;   // 倒数第二层的满二叉树 / 2 - 1得到左子树的部分长度
    int lLength_1 = (int) (pow(2, level - 1) - 1 / 2) ;
    // 比较最后一层的节点数和节点数 / 2的大小，小的为左子树的大小
    int lLength_2 = (2^(level - 1) - length) < (2^(level - 2)) ? (2^(level - 1) - length) : (2^(level - 2));
    int lLength = lLength_1 + lLength_2;
    // 右子树长度
    int rLength = length - lLength - 1;

    // 分别判断左右子树是否二叉排序树
    int isLeftInOrderBST = judgeInOrderBST(root, lRootId, lLength);
    int isRightInOrderBST = judgeInOrderBST(root, rRootId, rLength);

    // 找到左子树最大值和右子树最小值
    int leftMax = 0;
    int rightMin = 10000;

    for (int j = lRootId; j < lRootId + lLength; j++) {
        if (root[j] > leftMax) leftMax = root[j];
    }
    for (int j = rRootId; j < rRootId + rLength; j++) {
        if (root[j] < rightMin) rightMin = root[j];
    }
    if (leftMax < root[start] && root[start] < rightMin) {
        return isLeftInOrderBST && isRightInOrderBST;
    } else
        return 0;
}

/**
 * 判断是否为二叉排序树的第二种算法
 * 中序遍历得到升序序列
 * @param root
 * @param k
 * @param val
 * @return
 */
int judgeBST_2(SqBitTree root, int k, int *val) { // 初始调用时k为0
    if (k < root.length && root.data[k] != -1) {
        if (!judgeBST_2(root, 2 * k + 1, val)) return 0;
        if (root.data[k] < *val) return 0;
        *val = root.data[k];
        if (!judgeBST_2(root, 2 * k + 2, val)) return 0;
    }
    return 1;
}

/**
 * 统计用孩子兄弟表示法存储的森林的叶节点的个数
 * @param forest
 * @return
 */
int countLeafs(BiTree forest) {
    if (!forest) return 0;
    int left = countLeafs(forest->lchild);
    int right = countLeafs(forest->rchild);
    if (!forest->lchild) return left + right + 1;
    else return left + right;
}


int height(BiTree root) {
    if (!root) return 0;
    int left = height(root->lchild) + 1;
    int right = height(root->rchild);
    return (left > right) ? left : right;
}

/**
 * 利用层次遍历序列和结点度数构造孩子兄弟表示法的二叉树
 * @param root
 * @param e
 * @param degree
 * @param n
 */
void createBiTree(BiTree root, const int *e, const int *degree, int n) {
    BiTNode *pointer[MaxSize];
    for (int m = 0; m < n; m++) {
        pointer[m]->data = e[m];
        pointer[m]->lchild = pointer[m]->rchild = NULL;
    }
    int d = 0, k = 0;
    for (int m = 0; m < n; m++) {
        d = degree[m];
        k++;    // k为子女序号
        if (d) {
            pointer[m]->lchild = pointer[k];
            for (int j = 2; j < d; j++){
                pointer[k - 1]->rchild = pointer[k];
            }
        }
    }
    root = pointer[0];
}





