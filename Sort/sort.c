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


