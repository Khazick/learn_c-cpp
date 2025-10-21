#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>

int main0() {
	//字符数组 
	char arr[] = "abcdef";
	printf("%zd\n", sizeof(arr));//7   7*sizeof(char)  a b c d e f \0
	printf("%zd\n", sizeof(arr + 0));// 4/8 地址 
	printf("%zd\n", sizeof(*arr));//1  sizeof(char) <-> *arr=*(arr+0)=arr[0] 
	printf("%zd\n", sizeof(arr[1]));//1 同上
	printf("%zd\n", sizeof(&arr));// 4/8 地址
	printf("%zd\n", sizeof(&arr + 1));//4/8 地址 整个地址+1
	printf("%zd\n", sizeof(&arr[0] + 1));// 4/8 地址 a的地址+1
	printf("\n");
	printf("%zd\n", strlen(arr));//6 截止到\0之前的元素个数
	printf("%zd\n", strlen(arr + 0));//6 同上
	//printf("%d\n", strlen(*arr));//err -> 解引用首元素地址 = 首元素 = ‘a’= 97，错误地址
	//printf("%d\n", strlen(arr[1]));//err 同上
	printf("%zd\n", strlen(&arr));//6 arr的地址，起始地址就是首元素地址，从首元素地址找到\0为止
	printf("%zd\n", strlen(&arr + 1));//随即值 arr的整个地址+1，在内存中找到第一个\0为止，大小不确定
	printf("%zd\n", strlen(&arr[0] + 1));//5 从a的地址+1 == b的地址，从b开始找到\0为止
	printf("\n");

	//字符指针
	char* p = "abcdef";
	printf("%zd\n", sizeof(p));// 4/8 p是指针=地址，是地址，大小就是4/8
	printf("%zd\n", sizeof(p + 1));// 4/8 地址 p是首元素地址，+1=第二个元素的地址
	printf("%zd\n", sizeof(*p));//1  *p=*(p+0)=p[0] = 首元素
	printf("%zd\n", sizeof(p[0]));//1 同上
	printf("%zd\n", sizeof(&p));// 4/8 地址 == char** 
	printf("%zd\n", sizeof(&p + 1));// 4/8 地址，跳过一个char*类型
	printf("%zd\n", sizeof(&p[0] + 1));// 4/8 地址，b的地址
	printf("\n");
	printf("%zd\n", strlen(p));//6 p是首元素地址，从首元素地址找到\0
	printf("%zd\n", strlen(p + 1));//5 首元素地址+1，然后找到\0
	//printf("%zd\n", strlen(*p));//err 解引用首元素地址=首元素 = ‘a'=97，错误地址
	//printf("%zd\n", strlen(p[0]));//err 同上
	printf("%zd\n", strlen(&p));//6   p的首元素地址=字符串首元素地址 char**，从该地址找到\0 
	printf("%zd\n", strlen(&p + 1));//随即值 跳过一个p类型
	printf("%zd\n", strlen(&p[0] + 1));//5 b的地址开始找到\0
	printf("\n");

	//二维数组
	int a[3][4] = { 0 };
	printf("%zd\n", sizeof(a));// 48  整个数组的大小 3*4*sizeof(int)
	printf("%zd\n", sizeof(a[0][0]));//4 首元素大小 int 
	printf("%zd\n", sizeof(a[0]));//16 4*sizeof(int)第一行的一维数组的地址，单独放在sizeof=第一行一维数组大小
	printf("%zd\n", sizeof(a[0] + 1));//4/8 第一行一维数组地址+1 = 第二行一维数组的地址，地址大小4、8
	printf("%zd\n", sizeof(*(a[0] + 1)));//4   *(a[0]+1)=a[0][1]==第一行第二列的元素
	printf("%zd\n", sizeof(a + 1));//4/8 首元素地址+1=a[1]的地址
	printf("%zd\n", sizeof(*(a + 1)));//16 第二行一维数组的地址，单独放在sizeof里  *(a + 1)=a[1]
	printf("%zd\n", sizeof(&a[0] + 1));//4/8    &a[0] + 1=&*(a+0)+1=a+1
	printf("%zd\n", sizeof(*(&a[0] + 1)));//16  *(&a[0] + 1)=*(&*(a+0)+1)=*(a+1)=a[1]
	printf("%zd\n", sizeof(*a));//16   a首元素地址 *a=*(a+0)=a[0]
	printf("%zd\n", sizeof(a[3]));//16 sizeof内不进行计算
	printf("\n");
	return 0;
}
//题目1
int main1()
{
	int a[5] = { 1, 2, 3, 4, 5 };
	int* ptr = (int*)(&a + 1);
	printf("%d,%d", *(a + 1), *(ptr - 1));
	return 0;
}
//程序的结果是什么？
//(int*)强制类型转换为int*指针，&a+1 = 指针跳过整个a数组，指针ptr此时在元素5之后的位置
//*(a+1)=a[1]=2,*(ptr-1)=5
//2,5

