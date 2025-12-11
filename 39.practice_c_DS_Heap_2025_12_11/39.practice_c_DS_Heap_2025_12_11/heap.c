#include "heap.h"

//小堆
//初始化
void HeapInit(Heap* php) {
	assert(php);
	php->arr = NULL;
	php->size = php->capacity = 0;
}
//销毁
void HeapDestroy(Heap* php) {
	assert(php);
	if (php->arr)
		free(php->arr);
	php->arr = NULL;
	php->size = php->capacity = 0;
}
void Swap(DataType* x, DataType* y) {
	DataType tmp = *x;
	*x = *y;
	*y = tmp;
}
//向上调整
void HeapAdjustUp(DataType* arr, int child) {
	int parent = (child - 1) / 2;
	while (child > 0) {
		if (arr[child] < arr[parent]) {
			//交换
			Swap(&arr[child], &arr[parent]);
			//前往上一层
			child = parent;
			parent = (child - 1) / 2;
		}
		else {
			break;
		}
	}

}
//插入
void HeapPush(Heap* php, DataType x) {
	assert(php);
	//判空
	if (php->size == php->capacity) {
		int newcapacity = php->capacity == 0 ? 4 : 2 * php->capacity;
		DataType* tmp = (DataType*)realloc(php->arr, sizeof(DataType) * newcapacity);
		if (!tmp) {
			perror("realloc fail!");
			exit(1);
		}
		php->arr = tmp;
		php->capacity = newcapacity;
	}
	php->arr[php->size] = x;
	//向上调整
	HeapAdjustUp(php->arr,php->size);
	php->size++;
}
//向下调整
void HeapAdjustDown(DataType* arr, int parent, int size) {
	int child = parent * 2 + 1;
	while (child < size) {
		//找最小孩子
		if (child + 1 < size && arr[child] > arr[child + 1]) {
			child++;
		}
		//交换父子
		if (arr[parent] > arr[child]) {
			Swap(&arr[parent], &arr[child]);
			parent = child;
			child = parent * 2 + 1;
		}
		else {
			break;
		}
	}
}
//删除
void HeapPop(Heap* php) {
	assert(php && php->size);
	//删除堆顶
	//将最后一个叶子节点和根节点互换
	Swap(&php->arr[0], &php->arr[php->size - 1]);
	php->size--;
	//向下调整;
	HeapAdjustDown(php->arr,0,php->size);
}

//取堆顶元素
DataType HeapTop(Heap* php) {
	assert(php&&php->size);
	return php->arr[0];
}
//判空
bool HeapEmpty(Heap* php) {
	assert(php);
	return php->size == 0;
}