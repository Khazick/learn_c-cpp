#include"game.h"
//游玩内容
void guess_game(int r, int level) {
	int guess = 0;
	int count = level;
	while (count >= 0) {
		scanf("%d", &guess);
		if (guess < r) {
			printf("猜小了,你还有%d次机会\n", count);
		}
		else if (guess > r) {
			printf("猜大了,你还有%d次机会\n", count);
		}
		else {
			win_interface(r);
			break;
		}
		count--;
	}
	if (count < 0) {
		lose_interface(r);
	}
}
//游戏
void game() {
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
		level_start:
			difficulty();
			printf("请选择难度：\n");
			scanf("%d", &input2);
			switch (input2) {
			case 1:
				level = 30;
				break;
			case 2:
				level = 15;
				break;
			case 3:
				level = 7;
				break;
			default:
				system("cls");
				printf("输入错误！\n");
				goto level_start;
			}
			printf("开始猜数字游戏\n（数字范围在0~100）\n请输入数字：\n");
			guess_game(r, level);
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