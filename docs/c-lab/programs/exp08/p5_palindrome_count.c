/*
 * Experiment 8.5: Check palindrome and count vowels, digits, and special characters
 * Palindrome check is case-sensitive and compares every character as typed.
 * Special character = anything that is not a letter, digit or space.
 */

#include <stdio.h>

#define SIZE 100

int main(void) {
    char str[SIZE];
    int i, length = 0;
    int vowels = 0, digits = 0, special = 0;
    int is_palindrome = 1;
    char c;

    printf("Enter a string: ");
    if (fgets(str, SIZE, stdin) == NULL) {
        printf("No input.\n");
        return 0;
    }

    while (str[length] != '\0' && str[length] != '\n') {
        length++;
    }
    str[length] = '\0';

    /* palindrome: compare first and last characters, moving inwards */
    for (i = 0; i < length / 2; i++) {
        if (str[i] != str[length - 1 - i]) {
            is_palindrome = 0;
            break;
        }
    }

    /* count vowels, digits and special characters */
    for (i = 0; i < length; i++) {
        c = str[i];
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
            vowels++;
        } else if (c >= '0' && c <= '9') {
            digits++;
        } else if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == ' ')) {
            special++;
        }
    }

    if (is_palindrome) {
        printf("\"%s\" is a palindrome\n", str);
    } else {
        printf("\"%s\" is not a palindrome\n", str);
    }
    printf("Vowels = %d\n", vowels);
    printf("Digits = %d\n", digits);
    printf("Special characters = %d\n", special);
    return 0;
}
