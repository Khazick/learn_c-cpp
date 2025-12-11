#include "heap.h"

void test01() {
	Heap hp;
	HeapInit(&hp);
	int arr[] = { 57,12,36,18,9,0 };
	for (int i = 0;i < 6;i++) {
		HeapPush(&hp, arr[i]);
	}
	while (!HeapEmpty(&hp)) {
		printf("%d ", HeapTop(&hp));
		HeapPop(&hp);
	}
	HeapDestroy(&hp);
}
int main() {
	test01();
	return 0;
}