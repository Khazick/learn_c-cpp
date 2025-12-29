#include "heap.h"

//第 1 题（编程题）
//题目名称：
//堆的实现
//题目内容：
//typedef int HPDataType;
//typedef struct Heap
//{
//	HPDataType* _a;
//	int _size;
//	int _capacity;
//}Heap;
//
//void HeapInit(HP* php);
//// 堆的销毁
//void HeapDestory(Heap* hp);
//// 堆的插入
//void HeapPush(Heap* hp, HPDataType x);
//// 堆的删除
//void HeapPop(Heap* hp);
//// 取堆顶的数据
//HPDataType HeapTop(Heap* hp);
//// 堆的数据个数
//int HeapSize(Heap* hp);
//// 堆的判空
//int HeapEmpty(Heap* hp);

void test01() {
	HP hp;
	HPInit(&hp);
	int arr[] = { 12,56,20,6,17,29 };
	int size = sizeof(arr) / sizeof(arr[0]);
	for (int i = 0;i < size;i++) {
		HPPush(&hp, arr[i]);
	}
	for (int i = 0;i < size;i++) {
		printf("%d ", HPTop(&hp));
		HPPop(&hp);
	}

	HPDestroy(&hp);
}
int main() {
	test01();
	return 0;
}