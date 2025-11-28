#include "list.h"

//作业标题
//双链表的增删查改
//作业内容
//// 带头+双向+循环链表增删查改实现
//typedef int LTDataType;
//typedef struct ListNode
//{
//	LTDataType _data;
//	struct ListNode* _next;
//	struct ListNode* _prev;
//}ListNode;
//
//// 创建返回链表的头结点.
//ListNode* ListCreate();
//// 双向链表销毁
//void ListDestory(ListNode* pHead);
//// 双向链表打印
//void ListPrint(ListNode* pHead);
//// 双向链表尾插
//void ListPushBack(ListNode* pHead, LTDataType x);
//// 双向链表尾删
//void ListPopBack(ListNode* pHead);
//// 双向链表头插
//void ListPushFront(ListNode* pHead, LTDataType x);
//// 双向链表头删
//void ListPopFront(ListNode* pHead);
//// 双向链表查找
//ListNode* ListFind(ListNode* pHead, LTDataType x);
//// 双向链表在pos的前面进行插入
//void ListInsert(ListNode* pos, LTDataType x);
//// 双向链表删除pos位置的节点
//void ListErase(ListNode* pos);

void test_back() {
	ListNode* plist = LTinit();
	LTPushBack(plist, 1);
	LTPrint(plist);
	LTPushBack(plist, 2);
	LTPrint(plist);
	LTPushBack(plist, 3);
	LTPrint(plist);
	LTPushBack(plist, 4);
	LTPrint(plist);

	LTPopBack(plist);
	LTPrint(plist);
	LTPopBack(plist);
	LTPrint(plist);	
	LTPopBack(plist);
	LTPrint(plist);
	LTPopBack(plist);
	LTPrint(plist);

	//LTPopBack(plist);
	//LTPrint(plist);

	LTDestroy(plist);
	plist = NULL;
}
void test_front() {
	ListNode* plist = LTinit();
	LTPushFront(plist, 1);
	LTPrint(plist);
	LTPushFront(plist, 2);
	LTPrint(plist);
	LTPushFront(plist, 3);
	LTPrint(plist);
	LTPushFront(plist, 4);
	LTPrint(plist);

	LTPopFront(plist);
	LTPrint(plist);
	LTPopFront(plist);
	LTPrint(plist);
	LTPopFront(plist);
	LTPrint(plist);
	LTPopFront(plist);
	LTPrint(plist);

	//LTPopFront(plist);
	//LTPrint(plist);

	LTDestroy(plist);
	plist = NULL;
}
void test_pos() {
	ListNode* plist = LTinit();
	LTPushBack(plist, 1);
	LTPrint(plist);
	LTPushBack(plist, 2);
	LTPrint(plist);
	LTPushBack(plist, 3);
	LTPrint(plist);
	LTPushBack(plist, 4);
	LTPrint(plist);
	ListNode* ret = LTFind(plist,1);
	if (ret)
		printf("find\n");
	else
		printf("not find\n");
	LTInsert(LTFind(plist, 1), 0);
	LTPrint(plist);
	LTInsert(LTFind(plist, 3), 9);
	LTPrint(plist);

	LTErase(LTFind(plist, 2));
	LTPrint(plist);
	LTErase(LTFind(plist, 3));
	LTPrint(plist);

	LTDestroy(plist);
	plist = NULL;
}
int main() {
	test_back();
	test_front();
	test_pos();
	return 0;
}