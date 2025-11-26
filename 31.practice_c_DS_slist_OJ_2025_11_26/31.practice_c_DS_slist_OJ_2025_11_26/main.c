//#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct ListNode {
	int val;
	struct ListNode* next;
};
typedef struct ListNode listnode;
//第 1 题（编程题）
//题目名称：
//1.删除链表中等于给定值 val 的所有节点
//题目内容：
//1.删除链表中等于给定值 val 的所有节点。 OJ链接
struct ListNode* removeElements(struct ListNode* head, int val) {
	listnode* newhead, *newtail;
	newhead = newtail = NULL;
	listnode* pcur = head;
	while (pcur) {
		if (pcur->val != val) {
			if(!newhead)//新链表为空
				newhead = newtail = pcur;
			else {//新链表不为空
				newtail->next = pcur;
				newtail = newtail->next;
			}
		}
		pcur = pcur->next;
	}
	if(newtail)
		newtail->next = NULL;
	return newhead;
}

//第 2 题（编程题）
//题目名称：
//2.反转一个单链表
//题目内容：
//2.反转一个单链表。 OJ链接
struct ListNode* reverseList(struct ListNode* head) {
	if (!head)
		return head;
	listnode* l1, * l2, * l3;
	l1 = head;
	l2 = l1->next;
	l3 = NULL;

	while (l1) {
		l1->next = l3;
		l3 = l1;
		l1 = l2;
		if(l2)
			l2 = l2->next;
	}
	return l3;
}

//第 3 题（编程题）
//题目名称：
//3.给定一个带有头结点 head 的非空单链表，返回链表的中间结点。如果有两个中间结点，则返回第二个中间结点
//题目内容：
//3.给定一个带有头结点 head 的非空单链表，返回链表的中间结点。如果有两个中间结点，则返回第二个中间结点。OJ链接
struct ListNode* middleNode(struct ListNode* head) {
	listnode* fast, * slow;
	fast = slow = head;
	while (fast&&fast->next) {
		fast = fast->next->next;
		slow = slow->next;
	}
	return slow;
}

//第 4 题（编程题）
//题目名称：
//4.输入一个链表，输出该链表中倒数第k个结点
//题目内容：
//4.输入一个链表，输出该链表中倒数第k个结点。 OJ链接
int kthToLast(struct ListNode* head, int k) {
	if (!head)
		exit(1);
	listnode* pcur = head;
	int i = 0;
	while (pcur) {
		pcur = pcur->next;
		i++;
	}
	pcur = head;
	int n = i - k;
	while (n--) {
		pcur = pcur->next;
	}
	return pcur->val;
}

//第 5 题（编程题）
//题目名称：
//5.将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的
//题目内容：
//5.将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。OJ链接
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
	if (!list1)
		return list2;
	if (!list2)
		return list1;
	listnode* newlist = (listnode*)malloc(sizeof(listnode));
	listnode* pcur = newlist;
	while (list1 && list2) {
		if (list1->val < list2->val) {
			pcur->next = list1;
			list1 = list1->next;
		}
		else {
			pcur->next = list2;
			list2 = list2->next;
		}
		pcur = pcur->next;
	}
	if (list1)
		pcur->next = list1;
	if (list2)
		pcur->next = list2;
	listnode* ret = newlist->next;
	free(newlist);
	newlist = NULL;
	return ret;
}

//第 6 题（编程题）
//题目名称：
//6.编写代码，以给定值x为基准将链表分割成两部分，所有小于x的结点排在大于或等于x的结点之前
//题目内容：
//6.编写代码，以给定值x为基准将链表分割成两部分，所有小于x的结点排在大于或等于x的结点之前 。OJ链接
struct ListNode* partition(struct ListNode* pHead, int x) {
	listnode* small_head = (listnode*)malloc(sizeof(listnode));
	listnode* small_tail = small_head;
	listnode* big_head = (listnode*)malloc(sizeof(listnode));
	listnode* big_tail = big_head;
	listnode* pcur = pHead;
	while (pcur) {
		if (pcur->val < x) {
			small_tail->next = pcur;
			small_tail = small_tail->next;
		}
		else {
			big_tail->next = pcur;
			big_tail = big_tail->next;
		}
		pcur = pcur->next;
	}
	big_tail->next = NULL;
	small_tail->next = big_head->next;
	listnode* ret = small_head->next;
	free(small_head);
	free(big_head);
	small_head = big_head = NULL;
	return ret;
}

//第 7 题（编程题）
//题目名称：
//7.链表的回文结构
//题目内容：
//7.链表的回文结构。OJ链接
bool chkPalindrome(listnode* A) {
	//思路1：创建新数组，遍历原链表，将链表节点中的值放入数组，在数组中判断是否为回文结构
	int arr[900];
	int i = 0;
	listnode* pcur = A;
	while (pcur){
		arr[i++] = pcur->val;
		pcur = pcur->next;
	}
	int start = 0;
	int end = i - 1;
	while(start < end){
		if (arr[start] != arr[end]) {
			return false;
		}
		else {
			start++;
			end--;
		}
	}
	return true;
}

