/*
 * Experiment 6.2: Sum of first N natural numbers
 * Idea: sum(n) = n + sum(n-1), and sum(0) = 0.
 */

#include <stdio.h>

int sum(int n);

int main(void) {
    int n;

    printf("Enter N: ");
    if (scanf("%d", &n) != 1 || n < 0) {
        printf("Invalid input. N must be zero or a positive integer.\n");
        return 0;
    }

    printf("Sum of first %d natural numbers = %d\n", n, sum(n));
    return 0;
}

int sum(int n) {
    if (n == 0) {
        return 0;               /* base case */
    }
    return n + sum(n - 1);      /* recursive case */
}