//题目2
//在X86环境下
//假设结构体的⼤⼩是20个字节
//程序输出的结果是啥？
struct Test
{
	int Num;
	char* pcName;
	short sDate;
	char cha[2];
	short sBa[4];
}*p = (struct Test*)0x100000;
int main2()
{
	printf("%p\n", p + 0x1);
	printf("%p\n", (unsigned long)p + 0x1);
	printf("%p\n", (unsigned int*)p + 0x1);
	return 0;
}
//x86下，结构体Test大小为 4+4+2+1*2+2*4=20
//现在p的指针指向 0x100000
//p + 0x1=p+1-->指针+1，跳过一个指针类型，故，p+1=跳过20个字节 == 0x100000+20D==0x100000+0x14=0x100014
//(unsigned long)p + 0x1,p被强制类型转化为整形，整形+1 == 0x100000+0x1= 0x100001
//(unsigned int*)p + 0x1,p被强制类型转换为无符号整形指针，故，+1跳过4个字节 == 0x100000+0x4=0x100004
//屏幕打印：
//0x100014
//0x100001
//0x100004

//题目3
int main3()
{
	int a[3][2] = { (0, 1), (2, 3), (4, 5) };
	int* p;
	p = a[0];
	printf("%d", p[0]);
	return 0;
}
//结果是？
//逗号表达式，从左向右运算，最终返回最右边表达式的结果
//故，int a[3][2] = { (0, 1), (2, 3), (4, 5) } == {1，3，5}
//p指针指向a[0]的地址，此时 p[0] = *(p+0)=*p = 1
//结果就为 1

//题目4
//假设环境是x86环境，程序输出的结果是啥？
int main4()
{
	int a[5][5];
	int(*p)[4];
	p = a;
	printf("%p,%d\n", &p[4][2] - &a[4][2], &p[4][2] - &a[4][2]);
	return 0;
}
//把p = a ，p是数组指针，数组大小为4，但a的一位数组大小为5
//故此时p[4][2]=a[3][3],那么&p[4][2] - &a[4][2] = &a[3][3] - &a[4][2] = -4
//%p 打印地址
//10000000 00000000 00000000 00000100源码 
//11111111 11111111 11111111 11111011补码
//11111111 11111111 11111111 11111100反码
//转换为地址：
//  F   F    F  F     F   F    F   C
//%d 打印整形 -4
//故屏幕上打印的结果为:
//FFFFFFFC , -4

//题目5
int main5()
{
	int aa[2][5] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int* ptr1 = (int*)(&aa + 1);
	int* ptr2 = (int*)(*(aa + 1));
	printf("%d,%d", *(ptr1 - 1), *(ptr2 - 1));
	return 0;
}
//&aa + 1是跳过整个数组，此时ptr1指向10之后的位置
//*(aa + 1)=aa[1] 是数组第二行的首元素地址，此时ptr2指向6
//*(ptr1 - 1) = 10, *(ptr2 - 1)=5
//打印10，5

//题目6
int main6()
{
	char* a[] = { "work","at","alibaba" };
	char** pa = a;
	pa++;
	printf("%s\n", *pa);
	return 0;
}
//char* a[]是指针数组，分别存放‘work’地址、‘at’地址、‘alibaba’地址
//把 把a赋给pa，此时pa指向a首元素的地址，即‘w'，pa++= 跳过一个char*类型，此时pa指向“at”地址
//故，*p="at"

//题目7
int main7()
{
	char* c[] = { "ENTER","NEW","POINT","FIRST" };
	char** cp[] = { c + 3,c + 2,c + 1,c };
	char*** cpp = cp;
	printf("%s\n", **++cpp);
	printf("%s\n", *-- * ++cpp + 3);
	printf("%s\n", *cpp[-2] + 3);
	printf("%s\n", cpp[-1][-1] + 1);
	return 0;
}
//c分别指向"ENTER","NEW","POINT","FIRST"的首字母地址
//cp 又指向c + 3,c + 2,c + 1,c的地址，即"FIRST","POINT","NEW","ENTER"
//cpp指向cp，此时cpp->"FIRST"
//1. **++cpp == **(++cpp) --> ++cpp,此时cpp->"POINT",然后解引用，打印 POINT
// 
//2. *-- * ++cpp + 3 == *(  --( *(++cpp) )  )  + 3  --> 先++cpp，此时cpp->"NEW"，然后解引用，此时cpp->c+1,
// 再 --，此时(c+1)-- = c,cpp->c,然后解引用，此时cpp->"ENTER"，再+3，打印“ER”
// 
//3. *cpp[-2] + 3 == **(cpp-2) + 3 -->cpp-2，此时cpp->"ENTER"，但cpp-2 ->c+3->"FIRST" ,然后解引用，再+3 打印“ST”
// 
//4. cpp[-1][-1] + 1 == *( *(cpp-1)-1 ) +1 --> 此时cpp->c->"ENTER",cpp-1 ->c+2->"POINT",然后解引用,
// 然后再-1 ，此时 ->"POINT"-1->"NEW",然后+1，打印 “EW”
//最后屏幕打印：
//POINT
//ER
//ST
//ST