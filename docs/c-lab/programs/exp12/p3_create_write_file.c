/*
 * Experiment 12.3: Create and write to a text file
 * Mode "w" creates students.txt (or erases it if it already exists).
 */
#include <stdio.h>

int main(void) {
    FILE *fp;
    int n, i, roll;
    char name[50];
    float marks;

    printf("Enter number of students: ");
    if (scanf("%d", &n) != 1 || n < 1) {
        printf("Invalid number\n");
        return 1;
    }

    fp = fopen("students.txt", "w");
    if (fp == NULL) {
        printf("Error: could not create students.txt\n");
        return 1;
    }

    for (i = 1; i <= n; i++) {
        printf("Enter roll number, name and marks of student %d: ", i);
        if (scanf("%d %49s %f", &roll, name, &marks) != 3) {
            printf("Invalid input\n");
            fclose(fp);
            return 1;
        }
        fprintf(fp, "%d %s %.1f\n", roll, name, marks);
    }

    fclose(fp);
    printf("%d record(s) written to students.txt\n", n);
    return 0;
}
