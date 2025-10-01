#include "arr01.h"

void arr_01() {
	int arr[10];
	int n = sizeof(arr) / sizeof(arr[0]);
	init(arr, n);
	print(arr, n);
	scan(arr, n);
	reverse(arr, n);
	print(arr, n);
}

void printMessage() {
	printf("Hello from printMessage!\n");
}