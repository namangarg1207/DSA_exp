#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct Node* findLCA(struct Node* root, int n1, int n2) {
    if (root == NULL)
        return NULL;
    if (root->data == n1 || root->data == n2)
        return root;
    struct Node* left_lca = findLCA(root->left, n1, n2);
    struct Node* right_lca = findLCA(root->right, n1, n2);
    if (left_lca && right_lca)
        return root;
    return (left_lca != NULL) ? left_lca : right_lca;
}

int main() {
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    int n1 = 4, n2 = 5;
    struct Node* t = findLCA(root, n1, n2);
    if (t != NULL)
        printf("LCA of %d and %d is %d\n", n1, n2, t->data);
    else
        printf("Keys are not present\n");

    n1 = 4, n2 = 10;
    t = findLCA(root, n1, n2);
    if (t != NULL)
        printf("LCA of %d and %d is %d\n", n1, n2, t->data);
    else
        printf("Keys are not present\n");

    return 0;
}
