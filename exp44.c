#include <stdio.h>
#include <stdbool.h>

bool isValid(char *s) {
    int count = 0;
    while (*s) {
        if (*s == '(')
            count++;
        else if (*s == ')') {
            if (count == 0)
                return false;
            count--;
        }
        s++;
    }
    return count == 0;
}

int main() {
    char str[] = "((()))";
    if (isValid(str))
        printf("Valid\n");
    else
        printf("Invalid\n");
    return 0;
}
