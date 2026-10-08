/*
 * Experiment 2.2: Demonstrate relational and logical operators.
 * In C, a true condition gives 1 and a false condition gives 0.
 */
#include <stdio.h>

int main(void) {
    int a, b;

    printf("Enter two integers: ");
    scanf("%d %d", &a, &b);

    printf("\nRelational operators\n");
    printf("%d == %d : %d\n", a, b, a == b);
    printf("%d != %d : %d\n", a, b, a != b);
    printf("%d >  %d : %d\n", a, b, a > b);
    printf("%d <  %d : %d\n", a, b, a < b);
    printf("%d >= %d : %d\n", a, b, a >= b);
    printf("%d <= %d : %d\n", a, b, a <= b);

    printf("\nLogical operators\n");
    printf("(a > 0) && (b > 0) : %d\n", (a > 0) && (b > 0));
    printf("(a > 0) || (b > 0) : %d\n", (a > 0) || (b > 0));
    printf("!(a > b)           : %d\n", !(a > b));
    return 0;
}
