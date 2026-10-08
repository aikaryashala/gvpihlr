/*
 * Pointers: swap two numbers
 * Look at Call Stack & Memory: swap() gets the addresses of x and y, so it changes main()'s variables.
 */
#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(void) {
    int x = 10, y = 20;

    printf("Before swap: x = %d, y = %d\n", x, y);
    swap(&x, &y);
    printf("After swap:  x = %d, y = %d\n", x, y);
    return 0;
}
