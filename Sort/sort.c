//
// Created by 86153 on 2023/7/26.
//

#include "sort.h"

/**
 * 双向冒泡排序
 * @param a
 * @param length
 */
void biBubbleSort(int *a, int length) {
    int mid = length / 2;
    for (int i = 0; i < mid; i++) {
        for (int j = i; j < length - i - 1; j++) {
            // 正向起泡
            if (a[j] > a[j + 1]) swap(&a[j], &a[j + 1]);
        }
        for (int j = length - i - 1; j > i; j--) {
            // 逆向起泡
            if (a[j] < a[j - 1]) swap(&a[j], &a[j - 1]);
        }
    }
}

int partition(int *a, int low, int high) {
    int pivot = a[low];
    while (low < high) {
        while (low < high && a[high] >= pivot) high--;
        a[low] = a[high];
        while (low < high && a[low] <= pivot) low++;
        a[high] = a[low];
    }
    a[low] = pivot;
    return low;
}

/**
 * 在数组中找到从小到大的第k个元素
 * @param a
 * @param low
 * @param high
 * @param k
 * @return
 */
int getKthElem(const int *a, int low, int high, int k) {
    if (low < high) {
        int index = partition(a, low, high);
        if (index == k) return a[index];
        else if (index > k) return getKthElem(a, low, index - 1, k);
        else return getKthElem(a, index + 1, high, k);
    }
    return -1;
}

/**
 * 分别用0，1，2代表红色，白色和蓝色
 * 实现将红色移动至最前面，蓝色移动至最后面
 * @param a
 * @param length
 */
void flagArrange(int *a, int length) {
    int i = 0, j = 0, k = length - 1;
    while (j < length) {
        switch (a[j]) {
            case 0: {
                swap(&a[i], &a[j]);
                i++;
                j++;
                break;
            }
            case 1: {
                j++;
                break;
            }
            case 2: {
                swap(&a[i], &a[j]);
                k--;
            }
        }
    }
}

/**
 * 将集合划分成两个不相交的子集A1， A2
 * n_1和n_2分别为集合中元素个数
 * S_1和S_2分别为集合中的元素和
 * 要求：
 *  |n_1 - n_2|最小
 *  |s_1 - s_2|最大
 * @param a
 * @param length
 * @return
 */
int setPartition(int *a, int length) {
    int flag = 1;
    int low = 0;
    int high = length - 1;
    int pivotIndex;
    while (flag) {
        pivotIndex = partition(a, low, high);
        if (pivotIndex == length / 2) flag = 0;
        else if (pivotIndex < length / 2) pivotIndex = partition(a, pivotIndex + 1, high);
        else pivotIndex = partition(a, low, pivotIndex - 1);
    }
    int s1 = 0;
    int s2 = 0;
    for (int i = 0; i < pivotIndex; i++) s1 += a[i];
    for (int i = pivotIndex; i < length; i++) s2 += a[i];
    return s2 - s1;
}

/**
 * 实现带头结点链表的简单选择排序
 * @param L
 */
void selectSort(Linklist L) {
    LNode *p, *pre;       // p为工作指针
    LNode *r = L;   // r为有序链表的尾指针
    LNode *min, *min_pre;
    while (r->next) {
        min_pre = r;
        min = r->next;
        pre = r;
        p = r->next;
        while (p) { // 遍历找到最小的结点
            if (p->data < min->data) {
                min_pre = pre;
                min = p;
            }
            pre = p;
            p = p->next;
        }
        // 将min从原链表中取下
        min_pre->next = min->next;
        // 将min接到有序链表表尾
        min->next = r->next;
        r->next = min;
        r = r->next;
    }
}

/**
 * 判断一个数组是否为小根堆
 * @param a
 * @param root
 * @param len
 * @return
 */
int isMinHeap(int *a, int root, int len) {
    if (root > len) return 1;
    int leftRoot = 2 * root;
    int left = 0;
    int rightRoot = 2 * root + 1;
    int right = 0;
    int isLeft = isMinHeap(a, leftRoot, len);
    int isRight = isMinHeap(a, rightRoot, len);
    if (isLeft && isRight) {    // 左右子树都是小根堆
        if (leftRoot <= len) {
            left = a[leftRoot];
            if (a[root] > left) return 0;
        }
        if (rightRoot <= len) {
            right = a[rightRoot];
            if (a[root] > right) return 0;
        }
        return 1;
    }
    return 0;
}

/**
 * 判断是否为小根堆的非递归写法
 * @param a
 * @param len
 * @return
 */
int isMinHeapNonRecursive(int *a, int len) {
    if (len % 2 == 0) { // 偶数，存在一个单分支结点
        if (a[len / 2] > a[len]) return 0;
        for (int i = len / 2 - 1; i >= 1; i--) {
            // 判断所有双分支结点
            if (a[i] > a[2 * i] || a[i] > a[2 * i + 1]) return 0;
        }
    } else {
        for (int i = len / 2; i >= 1; i--) {
            if (a[i] > a[2 * i] || a[i] > a[2 * i + 1]) return 0;
        }
    }
    return 1;
}





