#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//�� 8 �⣨����⣩
//��Ŀ���ƣ�
//��д�жϴ�С�˳���
//��Ŀ���ݣ�
//дһ�������жϵ�ǰ�����Ǵ�˻���С�ˣ������С�˷���1������Ǵ�˷���0.
int check_system() {
	int a = 1;
	return *((char*)&a);
}

int main1() {
	if (check_system()) {
		printf("С��\n");
	}
	else {
		printf("���\n");
	}
	return 0;
}
//�� 9 �⣨����⣩
//��Ŀ���ƣ�
//ģ��ʵ��atoi
//��Ŀ���ݣ�
//�����˽�⺯��atoi�Ĺ��ܣ�ѧϰʹ�ã���ģ��ʵ��atoi������
//C �⺯�� int atoi(const char *str) �Ѳ��� str ��ָ����ַ���ת��Ϊһ������������Ϊ int �ͣ���

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
