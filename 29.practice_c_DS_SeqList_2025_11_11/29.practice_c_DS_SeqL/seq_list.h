#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int data_type;
typedef struct seq_list {
	data_type* arr;
	int numbsize;
	int size;
}SL;

//创建
void seq_list_init(SL* ps);
//销毁
void seq_list_destroy(SL* ps);
//打印
void print_seqlist(SL* ps);
//插入
void seq_list_push_back(SL* ps, data_type x);//尾插
void seq_list_push_front(SL* ps, data_type x);//头插
//删除
void seq_list_pop_back(SL* ps);//尾删
void seq_list_pop_front(SL* ps);//头删
//指定位置插入
void seq_list_insert(SL* ps, int n, data_type x);
//指定位置删除
void seq_list_erase(SL* ps, int n);
//查找
int seq_list_find(SL* ps, data_type x);

