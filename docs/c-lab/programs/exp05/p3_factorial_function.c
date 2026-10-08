/*
 * Experiment 5.3: Compute factorial
 * The function factorial() multiplies 1 * 2 * ... * n and returns the result.
 */
#include <stdio.h>

unsigned long long factorial(int n);

int main(void) {
    int n;

    printf("Enter a number: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Factorial is not defined for negative numbers.\n");
    } else if (n > 20) {
        printf("Number too large (maximum supported is 20).\n");
    } else {
        printf("Factorial of %d = %llu\n", n, factorial(n));
    }
    return 0;
}

unsigned long long factorial(int n) {
    unsigned long long result = 1;
    int i;

    for (i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}
