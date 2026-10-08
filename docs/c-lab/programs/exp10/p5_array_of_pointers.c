/*
 * Experiment 10.5: Demonstrate arrays of pointers.
 * Each element of the array is a pointer to a string (or an int).
 */
#include <stdio.h>

int main(void) {
    int a = 10, b = 20, c = 30;
    int *nums[3] = {&a, &b, &c};     /* array of 3 int pointers */
    const char *names[4] = {"Asha", "Ravi", "Kiran", "Meena"};
    int i;

    printf("Array of int pointers:\n");
    for (i = 0; i < 3; i++) {
        printf("*nums[%d] = %d\n", i, *nums[i]);
    }

    *nums[1] = 99;                   /* changes b through the pointer */
    printf("After *nums[1] = 99, b = %d\n", b);

    printf("\nArray of string pointers:\n");
    for (i = 0; i < 4; i++) {
        printf("names[%d] = %s\n", i, names[i]);
    }
    return 0;
}
