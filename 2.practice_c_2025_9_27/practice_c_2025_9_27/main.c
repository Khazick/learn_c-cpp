#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdbool.h>

int x = 100;

int main()
{
	//1.注释
	//常用
	/* 不常用，且前后符号就近匹配 */

	//2.数据类型 及其长度
	printf("%zd\n", sizeof(char));
	printf("%zd\n", sizeof(bool));
	printf("%zd\n", sizeof(short));
	printf("%zd\n", sizeof(int));
	printf("%zd\n", sizeof(long));
	printf("%zd\n", sizeof(long long));
	int a = 0;
	printf("%zd\n", sizeof(a += 3));//sizeof内部不计算
	printf("\n");

	//3. signed/unsigned
	//signed int = int
	int b = 1;
	unsigned c = 1;
	printf("%d\n", b);
	printf("%u\n", c);//unsigned打印用%u
	printf("%d\n", c);
	b = -1;
	c = -1;
	printf("%d\n", b);
	printf("%u\n", c);
	printf("%d\n", c);

	//4.全局变量、局部变量
	printf("\n");
	int x = 1;
	printf("%d\n", x);//全局和局部同名时，优先用局部

	//5.加、减、乘、除、取模
	printf("\n");
	int q = 1;
	int w = 2;
	int e = 0;
	float r = 0.5;
	int t = -2;
	e = q + w;
	printf("%d\n", e);
	printf("%d\n", q+w);
	e = q - w;
	printf("%d\n", e);
	printf("%d\n", q - w);
	e = q * w;
	printf("%d\n", e);
	printf("%d\n", q * w);
	e = q / w;
	printf("%d\n", e);
	printf("%d\n", q / w);
	e = q / r;
	printf("q / r = %d\n", e);//e是int类型
	printf("%f\n", q / r);//除 必须 除号两边之一有一个浮点数
	e = q % w;//取模只能整数运算
	printf("%d\n", e);
	printf("%d\n", q % w);
	//printf("%f\n", q % r);浮点数取模会报错
	printf("%d\n", 3 % t);
	printf("%d\n", -3 % t);//负数取模，结果正负取决于取模左边的数的符号
	printf("%d\n", 3 % -t);

	//6.赋值
	printf("\n");
	e = q + 1;//赋值
	e = a = q + 1;//连续赋值
	e = e + a;//符合赋值
	e += a;
	e++;//单目操作符++，--
	int y = 0;
	printf("%d\n", y++);//后置++ 先用后加
	y = 0;
	printf("%d\n", ++y);//前置++ 先加后用

	//7.强制类型转换
	int d = (int)3.14;
	printf("%d\n", d);

	return 0;
}
