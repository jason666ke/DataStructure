cmake_minimum_required(VERSION 3.21)
project(untitled C)

set(CMAKE_C_STANDARD 99)

add_executable(untitled main.c LinkedList/Linkedlist.h LinkedList/Linkedlist.c LinkedList/DLinklist.c LinkedList/DLinklist.h SqStack/SqStack.c SqStack/SqStack.h SqStack/InfixExp2PostfixExp.c SqStack/InfixExp2PostfixExp.h Queue/SqQueue.c Queue/SqQueue.h SqStack/StackWithMin.c SString/SString.c SString/SString.h Tree/BiTNode.c Tree/BiTNode.h Tree/LinkTreeQueue.c Tree/LinkTreeQueue.h Tree/TreeStack.c Tree/TreeStack.h Tree/UFSets.c Tree/UFSets.h Tree/recursiveAlgorithm.c Tree/recursiveAlgorithm.h Graph/graph.c Graph/graph.h Search/SSTable.c Search/SSTable.h Search/TreeSort.c Search/TreeSort.h Sort/sort.c Sort/sort.h)
