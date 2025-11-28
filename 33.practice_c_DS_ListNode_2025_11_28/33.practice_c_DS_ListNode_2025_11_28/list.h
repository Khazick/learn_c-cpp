#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h> 
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

typedef int Datatype;
typedef struct ListNode {
	Datatype val;
	struct ListNode* prev;
	struct ListNode* next;
}ListNode;

//初始化
ListNode* LTinit();
//创建新结点
ListNode* BuyNode(Datatype x);
//打印链表
void LTPrint(ListNode* phead);
//查找
ListNode* LTFind(ListNode* phead, Datatype x);
//插入
void LTPushBack(ListNode* phead,Datatype x);//尾插
void LTPushFront(ListNode* phead, Datatype x);//头插
void LTInsert(ListNode* pos, Datatype x);//指定位置后插入
//判断链表是否为空
bool LTEmpty(ListNode* phead);
//删除
void LTPopBack(ListNode* phead);//尾删
void LTPopFront(ListNode* phead);//头删
void LTErase(ListNode* pos);//指定位置删除
//销毁
void LTDestroy(ListNode* phead);