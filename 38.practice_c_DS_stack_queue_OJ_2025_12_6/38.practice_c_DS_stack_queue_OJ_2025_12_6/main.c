#include "main.h"

//⽤队列实现栈
typedef struct {
	Queue Q1;
	Queue Q2;
}MyStack;

//初始化
MyStack* myStackCreate() {
	MyStack* pst = (MyStack*)malloc(sizeof(MyStack));
	if (pst == NULL) {
		perror("malloc failed for MyStack");
		exit(1);
	}
	QueueInit(&pst->Q1);
	QueueInit(&pst->Q2);
	return pst;
}

void myStackPush(MyStack* obj, int x) {
	assert(obj);
	if (!QueueEmpty(&obj->Q1)) {
		QueuePush(&obj->Q1, x);
	}
	else {
		QueuePush(&obj->Q2, x);
	}
}

int myStackPop(MyStack* obj) {
	assert(obj);
	Queue* EQ = &obj->Q1;
	Queue* NQ = &obj->Q2;
	if (!QueueEmpty(&obj->Q1)) {
		EQ = &obj->Q2;
		NQ = &obj->Q1;
	}
	while (QueueSize(NQ) > 1) {
		QueuePush(EQ, QueueHead(NQ));
		QueuePop(NQ);
	}
	int ret = QueueHead(NQ);
	QueuePop(NQ);
	return ret;
}

int myStackTop(MyStack* obj) {
	assert(obj);
	if (!QueueEmpty(&obj->Q1)) 
		return QueueTail(&obj->Q1);
	else
		return QueueTail(&obj->Q2);
}

bool myStackEmpty(MyStack* obj) {
	assert(obj);
	return QueueEmpty(&obj->Q1) && QueueEmpty(&obj->Q2);
}

void myStackFree(MyStack* obj) {
	assert(obj);
	QueueDestroy(&obj->Q1);
	QueueDestroy(&obj->Q2);
	free(obj);
	obj = NULL;
}
void test1() {
	printf("test1():\n");
	MyStack* p1 = myStackCreate();
	myStackPush(p1, 1);
	myStackPush(p1, 2);
	printf("%d\n", myStackTop(p1));
	myStackPop(p1);
	bool ret = myStackEmpty(p1);
	if (ret)
		printf("true\n");
	else
		printf("false\n");
	myStackFree(p1);
}


//用栈实现队列
typedef struct {
	Stack StPush;
	Stack StPop;
}MyQueue;

MyQueue* myQueueCreate() {
	MyQueue* pst = (MyQueue*)malloc(sizeof(MyQueue));
	if (!pst) {
		perror("malloc fail!");
		exit(1);
	}
	StackInit(&pst->StPop);
	StackInit(&pst->StPush);
	return pst;
}

void myQueuePush(MyQueue* obj, int x) {
	assert(obj);
	StackPush(&obj->StPush, x);
}

int myQueuePop(MyQueue* obj) {
	assert(obj);
	if (StackEmpty(&obj->StPop)) {
		while (!StackEmpty(&obj->StPush)){
			StackPush(&obj->StPop, StackTop(&obj->StPush));
			StackPop(&obj->StPush);
		}
	}
	int ret = StackTop(&obj->StPop);
	StackPop(&obj->StPop);
	return ret;
}
//取队头-栈顶元素
int myQueuePeek(MyQueue* obj) {
	assert(obj);
	if (StackEmpty(&obj->StPop)) {
		while (!StackEmpty(&obj->StPush)) {
			StackPush(&obj->StPop, StackTop(&obj->StPush));
			StackPop(&obj->StPush);
		}
	}
	return StackTop(&obj->StPop);
}

bool myQueueEmpty(MyQueue* obj) {
	assert(obj);
	return StackEmpty(&obj->StPop)&&StackEmpty(&obj->StPush);
}

void myQueueFree(MyQueue* obj) {
	assert(obj);
	StackDestroy(&obj->StPush);
	StackDestroy(&obj->StPop);
	free(obj);
	obj = NULL;
}
void test2() {
	printf("test2():\n");
	MyQueue* q1 = myQueueCreate();
	myQueuePush(q1, 1);
	myQueuePush(q1, 2);
	printf("%d\n", myQueuePeek(q1));
	myQueuePop(q1);
	bool ret = myQueueEmpty(q1);
	if (ret)
		printf("true\n");
	else
		printf("false\n");
	myQueueFree(q1);
}

//设计循环队列
typedef struct {
	int* arr;
	int head;
	int tail;
	int capacity;
} MyCircularQueue;


MyCircularQueue* myCircularQueueCreate(int k) {
	MyCircularQueue* pst = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
	if (!pst) {
		perror("malloc fail!");
		exit(1);
	}
	pst->arr = (int*)malloc(sizeof(int) * (k + 1));
	if (!pst->arr) {
		perror("malloc fail!");
		exit(1);
	}
	pst->head = pst->tail = 0;
	pst->capacity = k;
	return pst;
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
	assert(obj);
	return obj->head == (obj->tail + 1) % (obj->capacity + 1);
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
	assert(obj);
	return obj->tail == obj->head;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
	assert(obj);
	if (myCircularQueueIsFull(obj)) 
		return false;
	obj->arr[obj->tail++] = value;
	obj->tail %= obj->capacity + 1;
	return true;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
	assert(obj);
	if (myCircularQueueIsEmpty(obj)) 
		return false;
	obj->head++;
	obj->head %= obj->capacity + 1;
	return true;
}

int myCircularQueueFront(MyCircularQueue* obj) {
	assert(obj);
	if (myCircularQueueIsEmpty(obj)) 
		return -1;
	return obj->arr[obj->head];
}

int myCircularQueueRear(MyCircularQueue* obj) {
	assert(obj);
	if (myCircularQueueIsEmpty(obj)) 
		return -1;
	int prev = obj->tail - 1;
	if (obj->tail == 0) 
		prev = obj->capacity;
	return obj->arr[prev];
}

void myCircularQueueFree(MyCircularQueue* obj) {
	assert(obj);
	free(obj->arr);
	free(obj);
	obj = NULL;
}
void PrintBool(bool a) {
	if (a)
		printf("true\n");
	else
		printf("false\n");
}
void test3() {
	printf("test3():\n");
	MyCircularQueue* cq = myCircularQueueCreate(3);
	PrintBool(myCircularQueueEnQueue(cq, 1));
	PrintBool(myCircularQueueEnQueue(cq, 2));
	PrintBool(myCircularQueueEnQueue(cq, 3));
	PrintBool(myCircularQueueEnQueue(cq, 4));
	printf("%d\n", myCircularQueueRear(cq));
	PrintBool(myCircularQueueIsFull(cq));
	PrintBool(myCircularQueueDeQueue(cq));
	PrintBool(myCircularQueueEnQueue(cq, 4));
	printf("%d\n", myCircularQueueRear(cq));
}
int main() {
	test1();
	test2();
	test3();
	return 0;
}