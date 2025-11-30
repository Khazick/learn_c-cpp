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
	printf("通过 ↑ , ↓ , ← , → 按键分别控制上下左右");
	SetPos(32, 13);
	printf("按下'CTRL'键可以加速，按下'ALT'键可以减速");
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
		wprintf(L"%lc", WALL);
	}
	//down
	SetPos(0, 26);
	for (i = 0;i < 29;i++) {
		wprintf(L"%lc", WALL);
	}
	//left
	for (i = 1;i < 26;i++) {
		SetPos(0, i);
		wprintf(L"%lc", WALL);
	}
	//right
	for (i = 1;i < 26;i++) {
		SetPos(56, i);
		wprintf(L"%lc", WALL);
	}
}
void InitSnake(Snake* snake) {
	//初始化蛇身
	SnakeNode* pcur = NULL;
	int a, b;
	do {
		a = 2 + rand() % 43;
		b = 1 + rand() % 25;
	} while (a % 2 != 0);

	for (int i = 0;i < 5;i++) {
		pcur = (SnakeNode*)malloc(sizeof(SnakeNode));
		assert(pcur);
		pcur->next = NULL;
			pcur->x = a + i * 2;
			pcur->y = b;
		if (!snake->_snakehead)
			snake->_snakehead = pcur;
		else {
			pcur->next = snake->_snakehead;
			snake->_snakehead = pcur;
		}
	}
	//打印蛇身
	pcur = snake->_snakehead;
	while (pcur) {
		SetPos(pcur->x, pcur->y);
		wprintf(L"%lc",BODY);
		pcur = pcur->next;
	}
	//游戏相关信息
	snake->_dir = RIGHT;//初始方向
	snake->_score = 0;//初始分数
	snake->_stauts = OK;//初始状态
	snake->_foodweight = 10;//食物分值
	snake->_snakespeed = 200;//200ms
}
void CreateFood(Snake* snake) {
	//初始化食物
	SnakeNode* Food = (SnakeNode*)malloc(sizeof(SnakeNode));

	int x, y;
again:
	//设置食物的坐标范围
	do {
		x = 2 + rand() % 53;
		y = 1 + rand() % 25;

	} while (x % 2 != 0);//x只能为偶数
	SnakeNode* pcur = snake->_snakehead;
	while (pcur) {
		if (pcur->x == x && pcur->y == y)//食物坐标不能与蛇身重叠
			goto again;
		pcur = pcur->next;
	}
	assert(Food);
	Food->next = NULL;
	Food->x = x;
	Food->y = y;
	//打印食物
	SetPos(x, y);
	wprintf(L"%lc", FOOD);
	snake->_food = Food;
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
	InitSnake(snake);

	//创建食物
	CreateFood(snake);
}

