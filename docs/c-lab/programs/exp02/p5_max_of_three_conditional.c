/*
 * Experiment 2.5: Find the maximum of three numbers using the conditional operator
 * The form is: condition ? value_if_true : value_if_false
 */
#include <stdio.h>

int main(void) {
    int a, b, c, max;

    printf("Enter three integers: ");
    scanf("%d %d %d", &a, &b, &c);

    max = (a > b) ? ((a > c) ? a : c) : ((b > c) ? b : c);

    printf("Maximum = %d\n", max);
    return 0;
}
