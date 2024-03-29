#include<stdio.h>
#include<stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int search(int arr[], int strt, int end, int value) {
    int i;
    for (i = strt; i <= end; i++) {
        if (arr[i] == value)
            return i;
    }
    return -1;
}

struct TreeNode* buildUtil(int in[], int post[], int inStrt, int inEnd, int *pIndex) {
    if (inStrt > inEnd)
        return NULL;

    struct TreeNode* node = newNode(post[*pIndex]);
    (*pIndex)--;

    if (inStrt == inEnd)
        return node;

    int iIndex = search(in, inStrt, inEnd, node->val);

    node->right = buildUtil(in, post, iIndex + 1, inEnd, pIndex);
    node->left = buildUtil(in, post, inStrt, iIndex - 1, pIndex);

    return node;
}

struct TreeNode* buildTree(int in[], int post[], int n) {
    int pIndex = n - 1;
    return buildUtil(in, post, 0, n - 1, &pIndex);
}

void preOrder(struct TreeNode* node) {
    if (node == NULL) return;
    printf("%d ", node->val);
    preOrder(node->left);
    preOrder(node->right);
}

int main() {
    int in[] = {9, 3, 15, 20, 7};
    int post[] = {9, 15, 7, 20, 3};
    int n = sizeof(in) / sizeof(in[0]);
    struct TreeNode* root = buildTree(in, post, n);

    printf("Preorder traversal of the constructed tree is \n");
    preOrder(root);

    return 0;
}
