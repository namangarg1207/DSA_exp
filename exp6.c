#include <stdio.h>

int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i; 
        }
    }
    return -1; 
}


int main() {
    int arr[] = {12, 34, 45, 23, 76, 55};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 23;

    int result = linearSearch(arr, n, key);
    if (result != -1) {
        printf("Element found at index %d\n", result);
    } else {
        printf("Element not found\n");
    }
    return 0;
}
