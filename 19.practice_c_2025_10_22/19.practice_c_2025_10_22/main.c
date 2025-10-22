#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>

//第 1 题（编程题）
//题目名称：
//模拟实现strlen
//题目内容：
//模拟实现strlen
//法1：计数器
int my_strlen1(const char* p) {
	int count = 0;
	assert(p);
	while (*p++) 
		count++;
	return count;
}
//法2：指针-指针
int my_strlen2(const char* p) {
	char* start = p;
	assert(p);
	while (*p)
		p++;
	return p - start;
}
//法3：递归
int my_strlen3(const char* p) {
	assert(p);
	if (*p)
		return 1 + my_strlen3(p + 1);
	else
		return 0;
}
int main1() {
	char c1[] = "abcdefg";
	printf("%d\n", my_strlen1(c1));
	printf("%d\n", my_strlen2(c1));
	printf("%d\n", my_strlen3(c1));
	return 0;
}
//第 2 题（编程题）
//题目名称：
//模拟实现strcpy
//题目内容：
//模拟实现strcpy
char* my_strcpy(char* p2, const char* p1) {
	char* ret = p2;
	assert(p1 && p2);
	while (*p2++ = *p1++);
	return ret;
}
int main2() {
	char arr1[] = "abcdef";
	char arr2[20] = "******************";
	my_strcpy(arr2, arr1);
	printf("%s\n", arr2);
	printf("%s\n", my_strcpy(arr2, arr1));
	return 0;
}
//第 3 题（编程题）
//题目名称：
//模拟实现strcmp
//题目内容：
//模拟实现strcmp
int my_strcmp(const char* p1,const char* p2) {
	assert(p1 && p2);
	while (*p1 == *p2) {
		if (*p1 == '\0')
			return 0;
		p1++;
		p2++;
	}
	return *p1 - *p2;

}
int main3() {
	char arr1[] = "abcdef";
	char arr2[] = "abq";
	int ret = my_strcmp(arr1, arr2);
	if(ret>0)
		printf(">\n");
	else if(ret<0)
		printf("<\n");
	else
		printf("=\n");

	return 0;
}
//第 4 题（编程题）
//题目名称：
//模拟实现strcat
//题目内容：
//模拟实现strcat
char* my_strcat(char* p1, const char* p2) {
	char* ret = p1;
	assert(p1 && p2);
	while (*p1)
		p1++;
	while (*p1++ = *p2++);
	return ret;
}
int main4() {
	char arr1[20] = "hello ";
	char arr2[] = "bit";
	
	printf("%s\n", my_strcat(arr1, arr2));
	return 0;
}

int main() {
	//字符分类函数
	//需要头文件ctype.h
	char c[] = "a \nbcd e\n";
	int i = 0;
	while (!iscntrl(c[i]))//如果c是一个控制字符，则该函数返回非零值，否则返回 0。
		i++;
	printf("%d\n", i);
	printf("\n");
	while (!isspace(c[i]))//如果 c 是一个空白字符，则该函数返回非零值（true），否则返回 0（false）。
		i++;//空白字符：‘ ’,‘\f', '\n', '\r' ,'\t' ,'\v'
	printf("%d\n", i);
	printf("\n");
	printf("%d\n", iscntrl(1));//如果 c 是一个数字，则该函数返回非零值，否则返回 0。
	printf("%d\n", iscntrl('a'));
	printf("\n");
	printf("%d\n", islower('a'));//如果 c 是一个小写字母，则该函数返回非零值（true），否则返回 0（false）。
	printf("%d\n", islower(1));
	printf("\n");
	printf("%d\n", isupper('A'));//如果 c 是一个大写字母，则该函数返回非零值（true），否则返回 0（false）。
	printf("%d\n", isupper('a'));
	printf("\n");
	printf("%d\n", isalpha('a'));//如果 c 是一个字母，则该函数返回非零值（true），否则返回 0（false）。
	printf("%d\n", isalpha(1));
	printf("\n");
	printf("%d\n", isalnum('a'));//如果 c 是一个字母或数字，则该函数返回非零值（true），否则返回 0（false）。
	printf("%d\n", isalnum('2'));
	printf("\n");
	printf("%d\n", ispunct(','));//如果 c 是一个标点，则该函数返回非零值（true），否则返回 0（false）。
	printf("%d\n", ispunct(1));
	printf("\n");
	printf("%d\n", isgraph(','));//如果 c 有图形表示法，则该函数返回非零值，否则返回 0。
	printf("%d\n", isgraph('1'));
	printf("\n");
	//C 语言中所有图形字符:
	// !" # $ % & ' ( ) * + , - .
	// / 0 1 2 3 4 5 6 7 8 9
	// : ; < = > ? @ 
	// A B C D E F G H I J K L M N O P Q R S T U V W X Y Z
	// [ \ ] ^ _ ` 
	// a b c d e f g h i j k l m n o p q r s t u v w x y z 
	// { | } ~
	printf("%d\n", isprint(','));//如果 c 是一个可打印的字符，则该函数返回非零值（true），否则返回 0（false）。
	printf("%d\n", isprint('k'));
	printf("\n");

	//练习：将字符串中的小写转换为大写
	char arr[] = "abcdef";
	i = 0;
	char c1;
	while (arr[i]) {
		if (islower(arr[i]))
			arr[i] -= 32;//小写字母ascii - 32 == 大写字母ascii
		i++;
	}
	printf("%s\n", arr);

	//字符转换函数
	char arr1[] = "ABCD";
	char arr2[] = "abcdef";
	char arr3[50] = "**\0****************";
	i = 0;
	while (arr1[i]) {
		arr1[i] = tolower(arr1[i]);
		i++;
	}
	printf("%s\n", arr1);
	i = 0;
	while (arr2[i]) {
		arr2[i] = toupper(arr2[i]);
		i++;
	}
	printf("%s\n", arr2);

	//strncpy strncat strncmp
	strncpy(arr3,arr2,3);
	printf("%s\n", arr3);
	strncat(arr3, arr1, 2);
	printf("%s\n", arr3);
	printf("%d\n", strncmp(arr3, arr2, 3));

	//strtok是 C 标准库中的一个字符串处理函数，用于将字符串分割成一系列子字符串
	char arr4[] = "abc\nd_ef*g#123";
	char* sep = "\n_*#";//标记
	//printf("%s\n", strtok(arr4, sep));//返回指向下一个标记的指针。如果没有更多的标记，则返回 NULL。
	for (char* str = strtok(arr4, sep);str != NULL;str = strtok(NULL, sep)) {
		printf("%s\n", str);
	}

	return 0;
}