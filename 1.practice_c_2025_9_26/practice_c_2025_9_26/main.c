#define _CRT_SECURE_NO_WARNINGS 1
#include "test.h"

int main() {

	//1 printf
	printf("hello world!\n");

	//2 Õ¼Î»·û
	printf("%d\n", 5);
	printf("%c\n", 'y');
	printf("%f\n", 1.0);
	printf("%s\n", "Ë§");

	//3 ASCII
	printf("%c\n",'a');
	printf("%c\n", 65);
	for (int i = 32;i < 128;i++) {
		printf("%c ",i);
		if (i % 16 == 0) {
			printf("\n");
		}
	}
	printf("\n\n");

	//4 ×Ö·û ×Ö·û´® strlen
	char arr1[] = "xyz";
	char arr2[] = { 'x','y','z' };
	char arr3[] = { 'x','y','z','\0' };
	printf("%s\n", arr1);
	printf("%zd\n", strlen(arr1));

	printf("%s\n", arr2);
	printf("%zd\n", strlen(arr2));

	printf("%s\n", arr3);
	printf("%zd\n", strlen(arr3));
	printf("\n");

	//5 ×ªÒå×Ö·û
	printf("abcadc123abct1n\n");
	printf("abcadc\123a\bc\t1\n\n");
	printf("%c\n", '\123');
	printf("%c\n", 'S');
	printf("%c\n", '\x5a');
	printf("%c\n", 'Z');

	return 0;
}

