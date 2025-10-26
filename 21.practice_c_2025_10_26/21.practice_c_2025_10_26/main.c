#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//第 8 题（编程题）
//题目名称：
//编写判断大小端程序
//题目内容：
//写一个函数判断当前机器是大端还是小端，如果是小端返回1，如果是大端返回0.
int check_system() {
	int a = 1;
	return *((char*)&a);
}

int main1() {
	if (check_system()) {
		printf("小端\n");
	}
	else {
		printf("大端\n");
	}
	return 0;
}
//第 9 题（编程题）
//题目名称：
//模拟实现atoi
//题目内容：
//自行了解库函数atoi的功能，学习使用，并模拟实现atoi函数。
//C 库函数 int atoi(const char *str) 把参数 str 所指向的字符串转换为一个整数（类型为 int 型）。

int my_aoti(const char* p) {
	while (isspace(*p)) {
		p++;
	}
	int flag = 0;
	switch (*p) {
	case '-':
		flag = 1;
	case '+':
		p++;
		break;
	}
	int ret = 0;
	while (*p>='0'&&*p<='9') {
		ret = ret * 10 - (*p - '0');
		p++;
	}
	return flag ? ret : -ret;
}
int main() {
	//char arr1[20] = "23462673";
	//printf("%d\n", atoi(arr1));
	//char arr2[20] = "wgsdgg";
	//printf("%d\n", atoi(arr2));
	char arr1[] = "-23462673";
	char arr2[] = "wgsdgg";
	char arr3[] = "   +235346";
	int a = my_aoti(arr1);
	int b = my_aoti(arr2);
	int c = my_aoti(arr3);
	printf("%d %d %d\n", a, b, c);

	return 0;
}
