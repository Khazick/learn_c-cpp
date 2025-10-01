#include"game.h"
//菜单
void menu() {

	printf(" ------------------------ \n");
	printf(" |   Guess Number Game  | \n");
	printf(" |~~~~~~~~~~~~~~~~~~~~~~| \n");
	printf(" |     1.    play       | \n");
	printf(" |     2.    exit       | \n");
	printf(" ------------------------ \n");
}
//难度
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
//胜利
void win_interface(int r) {
	system("cls");
	printf(" ------------------------ \n");
	printf(" |    恭喜你猜对了!     |\n");
	printf(" |   正确的答案为:%3d   |\n", r);
	printf(" |      游戏结束!       |\n");
	printf(" ------------------------ \n");
}
//失败
void lose_interface(int r) {
	system("cls");
	printf(" ------------------------ \n");
	printf(" |   次数耗尽，你输了！ |\n");
	printf(" |   正确的答案为:%3d   |\n", r);
	printf(" |      游戏结束!       |\n");
	printf(" ------------------------ \n");
}