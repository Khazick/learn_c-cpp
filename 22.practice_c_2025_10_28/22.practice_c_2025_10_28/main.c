#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//第 11 题（编程题）
//题目名称：
//BC38 - 变种水仙花数
//题目内容：
//BC38 - 变种水仙花数
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
//提交牛客网提交代码截图和提交通过的2张截图
//
//第 12 题（编程题）
//题目名称：
//BC98 - 序列中删除指定数字
//题目内容：
//BC98 - 序列中删除指定数字

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

//参考答案
int main()
{
    int n = 0;//输入长度
    int arr[50] = { 0 };
    int del = 0;//删除
    scanf("%d", &n);
    int i = 0;
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    scanf("%d", &del);//要删除的元素
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