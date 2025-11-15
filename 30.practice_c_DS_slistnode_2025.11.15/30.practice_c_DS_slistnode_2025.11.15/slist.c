#include "slist.h"
//创建
SListNode* BuySListNode(SLDateType x) {
	SListNode* slist = (SListNode*)malloc(sizeof(SListNode));
	if (!slist) {
		perror("malloc: ");
		exit(1);
	}
	slist->x = x;
	slist->next = NULL;
	return slist;
}
//打印
void SListPrint(SListNode* plist) {
	SListNode* pcur = plist;
	while (pcur) {
		printf("%d ", pcur->x);
		pcur = pcur->next;
	}
	printf("NULL\n");
}
//插入
void SListPushBack(SListNode** pplist, SLDateType x) {
	assert(pplist);
	SListNode* newnode = BuySListNode(x);
	if (*pplist == NULL) {
		*pplist = newnode;
	}
	else {
		SListNode* pcur = *pplist;
		while (pcur->next) {
			pcur = pcur->next;
		}
		pcur->next = newnode;
	}
}//尾插
void SListPushFront(SListNode** pplist, SLDateType x) {
	assert(pplist);
	SListNode* newnode = BuySListNode(x);
	newnode->next = *pplist;
	*pplist = newnode;
}//头插
void SListInsert(SListNode** pplist, SListNode* pos, SLDateType x) {
	assert(pplist);
	assert(pos);
	if (pos == *pplist) {
		SListPushFront(pplist, x);
	}
	else {
		SListNode* newnode = BuySListNode(x);
		SListNode* pcur = *pplist;
		while (pcur->next != pos) {
			pcur = pcur->next;
		}
		newnode->next = pos;
		pcur->next = newnode;
	}
}//在指定位置之前插入
void SListInsertAfter(SListNode** pplist, SListNode* pos, SLDateType x) {
	assert(pplist);
	assert(pos);
	SListNode* newnode = BuySListNode(x);
	newnode->next = pos->next;
	pos->next = newnode;
}//在指定位置之后插入

//删除
void SListPopBack(SListNode** pplist) {
	assert(pplist&& *pplist);	
	if (!(*pplist)->next) {
		free(*pplist);
		*pplist = NULL;
	}
	else {
		SListNode* del = *pplist;
		SListNode* pcur = NULL;
		while (del->next) {
			pcur = del;
			del = del->next;
		}
		pcur->next = NULL;
		free(del);
		del = NULL;
	}
}//尾删
void SListPopFront(SListNode** pplist) {
	assert(pplist && *pplist);
	SListNode* phead = (*pplist)->next;
	free(*pplist);
	*pplist = phead;
}//头删
void SListErase(SListNode** pplist, SListNode* pos) {
	assert(pplist && *pplist);
	assert(pos);
	if (pos == *pplist) {
		SListPopFront(pplist);
	}
	else {
		SListNode* pcur = *pplist;
		while (pcur->next != pos) {
			pcur = pcur->next;
		}
		pcur->next = pos->next;
		free(pos);
		pos = NULL;
	}
}//在指定位置删除
void SListEraseAfter(SListNode** pplist, SListNode* pos) {
	assert(pplist && *pplist);
	assert(pos);
	if (!pos->next)
		SListPopFront(pplist);
	else {
		SListNode* del = pos->next;
		pos->next = del->next;
		free(del);
		del = NULL;
	}
}//在指定位置之后删除
//查找
SListNode* SlistFind(SListNode* plist, SLDateType x) {
	assert(plist);
	SListNode* pcur = plist;
	while (pcur) {
		if (pcur->x == x) {
			return pcur;
		}
		pcur = pcur->next;
	}
	return NULL;
}
//销毁
void SListDestroy(SListNode** pplist) {
	assert(pplist && *pplist);
	SListNode* pcur = *pplist;
	while (pcur) {
		pcur = pcur->next;
		free(*pplist);
		*pplist = pcur;
	}
}