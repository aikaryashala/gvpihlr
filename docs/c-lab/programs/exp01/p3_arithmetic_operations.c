/*
 * Experiment 1.3: Perform arithmetic operations
 * Reads two integers and applies +, -, *, / and %.
 */
#include <stdio.h>

int main(void) {
    int a, b;

    printf("Enter two integers: ");
    scanf("%d %d", &a, &b);

    printf("%d + %d = %d\n", a, b, a + b);
    printf("%d - %d = %d\n", a, b, a - b);
    printf("%d * %d = %d\n", a, b, a * b);
    if (b != 0) {
        printf("%d / %d = %d (integer division)\n", a, b, a / b);
        printf("%d / %d = %.2f (real division)\n", a, b, (float)a / b);
        printf("%d %% %d = %d (remainder)\n", a, b, a % b);
    } else {
        printf("Division and remainder are not possible when the second number is 0.\n");
    }
    return 0;
}
