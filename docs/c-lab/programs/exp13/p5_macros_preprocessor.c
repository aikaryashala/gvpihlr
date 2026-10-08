/*
 * Experiment 13.5: Demonstrate macros and preprocessor directives (#define, #ifdef, conditional compilation)
 * The preprocessor changes the source text before the compiler sees it.
 */
#include <stdio.h>

#define PI 3.14159                    /* constant macro */
#define MAX_SIZE 100
#define SQUARE(x) ((x) * (x))         /* function-like macro: note the parentheses */
#define MAX(a, b) ((a) > (b) ? (a) : (b))

/* Without parentheses, #define BAD_SQUARE(x) x * x
   would turn BAD_SQUARE(2 + 3) into 2 + 3 * 2 + 3 = 11, not 25. */

#define DEBUG                         /* comment this line out to turn debug off */
#define VERSION 2

int main(void) {
    int n;

    printf("Enter a number: ");
    if (scanf("%d", &n) != 1) {
        printf("Invalid input\n");
        return 1;
    }

    printf("PI = %.5f, MAX_SIZE = %d\n", PI, MAX_SIZE);
    printf("SQUARE(%d) = %d\n", n, SQUARE(n));
    printf("SQUARE(2 + 3) = %d\n", SQUARE(2 + 3));
    printf("MAX(%d, 10) = %d\n", n, MAX(n, 10));

#ifdef DEBUG
    printf("[DEBUG] n = %d\n", n);
#endif

#ifndef RELEASE
    printf("RELEASE is not defined, so this is a development build\n");
#endif

#if VERSION >= 2
    printf("Using version 2 features\n");
#else
    printf("Using version 1 features\n");
#endif

    printf("This line is line number %d of the source file\n", __LINE__);
    return 0;
}
