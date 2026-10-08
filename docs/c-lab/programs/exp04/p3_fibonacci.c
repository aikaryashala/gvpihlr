/*
 * Experiment 4.3: Generate Fibonacci series
 * Each term is the sum of the previous two, starting with 0 and 1.
 */
#include <stdio.h>

int main(void) {
    int n, i;
    long long first = 0, second = 1, next;

    printf("Enter number of terms (1-90): ");
    scanf("%d", &n);

    if (n < 1 || n > 90) {
        printf("Please enter a value between 1 and 90.\n");
        return 0;
    }

    printf("Fibonacci series: ");
    for (i = 1; i <= n; i++) {
        printf("%lld ", first);
        next = first + second;
        first = second;
        second = next;
    }
    printf("\n");
    return 0;
}
