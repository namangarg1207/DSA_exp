#include <stdio.h>

void calculate_totals_and_averages(int marks[][5], int num_students) {
    int i, j;
    int student_totals[num_students];
    float subject_totals[5] = {0};

    // Calculate total of every student
    for (i = 0; i < num_students; i++) {
        int total = 0;
        for (j = 0; j < 5; j++) {
            total += marks[i][j];
        }
        student_totals[i] = total;
    }

    // Calculate average of every subject
    for (i = 0; i < num_students; i++) {
        for (j = 0; j < 5; j++) {
            subject_totals[j] += marks[i][j];
        }
    }

    printf("Total marks of every student:\n");
    for (i = 0; i < num_students; i++) {
        printf("Student %d: %d\n", i + 1, student_totals[i]);
    }

    printf("Average marks of every subject:\n");
    for (j = 0; j < 5; j++) {
        printf("Subject %d: %.2f\n", j + 1, subject_totals[j] / num_students);
    }
}

int main() {
    int num_students, i, j;

    printf("Enter the number of students: ");
    scanf("%d", &num_students);

    int marks[num_students][5];

    for (i = 0; i < num_students; i++) {
        printf("Enter marks for student %d:\n", i + 1);
        for (j = 0; j < 5; j++) {
            printf("Enter marks for subject %d: ", j + 1);
            scanf("%d", &marks[i][j]);
        }
    }

    calculate_totals_and_averages(marks, num_students);

    return 0;
}
