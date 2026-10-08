/*
 * Functions
 * Look at Call Stack & Memory: main() calls area(), which calls square().
 */
#include <stdio.h>

int square(int n) {
    return n * n;
}

int area(int side) {
    return square(side);
}

int main(void) {
    int side = 7;
    int a = area(side);

    printf("Side of the square = %d\n", side);
    printf("Area of the square = %d\n", a);
    return 0;
}
