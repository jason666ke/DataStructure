//
// Created by 86153 on 2023/7/14.
//

#ifndef UNTITLED_UFSETS_H
#define UNTITLED_UFSETS_H

#define SIZE 100
int UFSETS[SIZE];

void initial(int s[]);
int find(const int s[], int x);
void Union(int s[], int root1, int root2);

int betterFind(int s[], int x);
void betterUnion(int s[], int root1, int root2);
#endif //UNTITLED_UFSETS_H
