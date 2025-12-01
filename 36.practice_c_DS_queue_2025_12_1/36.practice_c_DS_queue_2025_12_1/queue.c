#include "queue.h"

void QueueInit(Queue* qnode) {
	assert(qnode);
	qnode->phead = qnode->ptail = NULL;
	qnode->size = 0;
}

void QueuePush(Queue* qnode, DataType x) {
	assert(qnode);
	QueueNode* tmp = (QueueNode*)malloc(sizeof(QueueNode));
	assert(tmp);
	tmp->val = x;
	tmp->next = NULL;
	if (qnode->phead == NULL && qnode->ptail == NULL) {
		qnode->phead = qnode->ptail = tmp;
	}
	else {
		qnode->ptail->next = tmp;
		qnode->ptail = qnode->ptail->next;
	}
	qnode->size++;
}
bool QueueEmpty(Queue* qnode) {
	assert(qnode);
	return (qnode->phead == NULL) && (qnode->ptail == NULL);
}
void QueuePop(Queue* qnode) {
	assert(qnode);
	assert(!QueueEmpty(qnode));
	Queue* next = qnode->phead->next;
	free(qnode->phead);
	qnode->phead = next;
	if (!qnode->phead)
		qnode->ptail = qnode->phead;
	qnode->size--;
}
DataType QueueHead(Queue* qnode) {
	assert(qnode);
	assert(!QueueEmpty(qnode));
	return qnode->phead->val;
}
DataType QueueTail(Queue* qnode) {
	assert(qnode);
	assert(!QueueEmpty(qnode));
	return qnode->ptail->val;
}
int QueueSize(Queue* qnode) {
	assert(qnode);
	return qnode->size;
}
void QueueDestroy(Queue* qnode) {
	assert(qnode);
	QueueNode* pcur = qnode->phead;
	while (pcur) {
		QueueNode* next = pcur->next;
		free(pcur);
		pcur = next;
		qnode->size--;
	}
	pcur = qnode->ptail = qnode->phead = NULL;
}