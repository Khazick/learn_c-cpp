#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

//
//第 12 题（编程题）
//题目名称：
//数组串联
//题目内容：
//题目来自leetocde，点击链接完成作答：1929.数组串联 - 力扣（LeetCode）
int* getConcatenation(int* nums, int numsSize, int* returnSize) {
    int* ans = (int*)malloc(2 * numsSize * sizeof(int));
    if (ans == NULL) {
        return 1;
    }
    for (int i = 0;i < numsSize;i++) {
        ans[i] = nums[i];
    }
    for (int i = 0;i < numsSize;i++) {
        ans[i + numsSize] = nums[i];
    }
    *returnSize = 2 * numsSize;
    return ans;
}


//第 13 题（编程题）
//题目名称：
//练习使用动态内存相关的函数
//题目内容：
//练习使用动态内存相关的4个函数，并调试观察。

int main1() {
    char* p = (char*)malloc(10 * sizeof(char));
    if (p == NULL) {
        perror("malloc");
        return 1;
    }
    for (int i = 0;i < 10;i++)
        p[i] = i + 'a';
    for (int i = 0;i < 10;i++)
        printf("%c ", p[i]);
    printf("\n");
    free(p);
    p = NULL;

    int* arr = (int*)calloc(10 , sizeof(int));
    if (arr == NULL) {
        perror("calloc");
        return 1;
    }
    for (int i = 0;i < 10;i++)
        arr[i] = i + 1;
    for (int i = 0;i < 10;i++)
        printf("%d ", arr[i]);
    printf("\n");

    int* arr2 = NULL;
    arr2 = realloc(arr, 11* sizeof(int));
    if (arr2 != NULL) {
        arr = arr2;
    }
    free(arr);
    arr = NULL;
    return 0;
}
//第 14 题（编程题）
//题目名称：
//使用malloc函数模拟开辟一个二维数组
//题目内容：
//使用malloc函数模拟开辟一个3 * 5的整型二维数组，开辟好后，使用二维数组的下标访问形式，访问空间。

int main2() {
    int** p = (int**)malloc(3 * sizeof(int*));
    if (!p)
        return 1;
    for (int i = 0;i < 3;i++) {
        p[i] = (int*)calloc(5 , sizeof(int));
    }
    for (int i = 0;i < 3;i++) {
        for (int j = 0;j < 5;j++) {
            p[i][j] = i + j;
        }         
    }
    for (int i = 0;i < 3;i++) {
        for (int j = 0;j < 5;j++) {
            printf("%d ", p[i][j]);
        }
        printf("\n");
    }
    return 0;
}
//第 15 题（编程题）
//题目名称：
//使用联合体判断大小端
//题目内容：
//使用联合体的知识，写一个函数判断当前机器是大端还是小端，如果是小端返回1，如果是大端返回0.
union n
{
    char i;
    int a;
};
void test_sys() {
    union n n1 = { 0 };
    n1.a = 1;
    if (n1.i)
        printf("小端\n");
    else
        printf("大端\n");
}
int main() {
    test_sys();
    return 0;
}