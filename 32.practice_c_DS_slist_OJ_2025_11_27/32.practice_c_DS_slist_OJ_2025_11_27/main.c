#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct ListNode {
	int val;
	struct ListNode* next;
};
typedef struct ListNode ListNode;

struct Node {
	int val;
	struct Node* next;
	struct Node* random;
};
typedef struct Node Node;

void Print(Node* head) {
	Node* pcur = head;
	while (pcur){
		printf("%d ", pcur->val);
		pcur = pcur->next;
	}
	printf("\n");
}
//第 1 题（编程题）
//题目名称：
//8.输入两个链表，找出它们的第一个公共结点
//题目内容：
//8.输入两个链表，找出它们的第一个公共结点。OJ链接
struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB) {
	ListNode* pcurA = headA;
	ListNode* pcurB = headB;
	int a = 0, b = 0;
	while (pcurA) {
		pcurA = pcurA->next;
		a++;
	}
	while (pcurB) {
		pcurB = pcurB->next;
		b++;
	}
	ListNode* longlist = headA;
	ListNode* shortlist = headB;
	if (a < b) {
		longlist = headB;
		shortlist = headA;
	}
	int value = abs(a - b);
	while (value--) {
		longlist = longlist->next;
	}
	while (longlist && shortlist) {
		if (longlist == shortlist)
			return longlist;
		longlist = longlist->next;
		shortlist = shortlist->next;
	}
	return NULL;
}

//第 2 题（编程题）
//题目名称：
//9.给定一个链表，判断链表中是否有环
//题目内容：
//9.给定一个链表，判断链表中是否有环。 OJ链接
bool hasCycle(struct ListNode* head) {
	ListNode* fast = head;
	ListNode* slow = head;
	while (fast && fast->next) {
		fast = fast->next->next;
		slow = slow->next;
		if (fast == slow)
			return true;
	}
	return false;
}

//第 3 题（编程题）
//题目名称：
//10.给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 NULL
//题目内容：
//10.给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 NULL OJ链接
struct ListNode* meetpoint(struct ListNode* head) {
	ListNode* fast = head;
	ListNode* slow = head;
	while (fast && fast->next) {
		fast = fast->next->next;
		slow = slow->next;
		if (fast == slow)
			return fast;
	}
	return NULL;
}
struct ListNode* detectCycle(struct ListNode* head) {
	ListNode* meet = meetpoint(head);
	ListNode* pcur = head;
	while (meet && pcur) {
		if (meet == pcur)
			return meet;
		meet = meet->next;
		pcur = pcur->next;
	}
	return NULL;
}

//第 4 题（编程题）
//题目名称：
//11.给定一个链表，每个节点包含一个额外增加的随机指针，该指针可以指向链表中的任何节点或空节点。要求返回这个链表的深度拷贝
//题目内容：
//11.给定一个链表，每个节点包含一个额外增加的随机指针，该指针可以指向链表中的任何节点或空节点。
//要求返回这个链表的深度拷贝。OJ链接
Node* buynode(int x) {
	Node* newnode = (Node*)malloc(sizeof(Node));//备注销毁
	newnode->val = x;
	newnode->next = newnode->random = NULL;
	return newnode;
}
struct Node* copyRandomList(struct Node* head) {
	if (!head)
		return NULL;
	//原基础复制
	Node* pcur = head;
	while (pcur) {
		Node* Next = pcur->next;
		Node* newnode = buynode(pcur->val);
		newnode->next = Next;
		pcur->next = newnode;
		pcur = Next;
	}
	//设置随机指针
	pcur = head;
	while (pcur) {
		Node* copy = pcur->next;
		if (pcur->random)
			copy->random = pcur->random->next;
		else
			copy->random = NULL;
		pcur = copy->next;
	}
	//断开复制链表与原链表
	pcur = head;
	Node* newhead = pcur->next;
	Node* newtail = newhead;
	while (pcur) {
		pcur->next = newtail->next;
		pcur = pcur->next;
		if (pcur) {
			newtail->next = pcur->next;
			newtail = newtail->next;
		}
	}
	return newhead;
}


