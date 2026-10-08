/*
 * Experiment 13.4: Demonstrate command line arguments (sum of numbers passed as arguments)
 * argc is the number of arguments; argv[0] is the program name, argv[1..] are the values.
 */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int i;
    int sum = 0;

    if (argc < 2) {
        printf("Usage: %s num1 num2 num3 ...\n", argv[0]);
        return 1;
    }

    printf("Number of arguments (argc) = %d\n", argc);
    for (i = 1; i < argc; i++) {
        sum += atoi(argv[i]);      /* convert text to int */
    }
    printf("Sum of %d number(s) = %d\n", argc - 1, sum);
    return 0;
}
