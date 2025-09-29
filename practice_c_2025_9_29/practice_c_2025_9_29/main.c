#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

//第 2 题（编程题）
//题目名称：
//猜数字游戏
//题目内容：
//完成上课的猜数字游戏
void menu() {
	
	printf(" ------------------------ \n");
	printf(" |   Guess Number Game  | \n");
	printf(" |~~~~~~~~~~~~~~~~~~~~~~| \n");
	printf(" |     1.    play       | \n");
	printf(" |     2.    exit       | \n");
	printf(" ------------------------ \n");
}
void difficulty() {
	system("cls");
	printf(" ------------------------ \n");
	printf(" |   Guess Number Game  | \n");
	printf(" |~~~~~~~~~~~~~~~~~~~~~~| \n");
	printf(" |     1.    easy       | \n");
	printf(" |     2.   normal      | \n");
	printf(" |     3.    hard       | \n");
	printf(" ------------------------ \n");
}
void guess_game(int r,int level) {
	int guess = 0;	
	int count = level;
	while (count>=0){
		scanf("%d", &guess);
		if (guess < r) {
			printf("猜小了,你还有%d次机会\n",count);
		}		
		else if (guess > r) {
			printf("猜大了,你还有%d次机会\n",count);
		}
		else {		
			system("cls");
			printf(" ------------------------ \n");
			printf(" |    恭喜你猜对了!     |\n");
			printf(" |   正确的答案为:%3d   |\n", r);
			printf(" |      游戏结束!       |\n");
			printf(" ------------------------ \n");
			break;			
		}
		count--;
	}
	if (count < 0) {
		system("cls");
		printf(" ------------------------ \n");
		printf(" |   次数耗尽，你输了！ |\n");
		printf(" |   正确的答案为:%3d   |\n", r);
		printf(" |      游戏结束!       |\n");
		printf(" ------------------------ \n");
	}		
}
void game() {
	//游戏
	int input = 0;
	int input2 = 0;
	int a = 1;
	int level = 0;
	do {
	start:
		//游戏菜单			
		a = 1;
		menu();
		//随机数
		int r = rand() % 100 + 1;
		printf("输入选项编号：");
		scanf("%d", &input);
		//菜单选项
		switch (input) {
		case 1:
			difficulty();		
			printf("请选择难度：\n");		
			scanf("%d", &input2);
			switch(input2) {
			case 1: 
				level = 30;
				break;
			case 2:
				level = 15;
				break;
			case 3:
				level = 7;
				break;		
			}
			printf("开始猜数字游戏\n（数字范围在0~100）\n请输入数字：\n");			
			guess_game(r,level);
			break;
		case 2:
			printf("退出游戏\n");
			break;
		default:
			system("cls");
			printf("输入错误！\n");
			goto start;
		}
	} while (input - 2);
}

int main1() {
	//种子
	srand((unsigned int)time(NULL));
	//游戏内容
	game();
	return 0;
}


//第 9 题（编程题）
//题目名称：
//BC51 - 三角形判断
//题目内容：
int main2() {
	int a, b, c;
	while (scanf("%d %d %d", &a, &b, &c) != EOF) {
		if ((a + b) > c && (a + c) > b && (b + c) > a) {
			if (a == b && b == c)
				printf("Equilateral triangle!\n");
			else if (a == b || a == c || b == c)
				printf("Isosceles triangle!\n");
			else
				printf("Ordinary triangle!\n");
		}
		else {
			printf("Not a triangle!\n");
		}
	}
	return 0;
}

//第 10 题（编程题）
//题目名称：
//乘法口诀表
//题目内容：
//在屏幕上输出9 * 9乘法口诀表
int main3() {
	int a = 1;
	for (int i = 1;i < 10;i++) {
		for (int j = a;j < 10;j++)
			printf("%d * %d ", i, j);
		printf("\n");
		a++;	
	}
	return 0;
}

//第 11 题（编程题）
//题目名称：
//打印素数
//题目内容：
//写一个代码：打印100~200之间的素数
int main4() {
	for (int i = 100;i <= 200;i++) {
		int flat = 1;
		for (int j = 2;j < i;j++) {
			if (i % j == 0) {
				flat = 0;
				break;
			}
		}
		if (flat == 1) {
			printf("%d ", i);
		}
	}
	return 0;
}

int main() {
	//1.循环嵌套
	//打印素数-改良
	for (int i = 100;i <= 200;i++) {
		int flat = 1;
		for (int j = 2;j < sqrt(i);j++) {//sqrt()求根号的库函数，头文件<math.h>
			if (i % j == 0) {
				flat = 0;
				break;
			}
		}
		if (flat == 1) {
			printf("%d ", i);
		}
	}
	printf("\n");
	//2.goto
	goto next;
	printf("帅！\n");
	next:
	printf("丑！\n");
	char arr1[20] = { 0 };
	/*system("shutdown -s -t 180");
again:
	printf("你的电脑将在三分钟内关机！输入：魔尊比仙尊帅，将会取消关机！\n");
	scanf("%s", arr1);
	if (strcmp("魔尊比仙尊帅", arr1) == 0)
		system("shutdown -a");
	else
		goto again;*/
	printf("\n");
	//3.随机数
	int a = 0;
	int b = 0;
	scanf("%d %d", &a, &b);
	printf("%d\n", rand());//伪随机
	srand(a);//设置rand的随即种子，改变随机数
	printf("%d\n", rand());
	srand(time(NULL));//time() 可以获取程序运行那一刻的时间，返回时间戳，可以做到每时每刻都有不同的种子
	//rand、srand头文件<stdlib.h>,time头文件<time.h>
	rand() % 100;//rand上限32767，取模可以控制实际需要的随机数范围
	//如果要生成a-b之间的随机数，公式如下：
	a + rand() % (b - a + 1);
	printf("\n");
	//4.一维数组
	//初始化
	int arr2[10] = { 0 };
	int arr3[] = { 1,2,3,4,5,6,7 };
	char ch1[10] = { 'a','b','c' };
	char ch2[10] = "abc";
	int arr4[2];
	char ch3[2];
	//数组的初始值不能超过数组的上限 
	//例如：int arr5[2]={1,2,3,4};就会报错
	for (int i = 0;i < 10;i++) 
		scanf("%d", &arr2[i]);
	for (int j = 0;j < 10;j++)//数组的下标从0开始
		printf("%d ", arr2[j]);
	printf("\n");
	for (int i = 0;i < 10;i++)//并且数组下标在内存中是连续的
		printf("%p\n", &arr2[i]);

	for (int i = 0;i < 7;i++)
		printf("%d ", arr3[i]);
	printf("\n");

	//sizeof()可以用来计算数组占内存的大小
	printf("arr2数组所占内存空间为%d字节\n", (unsigned int)sizeof(arr2));
	int sz = sizeof(arr2) / sizeof(arr2[0]);//用所占内存大小/单个元素的内存大小=数组内有多少元素
	printf("arr2数组中有%d个元素\n", sz);


	return 0;
}