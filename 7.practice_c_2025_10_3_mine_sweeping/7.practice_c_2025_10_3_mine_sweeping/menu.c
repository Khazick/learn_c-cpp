#include "game.h"

void menu() {
	printf("-----------------------\n");
	printf("|    **************   |\n");
	printf("|    * Mine-Sweep *   |\n");
	printf("|    **************   |\n");
	printf("|---------------------|\n");
	printf("|       1. Play       |\n");
	printf("|---------------------|\n");
	printf("|       2. Exit       |\n");
	printf("-----------------------\n");
}

void difficulty() {
	printf("-----------------------\n");
	printf("|    **************   |\n");
	printf("|    * Game-Level *   |\n");
	printf("|    **************   |\n");
	printf("|---------------------|\n");
	printf("|       1. EAZY       |\n");
	printf("|---------------------|\n");
	printf("|       2. NORMAL     |\n");
	printf("-----------------------\n");
	printf("|       3. HARD       |\n");
	printf("-----------------------\n");
}

//游戏菜单界面
void game_interface() {
	int input1 = 1;
	int input2 = 0;
	do {
	start:
		if(input1 != 1)
			system("cls");
		//菜单
		menu();
		printf("请选择：\n");
		scanf("%d", &input1);
		switch (input1) {
		case 1:
		diff:
			system("cls");
			//难度选择				
			difficulty();
			printf("请选择难度：\n");
			scanf("%d", &input2);
			switch (input2)
			{
			case 1:
				game(EAZY);
				break;
			case 2:
				game(NORMAL);
				break;
			case 3:
				game(HARD);
				break;
			default:
				system("cls");
				goto diff;
			}
			break;
		case 2:
			printf("退出游戏\n");
			break;
		default:
			goto start;
		}
	} while (input1 - 2);
}
