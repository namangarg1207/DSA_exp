#include <stdio.h>
#define MAX_SIZE 100

int stack[MAX_SIZE];
int top = -1;

void push(int value) {
    if (top >= MAX_SIZE - 1) {
        printf("Stack overflow\n");
        return;
    }
    stack[++top] = value;
}

int pop() {
    if (top < 0) {
        printf("Stack underflow\n");
        return -1;
    }
    return stack[top--];
}

void nextGreater(int arr[], int n) {
    int i, next;
    push(arr[0]);

    for (i = 1; i < n; i++) {
        next = arr[i];
        if (top >= 0) {
            while (next > stack[top]) {
                printf("%d --> %d\n", stack[top], next);
                pop();
                if (top < 0) break;
            }
        }
        push(next);
    }

    while (top >= 0) {
        printf("%d --> -1\n", stack[top]);
        pop();
    }
}

int main() {
    int arr[] = {4, 5, 2, 10, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    nextGreater(arr, n);
    return 0;
}

