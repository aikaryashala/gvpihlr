/*
 * Experiment 4.1: Generate multiplication tables
 * A for loop prints n x 1 up to n x 10.
 */
#include <stdio.h>

int main(void) {
    int n, i;

    printf("Enter a number: ");
    scanf("%d", &n);

    printf("Multiplication table of %d\n", n);
    for (i = 1; i <= 10; i++) {
        printf("%d x %2d = %d\n", n, i, n * i);
    }
    return 0;
}
