#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include "LinkedList/Linkedlist.h"
#include "LinkedList/DLinklist.h"
#include "SqStack/InfixExp2PostfixExp.h"
#include "Queue/SqQueue.h"
#include "SString/SString.h"
#include "Tree/BiTNode.h"
#include "Tree/recursiveAlgorithm.h"

int main() {
    // 初始化链表
    Linklist myList = initLinklist();

    // 插入节点
    insertNode(myList, 3);
    insertNode(myList, 5);
    insertNode(myList, 7);
    insertNode(myList, 6);
    insertNode(myList, 8);
    insertNode(myList, 2);
    insertNode(myList, 1);
    insertNode(myList, 9);

    // 打印链表
    printLinklist(myList);

    // 链表逆置
    reverseLinklist(myList);
    printLinklist(myList);

    // 链表升序排列
//    ascendingOrder(myList);
    ascendingOrder2(myList);
    printLinklist(myList);

    // 删除介于min和max之间的所有结点
    int min = 4;
    int max = 7;
    deleteFromA2B(myList, min, max);
    printLinklist(myList);
    printf("\n");

    // 划分奇偶链表
    Linklist originList = initLinklist();
    insertNode(originList, 1);
    insertNode(originList, 2);
    insertNode(originList, 3);
    insertNode(originList, 4);
    insertNode(originList, 5);
    insertNode(originList, 6);
    insertNode(originList, 7);
    insertNode(originList, 8);
    printf("原链表: ");
    printLinklist(originList);
    Linklist oddList = initLinklist();
    Linklist evenList = initLinklist();
    divideOddAndEven(originList, oddList, evenList);
    printf("\n");


    // 删除重复元素
    Linklist repeatList = initLinklist();
    insertNode(repeatList, 1);
    insertNode(repeatList, 1);
    insertNode(repeatList, 1);
    insertNode(repeatList, 1);
    insertNode(repeatList, 6);
    insertNode(repeatList, 6);
    insertNode(repeatList, 7);
    insertNode(repeatList, 8);
    printf("原链表为: ");
    printLinklist(repeatList);
    deleteSameElement(repeatList);
    printLinklist(repeatList);
    printf("\n");


    // 判断A是否是B的子序列
    Linklist listA = initLinklist();
    insertNode(listA, 1);
    insertNode(listA, 1);
    insertNode(listA, 1);
    insertNode(listA, 1);
    insertNode(listA, 2);
    insertNode(listA, 3);
    Linklist listB = initLinklist();
    insertNode(listB, 3);
    insertNode(listB, 1);
    insertNode(listB, 1);
    insertNode(listB, 1);
    insertNode(listB, 2);
    int isSub = isSubsequence(listA, listB);
    printf("B是A的子序列: %d\n", isSub);

    // 循环双链表是否对称
    DLinklist dLinklist = initDLinklist();
    insertDNode(dLinklist, 1, 1);
    insertDNode(dLinklist, 2, 1);
    insertDNode(dLinklist, 3, 1);
    int isSym = isSymmetric(dLinklist);
    printDLinklist(dLinklist);
    printf("该链表是对称的: %d\n", isSym);

    // 查找倒数第k个结点
    Linklist linklist = initLinklist();
    insertNode(linklist, 1);
    insertNode(linklist, 2);
    insertNode(linklist, 3);
    insertNode(linklist, 4);
    getLastKthNode(linklist, 2);

    // 找到公共后缀首节点
    printf("\n查找公共后缀\n");
    Linklist linklist1 = initLinklist();
    insertNode(linklist1, 1);
    insertNode(linklist1, 2);
    insertNode(linklist1, 3);
    insertNode(linklist1, 4);
    Linklist linklist2 = initLinklist();
    insertNode(linklist2, 1);
    insertNode(linklist2, 2);
    insertNode(linklist2, 2);
    insertNode(linklist2, 2);

    LNode *commonSuffixStart = findCommonSuffixStart(linklist1, linklist2);
    printf("list1 和 list2 的公共后缀为: ");
    while (commonSuffixStart) {
        printf("%d", commonSuffixStart->data);
        commonSuffixStart = commonSuffixStart->next;
    }
    printf("\n");

    int a = 5 / 2;
    printf("%d\n", a);

    // 栈在表达式求值中的应用
    char infixExp[] = "3+2-(5*9)+1";
    char postExp[MaxSize];

    int length = strlen(infixExp);  // Exclude the newline character
    infix2Postfix(infixExp, postExp, length);
    printf("Postfix expression: %s\n", postExp);

    int postfixLength = strlen(postExp);
    int result = calPostfixExp(postExp, postfixLength);
    printf("Result: %d\n", result);


    // 渡口轮船管理算法
    // 初始化货车等待队列
    LinkQueue truckQueue;
    initLinkQueue(&truckQueue);
    enLinkQueue(&truckQueue, 2);
    enLinkQueue(&truckQueue, 2);
    enLinkQueue(&truckQueue, 2);

    printLinkQueue(&truckQueue);

    // 初始化客车等待队列
    LinkQueue busQueue;
    initLinkQueue(&busQueue);
    enLinkQueue(&busQueue, 1);
    enLinkQueue(&busQueue, 1);
    enLinkQueue(&busQueue, 1);
    enLinkQueue(&busQueue, 1);
    enLinkQueue(&busQueue, 1);
    enLinkQueue(&busQueue, 1);
    enLinkQueue(&busQueue, 1);
    enLinkQueue(&busQueue, 1);
    printLinkQueue(&busQueue);

    int passCars[10];

    ferryManage(passCars, truckQueue, busQueue);

    printf("Passenger cars on the ferry:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", passCars[i]);
    }
    printf("\n");


    // 测试字符串基本操作
    printf("*********************************\n");
    printf("              第四章.串            \n");
    printf("**********************************\n");
    testStringOperations();


    // 测试字符串基本操作
    printf("*********************************\n");
    printf("              第五章.树和二叉树            \n");
    printf("**********************************\n");

    int data[5] = {1, 2, 3, 4, 5};

    BiTree tree = createCompleteBinaryTree(data, 5, 0);
    find_x(tree, 5);
    printf("\n");

    int biTree[5] = {10, 5, 12, 4, 7};
    BiTree biTree1 = createCompleteBinaryTree(biTree, 5, 0);
    int path[5];
    printPathsSum(biTree1, 22, path, 0, 0);

    return 0;
}

