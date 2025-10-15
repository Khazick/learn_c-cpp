#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>


//第 4 题（编程题）
//题目名称：
//BC68 - X形图案
//题目内容：
//BC68 - X形图案
int main1() {
	int a = 0;
	char star[20][20] = {0};
	while (scanf("%d", &a)!=EOF) {
		int left = 0;
		int right = a - 1;
		for (int i = 0;i < a;i++) {
			for (int j = 0;j < a;j++) {
				star[i][j] = ' ';
			}
		}
		for (int i = 0;i < a;i++) {
			star[i][left++] = '*';
			star[i][right--] = '*';
		}
		for (int i = 0;i < a;i++) {
			for (int j = 0;j < a;j++) {
				printf("%c", star[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}
//答案提供的思路：
int main01()
{
	int n = 0;
	while (scanf("%d", &n) != EOF)
	{
		int i = 0;
		int j = 0;
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				if (i == j)
					printf("*");
				else if (i + j == n - 1)//因为行和列是从0开始的
					printf("*");
				else
					printf(" ");
			}
			printf("\n");
		}
	}
	return 0;
}
//
//第 5 题（编程题）
//题目名称：
//BC69 - 空心正方形图案
//题目内容：
//BC69 - 空心正方形图案
int main2() {
	int a = 0;
	while (scanf("%d", &a) != EOF) {
		int left = 0;
		int right = a - 1;
		for (int i = 0;i < a;i++) {
			for (int j = 0;j < a;j++) {
				if (i == 0 || i == a - 1)
					printf("* ");
				else if (j == 0 || j == a - 1)
					printf("* ");
				else
					printf("  ");
			}
			printf("\n");
		}
	}
	return 0;
}

//第 6 题（编程题）
//题目名称：
//【二维数组】BC107 - 矩阵转置
//题目内容：
//BC107 - 矩阵转置
int main3() {
	int a = 0;
	int b = 0;
	while (scanf("%d %d", &a, &b) != EOF) {
		int arr[100][100] = { 0 };
		for (int i = 0;i < a;i++) {
			for (int j = 0;j < b;j++)
				scanf("%d", &arr[i][j]);
		}
		for (int i = 0;i < b;i++) {
			for (int j = 0;j < a;j++)
				printf("%d ", arr[j][i]);
			printf("\n");
		}
	}
	return 0;
}
//答案思路，由于vs2022不支持变长数组，所以无法在vs上运行
//int main03()
//{
//	int n = 0;
//	int m = 0;
//	scanf("%d%d", &n, &m);
//	int a[n][m];
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < n; i++)
//	{
//		for (j = 0; j < m; j++)
//		{
//			scanf("%d", &a[i][j]);
//		}
//	}
//	//转置
//	for (i = 0; i < m; i++)//3
//	{
//		for (j = 0; j < n; j++)//2
//		{
//			printf("%d ", a[j][i]);
//		}
//		printf("\n");
//	}
//	return 0;
//}

//第 7 题（编程题）
//题目名称：
//【一维数组】BC92 - 逆序输出
//题目内容：
//BC92 - 逆序输出
int main4() {
	int arr[10] = { 0 };
	for (int i = 0;i < 10;i++)
		scanf("%d", &arr[i]);
	for (int i = 9;i >= 0;i--)
		printf("%d ", arr[i]);
	return 0;
}

//
//第 8 题（编程题）
//题目名称：
//【一维数组】BC100 - 有序序列合并
//题目内容：
//BC100 - 有序序列合并
int main5() {
	int a = 0;
	int b = 0;
	scanf("%d %d", &a, &b);
	int arr1[1000] = { 0 };
	int arr2[1000] = { 0 };
	for (int i = 0;i < a;i++)
		scanf("%d", &arr1[i]);
	for (int i = 0;i < b;i++)
		scanf("%d", &arr2[i]);
	int i = 0;
	int j = 0;
	while (i < a && j < b) {
		if (arr1[i] <= arr2[j])
			printf("%d ", arr1[i++]);
		else if (arr1[i] > arr2[j])
			printf("%d ", arr2[j++]);
	}
	while (i < a || j < b) {
		if (i < a)
			printf("%d ", arr1[i++]);
		else
			printf("%d ", arr2[j++]);
	}
	return 0;
}
//
//第 9 题（编程题）
//题目名称：
//【一维数组】输入10个整数，求平均值
//题目内容：
//编写一个程序，从用户输入中读取10个整数并存储在一个数组中。然后，计算并输出这些整数的平均值。
int main6() {
	int arr[10] = { 0 };
	for (int i = 0;i < 10;i++) {
		scanf("%d", &arr[i]);
	}
	int a = 0;
	for (int i = 0;i < 10;i++) {
		a += arr[i];
	}
	printf("%f", a / 10.0);
	return 0;
}
//参考答案，更简化
int main06() {
	int numbers[10];
	int sum = 0;
	// 读取用户输入的整数并存储到数组中
	for (int i = 0; i < 10; i++) {
		scanf("%d", &numbers[i]);
		sum += numbers[i];
	}
	double average = (double)sum / 10;
	printf("平均值为：%lf\n", average);
	return 0;
}

//第 10 题（编程题）
//题目名称：
//【一维数组】交换数组
//题目内容：
//将数组A中的内容和数组B中的内容进行交换。（数组一样大）
int main7() {
	int arr1[] = { 1,2,3,4,5 };
	int arr2[] = { 6,7,8,9,0 };
	int sz = sizeof(arr1) / sizeof(arr1[0]);
	for (int i = 0;i < sz;i++) {
		int tmp = arr1[i];
		arr1[i] = arr2[i];
		arr2[i] = tmp;
	}
	return 0;
}

int main() {
	//1.二维数组
	//定义 初始化
	int arr[2][3];
	char ch[1][2];
	float f[2][2];
	int arr1[][3] = { 0 };//初始化 行可以省。列不能省
	int arr2[2][3] = { 1,2,3,4,5,6 };//初始化中为行列数，下标数在其基础上-1
	int arr3[2][3] = { {1,2,3},{4,5,6} };
	printf("%d\n", arr2[1][2]);//二位数组下标同一维数组，都是从0开始
	//输入输出
	for (int i = 0;i < 2;i++) {
		for (int j = 0; j < 3; j++)
			scanf("%d", &arr[i][j]);
	}
	for (int i = 0;i < 2;i++) {
		for (int j = 0; j < 3; j++)
			printf("%d ", arr[i][j]);
		printf("\n");
	}
	for (int i = 0;i < 2;i++) {
		for (int j = 0; j < 3; j++)
			printf("%p\n", &arr2[i][j]);//二位数组地址也同一维数组一样，是连续的
	}

	//int n = 1 + 2;
	//int arr4[n];//变长数组，因为只有运行时才能确定长度，所以不能初始化。
	//vs不支持变长数组

	//2.数组练习
	//多个字符从两端移动，向中间汇聚
	char ch1[] = "abcdefg";
	char ch2[] = "*******";
	int len = strlen(ch1);//strlen需要头文件<string.h>
	int left = 0;
	int right = len - 1;
	while (left <= right) {
	
		ch2[left] = ch1[left];
		ch2[right] = ch1[right];
		left++;
		right--;
		printf("%s\n", ch2);
		Sleep(1000);//头文件<windows.h>
		system("cls");//头文件<stdlib.h>
	}
	printf("%s\n", ch2);

	//二分查找
	int arr01[] = { 1,2,3,4,5,6,7,8,9,10 };
	left = 0;
	right = sizeof(arr01) / sizeof(arr01[0]) - 1;
	int find = 0;
	scanf("%d", &find);
	while (left <= right) {
		int mid = (left + right) / 2;
		if (find < arr01[mid])
			right = mid - 1;
		else if (find > arr01[mid])
			left = mid + 1;
		else {
			printf("找到了！\n");
			break;
		}
	}
	if (left > right)
		printf("没找到\n");

	//为防止left+right过大，超过int上线
	//可以用让
	int mid = left + (right - left) / 2;
	return 0;
}