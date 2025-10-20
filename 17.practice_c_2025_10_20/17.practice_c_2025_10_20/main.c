#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>

//�� 1 �⣨����⣩
//��Ŀ���ƣ�
//qsortʹ����ϰ
//��Ŀ���ݣ�
//��ϰʹ�ÿ⺯����qsort����������͵�����
void print_arr(int* arr, int n) {
	for (int i = 0;i < n;i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}
int int_cmp(const void* p1, const void* p2) {
	return *(int*)p1 - *(int*)p2;
}
void test1() {
	int arr[] = { 5,4,7,2,9,1,0,3,6,8 };
	size_t sz = sizeof(arr) / sizeof(arr[0]);
	qsort(arr, sz, sizeof(arr[0]), int_cmp);
	print_arr(arr, sz);
}

typedef struct stu {
	char name[20];
	int age;
	float score;
}st;
int st_name_cmp(const void* p1, const void* p2) {
	return strcmp( ((st*)p1)->name, ((st*)p2)->name);
}
void test2(){
	st sarr[] = { {"zhangsan",18,59.9},{"lisi",20,98.0},{"wangwu",50,1.5} };
	size_t sz = sizeof(sarr) / sizeof(sarr[0]);
	qsort(sarr, sz, sizeof(sarr[0]), st_name_cmp);
}

void st_age_cmp(const void* p1, const void* p2) {
	return ((st*)p2)->age - ((st*)p1)->age;//����
}
void test3() {
	st sarr[] = { {"zhangsan",18,59.9},{"lisi",20,98.0},{"wangwu",50,1.5} };
	size_t sz = sizeof(sarr) / sizeof(sarr[0]);
	qsort(sarr, sz, sizeof(sarr[0]), st_age_cmp);
}
int st_score_cmp(const void* p1, const void* p2) {
	return ((st*)p1)->score - ((st*)p2)->score;
}
void test4() {
	st sarr[] = { {"zhangsan",18,59.9},{"lisi",20,98.0},{"wangwu",50,1.5} };
	size_t sz = sizeof(sarr) / sizeof(sarr[0]);
	qsort(sarr, sz, sizeof(sarr[0]), st_score_cmp);
}


int main1() {
	test1();//qsort������������
	test2();//qsort�ṹ������-char �ַ���
	test3();//qsort�ṹ������-int ����
	test4();//qsort�ṹ������-float ������
	return 0;
}
//�� 2 �⣨����⣩
//��Ŀ���ƣ�
//qsortģ��ʵ��
//��Ŀ���ݣ�
//ģ��qsort�Ĺ���ʵ��һ��ͨ�õ�ð������
void swop(void* p1,void* p2,size_t sz) {
	for (int i = 0;i < sz;i++) {
		char tmp = *((char*)p1 + i);
		*((char*)p1 + i) = *((char*)p2 + i);
		*((char*)p2 + i) = tmp;
	}
}
//�ο��� ʵ������Ԫ�صĽ���
void swap(char* p1, char* p2, int width)   
{
	int t = 0;
	int i = 0;
	for (i = 0; i < width; i++)
	{
		t = *p1;
		*p1 = *p2;
		*p2 = t;
		p1++;
		p2++;
	}
}

void bubble_sort(void* arr, size_t len, size_t size, int(*cmp)(const void*, const void*)) {
	for (int i = 0;i < len - 1;i++) {
		for (int j = 0;j < len - 1 - i;j++) {
			if (cmp((char*)arr + j * size, (char*)arr + (j + 1) * size) > 0) {
				swop((char*)arr + j * size, (char*)arr + (j + 1) * size, size);
			}
		}
	}
}
void test5() {
	int arr[] = { 5,4,7,2,9,1,0,3,6,8 };
	size_t sz = sizeof(arr) / sizeof(arr[0]);
	bubble_sort(arr, sz, sizeof(arr[0]), int_cmp);
	print_arr(arr, sz);
}

int main2() {
	test5();//ģ��qsort�Ĺ���ʵ��һ��ͨ�õ�ð������
	return 0;
}

int add_C(int x, int y) {
	return x + y;
}
int sub(int x, int y) {
	return x - y;
}
int mul(int x, int y) {
	return x * y;
}
int div(int x, int y) {
	return x / y;
}
//ͨ������ָ����ú�����ַ�������õĺ������ǻص�����
void calc_B(int(*p)(int, int)) {
	printf("������:");
	int x, y;
	scanf("%d %d", &x, &y);
	int ret = p(x, y);//�ص�����-add
	printf("%d\n", ret);
}
int main() {
	//�ص����� ����main ͨ������B ���ú���C
	calc_B(add_C);

	//sizeof��strlen
	int a1 = 0;
	int arr1[] = { 1,2,3,4,5 };
	printf("%zd\n", sizeof(a1));
	printf("%zd\n", sizeof(int));//sizeofֻ���������������ռ�ڴ�ռ�Ĵ�С����λ�ֽ�
	printf("%zd\n", sizeof(arr1));

	char c1[] = "abcd";
	char c2[] = { 'a','b','c','d' };
	printf("%zd\n", strlen(c1));//strlen�����ַ������ȣ���һֱ�ҵ�\0λ��
	printf("%zd\n", strlen(c2));//����Խ�����

	//sizeof����
	int a[] = { 1,2,3,4 };
	//��������������Ԫ�صĵ�ַ������ sizeof�������������� &������
	printf("%zd\n", sizeof(a));//16��4*sizeof��int��
	printf("%zd\n", sizeof(a + 0));// 4/8 ��ַ
	printf("%zd\n", sizeof(*a));//4 ������ a����Ԫ�ص�ַ��*a����Ԫ�أ���Ԫ�ش�С��int
	printf("%zd\n", sizeof(a + 1));// 4/8 ��ַ
	printf("%zd\n", sizeof(a[1]));// 4 Ԫ��
	printf("%zd\n", sizeof(&a));//  4/8 ��������ĵ�ַ
	printf("%zd\n", sizeof(*&a));// 16  *&�໥����
	printf("%zd\n", sizeof(&a + 1));// 4/8 ��������ĵ�ַ+1
	printf("%zd\n", sizeof(&a[0]));// 4/8  ��Ԫ�ص�ַ
	printf("%zd\n", sizeof(&a[0] + 1));// 4/8 �ڶ���Ԫ�صĵ�ַ

	char arr[] = { 'a','b','c','d','e','f' };
	printf("%d\n", sizeof(arr));//6 6*sizeof(char)
	printf("%d\n", sizeof(arr + 0));// 4/8  ��ַ
	printf("%d\n", sizeof(*arr));//1 ��Ԫ�ص�ַ����������Ԫ�أ���Ԫ�ش�Сchar
	printf("%d\n", sizeof(arr[1]));//1 Ԫ�ش�Сchar
	printf("%d\n", sizeof(&arr));// 4/8 ��ַ
	printf("%d\n", sizeof(&arr + 1));// 4/8
	printf("%d\n", sizeof(&arr[0] + 1));// 4/8

	//strlen����
	char ar[] = { 'a','b','c','d','e','f' };
	printf("%zd\n", strlen(ar));//�漴ֵ ����Ԫ�ؿ�ʼ���Ѱ��\0,û��\0�ͻ��ҵ��ڴ�������Ϊֹ
	printf("%zd\n", strlen(ar + 0));//�漴ֵ
	//printf("%zd\n", strlen(*ar));//err ������ ��Ԫ�ء�a��== 97��strlen��97������ַ���ᱨ�� ������
	//printf("%zd\n", strlen(ar[1]));//err ͬ�� 
	printf("%zd\n", strlen(&ar));//�漴ֵ 
	printf("%zd\n", strlen(&ar + 1));//�漴ֵ 
	printf("%zd\n", strlen(&ar[0] + 1));//�漴ֵ 

	return 0;
}