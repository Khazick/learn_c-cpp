#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//
//第 7 题（编程题）
//题目名称：
//课堂中转移表代码实践
//题目内容：
//将课堂上所讲使用函数指针数组实现转移表的代码，自己实践后，并提交代码到答案窗口。
void menu() {
	printf("*****************\n");
	printf("****  1.add  ****\n");
	printf("****  2.sub  ****\n");
	printf("****  3.mul  ****\n");
	printf("****  4.div  ****\n");
	printf("****  0.exit ****\n");
	printf("*****************\n");
}
int add(int x, int y) {
	return x + y;
}
int sub(int x, int y) {
	return x - y;
}
int mul(int x, int y) {
	return x * y;
}
int div(int x, int y) {
	return x / y;
}
int main1() {
	int input = 1;
	int x, y;
	do {
		menu();
		printf("请输入:");
		int (*p[5])(int, int) = { 0,add,sub,mul,div };
		scanf("%d", &input);
		if (input >= 1 && input <= 4) {
			scanf("%d %d", &x, &y);
			int ret = (*p[input])(x, y);
			printf("%d\n", ret);
		}
		else if (input == 0)
			printf("退出\n");
		else
			printf("重新输入\n");
	} while (input);
	return 0;
}

//第 10 题（编程题）
//题目名称：
//找单身狗2
//题目内容：
//一个数组中只有两个数字是出现一次，其他所有数字都出现了两次。
//编写一个函数找出这两个只出现一次的数字。
//例如：
//有数组的元素是：1，2，3，4，5，1，2，3，4，6
//只有5和6只出现1次，要找出5和6.
void find_two_dog(int arr1[], int arr2[], int n) {
	int a = 0;
	for (int i = 0;i < n;i++) 
		a ^= arr1[i];
	int b = 0;
	for (int i = 0;i < 32;i++) {
		if (a & 1 << i) {
			b = i;
			break;
		}
	}
	for (int i = 0;i < n;i++) {
		if (arr1[i] & 1 << b)
			arr2[0] ^= arr1[i];
		else
			arr2[1] ^= arr1[i];
	}
}
int main2() {
	int arr1[10] = { 0 };
	int arr2[2] = { 0 };
	int sz = sizeof(arr1) / sizeof(arr1[0]);
	for (int i = 0;i < sz;i++) {
		scanf("%d", &arr1[i]);
	}
	find_two_dog(arr1, arr2, sz);
	for (int i = 0;i < 2;i++)
		printf("%d ", arr2[i]);
	return 0;
}

//参考答案
void findTwoNum(int arr[], int n, int* pnum1, int* pnum2)
{
	int i;
	int sum = 0;
	for (i = 0; i < 9; i++)
	{
		sum ^= arr[i];
	} //先找到两个数互相异或的结果	​
	int pos;
	for (i = 0; i < 32; i++)
	{
		if (sum & 1 << i)
		{
			pos = i;
			break;
		}
	} //再找到有分歧的一位。在这一位上，两个数一定是一个1一个0	​
	* pnum1 = *pnum2 = 0;
	for (i = 0; i < 10; i++)
	{
		if (arr[i] & 1 << pos)
		{
			*pnum1 ^= arr[i]; //这一位是1的，放在数1里
		}
		else
		{
			*pnum2 ^= arr[i]; //这一位是0的，放在数2里
		}
	}
}
//第 11 题（编程题）
//题目名称：
//BC54 - 获得月份天数
//题目内容：
//BC54 - 获得月份天数
int judge_year(int year) {
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
		return 1;
	else
		return 0;
}
void print_year_month(int* nm, int* lm, int n,int m) {
	if (n)
		printf("%d\n", lm[m]);
	else
		printf("%d\n", nm[m]);
}
int main3() {
	int noleap_month[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	int leap_month[13] = { 0,31,29,31,30,31,30,31,31,30,31,30,31 };
	int year, month;
	while (scanf("%d %d", &year, &month) != EOF) {
		int ret = judge_year(year);
		print_year_month(noleap_month, leap_month, ret, month);
	}
	return 0;
}
//参考答案
int main03()
{
	int y = 0;
	int m = 0;
	int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	while (scanf("%d%d", &y, &m) != EOF)
	{
		int day = days[m - 1];
		if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0))
		{
			if (m == 2)
				day += 1;
		}
		printf("%d\n", day);
	}
	return 0;
}
void test1(int arr[2][3],int x,int y) {
	;
}
void test2(int (*p)[3], int x, int y) {
	;
}
typedef int(*iarr_t)[3];
typedef void (*varr_t)(iarr_t, int, int);
int main() {
	//二维数组传参本质
	int arr[2][3] = { 0 };
	test1(arr, 2, 3);
	test2(arr, 2, 3);

	//函数指针变量
	printf("%p\n", test1);
	printf("%p\n", &test1);//完全等价

	void (*pa1)(int(*)[3], int, int) = test1;
	void (*pa2)(iarr_t, int, int) = test1;//typedef改名
	varr_t pa3 = test1;

	int (*padd)(int, int) = add;
	printf("%d\n", padd(1, 2));
	
	//函数指针数组
	int (*parr[2])(int,int) = { add,sub };
	printf("%d\n", (*parr[0])(1, 2));
	printf("%d\n", (*parr[1])(3, 1));

	return 0;
}