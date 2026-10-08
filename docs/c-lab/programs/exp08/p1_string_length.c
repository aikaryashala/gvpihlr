/*
 * Experiment 8.1: Find string length without strlen()
 * Idea: count characters until the end-of-string character '\0'.
 */

#include <stdio.h>

#define SIZE 100

int main(void) {
    char str[SIZE];
    int i, length = 0;

    printf("Enter a string: ");
    if (fgets(str, SIZE, stdin) == NULL) {
        printf("No input.\n");
        return 0;
    }

    /* remove the newline that fgets keeps */
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\n') {
            str[i] = '\0';
            break;
        }
    }

    while (str[length] != '\0') {
        length++;
    }

    printf("Length of \"%s\" = %d\n", str, length);
    return 0;
}
