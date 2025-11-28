#include "list.h"

ListNode* LTinit() {
	ListNode* phead = (ListNode*)malloc(sizeof(ListNode));
	assert(phead);
	phead->val = -1;
	phead->prev = phead->next = phead;
	return phead;
}
void LTPrint(ListNode* phead) {
	assert(phead);
	ListNode* pcur = phead->next;
	while (pcur!=phead) {
		printf("%d ", pcur->val);
		pcur = pcur->next;
	}
	printf("\n");
}
ListNode* BuyNode(Datatype x) {
	ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
	assert(newnode);
	newnode->val = x;
	newnode->prev = newnode->next = newnode;
	return newnode;
}
void LTPushBack(ListNode* phead, Datatype x) {
	assert(phead);
	ListNode* newnode = BuyNode(x);
	newnode->prev = phead->prev;
	newnode->next = phead;
	phead->prev->next = newnode;
	phead->prev = newnode;
}
void LTPushFront(ListNode* phead, Datatype x) {
	assert(phead);
	ListNode* newnode = BuyNode(x);
	newnode->prev = phead;
	newnode->next = phead->next;
	phead->next->prev = newnode;
	phead->next = newnode;
}

bool LTEmpty(ListNode* phead) {
	if (phead->prev == phead)
		return true;
	return false;
}
void LTPopBack(ListNode* phead) {
	assert(phead);
	assert(!LTEmpty(phead));
	ListNode* del = phead->prev;
	del->prev->next = phead;
	phead->prev = del->prev;
	free(del);
	del = NULL;
}
void LTPopFront(ListNode* phead) {
	assert(phead);
	assert(!LTEmpty(phead));
	ListNode* del = phead->next;
	del->next->prev = del->prev;
	phead->next = del->next;
	free(del);
	del = NULL;
}
ListNode* LTFind(ListNode* phead, Datatype x) {
	assert(phead);
	ListNode* pcur = phead->next;
	while (pcur != phead) {
		if (pcur->val == x)
			return pcur;
		pcur = pcur->next;
	}
	return NULL;
}
void LTInsert(ListNode* pos, Datatype x) {
	assert(pos);
	ListNode* newnode = BuyNode(x);
	newnode->prev = pos;
	newnode->next = pos->next;
	pos->next->prev = newnode;
	pos->next = newnode;
}
void LTErase(ListNode* pos) {
	assert(pos);
	assert(!LTEmpty(pos));
	pos->prev->next = pos->next;
	pos->next->prev = pos->prev;
	free(pos);
	pos = NULL;
}
void LTDestroy(ListNode* phead) {
	assert(phead);
	ListNode* pcur = phead->next;
	while (pcur != phead) {
		ListNode* next = pcur->next;
		free(pcur);
		pcur = next;
	}
	free(phead);
	pcur = phead = NULL;
}