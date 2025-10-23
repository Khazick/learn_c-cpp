#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <errno.h>

//第 1 题（编程题）
//题目名称：
//模拟实现strstr
//题目内容：
//模拟实现strstr
char* my_strstr(const char* p1, const char* p2) {
	assert(p1 && p2);
	char* s = NULL;
	char* e = NULL;
	char* ret = p1;
	if (*p2=='\0')
		return p1;
	while (*ret) {
		s = ret;
		e = p2;
		while (*s && *e && *s == *e) {
			s++;
			e++;
		}
		if (*e == '\0') {
			return ret;
		}
			
		ret++;
	}
	return NULL;
}
int main1() {
	char arr[] = "abcdabcdefg";
	char* find = "";
	//printf("%s\n", strstr(arr, find));
	char* p = my_strstr(arr,find);
	printf("%s\n", p);
	return 0;
}

//第 2 题（编程题）
//题目名称：
//模拟实现strncpy
//题目内容：
//模拟实现strncpy
char* my_strncpy(char* p2,const char* p1,size_t n) {
	char* ret = p2;
	while (n && *p1) {
		*p2 = *p1;
		p1++;
		p2++;
		n--;
	}	
	while (n) {
		*p2 = '\0';
		p2++;
		n--;
	}
		
	return ret;
}
int main2() {
	char arr1[] = "abcd";
	char arr2[20] = "xxxxxxxxxxxxxxxxx";
	//printf("%s\n", strncpy(arr2, arr1, 3));
	char* ret = my_strncpy(arr2,arr1,6);
	printf("%s\n", ret);
	return 0;
}
//第 3 题（编程题）
//题目名称：
//模拟实现strncat
//题目内容：
//模拟实现strncat
char* my_strncat(char* p1, const char* p2, size_t n) {
	assert(p1 && p2);
	char* ret = p1;
	while (*p1)
		p1++;
	while (n && *p2) {
		*p1 = *p2;
		p1++;
		p2++;
		n--;
	}
	while (n) {
		*p1 = '\0';
		p1++;
		n--;
	}
	return ret;
}

int main3() {
	char arr1[20] = "abcd\0xxxxx";
	char arr2[] = "efg";
	//printf("%s\n", strncat(arr1, arr2, 3));
	char* ret = my_strncat(arr1, arr2, 5);
	printf("%s\n", ret);
	return 0;
}

//第 4 题（编程题）
//题目名称：
//模拟实现memcpy
//题目内容：
//模拟实现memcpy
void* my_memcpy(void* p2,const void* p1,size_t n) {
	assert(p1 && p2);
	void* ret = p2;
	while (n--) {
		*(char*)p2 = *(char*)p1;
		p1 = (char*)p1 + 1;
		p2 = (char*)p2 + 1;
	}
	return ret;
}
int main4() {
	int arr1[] = { 1,2,3,4,5 };
	int arr2[20] = { 0 };
	//memcpy(arr2, arr1, 20);
	my_memcpy(arr2, arr1, 20);

	for (int i = 0;i < 5;i++) {
		printf("%d ", arr2[i]);
	}
	return 0;
}

//第 5 题（编程题）
//题目名称：
//模拟实现memmove
//题目内容：
//模拟实现memmove
void* my_memmove(void* p2,const void* p1, size_t n) {
	void* ret = p2;
	assert(p1 && p2);
	void* s = p2;
	void* e = p1;
	if (e>s) {
		while (n--) {
			*(char*)s = *(char*)e;
			s = (char*)s + 1;
			e = (char*)e + 1;
		}
	}
	else {
		while (n--) 
			*((char*)s + n) = *((char*)e + n);
	}
	return ret;
}
int main5() {
	int arr1[10] = { 1,2,3,4,5 ,6,7,8,9 };
	//memmove(arr1, arr1+2, 20);
	my_memmove(arr1+2, arr1, 20);
	//my_memmove(arr1, arr1+2, 20);

	for (int i = 0;i < 10;i++) {
		printf("%d ", arr1[i]);
	}
	return 0;
}

int main() {
	//strerror 需要头文件 errno.h
	for (int i = 0;i < 10;i++) {
		printf("%d : %s\n", i, strerror(i));
	}
	FILE* pFile;
	pFile = fopen("unexist.ent", "r");
	if (pFile == NULL)
		printf("Error opening file unexist.ent: %s\n", strerror(errno));

	//perror = pintf+strerror
	if (pFile == NULL)
		perror("Error opening file unexist.ent");//自动在结尾添加‘：’和‘ ’

	//memset
	char arr1[] = "hello";
	memset(arr1, 'a', 3);//从参数一的指针位置开始，设置参数3数字的个数的参数2
	printf("%s\n",arr1);

	//memcmp比较大小
	char c1[] = "DWgaOtP12df0";
	char c2[] = "DWGAOTP12DF0";
	printf("%d\n", memcmp(c1, c2, 2));
	printf("%d\n", memcmp(c1, c2, 3));

	//大小端
	int a = 0x11223344;
	//小端 
	//内存中：
	//44   33  22  11
	//地址：
	//974 975 976 977
	return 0;
}