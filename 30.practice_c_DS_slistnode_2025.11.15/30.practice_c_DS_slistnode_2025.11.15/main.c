#include "slist.h"

void test1() {
	SListNode* n1 = BuySListNode(1);
	SListNode* n2 = BuySListNode(2);
	SListNode* n3 = BuySListNode(3);
	SListNode* n4 = BuySListNode(4);
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = NULL;
	SListPrint(n1);
}
void test2() {
	SListNode* plist = NULL;
	SListPushBack(&plist, 1);
	SListPrint(plist);
	SListPushBack(&plist, 2);
	SListPrint(plist);
	SListPushBack(&plist, 3);
	SListPrint(plist);
	SListPushBack(&plist, 4);
	SListPrint(plist);

	SListPopFront(&plist);
	SListPrint(plist);
	SListPopFront(&plist);
	SListPrint(plist);
	SListPopFront(&plist);
	SListPrint(plist);
	SListPopFront(&plist);
	SListPrint(plist);

	//SListPopFront(&plist);
	//SListPrint(plist);

}
void test3() {
	SListNode* plist = NULL;
	SListPushFront(&plist, 1);
	SListPrint(plist);
	SListPushFront(&plist, 2);
	SListPrint(plist);
	SListPushFront(&plist, 3);
	SListPrint(plist);
	SListPushFront(&plist, 4);
	SListPrint(plist);

	SListPopBack(&plist);
	SListPrint(plist);
	SListPopBack(&plist);
	SListPrint(plist);
	SListPopBack(&plist);
	SListPrint(plist);
	SListPopBack(&plist);
	SListPrint(plist);

	//SListPopBack(&plist);
	//SListPrint(plist);

}
void test4() {
	SListNode* plist = NULL;
	SListPushBack(&plist, 1);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);
	SListPushBack(&plist, 4);
	SListPrint(plist);

	SListNode* find = SlistFind(plist, 0);
	if (find) {
		printf("找到了\n");
	}
	else {
		printf("没找到\n");
	}
}
void test5() {
	SListNode* plist = NULL;
	SListPushBack(&plist, 1);
	SListPushBack(&plist, 2);
	SListPrint(plist);
	SListInsert(&plist, SlistFind(plist, 1), 0);
	SListPrint(plist);
	SListInsertAfter(&plist, SlistFind(plist, 2), 3);
	SListPrint(plist);
	SListErase(&plist, SlistFind(plist, 0));
	SListPrint(plist);
	SListEraseAfter(&plist, SlistFind(plist, 2));
	SListPrint(plist);
	SListDestroy(&plist);
}
int main() {
	//test1();
	//test2();
	//test3();
	//test4();
	test5();
	return 0;
}