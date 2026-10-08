/*
 * Experiment 10.1: Demonstrate pointer arithmetic.
 * Adding 1 to a pointer moves it to the next element, not the next byte.
 */
#include <stdio.h>

int main(void) {
    int arr[5] = {10, 20, 30, 40, 50};
    int *p = arr;        /* p points to arr[0] */
    int *q = &arr[4];    /* q points to arr[4] */

    printf("*p       = %d\n", *p);
    printf("*(p + 2) = %d\n", *(p + 2));

    p++;                 /* move to the next int */
    printf("After p++, *p = %d\n", *p);

    p += 2;              /* move two ints forward */
    printf("After p += 2, *p = %d\n", *p);

    p--;                 /* move one int back */
    printf("After p--, *p = %d\n", *p);

    /* Subtracting two pointers gives the number of elements between them */
    printf("q - p = %d elements\n", (int)(q - p));

    printf("Size of one int = %d bytes\n", (int)sizeof(int));
    printf("Pointers move in steps of sizeof(int), so p + 1 is %d bytes ahead of p\n",
           (int)sizeof(int));

    /* Pointers can be compared */
    if (p < q) {
        printf("p comes before q in the array\n");
    }
    return 0;
}
