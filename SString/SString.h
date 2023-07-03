//
// Created by 86153 on 2023/7/3.
//
#define maxLen 255      // 预定义最大串长为255
typedef struct {
    char ch[maxLen];    // 每个分量存储一个字符，char[0]废弃不使用
    int length;         // 串的实际长度
}SString;

void strAssign(SString *dst, char *src);
void strCopy(SString *dst, SString *src);
int strEmpty(SString *src);
int strCompare(SString *string_1, SString *string_2);
int strLength(SString *src);
void subString(SString *sub, SString *src, int pos, int len);
void concat(SString *dst, SString *src_1, SString *src_2);
int index(SString *main, SString *sub);
void clearString(SString *src);
void destroyString(SString *src);
void testStringOperations();
#ifndef UNTITLED_SSTRING_H
#define UNTITLED_SSTRING_H

#endif //UNTITLED_SSTRING_H
