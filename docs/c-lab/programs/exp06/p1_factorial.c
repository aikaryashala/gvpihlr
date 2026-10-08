/*
 * Experiment 6.1: Factorial
 * Idea: n! = n * (n-1)!, and 0! = 1 (the stopping case).
 */

#include <stdio.h>

unsigned long long factorial(int n);

int main(void) {
    int n;

    printf("Enter a number (0 to 20): ");
    if (scanf("%d", &n) != 1 || n < 0 || n > 20) {
        printf("Invalid input. Enter a number between 0 and 20.\n");
        return 0;
    }

    printf("Factorial of %d = %llu\n", n, factorial(n));
    return 0;
}

unsigned long long factorial(int n) {
    if (n == 0) {
        return 1;               /* base case */
    }
    return n * factorial(n - 1); /* recursive case */
}
