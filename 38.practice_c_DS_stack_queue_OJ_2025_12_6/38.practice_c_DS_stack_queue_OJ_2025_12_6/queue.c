#include "main.h"

void QueueInit(Queue* q) {
	assert(q);
	q->phead = q->ptail = NULL;
	q->size = 0;
}
void QueuePush(Queue* q, int x) {
	assert(q);
	QueueNode* tmp = (QueueNode*)malloc(sizeof(QueueNode));
	if (!tmp) {
		perror("malloc failed for QueueNode");
		exit(1);
	}
	tmp->val = x;
	tmp->next = NULL;
	if (q->phead == NULL) {
		q->phead = q->ptail = tmp;
	}
	else {
		q->ptail->next = tmp;
		q->ptail = q->ptail->next;
	}
	q->size++;
}
bool QueueEmpty(Queue* q) {
	assert(q);
	return q->phead == NULL;
}
void QueuePop(Queue* q) {
	assert(q);
	assert(!QueueEmpty(q));
	QueueNode* next = q->phead->next;
	free(q->phead);
	q->phead = next;
	if (!q->phead)
		q->ptail = q->phead;
	q->size--;
}
int QueueHead(Queue* q) {
	assert(q);
	assert(!QueueEmpty(q));
	return q->phead->val;
}
int QueueTail(Queue* q) {
	assert(q);
	assert(!QueueEmpty(q));
	return q->ptail->val;
}
int QueueSize(Queue* q) {
	assert(q);
	return q->size;
}
void QueueDestroy(Queue* q) {
	assert(q);
	QueueNode* pcur = q->phead;
	while (pcur) {
		QueueNode* next = pcur->next;
		free(pcur);
		pcur = next;
		q->size--;
	}
	pcur = q->phead = q->ptail = NULL;
}