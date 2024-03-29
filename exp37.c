#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    int hd;
    struct Node *left, *right;
};

struct Queue {
    int capacity;
    int front, rear;
    struct Node **array;
};

struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

struct Queue* createQueue(int capacity) {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->rear = -1;
    queue->array = (struct Node**)malloc(queue->capacity * sizeof(struct Node*));
    return queue;
}

void enQueue(struct Queue* queue, struct Node* item) {
    queue->array[++queue->rear] = item;
    if (queue->front == -1) ++queue->front;
}

struct Node* deQueue(struct Queue* queue) {
    struct Node* item = queue->array[queue->front];
    if (queue->front == queue->rear) queue->front = queue->rear = -1;
    else ++queue->front;
    return item;
}

void bottomView(struct Node* root) {
    if (!root) return;

    int hd = 0;
    struct Queue* queue = createQueue(100);
    root->hd = hd;
    enQueue(queue, root);

    while (queue->front != -1) {
        struct Node* temp = deQueue(queue);
        hd = temp->hd;
        if (temp->left) {
            temp->left->hd = hd - 1;
            enQueue(queue, temp->left);
        }
        if (temp->right) {
            temp->right->hd = hd + 1;
            enQueue(queue, temp->right);
        }
    }

    int i;
    for (i = -100; i <= 100; i++) {
        int min = 10000;
        for (int j = 0; j <= queue->rear; j++) {
            struct Node* temp = queue->array[j];
            if (temp->hd == i && temp->data < min)
                min = temp->data;
        }
        if (min != 10000)
            printf("%d ", min);
    }
}

int main() {
    struct Node* root = newNode(20);
    root->left = newNode(8);
    root->right = newNode(22);
    root->left->left = newNode(5);
    root->left->right = newNode(3);
    root->right->left = newNode(4);
    root->right->right = newNode(25);
    root->left->right->left = newNode(10);
    root->left->right->right = newNode(14);

    printf("Bottom view of the binary tree:\n");
    bottomView(root);
    return 0;
}
