#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>

//第 1 题（编程题）
//题目名称：
//qsort使用练习
//题目内容：
//练习使用库函数，qsort排序各种类型的数据
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
	return ((st*)p2)->age - ((st*)p1)->age;//倒序
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
	test1();//qsort整形数组排序
	test2();//qsort结构体排序-char 字符串
	test3();//qsort结构体排序-int 整形
	test4();//qsort结构体排序-float 浮点型
	return 0;
}
//第 2 题（编程题）
//题目名称：
//qsort模拟实现
//题目内容：
//模仿qsort的功能实现一个通用的冒泡排序
void swop(void* p1,void* p2,size_t sz) {
	for (int i = 0;i < sz;i++) {
		char tmp = *((char*)p1 + i);
		*((char*)p1 + i) = *((char*)p2 + i);
		*((char*)p2 + i) = tmp;
	}
}
//参考答案 实现数组元素的交换
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
	test5();//模仿qsort的功能实现一个通用的冒泡排序
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
//通过函数指针调用函数地址，被调用的函数就是回调函数
void calc_B(int(*p)(int, int)) {
	printf("请输入:");
	int x, y;
	scanf("%d %d", &x, &y);
	int ret = p(x, y);//回调函数-add
	printf("%d\n", ret);
}
int main() {
	//回调函数 函数main 通过函数B 调用函数C
	calc_B(add_C);

	//sizeof和strlen
	int a1 = 0;
	int arr1[] = { 1,2,3,4,5 };
	printf("%zd\n", sizeof(a1));
	printf("%zd\n", sizeof(int));//sizeof只计算变量的类型所占内存空间的大小，单位字节
	printf("%zd\n", sizeof(arr1));

	char c1[] = "abcd";
	char c2[] = { 'a','b','c','d' };
	printf("%zd\n", strlen(c1));//strlen计算字符串长度，会一直找到\0位置
	printf("%zd\n", strlen(c2));//存在越界查找

	//sizeof解析
	int a[] = { 1,2,3,4 };
	//数组名是数组首元素的地址，除了 sizeof（数组名）或者 &数组名
	printf("%zd\n", sizeof(a));//16，4*sizeof（int）
	printf("%zd\n", sizeof(a + 0));// 4/8 地址
	printf("%zd\n", sizeof(*a));//4 解引用 a是首元素地址，*a是首元素，首元素大小是int
	printf("%zd\n", sizeof(a + 1));// 4/8 地址
	printf("%zd\n", sizeof(a[1]));// 4 元素
	printf("%zd\n", sizeof(&a));//  4/8 整个数组的地址
	printf("%zd\n", sizeof(*&a));// 16  *&相互抵消
	printf("%zd\n", sizeof(&a + 1));// 4/8 整个数组的地址+1
	printf("%zd\n", sizeof(&a[0]));// 4/8  首元素地址
	printf("%zd\n", sizeof(&a[0] + 1));// 4/8 第二个元素的地址

	char arr[] = { 'a','b','c','d','e','f' };
	printf("%d\n", sizeof(arr));//6 6*sizeof(char)
	printf("%d\n", sizeof(arr + 0));// 4/8  地址
	printf("%d\n", sizeof(*arr));//1 首元素地址解引用是首元素，首元素大小char
	printf("%d\n", sizeof(arr[1]));//1 元素大小char
	printf("%d\n", sizeof(&arr));// 4/8 地址
	printf("%d\n", sizeof(&arr + 1));// 4/8
	printf("%d\n", sizeof(&arr[0] + 1));// 4/8

	//strlen解析
	char ar[] = { 'a','b','c','d','e','f' };
	printf("%zd\n", strlen(ar));//随即值 从首元素开始向后寻找\0,没有\0就会找到内存其他的为止
	printf("%zd\n", strlen(ar + 0));//随即值
	//printf("%zd\n", strlen(*ar));//err 解引用 首元素‘a’== 97，strlen把97当做地址，会报错 卡在这
	//printf("%zd\n", strlen(ar[1]));//err 同上 
	printf("%zd\n", strlen(&ar));//随即值 
	printf("%zd\n", strlen(&ar + 1));//随即值 
	printf("%zd\n", strlen(&ar[0] + 1));//随即值 

	return 0;
}