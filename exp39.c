#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

void rightViewUtil(struct Node* root, int level, int* max_level) {
    if (root == NULL) return;

    if (*max_level < level) {
        printf("%d ", root->data);
        *max_level = level;
    }

    rightViewUtil(root->right, level + 1, max_level);
    rightViewUtil(root->left, level + 1, max_level);
}

void rightView(struct Node* root) {
    int max_level = 0;
    rightViewUtil(root, 1, &max_level);
}

int main() {
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->right = newNode(5);
    root->right->right = newNode(4);
    
    printf("Right view of the binary tree is: ");
    rightView(root);
    return 0;
}
