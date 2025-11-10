#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stddef.h>

//第 1 题（编程题）
//题目名称：
//offsetof宏
//题目内容：
//写一个宏，计算结构体中某变量相对于首地址的偏移，并给出说明
//考察：offsetof宏的实现
struct S {
	char arr1[10];
	char arr2[10];
	int a;
};
#define OFFSETOF(type , member)   (size_t)( &(((type*)0 ) -> member) )
int main1() {
	printf("偏移量：%zd\n" , \
		offsetof(struct S, arr1));
	size_t a = OFFSETOF(struct S, arr1);
	printf("%zd\n", a);

	printf("偏移量：%zd\n" , \
		offsetof(struct S, arr2));
	size_t b = OFFSETOF(struct S, arr2);
	printf("%zd\n", b);

	printf("偏移量：%zd\n" , \
		offsetof(struct S, a));
	size_t c = OFFSETOF(struct S, a);
	printf("%zd\n", c);
	return 0;
}

//第 2 题（编程题）
//题目名称：
//交换奇偶位
//题目内容：
//写一个宏，可以将一个整数的二进制位的奇数位和偶数位交换。
#define SWAP(n) ( ( (n) & 0x55555555 ) << 1) | ( ( (n) & 0xaaaaaaaa) >>1) 
int main() {
	int n = 10;
	int a = SWAP(n);
	printf("%d\n", a);
	return 0;
}