void Print(struct ListNode* n1) {
	listnode* pcur = n1;
	while (pcur) {
		printf("%d ", pcur->val);
		pcur = pcur->next;
	}
	printf("\n");
}
void test1() {
	listnode* n1=(listnode*)malloc(sizeof(listnode));
	n1->val = 1;
	listnode* n2=(listnode*)malloc(sizeof(listnode));
	n2->val = 2;
	listnode* n3=(listnode*)malloc(sizeof(listnode));
	n3->val = 6;
	listnode* n4=(listnode*)malloc(sizeof(listnode));
	n4->val = 3;
	listnode* n5=(listnode*)malloc(sizeof(listnode));
	n5->val = 4;
	listnode* n6=(listnode*)malloc(sizeof(listnode));
	n6->val = 5;
	listnode* n7=(listnode*)malloc(sizeof(listnode));
	n7->val = 6;
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;
	n5->next = n6;
	n6->next = n7;
	n7->next = NULL;

	listnode* ret = removeElements(n1,6);

	Print(ret);
		
	free(n1);
	free(n2);
	free(n3);
	free(n4);
	free(n5);
	free(n6);
	free(n7);
	n1 = n2 = n3 = n4 = n5 = n6 = n7 = NULL;
}
void test2() {
	listnode* n1 = (listnode*)malloc(sizeof(listnode));
	n1->val = 1;
	listnode* n2 = (listnode*)malloc(sizeof(listnode));
	n2->val = 2;
	listnode* n3 = (listnode*)malloc(sizeof(listnode));
	n3->val = 3;
	listnode* n4 = (listnode*)malloc(sizeof(listnode));
	n4->val = 4;
	listnode* n5 = (listnode*)malloc(sizeof(listnode));
	n5->val = 5;
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;
	n5->next = NULL;

	listnode* ret = reverseList(n1);

	Print(ret);

	free(n1);
	free(n2);
	free(n3);
	free(n4);
	free(n5);
	n1 = n2 = n3 = n4 = n5 = NULL;
}
void test3() {
	listnode* n1 = (listnode*)malloc(sizeof(listnode));
	n1->val = 1;
	listnode* n2 = (listnode*)malloc(sizeof(listnode));
	n2->val = 2;
	listnode* n3 = (listnode*)malloc(sizeof(listnode));
	n3->val = 3;
	listnode* n4 = (listnode*)malloc(sizeof(listnode));
	n4->val = 4;
	listnode* n5 = (listnode*)malloc(sizeof(listnode));
	n5->val = 5;
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;
	n5->next = NULL;

	listnode* ret = middleNode(n1);
	printf("%d\n", ret->val);

	free(n1);
	free(n2);
	free(n3);
	free(n4);
	free(n5);
	n1 = n2 = n3 = n4 = n5 = NULL;
}
void test4() {
	listnode* n1 = (listnode*)malloc(sizeof(listnode));
	n1->val = 1;
	listnode* n2 = (listnode*)malloc(sizeof(listnode));
	n2->val = 2;
	listnode* n3 = (listnode*)malloc(sizeof(listnode));
	n3->val = 3;
	listnode* n4 = (listnode*)malloc(sizeof(listnode));
	n4->val = 4;
	listnode* n5 = (listnode*)malloc(sizeof(listnode));
	n5->val = 5;
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;
	n5->next = NULL;

	int ret = kthToLast(n1, 2);
	printf("%d\n", ret);

	free(n1);
	free(n2);
	free(n3);
	free(n4);
	free(n5);
	n1 = n2 = n3 = n4 = n5 = NULL;
}
void test5() {
	listnode* n1 = (listnode*)malloc(sizeof(listnode));
	n1->val = 1;
	listnode* n2 = (listnode*)malloc(sizeof(listnode));
	n2->val = 2;
	listnode* n3 = (listnode*)malloc(sizeof(listnode));
	n3->val = 4;
	n1->next = n2;
	n2->next = n3;
	n3->next = NULL;

	listnode* l1 = (listnode*)malloc(sizeof(listnode));
	l1->val = 1;
	listnode* l2 = (listnode*)malloc(sizeof(listnode));
	l2->val = 3;
	listnode* l3 = (listnode*)malloc(sizeof(listnode));
	l3->val = 4;
	l1->next = l2;
	l2->next = l3;
	l3->next = NULL;

	listnode* ret = mergeTwoLists(n1, l1);
	Print(ret);

	free(n1);
	free(n2);
	free(n3);
	free(l1);
	free(l2);
	free(l3);
	n1 = n2 = n3 = l1 = l2 = l3 = NULL;
}
void test6() {
	listnode* n1 = (listnode*)malloc(sizeof(listnode));
	n1->val = 1;
	listnode* n2 = (listnode*)malloc(sizeof(listnode));
	n2->val = 6;
	listnode* n3 = (listnode*)malloc(sizeof(listnode));
	n3->val = 2;
	listnode* n4 = (listnode*)malloc(sizeof(listnode));
	n4->val = 3;
	listnode* n5 = (listnode*)malloc(sizeof(listnode));
	n5->val = 5;
	//2-6-3-1-5
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;
	n5->next = NULL;
	
	listnode* ret = partition(n1, 3);
	Print(ret);

	free(n1);
	free(n2);
	free(n3);
	free(n4);
	free(n5);
	n1 = n2 = n3 = n4 = n5 = NULL;
}
void test7() {
	listnode* n1 = (listnode*)malloc(sizeof(listnode));
	n1->val = 1;
	listnode* n2 = (listnode*)malloc(sizeof(listnode));
	n2->val = 2;
	listnode* n3 = (listnode*)malloc(sizeof(listnode));
	n3->val = 2;
	listnode* n4 = (listnode*)malloc(sizeof(listnode));
	n4->val = 1;
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = NULL;

	bool ret = chkPalindrome(n1);
	if (ret)
		printf("true");
	else
		printf("false");

	free(n1);
	free(n2);
	free(n3);
	free(n4);
	n1 = n2 = n3 = n4  = NULL;
}
int main() {
	test1();
	test2();
	test3();
	test4();
	test5();
	test6();
	test7();
	return 0;
}