#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>

//�� 1 �⣨����⣩
//��Ŀ���ƣ�
//ģ��ʵ��strlen
//��Ŀ���ݣ�
//ģ��ʵ��strlen
//��1��������
int my_strlen1(const char* p) {
	int count = 0;
	assert(p);
	while (*p++) 
		count++;
	return count;
}
//��2��ָ��-ָ��
int my_strlen2(const char* p) {
	char* start = p;
	assert(p);
	while (*p)
		p++;
	return p - start;
}
//��3���ݹ�
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
//�� 2 �⣨����⣩
//��Ŀ���ƣ�
//ģ��ʵ��strcpy
//��Ŀ���ݣ�
//ģ��ʵ��strcpy
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
//�� 3 �⣨����⣩
//��Ŀ���ƣ�
//ģ��ʵ��strcmp
//��Ŀ���ݣ�
//ģ��ʵ��strcmp
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
//�� 4 �⣨����⣩
//��Ŀ���ƣ�
//ģ��ʵ��strcat
//��Ŀ���ݣ�
//ģ��ʵ��strcat
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
	//�ַ����ຯ��
	//��Ҫͷ�ļ�ctype.h
	char c[] = "a \nbcd e\n";
	int i = 0;
	while (!iscntrl(c[i]))//���c��һ�������ַ�����ú������ط���ֵ�����򷵻� 0��
		i++;
	printf("%d\n", i);
	printf("\n");
	while (!isspace(c[i]))//��� c ��һ���հ��ַ�����ú������ط���ֵ��true�������򷵻� 0��false����
		i++;//�հ��ַ����� ��,��\f', '\n', '\r' ,'\t' ,'\v'
	printf("%d\n", i);
	printf("\n");
	printf("%d\n", iscntrl(1));//��� c ��һ�����֣���ú������ط���ֵ�����򷵻� 0��
	printf("%d\n", iscntrl('a'));
	printf("\n");
	printf("%d\n", islower('a'));//��� c ��һ��Сд��ĸ����ú������ط���ֵ��true�������򷵻� 0��false����
	printf("%d\n", islower(1));
	printf("\n");
	printf("%d\n", isupper('A'));//��� c ��һ����д��ĸ����ú������ط���ֵ��true�������򷵻� 0��false����
	printf("%d\n", isupper('a'));
	printf("\n");
	printf("%d\n", isalpha('a'));//��� c ��һ����ĸ����ú������ط���ֵ��true�������򷵻� 0��false����
	printf("%d\n", isalpha(1));
	printf("\n");
	printf("%d\n", isalnum('a'));//��� c ��һ����ĸ�����֣���ú������ط���ֵ��true�������򷵻� 0��false����
	printf("%d\n", isalnum('2'));
	printf("\n");
	printf("%d\n", ispunct(','));//��� c ��һ����㣬��ú������ط���ֵ��true�������򷵻� 0��false����
	printf("%d\n", ispunct(1));
	printf("\n");
	printf("%d\n", isgraph(','));//��� c ��ͼ�α�ʾ������ú������ط���ֵ�����򷵻� 0��
	printf("%d\n", isgraph('1'));
	printf("\n");
	//C ����������ͼ���ַ�:
	// !" # $ % & ' ( ) * + , - .
	// / 0 1 2 3 4 5 6 7 8 9
	// : ; < = > ? @ 
	// A B C D E F G H I J K L M N O P Q R S T U V W X Y Z
	// [ \ ] ^ _ ` 
	// a b c d e f g h i j k l m n o p q r s t u v w x y z 
	// { | } ~
	printf("%d\n", isprint(','));//��� c ��һ���ɴ�ӡ���ַ�����ú������ط���ֵ��true�������򷵻� 0��false����
	printf("%d\n", isprint('k'));
	printf("\n");

	//��ϰ�����ַ����е�Сдת��Ϊ��д
	char arr[] = "abcdef";
	i = 0;
	char c1;
	while (arr[i]) {
		if (islower(arr[i]))
			arr[i] -= 32;//Сд��ĸascii - 32 == ��д��ĸascii
		i++;
	}
	printf("%s\n", arr);

	//�ַ�ת������
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

	//strtok�� C ��׼���е�һ���ַ��������������ڽ��ַ����ָ��һϵ�����ַ���
	char arr4[] = "abc\nd_ef*g#123";
	char* sep = "\n_*#";//���
	//printf("%s\n", strtok(arr4, sep));//����ָ����һ����ǵ�ָ�롣���û�и���ı�ǣ��򷵻� NULL��
	for (char* str = strtok(arr4, sep);str != NULL;str = strtok(NULL, sep)) {
		printf("%s\n", str);
	}

	return 0;
}