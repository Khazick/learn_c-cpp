#include "stack.h"

void test_stack() {
	Stack st;
	StackInit(&st);
	printf("size: %d\n", StackSize(&st));

	StackPush(&st,1);
	printf("size: %d\n", StackSize(&st));
	StackPush(&st,2);
	printf("size: %d\n", StackSize(&st));
	StackPush(&st,3);
	printf("size: %d\n", StackSize(&st));
	StackPush(&st,4);
	printf("size: %d\n", StackSize(&st));

	printf("top: %d\n", StackTop(&st));
	printf("size: %d\n", StackSize(&st));
	StackPop(&st);
	
	printf("top: %d\n", StackTop(&st));
	printf("size: %d\n", StackSize(&st));
	StackPop(&st);
	printf("top: %d\n", StackTop(&st));
	printf("size: %d\n", StackSize(&st));
	StackPop(&st);
	printf("top: %d\n", StackTop(&st));
	printf("size: %d\n", StackSize(&st));
	StackPop(&st);
	printf("size: %d\n", StackSize(&st));

	//printf("%d\n", StackTop(&st));
	//StackPop(&st);
	StackDestroy(&st);
}
int main() {
	test_stack();
	return 0;
}