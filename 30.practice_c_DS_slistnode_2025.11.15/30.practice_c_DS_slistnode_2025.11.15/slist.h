#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int SLDateType;
typedef struct SListNode {
	SLDateType x;
	struct SListNode* next;
}SListNode;

//创建
SListNode* BuySListNode(SLDateType x);
//打印
void SListPrint(SListNode* plist);
//插入
void SListPushBack(SListNode** pplist,SLDateType x);//尾插
void SListPushFront(SListNode** pplist, SLDateType x);//头插
void SListInsert(SListNode** pplist, SListNode* pos, SLDateType x);//在指定位置之前插入
void SListInsertAfter(SListNode** pplist, SListNode* pos, SLDateType x);//在指定位置之后插入
//删除
void SListPopBack(SListNode** pplist);//尾删
void SListPopFront(SListNode** pplist);//头删
void SListErase(SListNode** pplist, SListNode* pos);//在指定位置删除
void SListEraseAfter(SListNode** pplist, SListNode* pos);//在指定位置之后删除

//查找
SListNode* SlistFind(SListNode* pplist,SLDateType x);

//销毁
void SListDestroy(SListNode** pplist);