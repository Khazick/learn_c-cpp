#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>
//�� 5 �⣨����⣩
//��Ŀ���ƣ�
//����ˮ����
//��Ŀ���ݣ�
//����ˮ��1ƿ��ˮ1Ԫ��2����ƿ���Ի�һƿ��ˮ����20Ԫ�����Ժȶ�����ˮ�����ʵ�֣���
//
int main1() {
	int water = 1;
	int money = 20;
	int bottle = 0;
	for (int i = water;i <= money;i++) {
		bottle++;
		if (bottle % 2 == 0)
			bottle++;
	}
	printf("���Ժ�%dƿ��ˮ\n", bottle);
	return 0;
}
//�ο���:
int main01()
{
	int money = 0;
	int total = 0;
	int empty = 0;
	scanf("%d", &money);
	//����1
	total = money;
	empty = money;
	while (empty > 1)
	{
		total += empty / 2;
		empty = empty / 2 + empty % 2;
	}

	printf("total = %d\n", total);
	return 0;
}
// ������������������ˮ����ƿ�ӻ��Ĺ���Ļ������Է��֣���ʵ���Ǹ��Ȳ����У�money*2-1
int main001()
{
	int money = 0;
	int total = 0;
	int empty = 0;
	scanf("%d", &money);
	//����2
	if (money <= 0)
	{
		total = 0;
	}
	else
	{
		total = money * 2 - 1;
	}
	printf("total = %d\n", total);
	return 0;
}


// 
//�� 6 �⣨����⣩
//��Ŀ���ƣ�
//��ӡ����
//��Ŀ���ݣ�
//��C��������Ļ���������ͼ����
int main2() {
	int a = 13;
	int n = 0;
	char arr[13] = { 0 };

	for (int i = 1;i <= 13;i+=2) {
		n = (a - i) / 2;
		for (int j = 0;j < 13;j++) {
			printf("%c", ' ');
			if (j == n) {
				for(int k = 0;k<i;k++)
					printf("%c", '*');
			}
		}
		printf("\n");
	}
	for (int i = 13;i > 0;i -= 2) {
		n = (a - i) / 2;
		for (int j = 0;j < 13;j++) {
			printf("%c", ' ');
			if (j == n) {
				for (int k = 0;k < i;k++)
					printf("%c", '*');
			}
		}
		printf("\n");
	}
	return 0;
}
//�ο���
int main02(){
	int line = 0;
	int i = 0;
	scanf("%d", &line);//7
	//��ӡ�ϰ벿��
	for (i = 0; i < line; i++)
	{
		//��ӡһ��
		//��ӡ�ո�
		int j = 0;
		for (j = 0; j < line - 1 - i; j++)
		{
			printf(" ");
		}
		//��ӡ*
		for (j = 0; j < 2 * i + 1; j++)
		{
			printf("*");
		}
		printf("\n");
	}
	//��ӡ�°벿��
	for (i = 0; i < line - 1; i++)
	{
		//��ӡһ��
		int j = 0;
		for (j = 0; j <= i; j++)
		{
			printf(" ");
		}
		for (j = 0; j < 2 * (line - 1 - i) - 1; j++)
		{
			printf("*");
		}
		printf("\n");
	}
	return 0;
}
//�� 7 �⣨����⣩
//��Ŀ���ƣ�
//��ӡˮ�ɻ���
//��Ŀ���ݣ�
//���0��100000֮������С�ˮ�ɻ������������
//��ˮ�ɻ�������ָһ��nλ�������λ���ֵ�n�η�֮��ȷ�õ��ڸ��������� : 153��1 ^ 3��5 ^ 3��3 ^ 3����153��һ����ˮ�ɻ�������
int main3() {
	for (int i = 0;i <= 100000;i++) {
		int a = 0;
		int b = 0;
		int c = 0;
		int n = 0;
		//�ж�λ��
		a = i;
		while (a) {
			a /= 10;
			n++;
		}
		a = i;
		//�����λ����n�η�֮��
		while (a)
		{
			b = a % 10;
			a /= 10;
			c += pow(b, n);
		}
		if (i == c)
			printf("%d ", i);
	}
	printf("\n");
	return 0;
}

//�� 8 �⣨����⣩
//��Ŀ���ƣ�
//�������
//��Ŀ���ݣ�
//��Sn = a + aa + aaa + aaaa + aaaaa��ǰ5��֮�ͣ�����a��һ�����֣�
//
//���磺2 + 22 + 222 + 2222 + 22222
int main4() {
	int a = 0;
	scanf("%d", &a);
	int Sn = a * 12345;
	printf("%d\n", Sn);
	return 0;
}
//�ο���
int main04()
{
	int a = 0;//��
	int n = 0;//��
	int i = 0;
	int sum = 0;
	int tmp = 0;
	scanf("%d%d", &a, &n);
	for (i = 0; i < n; i++)
	{
		tmp = tmp * 10 + a;
		sum += tmp;
	}
	printf("%d\n", sum);
	return 0;
}