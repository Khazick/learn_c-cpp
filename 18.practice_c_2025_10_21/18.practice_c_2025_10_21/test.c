//第 1 题（单选题）
//题目名称：
//下面代码中print_arr函数参数设计哪个是正确的？（C）
//
//int arr[3][5] = { 1,2,3,4,5,6,7,8,9,10 };
//print_arr(arr, 3, 5);
//题目内容：
//A .void print_arr(int arr[][], int row, int col);
//B .void print_arr(int* arr, int row, int col);
//C .void print_arr(int(*arr)[5], int row, int col);
//D .void print_arr(int(*arr)[3], int row, int col);
// 
//第 2 题（多选题）
//题目名称：
//下面test函数设计正确的是：（ BD ）
//
//char* arr[5] = { "hello", "bit" };
//
//test(arr);
//
//题目内容：
//A .void test(char* arr);
//B .void test(char** arr);
//C .void test(char arr[5]);
//D .void test(char* arr[5]);
//第 3 题（单选题）
//题目名称：
//下面程序的结果是：（B）
//
//int main()
//{
//	int a[5] = { 5, 4, 3, 2, 1 };
//	int* ptr = (int*)(&a + 1);
//	printf("%d,%d", *(a + 1), *(ptr - 1));
//	return 0;
//}
//题目内容：
//A .5, 1
//B .4, 1
//C .4, 2
//D .5, 2
//第 4 题（单选题）
//题目名称：
//下面程序的结果是：（A）
//
//int main()
//{
//	int aa[2][5] = { 10,9,8,7,6,5,4,3,2,1 };
//	int* ptr1 = (int*)(&aa + 1);
//	int* ptr2 = (int*)(*(aa + 1));
//	printf("%d,%d", *(ptr1 - 1), *(ptr2 - 1));
//	return 0;
//}
//题目内容：
//A .1, 6
//B .10, 5
//C .10, 1
//D .1, 5