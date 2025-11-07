#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

//第 4 题（编程题）
//题目名称：
//写一个程序拷贝文件
//题目内容：
//使用所学文件操作，在当前目录下放一个文件data.txt，写一个程序，将data.txt文件拷贝一份，生成data_copy.txt文件。
//
//基本思路：
//
//打开文件data.txt，读取数据
//打开文件data_copy.txt，写数据
//从data.txt中读取数据存放到data_copy.txt文件中，直到文件结束。
//关闭两个文件

int main() {
	//打开文件
	FILE* pf1 = fopen("data.txt", "r");
	if (pf1 == NULL) {
		perror("fopen pf1: ");
		return 1;
	}
	FILE* pf2 = fopen("data_copy.txt", "w");
	if (pf2 == NULL) {
		perror("fopen pf2: ");
		fclose(pf1);
		pf1 = NULL;
		return 1;
	}
	//操作文件
	int c;
	while ((c = fgetc(pf1)) != EOF) {
		fputc(c,pf2);
	}

	//关闭文件
	fclose(pf1);
	pf1 = NULL;
	fclose(pf2);
	pf2 = NULL;
	return 0;
}
