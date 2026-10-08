/*
 * Experiment 5.2: Find GCD and LCM
 * GCD uses Euclid's algorithm; then LCM = (a * b) / GCD.
 */
#include <stdio.h>

int gcd(int a, int b);
long long lcm(int a, int b);

int main(void) {
    int a, b;

    printf("Enter two positive integers: ");
    scanf("%d %d", &a, &b);

    if (a <= 0 || b <= 0) {
        printf("Please enter positive integers.\n");
        return 0;
    }

    printf("GCD of %d and %d = %d\n", a, b, gcd(a, b));
    printf("LCM of %d and %d = %lld\n", a, b, lcm(a, b));
    return 0;
}

int gcd(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

long long lcm(int a, int b) {
    return (long long)a / gcd(a, b) * b;
}
