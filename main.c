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
    ascendingOrder(myList);
    printLinklist(myList);

    // 删除介于min和max之间的所有结点
    int min = 4;
    int max = 7;
    deleteFromA2B(myList, min, max);
    printLinklist(myList);
    return 0;
}

