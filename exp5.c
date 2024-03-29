#include <stdio.h>

#define MAX_SIZE 100

void insertAtEnd(int arr[], int *n, int value) {
    if (*n >= MAX_SIZE) {
        printf("Array overflow: Cannot insert element\n");
        return;
    }
    arr[*n] = value;
    (*n)++;
}

void deleteAtEnd(int arr[], int *n) {
    if (*n == 0) {
        printf("Array underflow: Cannot delete element\n");
        return;
    }
    (*n)--;
}

int main() {
    int arr[MAX_SIZE], n, value, choice;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Array elements before insertion/deletion: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Enter 1 for insertion at end, 2 for deletion at end: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter the value to insert at end: ");
            scanf("%d", &value);
            insertAtEnd(arr, &n, value);
            if (n <= MAX_SIZE) {
                printf("Array elements after insertion at end: ");
                for (int i = 0; i < n; i++) {
                    printf("%d ", arr[i]);
                }
            }
            break;
        case 2:
            deleteAtEnd(arr, &n);
            if (n >= 0) {
                printf("Array elements after deletion from end: ");
                for (int i = 0; i < n; i++) {
                    printf("%d ", arr[i]);
                }
            }
            break;
        default:
            printf("Invalid choice\n");
    }
    return 0;
}
