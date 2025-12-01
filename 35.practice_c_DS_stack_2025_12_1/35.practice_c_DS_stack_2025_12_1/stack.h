#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <stdlib.h>

typedef int Datatype;

typedef struct Stack {
	Datatype* arr;
	int top;
	int capacity;
}Stack;

//初始化
void StackInit(Stack* st);

//插入
void StackPush(Stack* st,Datatype x);
//删除
void StackPop(Stack* st);
//判断栈是否为控
bool StackEmpty(Stack* st);
//取栈顶元素
Datatype StackTop(Stack* st);
//获取栈中有效个数
int StackSize(Stack* st);

//销毁
void StackDestroy(Stack* st);
