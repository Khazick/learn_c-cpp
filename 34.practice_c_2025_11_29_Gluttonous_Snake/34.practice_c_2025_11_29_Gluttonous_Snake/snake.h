#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <stdbool.h>
#include <locale.h>

//类型的声明
//蛇身节点类型
typedef struct SnakeNode
{
	int x;
	int y;
	struct SnakeNode* next;
}SnakeNode;


//蛇的方向
enum DIRECTION {
	UP = 1,
	DOWN,
	LEFT,
	RIGHT
};
//游戏状态
enum GAME_STATUS {
	OK,//正常状态
	KILL_BY_WALL,//撞墙
	KILL_BY_SELF,//撞身体
	END_NORMAL//正常结束游戏
};
//维护蛇的节点类型
typedef struct Snake {
	//蛇头
	SnakeNode* _snakehead;
	//蛇速度
	int _snakespeed;//时间越短，速度越快；时间越长，速度越慢
	//蛇方向（枚举）
	enum DIRECTION _dir;
	//食物坐标
	SnakeNode* _food;
	//食物分数
	int _foodweight;//食物权重
	//总分数
	int _score;
	//游戏状态
	enum GAME_STATUS _stauts;
}Snake;

//初始化游戏
void game_start(Snake* snake);

//打印界面
void WelcomeToGame();
//封装一个设置光标位置的函数
void SetPos(short x, short y);
//创建地图
void CreateMap();

