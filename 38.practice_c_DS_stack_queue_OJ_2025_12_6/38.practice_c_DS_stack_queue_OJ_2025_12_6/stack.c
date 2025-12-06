#include "main.h"

void StackInit(Stack* st) {
	assert(st);
	st->top = st->capacity = 0;
	st->arr = NULL;
}
void StackPush(Stack* st, int x) {
	assert(st);
	if (st->top == st->capacity) {
		int newcapacity = st->capacity == 0 ? 4 : 2 * st->capacity;
		int* tmp = (int*)realloc(st->arr, sizeof(int) * newcapacity);
		if (!tmp) {
			perror("malloc failed for realloc");
			exit(1);
		}
		st->arr = tmp;
		st->capacity = newcapacity;
	}
	st->arr[st->top++] = x;
}
bool StackEmpty(Stack* st) {
	assert(st);
	return st->top == 0;
}
void StackPop(Stack* st) {
	assert(st);
	assert(!StackEmpty(st));
	st->top--;
}
int StackTop(Stack* st) {
	assert(st);
	assert(!StackEmpty(st));
	return st->arr[st->top-1];
}
int StackSize(Stack* st) {
	assert(st);
	return st->top;
}
void StackDestroy(Stack* st) {
	assert(st);
	if (st->arr) {
		free(st->arr);
	}
	st->arr = NULL;
	st->top = st->capacity = 0;
}