#include "seq_list.h"
//第 1 题（编程题）
//题目名称：
//4.旋转数组
//题目内容：
//4.旋转数组。
void print(int* arr,int n) {
	for (int i = 0;i < n;i++)
		printf("%d ", arr[i]);
	printf("\n");
}
void rotate1(int* arr, int sz,int k) {
	k %= sz;
	for (int i = 0;i < k;i++) {
		int tmp = arr[sz - 1];;
		for (int j = sz-1;j > 0;j--) {
			arr[j] = arr[j - 1];
		}
		arr[0] = tmp;
	}
}
void rotate2(int* arr, int sz, int k) {
	k %= sz;
	int* tmp = (int*)malloc(sz*sizeof(int));
	if (!tmp) {
		perror("malloc:");
		exit(1);
	}
	for (int i = 0;i < sz ;i++) {
		tmp[(i+k)%sz] = arr[i];
	}
	for (int i = 0;i < sz;i++) {
		arr[i] = tmp[i];
	}
}
void reversal(int* nums,int left,int right) {
	while (left < right) {
		int tmp = nums[left];
		nums[left] = nums[right];
		nums[right] = tmp;
		left++;
		right--;
	}
}
void rotate(int* nums, int numsSize, int k) {
	k %= numsSize;
	reversal(nums, 0, numsSize - k - 1);
	reversal(nums, numsSize - k,  numsSize-1);
	reversal(nums, 0, numsSize - 1);
}
void test_1() {
	int arr[] = { 1,2,3,4,5,6,7 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	int k = 0;
	scanf("%d", &k);
	//rotate1(arr, sz, k);//时间O(n^2)，空间O(1) 
	//rotate2(arr, sz, k);//时间O(n),空间O(n);
	rotate(arr, sz, k);
	print(arr,sz);
}

//第 2 题（编程题）
//题目名称：
//顺序表的增删查改
//题目内容：
//// SeqList.h
//#pragma once
//#include <stdio.h>
//#include <assert.h>
//#include <stdlib.h>
//typedef int SLDateType;
//typedef struct SeqList
//{
//	SLDateType* a;
//	int size;
//	int capacity;
//}SeqList;
//// 对数据的管理:增删查改 
//void SeqListInit(SeqList* ps);
//void SeqListDestroy(SeqList* ps);
//
//void SeqListPrint(SeqList* ps);
//void SeqListPushBack(SeqList* ps, SLDateType x);
//void SeqListPushFront(SeqList* ps, SLDateType x);
//void SeqListPopFront(SeqList* ps);
//void SeqListPopBack(SeqList* ps);
//
//// 顺序表查找
//int SeqListFind(SeqList* ps, SLDateType x);
//// 顺序表在pos位置插入x
//void SeqListInsert(SeqList* ps, int pos, SLDateType x);
//// 顺序表删除pos位置的值
//void SeqListErase(SeqList* ps, int pos);
void test_seplist1() {
	SL s1;//尾插
	seq_list_init(&s1);
	seq_list_push_back(&s1, 1);
	print_seqlist(&s1);
	seq_list_push_back(&s1, 2);
	print_seqlist(&s1);
	seq_list_push_back(&s1, 3);
	print_seqlist(&s1);
	seq_list_push_back(&s1, 4);
	print_seqlist(&s1);
	seq_list_push_back(&s1, 5);
	print_seqlist(&s1);

	seq_list_pop_front(&s1);
	print_seqlist(&s1);
	seq_list_pop_front(&s1);
	print_seqlist(&s1);
	seq_list_pop_front(&s1);
	print_seqlist(&s1);
	seq_list_pop_front(&s1);
	print_seqlist(&s1);
	seq_list_pop_front(&s1);
	print_seqlist(&s1);

	//seq_list_pop_front(&s1);
	//print_seqlist(&s1);

	seq_list_destroy(&s1);

	SL s2;//头插
	seq_list_init(&s2);
	seq_list_push_front(&s2,1);
	print_seqlist(&s2);
	seq_list_push_front(&s2,2);
	print_seqlist(&s2);
	seq_list_push_front(&s2,3);
	print_seqlist(&s2);
	seq_list_push_front(&s2,4);
	print_seqlist(&s2);
	seq_list_push_front(&s2,5);
	print_seqlist(&s2);

	//尾删
	seq_list_pop_back(&s2);
	print_seqlist(&s2);
	seq_list_pop_back(&s2);
	print_seqlist(&s2);
	seq_list_pop_back(&s2);
	print_seqlist(&s2);
	seq_list_pop_back(&s2);
	print_seqlist(&s2);
	seq_list_pop_back(&s2);
	print_seqlist(&s2);

	//seq_list_pop_back(&s2);
	//print_seqlist(&s2);

	seq_list_destroy(&s2);
}
void test_seplist2() {
	SL s;//尾插
	seq_list_init(&s);

	seq_list_push_back(&s, 1);
	print_seqlist(&s);
	seq_list_push_back(&s, 2);
	print_seqlist(&s);
	//指定位置插入
	seq_list_insert(&s, 0, -1);
	print_seqlist(&s);
	seq_list_insert(&s, 1, 3);
	print_seqlist(&s);
	seq_list_insert(&s, s.size-1, 0);
	print_seqlist(&s);

	//指定位置删除
	seq_list_erase(&s, 2);
	print_seqlist(&s);
	seq_list_erase(&s, 0);
	print_seqlist(&s);
	//seq_list_erase(&s, 0);
	//seq_list_erase(&s, 0);
	//seq_list_erase(&s, 0);
	//seq_list_erase(&s, 0);
	
	//查找
	int input;
	scanf("%d", &input);
	int ret = seq_list_find(&s, input);
	printf("%d\n", ret);

	seq_list_destroy(&s);
}
int main() {
	//test_1();
	//test_seplist1();
	test_seplist2();
	return 0;
}