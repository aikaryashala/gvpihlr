/*
 * Arrays and loops
 * Look at the Assembly stage to see how a for loop becomes compare-and-jump instructions.
 */
#include <stdio.h>

int main(void) {
    int marks[5] = {78, 92, 65, 88, 71};
    int i, sum = 0, max = marks[0];

    for (i = 0; i < 5; i++) {
        sum += marks[i];
        if (marks[i] > max) {
            max = marks[i];
        }
    }

    printf("Total   = %d\n", sum);
    printf("Average = %.2f\n", sum / 5.0);
    printf("Highest = %d\n", max);
    return 0;
}
