#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <assert.h>

//�� 3 �⣨����⣩
//��Ŀ���ƣ�
//�ַ�������
//��Ŀ���ݣ�
//дһ����������������һ���ַ��������ݡ�
void swop(char* p) {
	char* str = p;
	int start = 0;
	int end = strlen(p) - 1;
	while (start<end) {
		char t = *(p + start);
		*(p + start) = *(p + end);
		*(p + end) = t;
		start++;
		end--;
	}
}
int main1() {
	char arr[10000] = { 0 };
	gets(arr);
	swop(arr);
	printf("%s", arr);
	return 0;
}
//�ο���
void Reverse(char* str)
{
	char* left = str;
	char* right = str + strlen(str) - 1;
	while (left < right)
	{
		char temp = *left;
		*left = *right;
		*right = temp;
		++left;
		--right;
	}
}
int main01()
{
	char str[101] = { 0 };
	while (gets(str))
	{
		Reverse(str);
		printf("%s\n", str);
		memset(str, 0, sizeof(str) / sizeof(str[0]));
	}
	return 0;
}
//�� 11 �⣨����⣩
//��Ŀ���ƣ�
//�ַ�������
//��Ŀ���ݣ�
//ʵ��һ�����������������ַ����е�k���ַ���
//���磺
//ABCD����һ���ַ��õ�BCDA
//ABCD���������ַ��õ�CDAB
void revolve(char* p,int n) {
	while (n--) {
		for (int i = 0;i < strlen(p) - 1;i++) {
			char t = *(p + i);
			*(p + i) = *(p + i + 1);
			*(p + i + 1) = t;
		}
	}
}
int main2() {
	char arr[] = { "ABCD" };
	int k = 0;
	scanf("%d", &k);
	printf("����%d���ַ�ǰ��%s\n",k, arr);
	revolve(arr, k);
	printf("����%d���ַ���%s\n",k, arr);

	return 0;
}
//�ο���
//�Ƚ�Ҫ������ǰ�����һ�����CBADEFG����Ȼ�󽫺���Ҳ����CBAGFED���������������DEFGABC�����ɡ�
//����ֻ��Ҫ����ֵ�������ɣ�����дһ��������������ɾֲ����򣬴������£�
void reverse_part(char* str, int start, int end) //���ַ�����start��end��һ������
{
	int i, j;
	char tmp;
	for (i = start, j = end; i < j; i++, j--)
	{
		tmp = str[i];
		str[i] = str[j];
		str[j] = tmp;
	}
}
void leftRound(char* src, int time)
{
	int len = strlen(src);
	int pos = time % len;
	reverse_part(src, 0, pos - 1); //����ǰ��
	reverse_part(src, pos, len - 1); //������
	reverse_part(src, 0, len - 1); //��������
}
int main02() {
	char arr[] = "ABCDEFG";
	int k = 0;
	scanf("%d", &k);
	printf("����%d���ַ�ǰ��%s\n", k, arr);
	leftRound(arr, k);
	printf("����%d���ַ���%s\n", k, arr);
	return 0;
}
//�� 12 �⣨����⣩
//��Ŀ���ƣ�
//strlenʵ��
//��Ŀ���ݣ�
//ģ��ʵ�ֿ⺯��strlen
//��1
size_t simu_strlen1(const char* p) {
	assert(p);
	int count = 0;
	while (*p) {
		p++;
		count++;
	}
	return count;
}
//��2
size_t simu_strlen2(char* p) {
	char* r = p;
	while (*r)
		r++;
	return r - p;
}
int main3() {
	char arr[] = "ABCDE01234";
	printf("%zd\n", simu_strlen1(arr));	
	printf("%zd\n", simu_strlen2(arr));

	return 0;
}

//�� 13 �⣨����⣩
//��Ŀ���ƣ�
//��������ż��˳��
//��Ŀ���ݣ�
//��������ʹ����ȫ����λ��ż��ǰ�档

//��Ŀ��
//����һ���������飬ʵ��һ��������
//�����������������ֵ�˳��ʹ�����������е�����λ�������ǰ�벿�֣�
//����ż��λ������ĺ�벿�֡�
void split_odd_even(int* p,int n) {
	for (int i = 0;i < n;i++) {
		int a = 1;
		while(p[i] % 2 == 0 && a < n) {
			int t = p[i];
			if (p[i + a] % 2 != 0) {
				p[i] = p[i + a];
				p[i + a] = t;
			}
			else
				a++;
		}	
	}
}
int main4() {
	int arr[10] = { 0,1,2,3,4,5,6,7,8,9 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	for (int i = 0;i < sz-1;i++)
		scanf("%d ", &arr[i]);
	split_odd_even(arr,sz-1);
	for (int i = 0;i < sz;i++)
		printf("%d ", arr[i]);
	return 0;
}
//�ο���
//˼·��
//1. ���������±�left��right��left�����������ʼλ�ã�right�������������һ��Ԫ�ص�λ��
//2. ѭ������һ�²���
//a.���left��right��ʾ������[left, right]��Ч������b���������ѭ��
//b.left��ǰ�����ң��ҵ�һ��ż����ֹͣ
//c.right�Ӻ���ǰ�ң��ҵ�һ��������ֹͣ
//d.���left��right���ҵ��˶�Ӧ�����ݣ��򽻻�������a��
void swap_arr(int* p, int n) {
	int left = 0;
	int right = n - 1;
	int t = 0;
	while (left < right) {
		while (left < right && (p[left] % 2 == 1))
			left++;
		while (left < right && (p[right] % 2 == 0))
			right--;
		if (left < right) {
			t = p[left];
			p[left] = p[right];
			p[right] = t;
		}
	}
}
int main() {
	int arr[10] = { 0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	for (int i = 0;i < sz - 1;i++)
		scanf("%d ", &arr[i]);
	swap_arr(arr, sz);
	for (int i = 0;i < sz;i++)
		printf("%d ", arr[i]);
	return 0;
}