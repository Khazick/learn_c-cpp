#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//�� 11 �⣨����⣩
//��Ŀ���ƣ�
//BC38 - ����ˮ�ɻ���
//��Ŀ���ݣ�
//BC38 - ����ˮ�ɻ���
//
void lily_number(int n) {
	if (n == (n / 10) * (n % 10) + (n / 100) * (n % 100) + (n / 1000) * (n % 1000) + (n / 10000) * (n % 10000))
		printf("%d ", n);
}
int main1() {
	for (int i = 10000;i <= 100000;i++) 
		lily_number(i);
	return 0;
}
//
//�ύţ�����ύ�����ͼ���ύͨ����2�Ž�ͼ
//
//�� 12 �⣨����⣩
//��Ŀ���ƣ�
//BC98 - ������ɾ��ָ������
//��Ŀ���ݣ�
//BC98 - ������ɾ��ָ������

int main2() {
	int arr[50] = { 0 };
	int input1 = 0;
	scanf("%d", &input1);
	for (int i = 0;i < input1;i++) 
		scanf("%d", &arr[i]);
	int input2 = 0;
	scanf("%d", &input2);

	for (int i = 0;i < input1;i++) {
		if (input2 == arr[i])
			arr[i] = 0;
	}
	for (int i = 0;i < input1;i++) {
		if (arr[i] != 0)
			printf("%d ", arr[i]);
	}
	return 0;
}

//�ο���
int main()
{
    int n = 0;//���볤��
    int arr[50] = { 0 };
    int del = 0;//ɾ��
    scanf("%d", &n);
    int i = 0;
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    scanf("%d", &del);//Ҫɾ����Ԫ��
    int j = 0;
    for (i = 0; i < n; i++)
    {
        if (arr[i] != del)
        {
            arr[j++] = arr[i];
        }
    }

    for (i = 0; i < j; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}