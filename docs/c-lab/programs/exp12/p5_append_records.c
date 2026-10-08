/*
 * Experiment 12.5: Append records to a file
 * Mode "a" adds new data at the end without erasing the old data.
 */
#include <stdio.h>

int main(void) {
    FILE *fp;
    int n, i, roll;
    char name[50];
    float marks;
    char line[100];

    printf("Enter number of records to append: ");
    if (scanf("%d", &n) != 1 || n < 1) {
        printf("Invalid number\n");
        return 1;
    }

    fp = fopen("students.txt", "a");
    if (fp == NULL) {
        printf("Error: could not open students.txt\n");
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
    printf("%d record(s) appended\n", n);

    /* Open again for reading to show the whole file */
    fp = fopen("students.txt", "r");
    if (fp == NULL) {
        printf("Error: could not read students.txt\n");
        return 1;
    }
    printf("\nContents of students.txt:\n");
    printf("Roll Name Marks\n");
    while (fgets(line, sizeof(line), fp) != NULL) {
        printf("%s", line);
    }
    fclose(fp);
    return 0;
}
