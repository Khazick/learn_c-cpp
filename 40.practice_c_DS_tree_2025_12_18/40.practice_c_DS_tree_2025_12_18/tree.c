#include "tree.h"

//前中后序遍历
void PreOrder(BTNode* root) {
	if (root==NULL) {
		return;
	}
	printf("%d ", root->val);
	PreOrder(root->left);
	PreOrder(root->right);
}
void InOrder(BTNode* root) {
	if (root == NULL) {
		return;
	}
	InOrder(root->left);
	printf("%d ", root->val);
	InOrder(root->right);
}
void PostOrder(BTNode* root) {
	if (root == NULL) {
		return;
	}
	PostOrder(root->left);
	PostOrder(root->right);
	printf("%d ", root->val);
}