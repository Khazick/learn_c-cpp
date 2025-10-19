#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdbool.h>
//
//第 3 题（编程题）
//题目名称：
//使用指针打印数组内容
//题目内容：
//写一个函数打印arr数组的内容，不使用数组下标，使用指针。
//arr是一个整形一维数组。
void print_arr(int* arr, int sz) {
	for (int i = 0;i < sz;i++) {
		printf("%d ", *(arr + i));
	}
	printf("\n");
}
int main1() {
	int arr[5] = { 1,2,3,4,5 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	print_arr(arr, sz);
	return 0;
}

//第 4 题（编程题）
//题目名称：
//冒泡排序
//题目内容：
//实现一个对整形数组的冒泡排序
void input_arr(int* arr, int sz) {
	for (int i = 0;i < sz;i++) {
		scanf("%d", &arr[i]);
	}
}
void bubble_sort(int* arr,int sz) {
	for (int i = 0;i < sz;i++) {
		int flag = 1;
		for (int j = 0;j < sz - 1 - i;j++) {
			if (arr[j] > arr[j + 1]) {
				flag = 0;
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
		if (flag)
			break;
	}
}
int main2() {
	int arr[5] = { 0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	input_arr(arr, sz);
	bubble_sort(arr, sz);
	print_arr(arr, sz);
	return 0;
}

//第 11 题（编程题）
//题目名称：
//字符串旋转结果
//题目内容：
//写一个函数，判断一个字符串是否为另外一个字符串旋转之后的字符串。
//例如：给定s1 = AABCD和s2 = BCDAA，返回1
//给定s1 = abcd和s2 = ACBD，返回0.
//AABCD左旋一个字符得到ABCDA
//AABCD左旋两个字符得到BCDAA
//AABCD右旋一个字符得到DAABC
int judge_turn(char* s1, char* s2,int sz) {
	int count = 0;
	int flag = 0;
	for (int i = 0;i < sz-1;i++) {
		for (int j = 0;j < sz-1;j++) {
			if (s1[i] == s2[j]) {
				flag = j;
				break;
			}
		}
	}
	for (int i = 0;i < flag;i++) {
		char tmp = s1[0];
		for (int j = 0;j < sz-1;j++) {
			s1[j] = s1[j + 1];
		}
		s1[sz - 2] = tmp;
	}
	for (int i = 0;i < sz;i++) {
		if (s1[i] == s2[i])
			count++;
	}
	if (count == sz) {

		return 1;
	}
	else
		return 0;
}
int main3() {
	char s1[6] = "AABCD";
	char s2[6] = "BCDAA";
	int sz = sizeof(s1) / sizeof(s1[0]);
	int ret = judge_turn(s1,s2,sz);
	printf("%d\n", ret);
	return 0;
}
//参考答案
int findRound(const char* src, char* find){
	char tmp[256] = { 0 }; //用一个辅助空间将原字符串做成两倍原字符串
	strcpy(tmp, src); //先拷贝一遍
	strcat(tmp, src); //再连接一遍
	return strstr(tmp, find) != NULL; //看看找不找得到
}
int main03() {
	char s1[6] = "AABCD";
	char s2[6] = "BCDAA";
	int ret = findRound(s1, s2);
	printf("%d\n", ret);
}
//第 12 题（编程题）
//题目名称：
//杨氏矩阵
//题目内容：
//有一个数字矩阵，矩阵的每行从左到右是递增的，矩阵从上到下是递增的，请编写程序在这样的矩阵中查找某个数字是否存在。
//要求：时间复杂度小于O(N);
//O(N^2)
int find_num1(int arr[][5],int n) {
	for (int i = 0;i < 5;i++) {
		for (int j = 0;j < 5;j++) {
			if (n == arr[i][j]) {
				return 1;
			}
			else
				return 0;
		}
	}
}
//0(N)  
// 思路：从右上角开始查找，右上角的元素比我们要查找元素小，我们就可以去掉右上角元素所在的这一行；
// 右上角的元素比我们要查找的元素大，我们就可以去掉右上角元素所在的这一列。
// 然后依然找右上角的元素继续和要查找的元素与比较。这样每一次比较去掉一行或者去掉一列。
int find_num2(int arr[][5],int n) {
	int i = 0;
	int j = 4;
	while (i<5 && j>-1) {
		if (arr[i][j] < n)
			i++;
		else if (arr[i][j] > n)
			j--;
		else
			return 1;
	}
	return 0;
}
int main4() {
	int arr[5][5] = { 1,2,3,4,5, 2,3,4,5,6, 3,4,5,6,7 };
	int input = 0;
	scanf("%d", &input);
	int ret1 = find_num1(arr,input);
	int ret2 = find_num2(arr, input);
	if(ret2)
		printf("存在\n");
	else
		printf("不存在\n");
	return 0;
}

//参考答案
int findnum(int a[][3], int x, int y, int f) //第一个参数的类型需要调整
{
	int i = 0, j = y - 1; //从右上角开始遍历
	while (j >= 0 && i < x)
	{
		if (a[i][j] < f) //比我大就向下
		{
			i++;
		}
		else if (a[i][j] > f) //比我小就向左
		{
			j--;
		}
		else
		{
			return 1;
		}
	}
	return 0;
}
int main04()
{
	int a[][3] = { {1, 3, 5},
				  {3, 5, 7},
				  {5, 7, 9} }; //一个示例

	if (findnum(a, 3, 3, 2))
	{
		printf("It has been found!\n");
	}
	else
	{
		printf("It hasn't been found!\n");
	}
	return 0;
}
//第 13 题（编程题）
//题目名称：
//猜凶手
//题目内容：
//日本某地发生了一件谋杀案，警察通过排查确定杀人凶手必为4个嫌疑犯的一个。
//以下为4个嫌疑犯的供词:
//A说：不是我。
//B说：是C。
//C说：是D。
//D说：C在胡说 == D：不是我
//已知3个人说了真话，1个人说的是假话。
//现在请根据这些信息，写一个程序来确定到底谁是凶手。
//参考答案
int main5() {
	for (int killer = 'A';killer <= 'D';killer++) {
		if ((killer != 'A'/*A说：不是我*/) + (killer == 'C'/*B说：是C*/) 
			+ (killer == 'D'/*C说：是D*/) + (killer != 'D'/*D说：C在胡说*/) == 3)
			printf("凶手是%c", killer);
	}
	return 0;
}
//第 14 题（编程题）
//题目名称：
//杨辉三角
//题目内容：
//在屏幕上打印杨辉三角。
//1
//1 1
//1 2 1
//1 3 3 1
//……

int main6() {
	int arr[10][10] = { 1 };
	for (int i = 1;i < 10;i++) {
		for (int j = 0;j < 10;j++) {
			if (j == 0)
				arr[i][j] = 1;
			else
				arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
		}
	}
	for (int i = 0;i < 10;i++) {
		for (int j = 0;j < 10;j++) {
			if (arr[i][j] != 0)
				printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}//参考答案
//改进：由于我在填第n行的杨辉三角时，只跟第n - 1行的杨辉三角产生联系，不会跟之前的有联系，
// 所以没必要保存每一行的杨辉三角，填一行打一行就行了，这样能让空间复杂度从n ^ 2降低到n。
// 但是在填数据的时候不能对之前的数据覆盖，所以需要从后向前填。
// 而填杨辉三角顺序对结果是没有影响的，所以可以实现。

void yangHuiTriangle(int n)
{
	int data[30] = { 1 };
	int i, j;
	printf("1\n"); //第一行就直接打印了
	for (i = 1; i < n; i++) //从第二行开始
	{
		for (j = i; j > 0; j--) //从后向前填，避免上一行的数据在使用前就被覆盖
		{
			data[j] += data[j - 1]; //公式同上，由于变成了一维，公式也变简单了。
		}
		for (j = 0; j <= i; j++) //这一行填完就直接打印了。
		{
			printf("%d ", data[j]);
		}
		putchar('\n');
	}
}
int main06() {
	int n = 0;
	scanf("%d", &n);
	yangHuiTriangle(n);
	return 0;
}

void test1(int arr[])//参数写成数组形式，本质上还是指针
{
	printf("%d\n", sizeof(arr));//计算⼀个指针变量的⼤⼩
}
void test2(int* arr)//参数写成指针形式
{
	printf("%d\n", sizeof(arr));//计算⼀个指针变量的⼤⼩
}


int main() {
	//数组名
	int arr[5] = { 1,2,3,4,5};
	int* p = &arr[0];
	//数组名==首元素地址
	printf("arr=%p\n", arr);
	printf("&arr[0]=%p\n", &arr[0]);
	//&数组名 == 整个元素的地址
	printf("&arr=%p\n", &arr);
	//数组名==首元素地址
	printf("arr+1=%p\n", arr + 1);
	printf("&arr[0]+1=%p\n", &arr[0] + 1);//跳过一个元素大小
	//&数组名 == 整个元素的地址
	printf("&arr + 1=%p\n", &arr + 1);//跳过一个数组大小
	//sizeof中的arr代表整个数组，而非首元素地址
	printf("%zd\n", sizeof(arr));

	//一维数组传参
	test1(arr);
	test2(arr);

	//二级指针
	int a = 10;
	printf("%d\n", a);
	int* pa = &a;
	int** ppa = &pa;
	**ppa = 5;//二级指针解引用
	printf("%d\n", a);

	//指针数组*
	//模拟二位数组
	int arr1[] = { 1,2,3,4,5 };
	int arr2[] = { 2,3,4,5,6 };
	int arr3[] = { 3,4,5,6,7 };
	int* parr[3] = { &arr1,&arr2,&arr3 };
	for (int i = 0;i < 3;i++) {
		for (int j = 0;j < 5;j++)
			printf("%d ", parr[i][j]);
		printf("\n");
	}
	//上述的代码模拟出⼆维数组的效果，实际上并⾮完全是⼆维数组，因为每⼀⾏并⾮是连续的

	//字符指针变量
	char ch = 'a';
	char* pch = &ch;
	*pch = 'b';
	printf("%c\n", ch);
	//字符串指针
	char* ps = "hello";//常量字符串 存在内存中的 只读数据区
	//*ps = "bbaa";//字符串常量，不可修改
	printf("%s\n", ps);
	
	//数组指针*
	int(*p)[5] = &arr;//初始化
	//注意与指针数组区分

	return 0;
}