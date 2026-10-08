/*
 * Recursion: factorial
 * Look at Call Stack & Memory: factorial() calls itself, so the stack grows and then shrinks.
 */
#include <stdio.h>

int factorial(int n) {
    if (n <= 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

int main(void) {
    int i;

    for (i = 1; i <= 5; i++) {
        printf("%d! = %d\n", i, factorial(i));
    }
    return 0;
}
