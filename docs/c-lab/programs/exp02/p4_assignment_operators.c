/*
 * Experiment 2.4: Demonstrate assignment operators.
 * Each compound operator (like +=) is a short form of x = x op value.
 */
#include <stdio.h>

int main(void) {
    int x = 20;

    printf("x = 20   -> x = %d\n", x);
    x += 5;
    printf("x += 5   -> x = %d\n", x);
    x -= 3;
    printf("x -= 3   -> x = %d\n", x);
    x *= 2;
    printf("x *= 2   -> x = %d\n", x);
    x /= 4;
    printf("x /= 4   -> x = %d\n", x);
    x %= 4;
    printf("x %%= 4   -> x = %d\n", x);
    return 0;
}
