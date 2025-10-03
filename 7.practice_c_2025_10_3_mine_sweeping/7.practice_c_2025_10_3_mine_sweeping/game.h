#pragma once
#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define EAZY 10
#define NORMAL 40
#define HARD 99

#define ROWS ROW+2
#define COLS COL+2



//菜单
void menu();
//难度选择
void difficulty();
//游戏菜单整体
void game_interface();

//游戏本体
void game(int d);

//初始化扫雷棋盘
void init_mine(char mine[99][99], int rows, int cols ,char set);

//打印扫雷棋盘
void print_mine(char mine[99][99], int row, int col);

//设置地雷
void set_mine(char mine[99][99], int row, int col,int d);

//扫描3*3范围内的地雷数量
int get_mine_number(char mine[99][99], int x, int y);

//排查地雷
void find_mine(char mine[99][99], char board[99][99], int row, int col,int d);