#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//第 9 题（编程题）
//题目名称：
//求最大值
//题目内容：
//求10 个整数中最大值
int main1() {
	int arr[10];
	for (int i = 0;i < 10;i++) {
		scanf("%d", &arr[i]);
	}
	for (int i = 0;i < 9;i++) {
		if (arr[i] > arr[i + 1])
		{
			int tmp = arr[i];
			arr[i] = arr[i + 1];
			arr[i + 1] = tmp;
		}
	}
	printf("%d ", arr[9]);
	return 0;
}
//第 10 题（编程题）
//题目名称：
//分数求和
//题目内容：
//计算1 / 1 - 1 / 2 + 1 / 3 - 1 / 4 + 1 / 5 …… + 1 / 99 - 1 / 100 的值，打印出结果
int main2() {
	int i= 0;
	double a = 0.0;
	double b = 0.0;
	for (i = 1;i <= 100;i += 2) 
		a += 1.0 / i;	
	for (i = 2;i <= 100;i += 2) 
		b -= 1.0 / i;
	double c = a + b;
	printf("%lf\n", c);
	return 0;
}
int  main02()
{
	int i = 0;
	double sum = 0.0;
	int flag = 1;
	for (i = 1; i <= 100; i++)
	{
		sum += flag * 1.0 / i;
		flag = -flag;
	}
	printf("%lf\n", sum);
	return 0;
}

//第 11 题（编程题）
//题目名称：
//数9的个数
//题目内容：
//编写程序数一下 1到 100 的所有整数中出现多少个数字9
int main3() {
	int count = 0;
	for (int i = 1;i <= 100;i++) {
		if (i % 10 == 9)
			count++;
		if (i / 10 == 9)
			count++;
	}
	printf("出现%d个数字9\n", count);
	return 0;
}

//第 12 题（编程题）
//题目名称：
//打印闰年
//题目内容：
//打印1000年到2000年之间的闰年
int main4() {
	for (int i = 1000;i <= 2000;i++) {
		if (i % 4 == 0 && i % 100 != 0 || i % 400 == 0)
			printf("%d ", i);
	}
	printf("\n");
	return 0;
}

//第 13 题（编程题）
//题目名称：
//最大公约数
//题目内容：
//给定两个数，求这两个数的最大公约数
//
//例如：
//
//输入：20 40
//
//输出：20
int main5() {
	int a = 0;
	int b = 0;
	int c = 1;
	scanf("%d %d", &a, &b);
	while (c) {
		c = a % b;
		a = b;
		b = c;
	}
	printf("最大公约数: %d\n", a);
	return 0;
}

int main() {
	//1.条件操作符
	int age;
	scanf("%d", &age);
	int result = age > 17 ? 1 : 0;// 条件；真结果；假结构
	printf("%d\n", result);
	//用条件操作符实现以下代码逻辑
	//int a = 0;
	//int b = 0;
	//scanf("%d", &a);
	//if (a > 5)
	//	b = 3;
	//else
	//	b = -3;
	//printf("%d\n", b);
	int a = 0;
	scanf("%d", &a);
	int b = a > 5 ? 3 : -3;
	printf("%d\n", b);
	//使⽤条件表达式实现找两个数中较⼤值
	a = 0;
	b = 0;
	printf("输入两个数比较：");
	scanf("%d %d", &a, &b);
	char c = a > b ? 'a' : 'b';
	printf("%c\n", c);
	printf("\n");
	//2.逻辑与或非
	if (a > b && age == 1)
		printf("111\n");
	if (a < b || age == 1)
		printf("222\n");
	if (a != b )
		printf("333\n");

	int year = 0;
	scanf("%d", &year);
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
		printf("%d是闰年\n", year);
	else
		printf("%d不是闰年\n", year);
	//如果第一个条件都无法满足，将会短路，即不再执行后续表达式
	int i = 0, a1 = 0, b1 = 2, c1 = 3, d1 = 4;
	i = a1++ && ++b1 && d1++;
	printf("%d\n", i);//0
	printf("\n");
	//3.switch
	//输⼊任意⼀个整数值，计算除3之后的余数
	scanf("%d", &a);
	if (a % 3 == 1)
		printf("1\n");
	else if (a % 3 == 2)
		printf("2\n");
	else
		printf("0\n");
	switch (a % 3) {
	case 1:
		printf("1\n");
		break;
	case 2:
		printf("2\n");
		break;
	default:
		printf("0\n");
		break;
	}
	switch (a) {
	case 1:
	case 2:
	case 3:
	case 4:
	case 5:
		printf("work\n");
		break;
	case 6:
	case 7:
		printf("rest\n");
		break;
	default:
		printf("err\n");
		break;
	}
	printf("\n");

	//4.循环
	int n = 1;
	while (n <= 10)
		printf("%d ", n++);
	printf("\n");

	
	//输⼊⼀个正的整数，逆序打印这个整数的每⼀位
	//例如：
	//输⼊：1234，输出：4 3 2 1
	//输⼊：521，输出：1 2 5
	scanf("%d", &a);
	while (a) {
		b = a % 10;
		printf("%d ", b);
		a /= 10;
	}
	printf("\n");

	for (int i = 1;i <= 10;i++)
		printf("%d ", i);
	printf("\n");
	//计算1~100之间3的倍数的数字之和
	a = 0;
	for (int i = 3;i <= 100;i += 3)
		a += i;
	printf("%d\n", a);
	a = 1;
	do
		printf("%d ", a++);
	while (a<=10);
	printf("\n");
	//输⼊⼀个正整数，计算这个整数是⼏位数？
	scanf("%d", &a);
	b = 0;
	do {
		b++;
		a /= 10;
	} while (a);
	printf("%d\n", b);
	//break终止整个循环，continue跳过此次循环

	return 0;
}