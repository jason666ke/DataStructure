//
// Created by 86153 on 2023/7/21.
//

#include "SSTable.h"

int seqSearch(SSTable table, int key) {
    for (int i = 0; i < table.length; i++) {
        if (table.data[i] == key) return i;
    }
    return -1;
}

int binarySearch(SSTable table, int key) {
    int low = 0;
    int high = table.length - 1;
    while (low <= high) {
        int middle = (low + high) / 2;
        if (table.data[middle] == key) return middle;
        else if (table.data[middle] > key) high = middle - 1;
        else low = middle + 1;
    }
    return -1;
}

/**
 * 折半查找的递归写法
 * @param table
 * @param key
 * @param low
 * @param high
 * @return
 */
int binarySearchRecursion(SSTable table, int key, int low, int high) {
    if (low > high) return -1;
    int mid = (low + high) / 2;
    if (table.data[mid] > key) return binarySearchRecursion(table, key, low, mid - 1);
    else if (table.data[mid] < key) return binarySearchRecursion(table, key, mid + 1, high);
    else return mid;
}
