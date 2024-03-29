#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void push(struct Node** headRef, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *headRef;
    *headRef = newNode;
}

int nthFromEnd(struct Node* head, int n) {
    struct Node *mainPtr = head, *refPtr = head;
    int count = 0;
    
    while (count < n) {
        if (refPtr == NULL) {
            printf("%d is greater than the no. of elements in the list\n", n);
            return -1;
        }
        refPtr = refPtr->next;
        count++;
    }
    
    while (refPtr != NULL) {
        mainPtr = mainPtr->next;
        refPtr = refPtr->next;
    }
    return mainPtr->data;
}

int main() {
    struct Node* head = NULL;
    push(&head, 20);
    push(&head, 4);
    push(&head, 15);
    push(&head, 35);

    printf("Element at position 3 from end: %d\n", nthFromEnd(head, 3));
    return 0;
}
