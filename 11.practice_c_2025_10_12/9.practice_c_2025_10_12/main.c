#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//第 3 题（编程题）
//题目名称：
//计算斐波那契数
//题目内容：
//递归和非递归分别实现求第n个斐波那契数
//例如：
//输入：5  输出：5
//输入：10， 输出：55
//输入：2， 输出：1

int Fib1(int n) {
	if (n <= 2)
		return 1;
	else
		return Fib1(n - 1) + Fib1(n - 2);
}
int Fib2(int n) {
	int a = 1;
	int b = 1;
	int c = 1;
	while (n > 2) {
		c = a + b;
		a = b;
		b = c;
		n--;
	}
	return c;
}

int main1() {
	int input = 0;
	scanf("%d", &input);
	//递归法
	int r1 = Fib1(input);
	printf("%d\n", r1);
	//非递归法
	int r2 = Fib2(input);
	printf("%d\n", r2);

	return 0;
}
//第 4 题（编程题）
//题目名称：
//递归实现n的k次方
//题目内容：
//编写一个函数实现n的k次方，使用递归实现。
int power(int n, int k) {
	if (k == 0)
		return 1;
	else
		return n * power(n, k - 1);
}
int main2() {
	int base = 0;
	int index = 0;
	scanf("%d %d", &base, &index);
	int r = power(base,index);
	printf("%d\n", r);

	return 0;
}
//第 5 题（编程题）
//题目名称：
//计算一个数的每位之和（递归实现）
//题目内容：
//写一个递归函数DigitSum(n)，输入一个非负整数，返回组成它的数字之和
//
//例如，调用DigitSum(1729)，则应该返回1 + 7 + 2 + 9，它的和是19
//
//输入：1729，输出：19
int DigitSum(int n) {	
	if (n > 9)
		return DigitSum(n / 10) + n % 10;
	else
		return n;
}
int main3() {
	int input = 0;
	scanf("%d", &input);
	int r = DigitSum(input);
	printf("%d\n", r);

	return 0;
}
//第 6 题（编程题）
//题目名称：
//求阶乘
//题目内容：
//递归和非递归分别实现求n的阶乘（不考虑溢出的问题）
int Fact1(int n) {
	if (n == 0)
		return 1;
	else
		return n * Fact1(n - 1);
}
int Fact2(int n) {
	int r = 1;
	for (int i = 1;i <= n;i++) {
		r *= i;
	}
	return r;
}

int main4() {
	int input = 0;
	scanf("%d", &input);
	//递归法
	printf("%d\n", Fact1(input));
	//非递归法
	printf("%d\n", Fact2(input));

	return 0;
}
//第 7 题（编程题）
//题目名称：
//打印一个数的每一位
//题目内容：
//递归方式实现打印一个整数的每一位
void Print1(int n) {
	if (n > 9)
		Print1(n / 10);
	printf("%d ", n % 10);
}
int main5() {
	int input = 0;
	scanf("%d", &input);
	Print1(input);
	return 0;
}