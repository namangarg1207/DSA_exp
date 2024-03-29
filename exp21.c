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

int length(struct Node* head) {
    int len = 0;
    while (head != NULL) {
        len++;
        head = head->next;
    }
    return len;
}

struct Node* findMergePoint(struct Node* head1, struct Node* head2) {
    int len1 = length(head1);
    int len2 = length(head2);

    while (len1 > len2) {
        head1 = head1->next;
        len1--;
    }

    while (len2 > len1) {
        head2 = head2->next;
        len2--;
    }

    while (head1 != head2) {
        head1 = head1->next;
        head2 = head2->next;
    }

    return head1;
}

int main() {
    struct Node* intersectNode = createNode(7);
    intersectNode->next = createNode(8);
    intersectNode->next->next = createNode(9);

    struct Node* head1 = createNode(1);
    head1->next = createNode(2);
    head1->next->next = createNode(3);
    head1->next->next->next = intersectNode;

    struct Node* head2 = createNode(4);
    head2->next = createNode(5);
    head2->next->next = intersectNode;

    printf("Merge point of the two linked lists: %d\n", findMergePoint(head1, head2)->data);

    return 0;
}