void test1() {
	ListNode* n1 = (ListNode*)malloc(sizeof(ListNode));
	n1->val = 4;
	ListNode* n2 = (ListNode*)malloc(sizeof(ListNode));
	n2->val = 1;
	n1->next = n2;
	
	ListNode* l1 = (ListNode*)malloc(sizeof(ListNode));
	l1->val = 5;
	ListNode* l2 = (ListNode*)malloc(sizeof(ListNode));
	l2->val = 6;
	ListNode* l3 = (ListNode*)malloc(sizeof(ListNode));
	l3->val = 1;
	l1->next = l2;
	l2->next = l3;

	ListNode* a1 = (ListNode*)malloc(sizeof(ListNode));
	a1->val = 8;
	ListNode* a2 = (ListNode*)malloc(sizeof(ListNode));
	a2->val = 4;
	ListNode* a3 = (ListNode*)malloc(sizeof(ListNode));
	a3->val = 5;
	a1->next = a2;
	a2->next = a3;
	a3->next = NULL;

	l3->next = n2->next = a1;

	ListNode* ret = getIntersectionNode(n1, l1);
	printf("%d\n", ret->val);

	free(n1);
	free(n2);
	free(l1);
	free(l2);
	free(l3);
	free(a1);
	free(a2);
	free(a3);
	n1 = n2 = l1 = l2 = l3 = a1 = a2 = a3 = NULL;

}
void test2() {
	ListNode* n1 = (ListNode*)malloc(sizeof(ListNode));
	n1->val = 3;
	ListNode* n2 = (ListNode*)malloc(sizeof(ListNode));
	n2->val = 2;
	ListNode* n3 = (ListNode*)malloc(sizeof(ListNode));
	n3->val = 0;
	ListNode* n4 = (ListNode*)malloc(sizeof(ListNode));
	n4->val = -4;
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n2;

	bool ret = hasCycle(n1);
	if (ret)
		printf("true\n");
	else
		printf("false\n");

	free(n1);
	free(n2);
	free(n3);
	free(n4);
	n1 = n2 = n3 = n4 = NULL;
}
void test3() {
	ListNode* n1 = (ListNode*)malloc(sizeof(ListNode));
	n1->val = 3;
	ListNode* n2 = (ListNode*)malloc(sizeof(ListNode));
	n2->val = 2;
	ListNode* n3 = (ListNode*)malloc(sizeof(ListNode));
	n3->val = 0;
	ListNode* n4 = (ListNode*)malloc(sizeof(ListNode));
	n4->val = -4;
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n2;

	ListNode* ret = detectCycle(n1);
	printf("%d\n", ret->val);

	free(n1);
	free(n2);
	free(n3);
	free(n4);
	n1 = n2 = n3 = n4 = NULL;
}
void test4() {
	Node* n1 = (Node*)malloc(sizeof(Node));
	n1->val = 7;
	Node* n2 = (Node*)malloc(sizeof(Node));
	n2->val = 13;
	Node* n3 = (Node*)malloc(sizeof(Node));
	n3->val = 11;
	Node* n4 = (Node*)malloc(sizeof(Node));
	n4->val = 10;
	Node* n5 = (Node*)malloc(sizeof(Node));
	n5->val = 1;
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;
	n5->next = NULL;
	n1->random = NULL;
	n2->random = n1;
	n3->random = n5;
	n4->random = n3;
	n5->random = n1;

	Node* newhead = copyRandomList(n1);
	Print(newhead);

	free(n1);
	free(n2);
	free(n3);
	free(n4);
	free(n5);
	n1 = n2 = n3 = n4 = n5 = NULL;
}
int main() {
	test1();
	test2();
	test3();
	test4();
	return 0;
}