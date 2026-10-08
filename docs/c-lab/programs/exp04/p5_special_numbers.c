/*
 * Experiment 4.5: Check Armstrong, palindrome, perfect, and strong numbers
 * Each check is a small function that returns 1 (yes) or 0 (no).
 */
#include <stdio.h>

int isArmstrong(int n);
int isPalindrome(int n);
int isPerfect(int n);
int isStrong(int n);

int main(void) {
    int n;

    printf("Enter a positive number: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Please enter a positive number.\n");
        return 0;
    }

    printf("%d %s an Armstrong number.\n", n, isArmstrong(n) ? "is" : "is not");
    printf("%d %s a palindrome.\n", n, isPalindrome(n) ? "is" : "is not");
    printf("%d %s a perfect number.\n", n, isPerfect(n) ? "is" : "is not");
    printf("%d %s a strong number.\n", n, isStrong(n) ? "is" : "is not");
    return 0;
}

/* Sum of (each digit raised to the number of digits) equals the number */
int isArmstrong(int n) {
    int digits = 0, temp = n, sum = 0, i;

    while (temp > 0) {
        digits++;
        temp /= 10;
    }
    for (temp = n; temp > 0; temp /= 10) {
        int power = 1;
        for (i = 0; i < digits; i++) {
            power *= temp % 10;
        }
        sum += power;
    }
    return sum == n;
}

/* Number reads the same when its digits are reversed */
int isPalindrome(int n) {
    int reversed = 0, temp;

    for (temp = n; temp > 0; temp /= 10) {
        reversed = reversed * 10 + temp % 10;
    }
    return reversed == n;
}

/* Sum of proper divisors (all divisors except n itself) equals the number */
int isPerfect(int n) {
    int sum = 0, i;

    for (i = 1; i <= n / 2; i++) {
        if (n % i == 0) {
            sum += i;
        }
    }
    return sum == n && n > 1;
}

/* Sum of the factorials of the digits equals the number */
int isStrong(int n) {
    int sum = 0, temp, digit, f, i;

    for (temp = n; temp > 0; temp /= 10) {
        digit = temp % 10;
        f = 1;
        for (i = 2; i <= digit; i++) {
            f *= i;
        }
        sum += f;
    }
    return sum == n;
}
