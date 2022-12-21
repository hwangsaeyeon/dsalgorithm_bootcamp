#include <stdio.h>
#include <stdlib.h>
#include "traversalBT.h"

// data is parant node
// Allocate data dynamically, and assume that leftNode and rightNode were already assigned
// then, return data
treeNode* makeRootNode(element data, treeNode* leftNode, treeNode* rightNode) {
    //*을 하면 주소
    treeNode* new;
    new = malloc(sizeof(treeNode));
    
    new->data = data;
    new->left = leftNode;
    new->right = rightNode;
    return new;
}

// Preorder traversal: -*AB/CD
void preorder1(treeNode* root) {
    if (root != NULL)
    {
        printf("%c",root->data);
        preorder1(root->left);
        preorder1(root->right);
    }
}

// Inorder traversal: A*B-C/D
void inorder(treeNode* root) {
    if (root != NULL)
    {
        inorder(root->left);
        printf("%c",root->data);
        inorder(root->right);
        
    }
        
}

// Postorder traversal: AB*CD/-
void postorder1(treeNode* root) {
    if (root != NULL)
    {
        postorder1(root->left);
        postorder1(root->right);
        printf("%c",root->data);
    }
}
