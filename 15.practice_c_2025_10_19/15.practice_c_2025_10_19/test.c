//第 1 题（单选题）
//题目名称：
//下面代码关于数组名描述不正确的是（A）
//
//int main()
//{
//	int arr[10] = { 0 };
//	return 0;
//}
//题目内容：
//A.数组名arr和& arr是一样的
//B .sizeof(arr)，arr表示整个数组
//C .& arr，arr表示整个数组
//D.除了sizeof(arr)和& arr中的数组名，其他地方出现的数组名arr，都是数组首元素的地址。
// 
//第 2 题（单选题）
//题目名称：
//下面哪个代码是错误的？(D)
//
//#include <stdio.h>
//int main()
//{
//	int* p = NULL;
//	int arr[10] = { 0 };
//	return 0;
//}
//题目内容：
//A.p = arr;
//B .int(*ptr)[10] = &arr;
//C.p = &arr[0];
//D.p = &arr;
//
//第 5 题（单选题）
//题目名称：
//关于二级指针描述描述正确的是：（B）
//
//题目内容：
//A.二级指针也是指针，只不过比一级指针更大
//B.二级指针也是指针，是用来保存一级指针的地址
//C.二级指针是用来存放数组的地址
//D.二级指针的大小是4个字节
// 
//第 6 题（单选题）
//题目名称：
//如何定义一个int类型的指针数组，数组元素个数为10个：(C)
//
//题目内容：
//A .int a[10]
//B .int(*a)[10]
//C .int* a[10];
//D .int (*a[10])(int);
// 
//第 7 题（单选题）
//题目名称：
//下面哪个是指针数组：（A）
//
//题目内容：
//A . int* arr[10];
//B .int* arr[];
//C .int** arr;
//D .int(*arr)[10];
// 
//第 8 题（单选题）
//题目名称：
//下面关于"指针"的描述不正确的是：（ A ）
//
//题目内容：
//A.当使用free释放掉一个指针内容后, 指针变量的值被置为NULL
//B .32位系统下任何类型指针的长度都是4个字节
//C.指针的数据类型声明的是指针实际指向内容的数据类型
//D.野指针是指向未分配或者已经释放的内存地址
// 
//第 9 题（单选题）
//题目名称：
//关于下面代码描述正确的是：（C）
//
//char* p = "hello bit";
//
//题目内容：
//A.把字符串hello bit存放在p变量中
//B.把字符串hello bit的第一个字符存放在p变量中
//C.把字符串hello bit的第一个字符的地址存放在p变量中
//D.*p等价于hello bit
// 
//第 10 题（单选题）
//题目名称：
//下面代码的执行结果是（C）
//
//#include <stdio.h>
//int main()
//{
//	char str1[] = "hello bit.";
//	char str2[] = "hello bit.";
//	char* str3 = "hello bit.";
//	char* str4 = "hello bit.";
//	if (str1 == str2)
//		printf("str1 and str2 are same\n");
//	else
//		printf("str1 and str2 are not same\n");
//
//	if (str3 == str4)
//		printf("str3 and str4 are same\n");
//	else
//		printf("str3 and str4 are not same\n");
//
//	return 0;
//}
//题目内容：
//A.str1 and str2 are same str3 and str4 are same
//B.str1 and str2 are same str3 and str4 are not same
//C.str1 and str2 are not same str3 and str4 are same
//D.str1 and str2 are not same str3 and str4 are not same
