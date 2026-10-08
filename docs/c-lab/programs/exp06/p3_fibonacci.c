/*
 * Experiment 6.3: Fibonacci series
 * Idea: fib(i) = fib(i-1) + fib(i-2), with fib(0) = 0 and fib(1) = 1.
 */

#include <stdio.h>

int fib(int i);

int main(void) {
    int n, i;

    printf("Enter the number of terms: ");
    if (scanf("%d", &n) != 1 || n < 1 || n > 30) {
        printf("Invalid input. Enter a number between 1 and 30.\n");
        return 0;
    }

    printf("Fibonacci series: ");
    for (i = 0; i < n; i++) {
        printf("%d ", fib(i));
    }
    printf("\n");
    return 0;
}

int fib(int i) {
    if (i == 0) {
        return 0;
    }
    if (i == 1) {
        return 1;
    }
    return fib(i - 1) + fib(i - 2);
}
