#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>


typedef int DataType;

typedef struct Heap {
	DataType* arr;
	int size;
	int capacity;
}Heap;

//初始化
void HeapInit(Heap* php);
//销毁
void HeapDestroy(Heap* php);

//向上调整
void HeapAdjustUp(DataType* arr,int child);
//插入
void HeapPush(Heap* php, DataType x);
//向下调整
void HeapAdjustDown(DataType* arr, int parent, int size);
//删除
void HeapPop(Heap* php);

//取堆顶元素
DataType HeapTop(Heap* php);
//判空
bool HeapEmpty(Heap* php);