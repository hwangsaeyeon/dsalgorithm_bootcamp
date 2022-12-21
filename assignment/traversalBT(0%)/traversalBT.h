#pragma once
typedef char element;

typedef struct treeNode{
	element data;
	struct treeNode* left;
	struct treeNode* right;
} treeNode;

treeNode* makeRootNode(element data, treeNode* leftNode, treeNode* rightNode);
void preorder1(treeNode* root);
void inorder(treeNode* root);
void postorder1(treeNode* root);