void PrintHelpInfo() {
	SetPos(64,10);
	printf("不能穿墙，蛇头不能触碰身体");
	SetPos(64, 12);
	printf("↑↓←→:控制移动");
	SetPos(64, 14);
	printf("CTRL:加速，ALT:减速");
	SetPos(64, 16);
	printf("SPACE:暂停游戏");
	SetPos(64, 18);
	printf("ESC:退出游戏");
}
void pause() {
	while (1) {
		Sleep(300);
		if (KEY_PRESS(VK_SPACE))
			break;
	}
}
int NextIsFood(SnakeNode* next, Snake* snake) {
	return (next->x == snake->_food->x) && (next->y == snake->_food->y);
}
void EatFood(SnakeNode* next, Snake* snake) {
	next->next = snake->_snakehead;
	snake->_snakehead = next;
	//打印新蛇
	SnakeNode* pcur = snake->_snakehead;
	while (pcur) {
		SetPos(pcur->x, pcur->y);
		wprintf(L"%lc", BODY);
		pcur = pcur->next;
	}
	//吃到食物加分
	snake->_score += snake->_foodweight;
	//释放已吃食物节点
	free(snake->_food);
	//创建新食物
	CreateFood(snake);
}
void NotFood(SnakeNode* next, Snake* snake) {
	//移动到下一个节点
	next->next = snake->_snakehead;
	snake->_snakehead = next;
	//打印旧蛇并删除尾部节点
	SnakeNode* pcur = snake->_snakehead;
	while (pcur->next->next) {
		SetPos(pcur->x,pcur->y);
		wprintf(L"%lc", BODY);
		pcur = pcur->next;
	}
	SetPos(pcur->next->x, pcur->next->y);//屏幕上先消除尾部节点
	printf("  ");
	free(pcur->next);
	pcur->next = NULL;
}
int KillByWall(Snake* snake) {
	if (snake->_snakehead->x == 0 ||
		snake->_snakehead->x == 56 ||
		snake->_snakehead->y == 0 ||
		snake->_snakehead->y == 26) {
		snake->_stauts = KILL_BY_WALL;
		return 1;
	}
	else
		return 0;
}
int KillByBody(Snake* snake) {
	SnakeNode* die = snake->_snakehead->next;
	while (die) {
		if (snake->_snakehead->x == die->x && snake->_snakehead->y == die->y) {
			snake->_stauts = KILL_BY_SELF;
			return 1;
		}
		die = die->next;
	}
	return 0;
}
void SnakeMove(Snake* snake) {
	//创建下一个节点
	SnakeNode* next = (SnakeNode*)malloc(sizeof(SnakeNode));
	assert(next);
	if (snake->_dir == UP) {
		next->x = snake->_snakehead->x;
		next->y = snake->_snakehead->y - 1;
	}
	else if (snake->_dir == DOWN) {
		next->x = snake->_snakehead->x;
		next->y = snake->_snakehead->y + 1;
	}
	else if (snake->_dir == LEFT) {
		next->x = snake->_snakehead->x - 2;
		next->y = snake->_snakehead->y;
	}
	else if (snake->_dir == RIGHT) {
		next->x = snake->_snakehead->x + 2;
		next->y = snake->_snakehead->y;
	}
	//判断下个节点是否为食物
	if (NextIsFood(next,snake)) {//是
		//吃
		EatFood(next,snake);
	}
	else {//否
		NotFood(next, snake);
	}
	//是否撞墙
	KillByWall(snake);
	//是否撞身体
	KillByBody(snake);
}

void game_run(Snake* snake) {
	//打印帮助信息
	PrintHelpInfo();
	//检查游戏状态
	do {
		//打印总分和食物分值
		SetPos(64, 5);
		printf("当前得分：%2d",snake->_score);
		SetPos(64, 6);
		printf("食物分值：%2d", snake->_foodweight);
		//检测按键宏
		if (KEY_PRESS(VK_UP) && snake->_dir != DOWN)
			snake->_dir = UP;
		else if (KEY_PRESS(VK_DOWN) && snake->_dir != UP)
			snake->_dir = DOWN;
		else if (KEY_PRESS(VK_LEFT) && snake->_dir != RIGHT)
			snake->_dir = LEFT;
		else if (KEY_PRESS(VK_RIGHT) && snake->_dir != LEFT)
			snake->_dir = RIGHT;
		else if (KEY_PRESS(VK_SPACE))//SPACE暂停
			pause();
		else if (KEY_PRESS(VK_ESCAPE)) {//ESC退出
			snake->_stauts = END_NORMAL;
			break;
		}
		else if (KEY_PRESS(VK_CONTROL)) {//CTRL加速
			if (snake->_snakespeed >= 80) {
				snake->_snakespeed -= 30;
				snake->_foodweight += 2;
			}
		}
		else if (KEY_PRESS(VK_MENU)) {//ALT减速
			if (snake->_snakespeed < 320) {
				snake->_snakespeed += 30;
				snake->_foodweight -= 2;
			}
		}
		//蛇移动
		Sleep(snake->_snakespeed);
		SnakeMove(snake);
	} while (snake->_stauts == OK);
}

void game_end(Snake* snake) {
	//告知游戏结束
	SetPos(64, 3);
	if (snake->_stauts == KILL_BY_WALL || snake->_stauts == KILL_BY_SELF) {
		printf("游戏失败!");
	}
	else {
		printf("退出游戏!");
	}
	//释放蛇节点
	while (snake->_snakehead) {
		SnakeNode* next = snake->_snakehead->next;
		free(snake->_snakehead);
		snake->_snakehead = next;
	}
	snake->_snakehead = NULL;
}
