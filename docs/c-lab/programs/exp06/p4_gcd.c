/*
 * Experiment 6.4: GCD of two numbers
 * Idea (Euclid): gcd(a, b) = gcd(b, a % b), and gcd(a, 0) = a.
 */

#include <stdio.h>

int gcd(int a, int b);

int main(void) {
    int a, b;

    printf("Enter two positive numbers: ");
    if (scanf("%d %d", &a, &b) != 2 || a <= 0 || b <= 0) {
        printf("Invalid input. Enter two positive integers.\n");
        return 0;
    }

    printf("GCD of %d and %d = %d\n", a, b, gcd(a, b));
    return 0;
}

int gcd(int a, int b) {
    if (b == 0) {
        return a;               /* base case */
    }
    return gcd(b, a % b);       /* recursive case */
}
