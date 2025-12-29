#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


//第 1 题（编程题）
//题目名称：
//文件中找TopK问题
//题目内容：
void CreateNDate()
{
	// 造数据
	int n = 10000;
	srand(time(0));
	const char* file = "data.txt";
	FILE* fin = fopen(file, "w");
	if (fin == NULL){
		perror("fopen error");
		return;
	}
	for (size_t i = 0; i < n; ++i){
		int x = rand() % 1000000;
		fprintf(fin, "%d\n", x);
	}
	fclose(fin);
}
void AdjustDown(int* arr, int size, int parent) {
	int child = 2 * parent + 1;
	while (child>0) {


	}
}
void PrintTopK(int k) {

}

void test01() {
	//CreateNDate();
	int k;
	scanf("%d", &k);
	PrintTopK(k);

}

//第 2 题（编程题）
//题目名称：
//堆排序
//题目内容：
void HeapSort(int* a, int n) {

}

int main() {
	test01();

	return 0;
}