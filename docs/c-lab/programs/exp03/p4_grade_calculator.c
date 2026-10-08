/*
 * Experiment 3.4: Calculate grades based on marks
 * Uses an if-else-if ladder on marks out of 100.
 */
#include <stdio.h>

int main(void) {
    int marks;

    printf("Enter marks (0-100): ");
    scanf("%d", &marks);

    if (marks < 0 || marks > 100) {
        printf("Invalid marks.\n");
    } else if (marks >= 90) {
        printf("Grade: A (Outstanding)\n");
    } else if (marks >= 80) {
        printf("Grade: B (Very Good)\n");
    } else if (marks >= 70) {
        printf("Grade: C (Good)\n");
    } else if (marks >= 60) {
        printf("Grade: D (Satisfactory)\n");
    } else if (marks >= 40) {
        printf("Grade: E (Pass)\n");
    } else {
        printf("Grade: F (Fail)\n");
    }
    return 0;
}
