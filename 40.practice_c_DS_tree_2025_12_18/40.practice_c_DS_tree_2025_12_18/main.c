#include "tree.h"

BTNode* BuyBTNode(BTDataType x) {
	BTNode* tree = (BTNode*)malloc(sizeof(BTNode));
	if (!tree) {
		perror("malloc fail!");
		exit(1);
	}
	tree->left = tree->right = NULL;
	tree->val = x;
	return tree;
}

void test01() {
	BTNode* n1 = BuyBTNode(1);
	BTNode* n2 = BuyBTNode(2);
	BTNode* n3 = BuyBTNode(3);
	BTNode* n4 = BuyBTNode(4);

	n1->left = n2;
	n1->right = n3;
	n2->left = n4;
	BTNode* plist = n1;

	PreOrder(plist);
	printf("\n");
	InOrder(plist);
	printf("\n");
	PostOrder(plist);
	printf("\n");

}

int main() {
	test01();

	return 0;
}