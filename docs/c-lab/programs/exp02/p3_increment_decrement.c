/*
 * Experiment 2.3: Demonstrate increment/decrement operators.
 * Prefix (++x) changes the value first; postfix (x++) uses the old value first.
 */
#include <stdio.h>

int main(void) {
    int x = 5, y;

    printf("Initial x = %d\n", x);

    y = x++;
    printf("After y = x++ : x = %d, y = %d\n", x, y);

    y = ++x;
    printf("After y = ++x : x = %d, y = %d\n", x, y);

    y = x--;
    printf("After y = x-- : x = %d, y = %d\n", x, y);

    y = --x;
    printf("After y = --x : x = %d, y = %d\n", x, y);
    return 0;
}
