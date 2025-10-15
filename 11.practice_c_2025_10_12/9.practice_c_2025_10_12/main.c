#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//�� 3 �⣨����⣩
//��Ŀ���ƣ�
//����쳲�������
//��Ŀ���ݣ�
//�ݹ�ͷǵݹ�ֱ�ʵ�����n��쳲�������
//���磺
//���룺5  �����5
//���룺10�� �����55
//���룺2�� �����1

int Fib1(int n) {
	if (n <= 2)
		return 1;
	else
		return Fib1(n - 1) + Fib1(n - 2);
}
int Fib2(int n) {
	int a = 1;
	int b = 1;
	int c = 1;
	while (n > 2) {
		c = a + b;
		a = b;
		b = c;
		n--;
	}
	return c;
}

int main1() {
	int input = 0;
	scanf("%d", &input);
	//�ݹ鷨
	int r1 = Fib1(input);
	printf("%d\n", r1);
	//�ǵݹ鷨
	int r2 = Fib2(input);
	printf("%d\n", r2);

	return 0;
}
//�� 4 �⣨����⣩
//��Ŀ���ƣ�
//�ݹ�ʵ��n��k�η�
//��Ŀ���ݣ�
//��дһ������ʵ��n��k�η���ʹ�õݹ�ʵ�֡�
int power(int n, int k) {
	if (k == 0)
		return 1;
	else
		return n * power(n, k - 1);
}
int main2() {
	int base = 0;
	int index = 0;
	scanf("%d %d", &base, &index);
	int r = power(base,index);
	printf("%d\n", r);

	return 0;
}
//�� 5 �⣨����⣩
//��Ŀ���ƣ�
//����һ������ÿλ֮�ͣ��ݹ�ʵ�֣�
//��Ŀ���ݣ�
//дһ���ݹ麯��DigitSum(n)������һ���Ǹ����������������������֮��
//
//���磬����DigitSum(1729)����Ӧ�÷���1 + 7 + 2 + 9�����ĺ���19
//
//���룺1729�������19
int DigitSum(int n) {	
	if (n > 9)
		return DigitSum(n / 10) + n % 10;
	else
		return n;
}
int main3() {
	int input = 0;
	scanf("%d", &input);
	int r = DigitSum(input);
	printf("%d\n", r);

	return 0;
}
//�� 6 �⣨����⣩
//��Ŀ���ƣ�
//��׳�
//��Ŀ���ݣ�
//�ݹ�ͷǵݹ�ֱ�ʵ����n�Ľ׳ˣ���������������⣩
int Fact1(int n) {
	if (n == 0)
		return 1;
	else
		return n * Fact1(n - 1);
}
int Fact2(int n) {
	int r = 1;
	for (int i = 1;i <= n;i++) {
		r *= i;
	}
	return r;
}

int main4() {
	int input = 0;
	scanf("%d", &input);
	//�ݹ鷨
	printf("%d\n", Fact1(input));
	//�ǵݹ鷨
	printf("%d\n", Fact2(input));

	return 0;
}
//�� 7 �⣨����⣩
//��Ŀ���ƣ�
//��ӡһ������ÿһλ
//��Ŀ���ݣ�
//�ݹ鷽ʽʵ�ִ�ӡһ��������ÿһλ
void Print1(int n) {
	if (n > 9)
		Print1(n / 10);
	printf("%d ", n % 10);
}
int main5() {
	int input = 0;
	scanf("%d", &input);
	Print1(input);
	return 0;
}