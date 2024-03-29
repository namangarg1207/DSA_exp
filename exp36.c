#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

Node* newNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

void topViewUtil(Node* root, int hd, int *min, int *max) {
    if (root == NULL) return;

    if (hd < *min) *min = hd;
    else if (hd > *max) *max = hd;

    topViewUtil(root->left, hd - 1, min, max);
    topViewUtil(root->right, hd + 1, min, max);
}

void topView(Node* root) {
    if (root == NULL) return;

    int min = 0, max = 0;
    topViewUtil(root, 0, &min, &max);

    for (int i = min; i <= max; i++) {
        printVerticalLine(root, i, 0);
        printf("\n");
    }
}

void printVerticalLine(Node* root, int hd, int line_hd) {
    if (root == NULL) return;

    if (hd == line_hd)
        printf("%d ", root->data);

    printVerticalLine(root->left, hd, line_hd - 1);
    printVerticalLine(root->right, hd, line_hd + 1);
}

int main() {
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->right = newNode(4);
    root->left->right->right = newNode(5);
    root->left->right->right->right = newNode(6);

    printf("Top view of the binary tree is: \n");
    topView(root);

    return 0;
}
