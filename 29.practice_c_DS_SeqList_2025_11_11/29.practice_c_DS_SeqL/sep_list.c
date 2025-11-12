#include "seq_list.h"
//创建初始化
void seq_list_init(SL* ps) {
	assert(ps);
	ps->arr = NULL;
	ps->numbsize = ps->size = 0;
}
//销毁
void seq_list_destroy(SL* ps) {
	assert(ps);
	free(ps->arr);
	ps->arr = NULL;
	ps->numbsize = ps->size = 0;
}
//打印
void print_seqlist(SL* ps) {
	for (int i = 0;i < ps->size;i++)
		printf("%d ", ps->arr[i]);
	printf("\n");
}
// 对数据的管理:增删查改 
void seq_list_check_memory(SL* ps) {
	if (ps->numbsize == ps->size) {
		int tmp_numbsize = ps->numbsize == 0 ? 4 : 2 * ps->numbsize;
		data_type* tmp = (data_type*)realloc(ps->arr, tmp_numbsize * sizeof(data_type));
		if (!tmp) {
			perror("realloc: ");
			exit(1);
		}
		ps->arr = tmp;
		ps->numbsize = tmp_numbsize;
	}
}
//插入
void seq_list_push_back(SL* ps,data_type x) {
	assert(ps);
	//检查空间是否足够
	seq_list_check_memory(ps);
	ps->arr[ps->size++] = x;
}//尾插
void seq_list_push_front(SL* ps, data_type x) {
	assert(ps);
	//检查空间是否足够
	seq_list_check_memory(ps);
	for (int i = ps->size;i > 0;i--) {
		ps->arr[i] = ps->arr[i - 1];
	}
	ps->arr[0] = x;
	ps->size++;
}//头插

//删除
void seq_list_pop_back(SL* ps) {
	assert(ps);
	assert(ps->size);

	ps->size--;
	if (ps->size < 0) {
		printf("err : ps->size < 0\n");
		exit(1);
	}	
}//尾删
void seq_list_pop_front(SL* ps) {
	assert(ps);
	assert(ps->size);

	for (int i = 0;i < ps->size - 1 ;i++) {
		ps->arr[i] = ps->arr[i + 1];
	}
	ps->size--;
	if (ps->size < 0) {
		printf("err : ps->size < 0\n");
		exit(1);
	}
}//头删

//指定位置插入
void seq_list_insert(SL* ps, int n, data_type x) {
	assert(ps);
	assert(n >= 0 && n < ps->size);
	seq_list_check_memory(ps);
	ps->size++;
	for (int i = ps->size - 1;i > n;i--) {
		ps->arr[i] = ps->arr[i-1];
	}
	ps->arr[n] = x;
}
//指定位置删除
void seq_list_erase(SL* ps, int n) {
	assert(ps);
	assert(ps->numbsize);
	assert(n >= 0 && n < ps->size);

	for (int i = n;i < ps->size - 1;i++) {
		ps->arr[i] = ps->arr[i + 1];
	}
	ps->size--;
	if (ps->size < 0) {
		printf("err : ps->size < 0\n");
		exit(1);
	}
}
//查找
int seq_list_find(SL* ps, data_type x) {
	assert(ps);
	assert(ps->numbsize);
	for (int i = 0;i < ps->size;i++) {
		if (ps->arr[i] == x) 
			return 1;		
	}
	return -1;
}