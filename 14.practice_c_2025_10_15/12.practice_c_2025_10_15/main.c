#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <assert.h>

//第 3 题（编程题）
//题目名称：
//字符串逆序
//题目内容：
//写一个函数，可以逆序一个字符串的内容。
void swop(char* p) {
	char* str = p;
	int start = 0;
	int end = strlen(p) - 1;
	while (start<end) {
		char t = *(p + start);
		*(p + start) = *(p + end);
		*(p + end) = t;
		start++;
		end--;
	}
}
int main1() {
	char arr[10000] = { 0 };
	gets(arr);
	swop(arr);
	printf("%s", arr);
	return 0;
}
//参考答案
void Reverse(char* str)
{
	char* left = str;
	char* right = str + strlen(str) - 1;
	while (left < right)
	{
		char temp = *left;
		*left = *right;
		*right = temp;
		++left;
		--right;
	}
}
int main01()
{
	char str[101] = { 0 };
	while (gets(str))
	{
		Reverse(str);
		printf("%s\n", str);
		memset(str, 0, sizeof(str) / sizeof(str[0]));
	}
	return 0;
}
//第 11 题（编程题）
//题目名称：
//字符串左旋
//题目内容：
//实现一个函数，可以左旋字符串中的k个字符。
//例如：
//ABCD左旋一个字符得到BCDA
//ABCD左旋两个字符得到CDAB
void revolve(char* p,int n) {
	while (n--) {
		for (int i = 0;i < strlen(p) - 1;i++) {
			char t = *(p + i);
			*(p + i) = *(p + i + 1);
			*(p + i + 1) = t;
		}
	}
}
int main2() {
	char arr[] = { "ABCD" };
	int k = 0;
	scanf("%d", &k);
	printf("左旋%d个字符前：%s\n",k, arr);
	revolve(arr, k);
	printf("左旋%d个字符后：%s\n",k, arr);

	return 0;
}
//参考答案
//先将要左旋的前三个家伙逆序（CBADEFG），然后将后半段也逆序（CBAGFED），最后整体逆序（DEFGABC）即可。
//这样只需要做数值交换即可，可以写一个函数帮我们完成局部逆序，代码如下：
void reverse_part(char* str, int start, int end) //将字符串从start到end这一段逆序
{
	int i, j;
	char tmp;
	for (i = start, j = end; i < j; i++, j--)
	{
		tmp = str[i];
		str[i] = str[j];
		str[j] = tmp;
	}
}
void leftRound(char* src, int time)
{
	int len = strlen(src);
	int pos = time % len;
	reverse_part(src, 0, pos - 1); //逆序前段
	reverse_part(src, pos, len - 1); //逆序后段
	reverse_part(src, 0, len - 1); //整体逆序
}
int main02() {
	char arr[] = "ABCDEFG";
	int k = 0;
	scanf("%d", &k);
	printf("左旋%d个字符前：%s\n", k, arr);
	leftRound(arr, k);
	printf("左旋%d个字符后：%s\n", k, arr);
	return 0;
}
//第 12 题（编程题）
//题目名称：
//strlen实现
//题目内容：
//模拟实现库函数strlen
//法1
size_t simu_strlen1(const char* p) {
	assert(p);
	int count = 0;
	while (*p) {
		p++;
		count++;
	}
	return count;
}
//法2
size_t simu_strlen2(char* p) {
	char* r = p;
	while (*r)
		r++;
	return r - p;
}
int main3() {
	char arr[] = "ABCDE01234";
	printf("%zd\n", simu_strlen1(arr));	
	printf("%zd\n", simu_strlen2(arr));

	return 0;
}

//第 13 题（编程题）
//题目名称：
//调整奇数偶数顺序
//题目内容：
//调整数组使奇数全部都位于偶数前面。

//题目：
//输入一个整数数组，实现一个函数，
//来调整该数组中数字的顺序使得数组中所有的奇数位于数组的前半部分，
//所有偶数位于数组的后半部分。
void split_odd_even(int* p,int n) {
	for (int i = 0;i < n;i++) {
		int a = 1;
		while(p[i] % 2 == 0 && a < n) {
			int t = p[i];
			if (p[i + a] % 2 != 0) {
				p[i] = p[i + a];
				p[i + a] = t;
			}
			else
				a++;
		}	
	}
}
int main4() {
	int arr[10] = { 0,1,2,3,4,5,6,7,8,9 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	for (int i = 0;i < sz-1;i++)
		scanf("%d ", &arr[i]);
	split_odd_even(arr,sz-1);
	for (int i = 0;i < sz;i++)
		printf("%d ", arr[i]);
	return 0;
}
//参考答案
//思路：
//1. 给定两个下标left和right，left放在数组的起始位置，right放在数组中最后一个元素的位置
//2. 循环进行一下操作
//a.如果left和right表示的区间[left, right]有效，进行b，否则结束循环
//b.left从前往后找，找到一个偶数后停止
//c.right从后往前找，找到一个奇数后停止
//d.如果left和right都找到了对应的数据，则交换，继续a，
void swap_arr(int* p, int n) {
	int left = 0;
	int right = n - 1;
	int t = 0;
	while (left < right) {
		while (left < right && (p[left] % 2 == 1))
			left++;
		while (left < right && (p[right] % 2 == 0))
			right--;
		if (left < right) {
			t = p[left];
			p[left] = p[right];
			p[right] = t;
		}
	}
}
int main() {
	int arr[10] = { 0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	for (int i = 0;i < sz - 1;i++)
		scanf("%d ", &arr[i]);
	swap_arr(arr, sz);
	for (int i = 0;i < sz;i++)
		printf("%d ", arr[i]);
	return 0;
}