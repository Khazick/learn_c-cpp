#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

// 
//第 4 题（编程题）
//题目名称：
//BC18 - 计算带余除法
//题目内容：
//BC18 - 计算带余除法
int main1() {
	int a = 0;
	int b = 0;
	scanf("%d %d", &a, &b);
	printf("%d %d", a / b, a % b);
	return 0;
}

//
//第 5 题（编程题）
//题目名称：
//BC41 - 你是天才吗？
//题目内容：
//BC41 - 你是天才吗？
int main2() {
	int a = 0;
	while (scanf("%d", &a) != EOF) {
		if (a >= 140)
			printf("Genius");
	}
	return 0;
}
//
//第 6 题（编程题）
//题目名称：
//BC49 - 判断2个数的大小
//题目内容：
//BC49 - 判断2个数的大小
int main3() {
	int a = 0;
	int b = 0;
	while (scanf("%d %d", &a, &b) != EOF) {
		if (a > b)
			printf("%d>%d\n", a, b);
		else if (a == b)
			printf("%d=%d\n", a, b);
		else
			printf("%d<%d\n", a, b);
	}
	return 0;
}
//
//第 7 题（编程题）
//题目名称：
//BC83 - 被5整除问题
//题目内容：
//BC83 - 被5整除问题
int main4() {
	int a = 0;
	scanf("%d", &a);
	if (a % 5 == 0)
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}
//
//第 8 题（编程题）
//题目名称：
//BC56 - 线段图案
//题目内容：
//BC56 - 线段图案
int main5() {
	int a = 0;
	while (scanf("%d", &a) != EOF) {
		for (int i = 0;i < a;i++)
		{
			printf("%c", '*');
		}
		printf("\n");
	}
	return 0;
}
//
//第 11 题（编程题）
//题目名称：
//打印3的倍数的数
//题目内容：
//写一个代码打印1 - 100之间所有3的倍数的数字
int main6() {
	
	for (int i = 1;i < 100;i++) {
		if (i % 3 == 0)
			printf("%d ", i);
	}
	printf("\n");
	return 0;
}
//第 12 题（编程题）
//题目名称：
//从大到小输出
//题目内容：
//写代码将三个整数数按从大到小输出。
//
//例如：
//
//输入：2 3 1
//输出：3 2 1
int main7() {
	int a = 0;
	int b = 0;
	int c = 0;
	int tmp;
	scanf("%d %d %d", &a, &b, &c);
	if (a < b) {
		tmp = a;
		a = b;
		b = tmp;
	}
	if (a < c) {
		tmp = a;
		a = c;
		c = tmp;
	}
	if (b < c) {
		tmp = b;
		b = c;
		c = tmp;
	}
	printf("%d %d %d\n", a, b, c);
	return 0;
}


int main() {
	//1.printf 限定宽度 显示正负 限定小数位数 限定字符串位数
	printf("%s说有%d个人成绩为%c\n", "帅哥", 5, 'A');//占位符和参数一一对应，n个占位符有n+1个参数
	printf("O%3d,%-3dO\n", 1, 2);//正为右对齐，负为左对齐，限定为至少三格
	printf("%+d\n", 11);
	printf("%+d\n", -11);//%后加上+显示参数的正负符号
	printf("%6.1f\n", 123.321);//%后小数点前，限定至少的格子数，小数点后限定最多的小数位数，并且可能会丢失小数点后的精度
	printf("%*.*f\n", 6,1,123.321);//用*可以代替%后的限定数字
	printf("%.5s\n", "helloworld");//在%后用 小数点后限定数字（.n -> n为数字），可以限定字符串输出上限
	printf("%6.5s\n", "helloworld");
	printf("%-6.5s\n", "helloworld");
	printf("\n");

	//2.scanf 返回值 赋值忽略符
	int x = 0;
	printf("请输入：\n");
	scanf("%d", &x);//scanf的占位符对应地址
	printf("输出为%d\n", x);
	int a;
	float b;
	scanf("%d%f", &a,&b);
	printf("a = %d\nb = %f\n", a,b);
	int ret = scanf("%d%d%f", &x, &a, &b);
	printf("%d\n", ret);//scanf返回值取决于成功读取变量的个数
	//除了%c 其余占位符会自动忽略空白字符
	//%s会从非空白字符开始读，读到空白字符为止。并在读到字符串末尾，自动添加一个\0
	char name[5];
	scanf("%4s", name);//为了防止超过数组的范围，%后加数字（<数组最大个数，因为字符串数组中包含\0），
	//限定输入字符串的长度，多余的字符将会被忽略。
	printf("name = %s\n", name);
	int year,month,day;
	scanf("%d%*c%d%*c%d", &year, &month, &day);//在占位符的%后加入*，可以忽略这个占位符，解读后不返回
	printf("%d %d %d\n", year, month, day);
	printf("\n");

	//3.if else
	if (1)//非0为真，进入
		printf("yes\n");
	if (0)//0为假，不进入
		printf("no\n");
	scanf("%d", &a);
	if (a) 
		printf("真\n");
	else
		printf("假\n");

	if (a < 2)
		printf("a<2\n");
	else if(a==2)
		printf("a=2\n");
	else
		printf("a>2\n");//else会就近匹配if

	return 0;
}
