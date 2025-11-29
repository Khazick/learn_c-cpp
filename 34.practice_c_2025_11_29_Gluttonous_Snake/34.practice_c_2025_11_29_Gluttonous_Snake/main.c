#include "snake.h"

//完成游戏的测试逻辑
void test_game() {
	//设置本地环境
	setlocale(LC_ALL, "");
	//创建贪吃蛇
	Snake snake = { 0 };
	//初始化游戏
	game_start(&snake);
	//运行游戏

	//结束游戏-善后工作

}

int main() {
	test_game();

	return 0;
}