#include <stdio.h>

void insertAtBeginning(int arr[], int *n, int value) {
    if (*n >= 100) {
        printf("Array overflow\n");
        return;
    }
    for (int i = *n; i > 0; i--) {
        arr[i] = arr[i - 1];
    }
    arr[0] = value;
    (*n)++;
}

void deleteAtBeginning(int arr[], int *n) {
    if (*n == 0) {
        printf("Array underflow\n");
        return;
    }
    for (int i = 0; i < *n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*n)--;
}

int main() {
    int arr[100], n, value, choice;
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

    printf("Enter 1 for insertion at beginning, 2 for deletion at beginning: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter the value to insert at beginning: ");
            scanf("%d", &value);
            insertAtBeginning(arr, &n, value);
            printf("Array elements after insertion at beginning: ");
            for (int i = 0; i < n; i++) {
                printf("%d ", arr[i]);
            }
            break;
        case 2:
            deleteAtBeginning(arr, &n);
            printf("Array elements after deletion from beginning: ");
            for (int i = 0; i < n; i++) {
                printf("%d ", arr[i]);
            }
            break;
        default:
            printf("Invalid choice\n");
    }
    return 0;
}
