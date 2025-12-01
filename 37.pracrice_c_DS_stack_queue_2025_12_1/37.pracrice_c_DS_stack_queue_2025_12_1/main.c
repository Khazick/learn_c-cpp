#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>

//作业标题
//1.括号匹配问题
//
//作业内容
//1.括号匹配问题。OJ链接
typedef char Datatype;
typedef struct Stack {
	Datatype* arr;
	int top;
	int capacity;
}Stack;
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
	return st->arr[st->top - 1];
}

int StackSize(Stack* st) {
	assert(st);
	return st->top;
}

void StackDestroy(Stack* st) {
	assert(st);
	if (st->arr)
		free(st->arr);
	st->arr = NULL;
	st->top = st->capacity = 0;
}

bool isValid(char* s) {
	assert(s);
	Stack ps;
	StackInit(&ps);
	int i = 0;
	while (s[i] != '\0') {
		if (s[i] == '{' || s[i] == '[' || s[i] == '(') {
			StackPush(&ps, s[i]);
		}
		else if (s[i] == '}' || s[i] == ']' || s[i] == ')') {
			if (!ps.top) {
				StackDestroy(&ps);
				return false;
			}
			if (StackTop(&ps) == '{' && s[i] !='}' 
				|| StackTop(&ps) == '[' && s[i] != ']' 
				|| StackTop(&ps) == '(' && s[i] != ')') {
				StackDestroy(&ps);
				return false;
			}
			StackPop(&ps);				
		}
		i++;
	}
	if (ps.top) {
		StackDestroy(&ps);
		return false;
	}
	StackDestroy(&ps);
	return true;
}

void test() {
	char s[] = "]" ;
	bool ret = isValid(s);
	if (ret)
		printf("true\n");
	else
		printf("false\n");
}
int main() {
	test();
	return 0;
}