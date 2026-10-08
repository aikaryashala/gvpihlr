/*
 * Experiment 8.4: Reverse a string
 * Idea: swap the first and last characters, then move inwards.
 */

#include <stdio.h>

#define SIZE 100

int main(void) {
    char str[SIZE];
    int i, length = 0;
    char temp;

    printf("Enter a string: ");
    if (fgets(str, SIZE, stdin) == NULL) {
        printf("No input.\n");
        return 0;
    }

    /* find the length and remove the newline */
    while (str[length] != '\0' && str[length] != '\n') {
        length++;
    }
    str[length] = '\0';

    for (i = 0; i < length / 2; i++) {
        temp = str[i];
        str[i] = str[length - 1 - i];
        str[length - 1 - i] = temp;
    }

    printf("Reversed string: %s\n", str);
    return 0;
}
