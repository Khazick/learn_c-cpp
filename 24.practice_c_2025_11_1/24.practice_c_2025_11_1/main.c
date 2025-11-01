#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
int main1(){
	int a = 10000;
	FILE * pf = fopen("test.txt", "wb");
	fwrite(&a, 4, 1, pf);//⼆进制的形式写到⽂件中
	fclose(pf);
	pf = NULL;
	return 0;
}

int main(){
	FILE* pFile;
	//打开⽂件
	pFile = fopen("myfile.txt", "w");
	//⽂件操作
	if (pFile != NULL){
		fputs("fopen example", pFile);
		//关闭⽂件
		fclose(pFile);
		pFile = NULL;
	}
	return 0;
}
