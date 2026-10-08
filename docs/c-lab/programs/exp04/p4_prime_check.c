/*
 * Experiment 4.4: Check prime numbers
 * A prime has no divisor other than 1 and itself; testing up to sqrt(n) is enough.
 */
#include <stdio.h>

int main(void) {
    int n, i, isPrime = 1;

    printf("Enter a number: ");
    scanf("%d", &n);

    if (n < 2) {
        isPrime = 0;
    }
    for (i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            isPrime = 0;
            break;
        }
    }

    if (isPrime) {
        printf("%d is a prime number.\n", n);
    } else {
        printf("%d is not a prime number.\n", n);
    }
    return 0;
}
