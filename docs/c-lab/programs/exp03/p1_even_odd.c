/*
 * Experiment 3.1: Check whether a number is even or odd
 * A number is even if dividing it by 2 leaves remainder 0.
 */
#include <stdio.h>

int main(void) {
    int n;

    printf("Enter an integer: ");
    scanf("%d", &n);

    if (n % 2 == 0) {
        printf("%d is even.\n", n);
    } else {
        printf("%d is odd.\n", n);
    }
    return 0;
}
