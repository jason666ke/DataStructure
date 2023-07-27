//
// Created by 86153 on 2023/7/26.
//

#ifndef UNTITLED_SORT_H
#define UNTITLED_SORT_H

#include "../LinkedList/Linkedlist.h"
void swap(int *a, int *b);

void biBubbleSort(int a[], int length);

int partition(int a[], int low, int high);

int getKthElem(const int *a, int low, int high, int k);

void flagArrange(int a[], int length);

void selectSort(Linklist L);

int isMinHeap(int *a, int root, int len);

int isMinHeapNonRecursive(int *a, int len);
#endif //UNTITLED_SORT_H
