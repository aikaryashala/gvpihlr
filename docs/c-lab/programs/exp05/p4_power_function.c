/*
 * Experiment 5.4: Find power of a number
 * power(base, exp) multiplies base by itself exp times.
 */
#include <stdio.h>

double power(double base, int exp);

int main(void) {
    double base;
    int exp;

    printf("Enter the base: ");
    scanf("%lf", &base);
    printf("Enter the exponent (non-negative integer): ");
    scanf("%d", &exp);

    if (exp < 0) {
        printf("Please enter a non-negative exponent.\n");
        return 0;
    }

    printf("%g raised to the power %d = %g\n", base, exp, power(base, exp));
    return 0;
}

double power(double base, int exp) {
    double result = 1;
    int i;

    for (i = 0; i < exp; i++) {
        result *= base;
    }
    return result;
}
