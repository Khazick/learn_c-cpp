#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int type_snode_data;
typedef struct s_list_node {
	type_snode_data x;
	struct s_list_node* next;
}SLN;

SLN* SLN_create();

void SLN_print(SLN* ps);