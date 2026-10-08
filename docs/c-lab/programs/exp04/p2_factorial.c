/*
 * Experiment 4.2: Compute factorial of a number
 * n! = 1 * 2 * 3 * ... * n. The largest n that fits in unsigned long long is 20.
 */
#include <stdio.h>

int main(void) {
    int n, i;
    unsigned long long fact = 1;

    printf("Enter a number: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Factorial is not defined for negative numbers.\n");
    } else if (n > 20) {
        printf("Number too large (maximum supported is 20).\n");
    } else {
        for (i = 1; i <= n; i++) {
            fact *= i;
        }
        printf("Factorial of %d = %llu\n", n, fact);
    }
    return 0;
}
