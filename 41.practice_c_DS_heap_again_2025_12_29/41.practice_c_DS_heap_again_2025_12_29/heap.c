#include "heap.h"

void HPInit(HP* php) {
	assert(php);
	php->arr = NULL;
	php->size = php->capacity = 0;
}
void HPDestroy(HP* php) {
	assert(php);
	if (php->arr)
		free(php->arr);
	php->arr = NULL;
	php->size = php->capacity = 0;
}
void Swap(HPDataType* x, HPDataType* y) {
	HPDataType tmp = *x;
	*x = *y;
	*y = tmp;
}
void AdjustUp(HP* php,int child) {
	assert(php->arr);
	int parent = (child - 1) / 2;
	while (child > 0) {
		//建立小堆，从下向上调整，把小的调到上面。
		//建立大队则相反，arr[parent]<arr[child]
		if (php->arr[parent] > php->arr[child]) {
			Swap(&php->arr[parent], &php->arr[child]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else {
			break;
		}
	}
}
void HPPush(HP* php, HPDataType x) {
	assert(php);
	//判断是否扩容
	if (php->size == php->capacity) {
		int newcapacity = php->capacity == 0 ? 4 : 2 * php->capacity;
		HPDataType* tmp = (HPDataType*)realloc(php->arr, newcapacity * sizeof(HPDataType));
		if (!tmp) {
			perror("realloc fail!");
			exit(1);
		}
		php->arr = tmp;
		php->capacity = newcapacity;
	}
	php->arr[php->size] = x;
	AdjustUp(php, php->size);//建立小堆
	php->size++;
}
void AdjustDown(HP* php, int parent, int n) {
	assert(php);
	int child = parent * 2 + 1;
	while (child < n) {
		if (php->arr[child] > php->arr[child + 1]) {//小堆的向下调整，将最小的子节点与父结点交换
			child++;
		}
		if (child + 1 <= n && php->arr[parent] > php->arr[child]) {
			Swap(&php->arr[parent], &php->arr[child]);
			parent = child;
			child = parent * 2 + 1;
		}
		else {
			break;
		}
	}
}

void HPPop(HP* php) {
	assert(php && php->size);
	Swap(&php->arr[0], &php->arr[php->size - 1]);
	php->size--;
	AdjustDown(php,0,php->size);
}
bool HPEmpty(HP* php) {
	assert(php);
	return php->size == 0;
}
int HPSize(HP* php) {
	assert(php);
	return php->size;
}

HPDataType HPTop(HP* php) {
	assert(php);
	return php->arr[0];
}
