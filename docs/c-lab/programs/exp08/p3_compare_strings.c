/*
 * Experiment 8.3: Compare two strings
 * The manual loop and strcmp() are both shown.
 */

#include <stdio.h>
#include <string.h>

#define SIZE 100

void remove_newline(char s[]);

int main(void) {
    char s1[SIZE], s2[SIZE];
    int i, manual_equal, lib_result;

    printf("Enter the first string: ");
    if (fgets(s1, SIZE, stdin) == NULL) {
        printf("No input.\n");
        return 0;
    }
    printf("Enter the second string: ");
    if (fgets(s2, SIZE, stdin) == NULL) {
        printf("No input.\n");
        return 0;
    }
    remove_newline(s1);
    remove_newline(s2);

    /* Manual: walk along while characters match and neither string ends */
    i = 0;
    while (s1[i] != '\0' && s1[i] == s2[i]) {
        i++;
    }
    manual_equal = (s1[i] == s2[i]);   /* equal only if both ended together */

    lib_result = strcmp(s1, s2);

    printf("\nUsing manual loop: ");
    if (manual_equal) {
        printf("the strings are equal\n");
    } else {
        printf("the strings are not equal\n");
    }

    printf("Using strcmp(): ");
    if (lib_result == 0) {
        printf("the strings are equal\n");
    } else {
        printf("the strings are not equal\n");
    }
    return 0;
}

void remove_newline(char s[]) {
    int i;
    for (i = 0; s[i] != '\0'; i++) {
        if (s[i] == '\n') {
            s[i] = '\0';
            break;
        }
    }
}
