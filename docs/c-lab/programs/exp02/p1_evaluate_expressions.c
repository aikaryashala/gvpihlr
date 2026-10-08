/*
 * Experiment 2.1: Evaluate arithmetic expressions.
 * Shows how operator precedence and parentheses change the result.
 */
#include <stdio.h>

int main(void) {
    int a, b, c;

    printf("Enter three integers a, b and c: ");
    scanf("%d %d %d", &a, &b, &c);

    printf("a + b * c       = %d\n", a + b * c);
    printf("(a + b) * c     = %d\n", (a + b) * c);
    printf("a * b - c       = %d\n", a * b - c);
    printf("a + b / c       = %d\n", a + b / c);
    printf("a %% b + c       = %d\n", a % b + c);
    printf("(a + b + c) / 3 = %.2f\n", (a + b + c) / 3.0);
    return 0;
}
