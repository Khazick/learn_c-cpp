#include "snake.h"

void SetPos(short cols, short lines) {
	COORD pos = { cols,lines };
	HANDLE houtput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(houtput, pos);//将标准输出上光标的位置设置为pos
}

void WelcomeToGame() {
	//欢迎界面
	SetPos(39,14);
	printf("欢迎来到贪吃蛇游戏\n");
	SetPos(40, 17);
	system("pause");
	system("cls");
	//功能介绍
	SetPos(30, 11);
	printf("通过'W','S','A','D'按键分别控制上下左右");
	SetPos(32, 13);
	printf("按下'J'键可以加速，按下'K'键可以减速");
	SetPos(35, 15);
	printf("小提示：加速可以更快地获得分数");
	SetPos(42, 17);
	system("pause");
	system("cls");
}
void CreateMap() {
	int i;
	//up
	for (i = 0;i < 29;i++) {
		wprintf(L"墙");
	}
	//down
	SetPos(0, 26);
	for (i = 0;i < 29;i++) {
		wprintf(L"墙");
	}
	//left
	for (i = 1;i < 26;i++) {
		SetPos(0, i);
		wprintf(L"墙");
	}
	//right
	for (i = 1;i < 26;i++) {
		SetPos(56, i);
		wprintf(L"墙");
	}

	SetPos(0, 28);
	system("pause");
	system("cls");
}

void game_start(Snake* snake) {
	//设置窗口大小及名称
	system("mode con cols=100 lines=30");//窗口的X&Y
	system("title 贪吃蛇");

	//隐藏光标
	HANDLE houtput = GetStdHandle(STD_OUTPUT_HANDLE);//获取句柄
	CONSOLE_CURSOR_INFO CursorInfo;
	GetConsoleCursorInfo(houtput, &CursorInfo);//获取光标信息
	CursorInfo.bVisible = false;//隐藏光标
	SetConsoleCursorInfo(houtput, &CursorInfo);//设置光标信息
	
	//打印初始界面及功能介绍
	WelcomeToGame();
	
	//绘制地图
	CreateMap();

	//创建蛇

	//创建食物

	//设置游戏的相关信息

}

