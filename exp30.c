#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void preorderTraversal(struct TreeNode* root) {
    if (root == NULL)
        return;
    
    printf("%d ", root->val);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int main() {
    struct TreeNode* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    printf("Preorder traversal of binary tree is: \n");
    preorderTraversal(root);
    printf("\n");

    return 0;
}
