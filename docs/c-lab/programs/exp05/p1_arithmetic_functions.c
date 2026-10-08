/*
 * Experiment 5.1: Perform arithmetic operations
 * Each operation is written as a separate user-defined function.
 */
#include <stdio.h>

int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
double divide(int a, int b);

int main(void) {
    int x, y;

    printf("Enter two integers: ");
    scanf("%d %d", &x, &y);

    printf("Sum        = %d\n", add(x, y));
    printf("Difference = %d\n", subtract(x, y));
    printf("Product    = %d\n", multiply(x, y));
    if (y != 0) {
        printf("Quotient   = %.2f\n", divide(x, y));
    } else {
        printf("Quotient   : cannot divide by zero\n");
    }
    return 0;
}

int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

double divide(int a, int b) {
    return (double)a / b;
}
