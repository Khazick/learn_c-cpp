#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>

//栈的实现
typedef struct Stack {
	int* arr;
	int top;
	int capacity;
}Stack;

void StackInit(Stack* st);
void StackPush(Stack* st, int x);
bool StackEmpty(Stack* st);
void StackPop(Stack* st);
int StackTop(Stack* st);
int StackSize(Stack* st);
void StackDestroy(Stack* st);

//队列的实现
typedef struct QueueNode {
	int val;
	struct QueueNode* next;
}QueueNode;
typedef struct Queue
{
	QueueNode* phead;
	QueueNode* ptail;
	int size;
}Queue;

void QueueInit(Queue* q);
void QueuePush(Queue* q, int x);
bool QueueEmpty(Queue* q);
void QueuePop(Queue* q);
int QueueHead(Queue* q);
int QueueTail(Queue* q);
int QueueSize(Queue* q);
void QueueDestroy(Queue* q);