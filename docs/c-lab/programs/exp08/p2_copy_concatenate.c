/*
 * Experiment 8.2: Copy and concatenate strings
 * Each task is done with a manual loop and again with the library function.
 */

#include <stdio.h>
#include <string.h>

#define SIZE 100

void remove_newline(char s[]);

int main(void) {
    char s1[SIZE], s2[SIZE];
    char copy[SIZE], joined[2 * SIZE];
    char copy_lib[SIZE], joined_lib[2 * SIZE];
    int i, j;

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

    /* Manual copy: copy s1 into copy */
    for (i = 0; s1[i] != '\0'; i++) {
        copy[i] = s1[i];
    }
    copy[i] = '\0';

    /* Manual concatenation: s1 followed by s2 */
    for (i = 0; s1[i] != '\0'; i++) {
        joined[i] = s1[i];
    }
    for (j = 0; s2[j] != '\0'; j++) {
        joined[i + j] = s2[j];
    }
    joined[i + j] = '\0';

    /* Library versions */
    strcpy(copy_lib, s1);
    strcpy(joined_lib, s1);
    strcat(joined_lib, s2);

    printf("\nUsing manual loops:\n");
    printf("  Copy of first string : %s\n", copy);
    printf("  Concatenated string  : %s\n", joined);
    printf("Using strcpy() and strcat():\n");
    printf("  Copy of first string : %s\n", copy_lib);
    printf("  Concatenated string  : %s\n", joined_lib);
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
