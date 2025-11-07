#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
//第 4 题（编程题）
//题目名称：
//写一个程序拷贝文件
//题目内容：
//使用所学文件操作，在当前目录下放一个文件data.txt，写一个程序，将data.txt文件拷贝一份，生成data_copy.txt文件。
//
//基本思路：
//
//打开文件data.txt，读取数据
//打开文件data_copy.txt，写数据
//从data.txt中读取数据存放到data_copy.txt文件中，直到文件结束。
//关闭两个文件

int main1() {
	//打开文件
	FILE* pf1 = fopen("data.txt", "r");
	if (pf1 == NULL) {
		perror("fopen pf1: ");
		return 1;
	}
	FILE* pf2 = fopen("data_copy.txt", "w");
	if (pf2 == NULL) {
		perror("fopen pf2: ");
		fclose(pf1);
		pf1 = NULL;
		return 1;
	}
	//操作文件
	int c;
	while ((c = fgetc(pf1)) != EOF) {
		fputc(c,pf2);
	}

	//关闭文件
	fclose(pf1);
	pf1 = NULL;
	fclose(pf2);
	pf2 = NULL;
	return 0;
}

//练习
int main() {
	//打开文件
	FILE* pf1 = fopen("test1.txt", "r");//只读,文件输出数据，打开一个已存在的文件，若文件不存在则报错；
	//判断是否打开失败，打开失败会返回NULL
	if (pf1 == NULL) {
		perror("fopen pf1:");
		return 1;
	}
	FILE* pf2 = fopen("test2.txt", "w");//只写，向文件内输入数据，若文件存在，则将文件内容清空。若不存在则新建一个文件
	if (pf2 == NULL) {
		perror("fopen pf1:");
		return 1;
	}

	//操作文件
	char arr1[10] = "xxxxxxxxx";
	fgets(arr1, 10, pf1);//最多读n-1个字符，在第n位放\0，按行读取，读到\0即文件结束EOF
	printf("%s\n", arr1);
	//fgetc 从文件流 pf1 的当前读取位置读取 1 个字符，并将文件指针向后移动 1 位。
	//若 fgets 读取了 9 个字符（未遇到 \n 或 EOF）：则 fgets 停在第 9 个字符后，fgetc 读取第 10 个字符。
	//若 fgets 因遇到 \n 提前结束（比如只读取了 5 个字符 + \n，共 6 个）：
	//则 fgets 停在 \n 后，fgetc 读取 * *\n 后面的第一个字符 * *。
	//若 fgets 因文件结束（EOF）停止：则 fgetc 返回 EOF（通常是 -1，但存到 char c1 中会因类型截断呈现为 \xff 等，取决于编译器）。
	
	//故使用fseek定位文件指针
	fseek(pf1, 0, SEEK_SET);//这里将文件指针定位到开始初
	rewind(pf1);//也可以用rewind直接回到起始位置

	char c1 = fgetc(pf1);//字符输入到c1里保存下来，所有输入流
	printf("%c\n", c1);//那么就会打印a
	fputc(c1, stdout);//同printf一个作用，但功能更多，可以往文件内输入数据
	printf("\n");

	fputs("ABCD \n", pf2);//文本行输出，所有输出流，只能传字符串指针
	printf("睡眠5秒-已经写数据了，打开test2.txt文件，发现文件没有内容\n");
	Sleep(5000);
	printf("刷新缓冲区\n");
	fflush(pf2);//刷新缓冲区
	printf("再睡眠5秒-此时，再次打开test2.txt文件，文件有内容了\n");
	Sleep(5000);

	//已知fgetc 从文件流 pf1的当前读取位置读取1个字符，并将文件指针向后移动1位。
	//所以现在pf1开始位置为'BCD'
	//fputs(pf1, pf2); err
	while ((c1 = fgetc(pf1)) != EOF) {
		fputc(c1, pf2);
	}

	int ch = fgetc(stdin);//从键盘上读取
	fputc(ch, stdout);//将字符输出到屏幕
	printf("\n");

	//scanf/ fscanf/ sscanf
	//printf/fprintf/sprintf
	char str1[10], str2[10], str3[10];
	int year;
	FILE* pf3 = fopen("test.txt", "w");//只写
	if (pf3 == NULL) {
		perror("fopen pf3: ");
		return 1;
	}
	fputs("We are in 2025", pf3);//写入
	fclose(pf3);
	//scanf / printf  针对标准输入流 / 标准输出流的 格式化 输入 / 输出函数
	int c2 = 0;
	scanf("%d", &c2);
	printf("%d\n", c2);

	//fscanf / fprintf 针对所有输入流 / 所有输出流的 格式化 输入 / 输出函数
	pf3 = fopen("test.txt", "r");//只读
	fscanf(pf3, "%s %s %s %d", str1, str2, str3, &year);//读出
	printf("Read String1 |%s|\n", str1);
	printf("Read String2 |%s|\n", str2);
	printf("Read String3 |%s|\n", str3);
	printf("Read Integer |%d|\n", year);
	fclose(pf3);

	pf3 = fopen("test.txt", "w");
	fprintf(pf3, "%s %s %s %d", "We", "are", "in", 2015);//把字符串打印（写进）进文件

	//sscanf  从字符串中提取格式化的数据(将字符串转化为格式化的数据)
	int day;
	char weekday[20], month[20], dtm[100];
	strcpy(dtm, "Saturday March 25 1989");
	sscanf(dtm, "%s %s %d  %d", weekday, month, &day, &year);//输入-读字符串
	printf("%s %d, %d = %s\n", month, day, year, weekday);
	//sprintf  将格式化的数据写到字符串中(将格式化的数据转换为字符串)
	sprintf(str1, "%s\n", weekday);//输出-打印-写进字符串
	puts(str1);

	//fseek ftell rewind
	FILE* pFile = fopen("example.txt", "wb");
	fputs("This is an apple.", pFile);
	fseek(pFile, 9, SEEK_SET);
	fputs(" sam", pFile);
	fclose(pFile);

	pFile = fopen("myfile.txt", "rb");
	long size;
	if (pFile == NULL)
		perror("Error opening file");
	else{
		fseek(pFile, 0, SEEK_END); 
		size = ftell(pFile);
		fclose(pFile);
		printf("Size of myfile.txt: %ld bytes.\n", size);
	}
	pFile = NULL;

	//feof
	int c = 0;; // 注意：int，⾮char，要求处理EOF
	FILE* fp = fopen("test4.txt", "r");
	if (!fp) {
		perror("File opening failed");
		return 1;
	}
	//fgetc 当读取失败的时候或者遇到⽂件结束的时候，都会返回EOF
	while ((c = fgetc(fp)) != EOF) // 标准C I/O读取⽂件循环
	{
		putchar(c);
	}
	printf("\n");
	//判断是什么原因结束的
	if (ferror(fp))
		puts("I/O error when reading");
	else if (feof(fp))
		puts("End of file reached successfully");


	//关闭文件
	fclose(pf1);
	pf1 = NULL;
	fclose(pf2);
	pf2 = NULL;
	fclose(pf3);
	pf3 = NULL;
	fclose(fp);
	fp = NULL;

	return 0;
}