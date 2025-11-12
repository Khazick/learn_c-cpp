#include "slistnode.h"
//
//第 1 题（编程题）
//题目名称：
//1.原地移除数组中所有的元素val，要求时间复杂度为O(N)，空间复杂度为O(1)
//题目内容：
//1.原地移除数组中所有的元素val，要求时间复杂度为O(N)，空间复杂度为O(1)。OJ链接

int removeElement(int* nums, int numsSize, int val) {
	int src = 0;
	int dst = 0;
	while (src < numsSize) {
		if (nums[src] == val) {
			src++;
		}
		else {
			nums[dst++] = nums[src++];
		}
	}
	return dst;
}

//第 2 题（编程题）
//题目名称：
//2.删除排序数组中的重复项
//题目内容：
//2.删除排序数组中的重复项。OJ链接

int removeDuplicates(int* nums, int numsSize) {	
	int dst = 0;
	int src = dst+1;
	while (src<numsSize) {
		if (nums[src] != nums[dst] && src!=dst) {
			nums[++dst] = nums[src];
		}
		src++;
	}
	return dst + 1;
}
//第 3 题（编程题）
//题目名称：
//3.合并两个有序数组
//题目内容：
//3.合并两个有序数组。OJ链接
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
	int l1 = m - 1;
	int l2 = n - 1;
	int l3 = nums1Size - 1;
	while (l1>=0&&l2>=0) {
		if (nums1[l1] < nums2[l2]) {
			nums1[l3--] = nums2[l2--];
		}
		else {
			nums1[l3--] = nums1[l1--];
		}
	}
	while (l2 >= 0) {
		nums1[l3--] = nums2[l2--];
	}
}
SLN* SLN_create() {
	SLN* sln1 = (SLN*)malloc(sizeof(SLN));
	sln1->x = 1;

	SLN* sln2 = (SLN*)malloc(sizeof(SLN));
	sln2->x = 2;

	SLN* sln3 = (SLN*)malloc(sizeof(SLN));
	sln3->x = 3;

	SLN* sln4 = (SLN*)malloc(sizeof(SLN));
	sln4->x = 4;

	sln1->next = sln2;
	sln2->next = sln3;
	sln3->next = sln4;
	sln4->next = NULL;

	SLN* phead = sln1;
	SLN_print(phead);
}
int main() {
	int arr1[] = { 3,2,2,3 };
	int sz1 = sizeof(arr1) / sizeof(arr1[0]);
	removeElement(arr1, sz1, 3);

	int arr2[] = { 1,1,2 };
	int sz2 = sizeof(arr2) / sizeof(arr1[0]);
	removeDuplicates(arr2,sz2);

	int nums1[] = { 4,5,6,0,0,0 };
	int size1 = sizeof(nums1) / sizeof(nums1[0]);
	int nums2[] = { 1,2,3 };
	int size2 = sizeof(nums2) / sizeof(nums2[0]);
	merge(nums1, size1, 3, nums2,size2, 3);

	
	SLN_create();

	return 0;
}