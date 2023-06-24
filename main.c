#include <stdio.h>
#include <malloc.h>
#include "LinkedList/Linkedlist.h"
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
    return 0;
}



