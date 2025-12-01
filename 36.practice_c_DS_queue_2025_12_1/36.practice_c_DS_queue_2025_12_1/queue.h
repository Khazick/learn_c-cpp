#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

typedef int DataType;

typedef struct QueueNode {
	DataType val;
	struct QueueNode* next;
}QueueNode;

typedef struct Queue {
	QueueNode* phead;
	QueueNode* ptail;
	int size;
}Queue;

//初始化
void QueueInit(Queue* qnode);

//插入 尾插
void QueuePush(Queue* qnode, DataType x);
//删除 头删
void QueuePop(Queue* qnode);
//判断队列是否为空
bool QueueEmpty(Queue* qnode);
//取队头数据
DataType QueueHead(Queue* qnode);
//取队尾数据
DataType QueueTail(Queue* qnode);
//队列有效元素个数
int QueueSize(Queue* qnode);

//销毁
void QueueDestroy(Queue* qnode);