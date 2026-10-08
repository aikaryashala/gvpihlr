/*
 * Macros and conditional compilation
 * Look at the Preprocessing stage: the #ifdef DEBUG line disappears because DEBUG is not defined,
 * and SQUARE(4) is expanded to ((4) * (4)).
 */
#include <stdio.h>

#define SQUARE(x) ((x) * (x))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

int main(void) {
    printf("SQUARE(4)    = %d\n", SQUARE(4));
    printf("SQUARE(2+3)  = %d\n", SQUARE(2 + 3));
    printf("MAX(15, 9)   = %d\n", MAX(15, 9));

#ifdef DEBUG
    printf("Debug mode is ON\n");
#else
    printf("Debug mode is OFF\n");
#endif
    return 0;
}
