#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

//
//�� 12 �⣨����⣩
//��Ŀ���ƣ�
//���鴮��
//��Ŀ���ݣ�
//��Ŀ����leetocde����������������1929.���鴮�� - ���ۣ�LeetCode��
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


//�� 13 �⣨����⣩
//��Ŀ���ƣ�
//��ϰʹ�ö�̬�ڴ���صĺ���
//��Ŀ���ݣ�
//��ϰʹ�ö�̬�ڴ���ص�4�������������Թ۲졣

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
//�� 14 �⣨����⣩
//��Ŀ���ƣ�
//ʹ��malloc����ģ�⿪��һ����ά����
//��Ŀ���ݣ�
//ʹ��malloc����ģ�⿪��һ��3 * 5�����Ͷ�ά���飬���ٺú�ʹ�ö�ά������±������ʽ�����ʿռ䡣

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
//�� 15 �⣨����⣩
//��Ŀ���ƣ�
//ʹ���������жϴ�С��
//��Ŀ���ݣ�
//ʹ���������֪ʶ��дһ�������жϵ�ǰ�����Ǵ�˻���С�ˣ������С�˷���1������Ǵ�˷���0.
union n
{
    char i;
    int a;
};
void test_sys() {
    union n n1 = { 0 };
    n1.a = 1;
    if (n1.i)
        printf("С��\n");
    else
        printf("���\n");
}
int main() {
    test_sys();
    return 0;
}