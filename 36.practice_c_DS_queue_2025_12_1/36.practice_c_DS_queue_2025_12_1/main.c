#include "queue.h"

void test_queue1() {
	Queue qnode;
	QueueInit(&qnode);
	QueuePush(&qnode, 1);
	printf("head = %d tail = %d size = %d\n", QueueHead(&qnode), QueueTail(&qnode), QueueSize(&qnode));
	QueuePush(&qnode, 2);
	printf("head = %d tail = %d size = %d\n", QueueHead(&qnode), QueueTail(&qnode), QueueSize(&qnode));
	QueuePush(&qnode, 3);
	printf("head = %d tail = %d size = %d\n", QueueHead(&qnode), QueueTail(&qnode), QueueSize(&qnode));
	QueuePush(&qnode, 4);

	printf("head = %d tail = %d size = %d\n", QueueHead(&qnode), QueueTail(&qnode), QueueSize(&qnode));
	QueuePop(&qnode);
	printf("head = %d tail = %d size = %d\n", QueueHead(&qnode), QueueTail(&qnode), QueueSize(&qnode));
	QueuePop(&qnode);
	printf("head = %d tail = %d size = %d\n", QueueHead(&qnode), QueueTail(&qnode), QueueSize(&qnode));
	QueuePop(&qnode);
	printf("head = %d tail = %d size = %d\n", QueueHead(&qnode), QueueTail(&qnode), QueueSize(&qnode));
	QueuePop(&qnode);

	//printf("head = %d tail = %d size = %d\n", QueueHead(&qnode), QueueTail(&qnode), QueueSize(&qnode));
	//QueuePop(&qnode);
	QueueDestroy(&qnode);
}
void test_queue2() {
	Queue qnode;
	QueueInit(&qnode);
	QueuePush(&qnode, 1);
	QueuePush(&qnode, 2);	
	QueuePush(&qnode, 3);	
	QueuePush(&qnode, 4);
	QueueDestroy(&qnode);
}

int main() {
	test_queue1();
	test_queue2();
	return 0;
}