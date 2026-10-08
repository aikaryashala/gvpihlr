/*
 * Experiment 6.5: Tower of Hanoi
 * Idea: to move n disks from A to C using B: move n-1 disks A to B,
 * move the largest disk A to C, then move n-1 disks B to C.
 */

#include <stdio.h>

void hanoi(int n, char from, char to, char via);

int main(void) {
    int n;

    printf("Enter the number of disks: ");
    if (scanf("%d", &n) != 1 || n < 1 || n > 10) {
        printf("Invalid input. Enter a number between 1 and 10.\n");
        return 0;
    }

    printf("Steps to move %d disks from A to C:\n", n);
    hanoi(n, 'A', 'C', 'B');
    return 0;
}

void hanoi(int n, char from, char to, char via) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", from, to);
        return;
    }
    hanoi(n - 1, from, via, to);
    printf("Move disk %d from %c to %c\n", n, from, to);
    hanoi(n - 1, via, to, from);
}
