//
// Created by 86153 on 2023/7/14.
//

#include "UFSets.h"

void initial(int *s) {
    for (int i = 0; i < SIZE; i++) {
        s[i] = -1;
    }
}

int find(const int *s, int x) {
    while (s[x] >= 0) x = s[x];
    return x;
}

void Union(int *s, int root1, int root2) {
    if (root1 == root2) return;
    s[root2] = root1;
}

int betterFind(int *s, int x) {
    int root = x;
    while (s[root] >= 0) root = s[root];
    int parent;
    while (x != root) {
        parent = s[x];  // 记录父节点
        s[x] = root;    // 将当前节点接到根节点下
        x = parent;     // x移向父节点
    }
}

void betterUnion(int *s, int root1, int root2) {
    if (root1 == root2) return;
    if (s[root2] > s[root1]) {
        // root2 < root1
        s[root1] += s[root2];
        s[root2] = root1;
    } else {
        // root2 >= root1
        s[root2] += s[root1];
        s[root1] = root2;
    }
}

