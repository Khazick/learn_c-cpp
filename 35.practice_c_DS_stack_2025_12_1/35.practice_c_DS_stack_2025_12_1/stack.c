#include "stack.h"

void StackInit(Stack* st) {
	assert(st);
	st->capacity = st->top = 0;
	st->arr = NULL;
}

void StackPush(Stack* st, Datatype x) {
	assert(st);
	if (st->capacity == st->top) {
		int newcapacity = st->capacity == 0 ? 4 : 2 * st->capacity;
		Datatype* newarr = (Datatype*)realloc(st->arr, newcapacity * sizeof(Datatype));
		assert(newarr);
		st->arr = newarr;
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

Datatype StackTop(Stack* st) {
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
	if(st->arr)
		free(st->arr);
	st->arr = NULL;
	st->top = st->capacity = 0;
}
