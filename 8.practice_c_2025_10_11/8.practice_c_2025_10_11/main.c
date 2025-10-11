#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>
//第 5 题（编程题）
//题目名称：
//喝汽水问题
//题目内容：
//喝汽水，1瓶汽水1元，2个空瓶可以换一瓶汽水，给20元，可以喝多少汽水（编程实现）。
//
int main1() {
	int water = 1;
	int money = 20;
	int bottle = 0;
	for (int i = water;i <= money;i++) {
		bottle++;
		if (bottle % 2 == 0)
			bottle++;
	}
	printf("可以喝%d瓶汽水\n", bottle);
	return 0;
}
//参考答案:
int main01()
{
	int money = 0;
	int total = 0;
	int empty = 0;
	scanf("%d", &money);
	//方法1
	total = money;
	empty = money;
	while (empty > 1)
	{
		total += empty / 2;
		empty = empty / 2 + empty % 2;
	}

	printf("total = %d\n", total);
	return 0;
}
// 方法二：按照上述喝水和用瓶子换的规则的话，可以发现，其实就是个等差数列：money*2-1
int main001()
{
	int money = 0;
	int total = 0;
	int empty = 0;
	scanf("%d", &money);
	//方法2
	if (money <= 0)
	{
		total = 0;
	}
	else
	{
		total = money * 2 - 1;
	}
	printf("total = %d\n", total);
	return 0;
}


// 
//第 6 题（编程题）
//题目名称：
//打印菱形
//题目内容：
//用C语言在屏幕上输出以下图案：
int main2() {
	int a = 13;
	int n = 0;
	char arr[13] = { 0 };

	for (int i = 1;i <= 13;i+=2) {
		n = (a - i) / 2;
		for (int j = 0;j < 13;j++) {
			printf("%c", ' ');
			if (j == n) {
				for(int k = 0;k<i;k++)
					printf("%c", '*');
			}
		}
		printf("\n");
	}
	for (int i = 13;i > 0;i -= 2) {
		n = (a - i) / 2;
		for (int j = 0;j < 13;j++) {
			printf("%c", ' ');
			if (j == n) {
				for (int k = 0;k < i;k++)
					printf("%c", '*');
			}
		}
		printf("\n");
	}
	return 0;
}
//参考答案
int main02(){
	int line = 0;
	int i = 0;
	scanf("%d", &line);//7
	//打印上半部分
	for (i = 0; i < line; i++)
	{
		//打印一行
		//打印空格
		int j = 0;
		for (j = 0; j < line - 1 - i; j++)
		{
			printf(" ");
		}
		//打印*
		for (j = 0; j < 2 * i + 1; j++)
		{
			printf("*");
		}
		printf("\n");
	}
	//打印下半部分
	for (i = 0; i < line - 1; i++)
	{
		//打印一行
		int j = 0;
		for (j = 0; j <= i; j++)
		{
			printf(" ");
		}
		for (j = 0; j < 2 * (line - 1 - i) - 1; j++)
		{
			printf("*");
		}
		printf("\n");
	}
	return 0;
}
//第 7 题（编程题）
//题目名称：
//打印水仙花数
//题目内容：
//求出0～100000之间的所有“水仙花数”并输出。
//“水仙花数”是指一个n位数，其各位数字的n次方之和确好等于该数本身，如 : 153＝1 ^ 3＋5 ^ 3＋3 ^ 3，则153是一个“水仙花数”。
int main3() {
	for (int i = 0;i <= 100000;i++) {
		int a = 0;
		int b = 0;
		int c = 0;
		int n = 0;
		//判断位数
		a = i;
		while (a) {
			a /= 10;
			n++;
		}
		a = i;
		//计算各位数的n次方之和
		while (a)
		{
			b = a % 10;
			a /= 10;
			c += pow(b, n);
		}
		if (i == c)
			printf("%d ", i);
	}
	printf("\n");
	return 0;
}

//第 8 题（编程题）
//题目名称：
//计算求和
//题目内容：
//求Sn = a + aa + aaa + aaaa + aaaaa的前5项之和，其中a是一个数字，
//
//例如：2 + 22 + 222 + 2222 + 22222
int main4() {
	int a = 0;
	scanf("%d", &a);
	int Sn = a * 12345;
	printf("%d\n", Sn);
	return 0;
}
//参考答案
int main04()
{
	int a = 0;//数
	int n = 0;//项
	int i = 0;
	int sum = 0;
	int tmp = 0;
	scanf("%d%d", &a, &n);
	for (i = 0; i < n; i++)
	{
		tmp = tmp * 10 + a;
		sum += tmp;
	}
	printf("%d\n", sum);
	return 0;
}