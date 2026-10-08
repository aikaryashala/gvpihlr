/*
 * Experiment 1.5: Calculate simple and compound interest
 * SI = P * R * T / 100,  CI = P * (1 + R/100)^T - P
 */
#include <stdio.h>
#include <math.h>

int main(void) {
    double principal, rate, time;
    double si, ci;

    printf("Enter principal amount: ");
    scanf("%lf", &principal);
    printf("Enter rate of interest (%% per year): ");
    scanf("%lf", &rate);
    printf("Enter time (years): ");
    scanf("%lf", &time);

    si = principal * rate * time / 100;
    ci = principal * pow(1 + rate / 100, time) - principal;

    printf("Simple Interest   = %.2f\n", si);
    printf("Compound Interest = %.2f\n", ci);
    return 0;
}
