/*
 * Hello World with macros
 * Look at the Preprocessing stage: the #define names are replaced by their values.
 */
#include <stdio.h>

#define UNIVERSITY "GVPIHLR"
#define YEAR 2026

int main(void) {
    printf("Hello World!\n");
    printf("Welcome to %s, batch of %d.\n", UNIVERSITY, YEAR);
    return 0;
}
