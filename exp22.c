#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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


bool detectCycle(struct Node* head) {
    struct Node* slow = head;
    struct Node* fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            return true;
        }
    }
    return false;
}


void removeCycle(struct Node* head) {
    struct Node* slow = head;
    struct Node* fast = head;
    struct Node* prev = NULL;

    while (fast && fast->next) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
           
            prev->next = NULL;
            return;
        }
    }
}


void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
  
    struct Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = head->next; 

    printf("Linked list with cycle: ");
    detectCycle(head) ? printf("Cycle Detected\n") : printf("No Cycle Detected\n");

    
    removeCycle(head);
    printf("Linked list after removing cycle: ");
    detectCycle(head) ? printf("Cycle Detected\n") : printf("No Cycle Detected\n");

    return 0;
}
