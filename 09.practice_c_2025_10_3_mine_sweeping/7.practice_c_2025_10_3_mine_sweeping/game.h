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



//�˵�
void menu();
//�Ѷ�ѡ��
void difficulty();
//��Ϸ�˵�����
void game_interface();

//��Ϸ����
void game(int d);

//��ʼ��ɨ������
void init_mine(char mine[99][99], int rows, int cols ,char set);

//��ӡɨ������
void print_mine(char mine[99][99], int row, int col);

//���õ���
void set_mine(char mine[99][99], int row, int col,int d);

//ɨ��3*3��Χ�ڵĵ�������
int get_mine_number(char mine[99][99], int x, int y);

//�Ų����
void find_mine(char mine[99][99], char board[99][99], int row, int col,int d);