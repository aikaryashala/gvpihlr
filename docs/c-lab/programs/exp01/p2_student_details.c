/*
 * Experiment 1.2: Read and print student details
 * Reads a name (with spaces), a roll number and marks, then prints them.
 */
#include <stdio.h>

int main(void) {
    char name[50];
    int roll;
    float marks;

    printf("Enter student name: ");
    scanf(" %49[^\n]", name);
    printf("Enter roll number: ");
    scanf("%d", &roll);
    printf("Enter marks: ");
    scanf("%f", &marks);

    printf("\n--- Student Details ---\n");
    printf("Name   : %s\n", name);
    printf("Roll no: %d\n", roll);
    printf("Marks  : %.2f\n", marks);
    return 0;
}
