#include "arr01.h" //多文件，使用自定义头文件，用双引号而不是尖括号

//第 6 题（编程题）
//题目名称：
//二分查找 - 函数实现
//题目内容：
//写一个二分查找函数
//功能：在一个升序数组中查找指定的数值，找到了就返回下标，找不到就返回 - 1.
//int bin_search(int arr[], int left, int right, int key)
//// arr 是查找的数组
////left 数组的左下标
////right 数组的右下标
////key 要查找的数字
int bin_search(int arr[], int left, int right, int key) {//形参是实参的临时拷贝
	while (left <= right) {
		int mid = left + (right - left) / 2;
		if (key < arr[mid])
			right = mid - 1;
		else if (key > arr[mid])
			left = mid + 1;
		else
			return mid;
	}
	return -1;
}
int main1() {
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	int left = 0;
	int right = sizeof(arr) / sizeof(arr[0]) - 1;
	int key = 0;
	scanf("%d", &key);
	int ret = bin_search(arr, left, right, key);
	printf("%d\n", ret);
	return 0;
}
//
//第 7 题（编程题）
//题目名称：
//乘法口诀表
//题目内容：
//实现一个函数，打印乘法口诀表，口诀表的行数和列数自己指定
//
//如：输入9，输出9 * 9口诀表，输出12，输出12 * 12的乘法口诀表。
void multiplication_table(int input) {
	for (int i = 1;i <= input;i++) {
		for (int j = 1;j <= i;j++)
			printf("%3d*%-3d=%3d ", j, i, i * j);
		printf("\n");
	}
}
int main2() {
	int input = 0;
	scanf("%d", &input);
	multiplication_table(input);
	return 0;
}

//第 8 题（编程题）
//题目名称：
//函数判断闰年
//题目内容：
//实现函数判断year是不是润年。
int leap_year(int y) {
	return (y % 4 == 0 && y % 100 != 0 || y % 400 == 0) ? 1 : 0;//return后可以跟数值，也可以跟表达式；只有在void类型时，可以什么都不跟
}
void is_leap_year(int x,int y) {
	if (x > 0)
		printf("%d年是闰年。\n", y);
	else
		printf("%d年不是闰年。\n", y);
}
int main3() {
	int year = 0;
	scanf("%d", &year);
	is_leap_year(leap_year(year),year);//链式访问，将一个函数的返回值作为另一个函数的参数
	return 0;
}

//第 9 题（编程题）
//题目名称：
//函数判断素数
//题目内容：
//实现一个函数is_prime，判断一个数是不是素数。
//
//利用上面实现的is_prime函数，打印100到200之间的素数。
bool is_prime(int x) {
	int flag = 1;
	for (int i = 2;i < x;i++) {
		if (x % i == 0) {
			flag = 0;
			break;
		}
	}
	if(flag == 1)
		return true;//return 执行后 ，函数彻底返回，后续代码不再执行
	return false;//return存在if语句中，需要将每种情况都设置一个返回值，否则会报错
}
int main4() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = n;i <= m;i++) {
		if (is_prime(i)) {
			printf("%d ", i);
		}
	}
	return 0;
}
//答案参考，注意：使用sqrt函数，1-10的质数无法判断
int is_prime1(int n){
	int i = 0;
	for (i = 2; i <= sqrt(n); i++){
		if (0 == n % i){
			return 0;
		}
	}
	return 1;
}
int main04()
{
	int i = 0;
	for (i = 100; i <= 200; i++) {
		if (is_prime1(i) == 1) {
			printf("%d ", i);
		}
	}
	return 0;
}

//第 10 题（编程题）
//题目名称：
//使用函数实现数组操作
//题目内容：
//创建一个整形数组，完成对数组的操作
//
//实现函数init() 初始化数组为全0
//实现print()  打印数组的每个元素
//实现reverse()  函数完成数组元素的逆置。
//要求：自己设计以上函数的参数，返回值。

void init(int arr[], int n) {//形参是一维数组，数组大小可以不填；如果是二维数组，行可以省，列不可以省
	for (int i = 0;i < n; i++)
		arr[i] = 0;//形参和实参的数组是同一个数组，形参数组修改会影响实参数组
}
void print(int arr[],int n) {//函数声明、定义，如果放在main后面将会报错
	for (int i = 0;i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

void scan(int arr[], int n);//除非先在之前做一个声明，函数的定义是一个特殊的声明

void reverse(int arr[],int n) {
	int left = 0;
	int right = n - 1;
	while (left < right) {
		int tmp = arr[left];
		arr[left] = arr[right];
		arr[right] = tmp;
		left++;
		right--;
	}
}

int main05() {
	arr_01();//多文件使用
	return 0;
}

void scan(int arr[], int n) {//不在上面做说明会报错
	for (int i = 0;i < n;i++)
		scanf("%d", &arr[i]);
}

//static 和 extern
extern void printMessage();// 声明外部变量/函数

int main() {
	static int a = 0;//用来修饰局部/全局变量/函数，使其变为静态
	// 调用外部函数
	printMessage();
	return 0;
}