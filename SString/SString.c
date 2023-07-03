//
// Created by 86153 on 2023/7/3.
//

#include <string.h>
#include <stdio.h>
#include "SString.h"

// 注意，dst.ch[0]废弃使用

void strAssign(SString *dst, char *src) {
    int len = strlen(src);
    if (len > maxLen) {
        printf("Source string exceeds maximum length.\n");
        return;
    }
    dst->length = len;
    strncpy(dst->ch + 1, src, len);
}

void strCopy(SString *dst, SString *src) {
    dst->length = src->length;
    strncpy(dst->ch + 1, src->ch + 1, src->length);
}

int strEmpty(SString *src) {
    return src->length == 0;
}

/**
 * S1 < S2: 返回-1
 * S1 > S2: 返回1
 * S1 = S2: 返回0
 * @param string_1
 * @param string_2
 * @return
 */
int strCompare(SString *string_1, SString *string_2) {
    for (int i = 1; i <= string_1->length && i <= string_2->length; i++) {
        if (string_1->ch[i] < string_2->ch[i]) {
            return -1;
        } else if (string_1->ch[i] > string_2->ch[i]) {
            return 1;
        }
    }
    return string_1->length - string_2->length;
}

int strLength(SString *src) {
    return src->length;
}

/**
 * 用Sub返回src第pos个字符起长度为len的子串
 * @param sub
 * @param src
 * @param pos
 * @param len
 */
void subString(SString *sub, SString *src, int pos, int len) {
    if (pos < 1 || pos > src->length || len < 0 || len > src->length - pos + 1) {
        printf("Invalid position or length.\n");
        return;
    }
    sub->length = len;
    strncpy(sub->ch + 1, src->ch + pos, len);
}

/**
 * 链接src_1与src_2
 * @param dst
 * @param src_1
 * @param src_2
 */
void concat(SString *dst, SString *src_1, SString *src_2) {
    if (src_1->length + src_2->length > maxLen) {
        printf("Concatenated string exceeds maximum length.\n");
        return;
    }
    dst->length = src_1->length + src_2->length;
    strncpy(dst->ch + 1, src_1->ch + 1, src_1->length);
    strncpy(dst->ch + src_1->length + 1, src_2->ch + 1, src_2->length);
}

int index(SString *main, SString *sub) {
    if (sub->length == 0) {
        return 0;
    }
    int i = 1, j = 1;
    while (i <= main->length && j <= sub->length) {
        if (main->ch[i] == sub->ch[j]) {
            i++;
            j++;
        } else {
            i = i - j + 2;
            j = 1;
        }
    }
    if (j > sub->length) {
        return i - sub->length;
    }
    return -1;
}

void clearString(SString *src) {
    src->length = 0;
}

void destroyString(SString *src) {
    src->length = 0;
}

void testStringOperations() {
    SString mainString, subString;
    char main[] = "Hello, World!";
    char sub[] = "World";

    strAssign(&mainString, main);
    strAssign(&subString, sub);

    printf("Main String: %s\n", mainString.ch + 1);
    printf("Sub String: %s\n", subString.ch + 1);

    int result = index(&mainString, &subString);
    if (result == -1) {
        printf("Sub String not found in Main String.\n");
    } else {
        printf("Sub String found at position: %d\n", result);
    }
}

/**
 * 字符串匹配的KMP算法
 * @param main 主串
 * @param sub 子串
 * @param next next数组
 * @return 子串在主串中的起始位置，若未找到返回-1
 */
int index_KMP(SString *main, SString *sub, int next[]) {
    int i = 1;  // 主串的当前位置
    int j = 1;  // 子串的当前位置
    while (i <= main->length && j <= sub->length) {
        if (j == 0 || main->ch[i] == sub->ch[j]) {
            // 当前字符匹配成功，继续比较下一个字符
            i++;
            j++;
        } else {
            // 当前字符匹配失败，根据next数组回溯
            j = next[j];
        }
    }
    if (j > sub->length) {
        // 子串已匹配完毕，返回子串在主串中的起始位置
        return i - sub->length;
    } else {
        // 子串未匹配完毕，未找到匹配
        return -1;
    }
}

/**
 * 计算next数组
 * @param sub 子串
 * @param next next数组
 */
void computeNext(SString *sub, int next[]) {
    int i = 1;  // 子串的当前位置
    int j = 0;  // next数组的当前位置
    next[1] = 0;  // next数组的第一个元素为0
    while (i < sub->length) {
        if (j == 0 || sub->ch[i] == sub->ch[j]) {
            // 当前字符匹配成功，更新next数组并继续比较下一个字符
            i++;
            j++;
            next[i] = j;
        } else {
            // 当前字符匹配失败，根据next数组回溯
            j = next[j];
        }
    }
}

/**
 * 计算nextVal数组
 * @param sub 子串
 * @param nextVal nextVal数组
 */
void computeNextVal(SString *sub, int nextVal[]) {
    int i = 1;  // 子串的当前位置
    int j = 0;  // nextVal数组的当前位置
    nextVal[1] = 0;  // nextVal数组的第一个元素为0
    while (i < sub->length) {
        if (j == 0 || sub->ch[i] == sub->ch[j]) {
            // 当前字符匹配成功，更新nextVal数组并继续比较下一个字符
            i++;
            j++;
            if (sub->ch[i] != sub->ch[j])
                nextVal[i] = j;
            else
                nextVal[i] = nextVal[j];
        } else {
            // 当前字符匹配失败，根据nextVal数组回溯
            j = nextVal[j];
        }
    }
}
