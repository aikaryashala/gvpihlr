/*
 * Experiment 5.5: Demonstrate parameter passing using call by value concept.
 * The function receives copies of the arguments, so swapping them inside
 * the function does not change the original variables in main().
 */
#include <stdio.h>

void swap(int a, int b);

int main(void) {
    int x, y;

    printf("Enter two integers: ");
    scanf("%d %d", &x, &y);

    printf("Before calling swap: x = %d, y = %d\n", x, y);
    swap(x, y);
    printf("After calling swap : x = %d, y = %d\n", x, y);
    printf("The values in main() are unchanged because only copies were passed.\n");
    return 0;
}

void swap(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
    printf("Inside swap        : a = %d, b = %d\n", a, b);
}
