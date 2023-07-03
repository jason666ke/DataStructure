cmake_minimum_required(VERSION 3.21)
project(untitled C)

set(CMAKE_C_STANDARD 99)

add_executable(untitled main.c LinkedList/Linkedlist.h LinkedList/Linkedlist.c LinkedList/DLinklist.c LinkedList/DLinklist.h SqStack/SqStack.c SqStack/SqStack.h SqStack/InfixExp2PostfixExp.c SqStack/InfixExp2PostfixExp.h Queue/SqQueue.c Queue/SqQueue.h SqStack/StackWithMin.c SString/SString.c SString/SString.h)
