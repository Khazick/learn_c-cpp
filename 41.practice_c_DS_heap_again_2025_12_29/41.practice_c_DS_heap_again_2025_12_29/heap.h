#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

typedef int HPDataType;
typedef struct Heap {
	HPDataType* arr;
	int size;
	int capacity;
}HP;

void HPInit(HP* php);
void HPDestroy(HP* php);
void HPPush(HP* php, HPDataType x);
void HPPop(HP* php);
HPDataType HPTop(HP* php);
bool HPEmpty(HP* php);
int HPSize(HP* php);
