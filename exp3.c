#include <stdio.h>

void insert(int arr[], int *n, int loc, int value) {
    if (loc < 0 || loc > *n) {
        printf("Invalid location\n");
        return;
    }
    if (*n >= 100) {
        printf("Array overflow\n");
        return;
    }
    for (int i = *n; i > loc; i--) {
        arr[i] = arr[i - 1];
    }
    arr[loc] = value;
    (*n)++;
}

void delete (int arr[], int *n, int loc) {
    if (loc < 0 || loc >= *n) {
        printf("Invalid location\n");
        return;
    }
    for (int i = loc; i < *n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*n)--;
}

int main() {
    int arr[100], n, loc, value, choice;
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

    printf("Enter 1 for insertion, 2 for deletion: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter the location to insert: ");
            scanf("%d", &loc);
            printf("Enter the value to insert: ");
            scanf("%d", &value);
            insert(arr, &n, loc, value);
            printf("Array elements after insertion: ");
            for (int i = 0; i < n; i++) {
                printf("%d ", arr[i]);
            }
            break;
        case 2:
            printf("Enter the location to delete: ");
            scanf("%d", &loc);
            delete (arr, &n, loc);
            printf("Array elements after deletion: ");
            for (int i = 0; i < n; i++) {
                printf("%d ", arr[i]);
            }
            break;
        default:
            printf("Invalid choice\n");
    }
    return 0;
}
