/*
 * Experiment 13.1: Demonstrate bitwise operators (AND, OR, XOR, NOT, shift)
 * Bitwise operators work on the individual bits of integers.
 */
#include <stdio.h>

void print_binary(unsigned char n);

int main(void) {
    unsigned char a, b;
    int x, y;

    printf("Enter two numbers (0 to 255): ");
    if (scanf("%d %d", &x, &y) != 2 || x < 0 || x > 255 || y < 0 || y > 255) {
        printf("Invalid input\n");
        return 1;
    }
    a = (unsigned char)x;
    b = (unsigned char)y;

    printf("a      = %3d = ", a); print_binary(a); printf("\n");
    printf("b      = %3d = ", b); print_binary(b); printf("\n");
    printf("a & b  = %3d = ", a & b); print_binary((unsigned char)(a & b)); printf("\n");
    printf("a | b  = %3d = ", a | b); print_binary((unsigned char)(a | b)); printf("\n");
    printf("a ^ b  = %3d = ", a ^ b); print_binary((unsigned char)(a ^ b)); printf("\n");
    printf("~a     = %3d = ", (unsigned char)~a); print_binary((unsigned char)~a); printf("\n");
    printf("a << 1 = %3d = ", (unsigned char)(a << 1)); print_binary((unsigned char)(a << 1)); printf("\n");
    printf("a >> 1 = %3d = ", a >> 1); print_binary((unsigned char)(a >> 1)); printf("\n");

    return 0;
}

/* Prints the 8 bits of n, starting from the leftmost bit */
void print_binary(unsigned char n) {
    int i;
    for (i = 7; i >= 0; i--) {
        printf("%d", (n >> i) & 1);
    }
}
