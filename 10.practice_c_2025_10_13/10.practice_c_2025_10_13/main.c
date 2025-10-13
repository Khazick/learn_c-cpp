#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//第 11 题（编程题）
//题目名称：
//单身狗1
//题目内容：
//在一个整型数组中，只有一个数字出现一次，其他数组都是成对出现的，请找出那个只出现一次的数字。
//例如：
//数组中有：1 2 3 4 5 1 2 3 4，只有5出现一次，其他数字都出现2次，找出5

int main1() {
	int arr[] = { 1, 2, 3, 4, 5, 1, 2, 3, 4 };
	int sz = sizeof(arr) / sizeof(arr[0]);

	for (int i = 0;i < sz;i++) {
		int flag = 0;
		for (int j = 0;j < sz;j++) {
			if (arr[i] == arr[j] && i != j) {
				flag = 1;
				break;
			}	
		}
		if (flag == 0)
			printf("%d\n", arr[i]);
	}
	return 0;
}
//参考答案
int find_single(int arr[], int size) {
	int ret = 0;
	for (int i = 0;i < size;i++) {
		ret ^= arr[i];//按位异或:1^2^3^4^1^2^3^4 = 0^5 = 5
	}
	return ret;
}
int main01() {
	int arr[] = { 1, 2, 3, 4, 5, 1, 2, 3, 4 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	int singledog = find_single(arr, sz);
	printf("%d\n", singledog);
	return 0;
}
//第 12 题（编程题）
//题目名称：
//交换两个变量（不创建临时变量）
//题目内容：
//不允许创建临时变量，交换两个整数的内容
void swop1(int a, int b) {
	printf("改变前：a=%d,b=%d\n", a, b);
	a = a + b;
	b = a - b;
	a = a - b;
	printf("改变后：a=%d,b=%d\n", a, b);
}
void swop2(int a, int b) {
	printf("改变前：a=%d,b=%d\n", a, b);
	a = a ^ b;
	b = a ^ b;//b = a^b^b = a
	a = a ^ b;//a = a^b^a = b
	//整体a = a^b^a^b^b = b
	printf("改变后：a=%d,b=%d\n", a, b);
}
int main2() {
	int a = 1;
	int b = 9;
	//法1
	swop1(a, b);
	//法2
	swop2(a, b);
	return 0;
}
//第 13 题（编程题）
//题目名称：
//统计二进制中1的个数
//题目内容：
//写一个函数返回参数二进制中 1 的个数。
//比如： 15    0000 1111    4 个 1
int NumberOf1(int n) {
	int count = 0;
	for (int i = 0;i < 32;i++) {
		if ((n ^ (n - 1)) == 1) 
			count++;		
		n >>= 1;
	}
	return count;
}
int NumberOf2(int n) {
	int count = 0;
	while (n) {
		n &= (n - 1);
		count++;
	}
	return count;
}
int main3() {
	int input = 0;
	scanf("%d", &input);
	//法1
	int ret = NumberOf1(input);
	printf("二进制中1的个数: %d\n", ret);
	//法2
	int ret2 = NumberOf2(input);
	printf("二进制中1的个数: %d\n", ret2);
	return 0;
}
//
//第 14 题（编程题）
//题目名称：
//打印整数二进制的奇数位和偶数位
//题目内容：
//获取一个整数二进制序列中所有的偶数位和奇数位，分别打印出二进制序列
int main4() {
	int input = 0;
	scanf("%d", &input);
	//奇数位
	int a = 1;
	printf("奇数位:");
	for (int i = 0;i < 16;i++) {		
		if ((input & a) == a)
			printf("1 ");
		else
			printf("0 ");
		a <<= 2;
	}
	printf("\n");
	//偶数位
	int b = 2;
	printf("偶数位:");
	for (int i = 0;i < 16;i ++) {
		if ((input & b) == b)
			printf("1 ");
		else
			printf("0 ");
		b <<= 2;
	}
	printf("\n");

	return 0;
}
//参考答案
void Printbit(int num)
{
	for (int i = 31; i >= 1; i -= 2)
	{
		printf("%d ", (num >> i) & 1);
	}
	printf("\n");
	for (int i = 30; i >= 0; i -= 2)
	{
		printf("%d ", (num >> i) & 1);
	}
	printf("\n");
}
int main04() {
	int input = 0;
	scanf("%d", &input);
	Printbit(input);
	return 0;
}
//第 15 题（编程题）
//题目名称：
//求两个数二进制中不同位的个数
//题目内容：
//编程实现：两个int（32位）整数m和n的二进制表达中，有多少个位(bit)不同？
//输入例子 :
//1999 2299
//输出例子 : 7
void diff(int m, int n) {
	int a = m ^ n;
	int count = 0;
	while (a) {
		count++;
		a &= (a - 1);
	}
	printf("%d", count);
}
int main5() {
	int m = 0;
	int n = 0;
	scanf("%d %d", &m, &n);
	diff(m, n);
	return 0;
}


struct str {
	char name[10];
	int age;
	float height;
}s1, s2, s3, s4 = {"shuaibi",10,9.8};//结构体嵌套初始化

int main() {
	//⼆进制位置0或者置1
	//编写代码将数字x⼆进制序列的第n位修改为1，然后再改回0
	int x = 0;
	int n = 0;
	scanf("%d %d", &x, &n);
	int a = 1;
	printf("%d的二进制数：\n", x);
	for (int i = 31;i >= 0;i--) {
		printf("%d ", (x >> i) & 1);
	}
	printf("\n");
	int b = x | (1 << (n - 1));
	printf("将数字%d 二进制序列的第%d位修改为1，现在的数为%d，其二进制数：\n", x, n, b);
	for (int i = 31;i >= 0;i--) {
		printf("%d ", (b >> i) & 1);
	}
	printf("\n");
	b &= ~(1 << (n - 1));
	printf("将数字%d 二进制序列的第%d位改回为0，其二进制数：\n", b, n);
	for (int i = 31;i >= 0;i--) {
		printf("%d ", (b >> i) & 1);
	}
	printf("\n");

	//逗号表达式
	int a1 = 1;
	int b1 = 2;
	int c1 = (a1 = b1 + 1, b1 = a1 + 1);//a1 = 3 -> b1 = 4 -> c1 = 4
	printf("c1 = %d\n", c1);

	//结构体
	struct str s1 = { "choubi",20,11.2 };//初始化
	printf("%s\n", s1.name);//访问 : 结构体变量.成员名
	printf("%s\n", s4.name);

	return 0;
}
