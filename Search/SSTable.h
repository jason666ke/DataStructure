//
// Created by 86153 on 2023/7/21.
//

#ifndef UNTITLED_SSTABLE_H
#define UNTITLED_SSTABLE_H

typedef struct {
    int *data;
    int length;
}SSTable;

int seqSearch(SSTable table, int key);
int binarySearch(SSTable table, int key);
int binarySearchRecursion(SSTable table, int key, int low, int high);

#endif //UNTITLED_SSTABLE_H
