/*
 * Experiment 1.4: Convert temperature (°C ↔ °F)
 * Uses F = C * 9 / 5 + 32 and C = (F - 32) * 5 / 9.
 */
#include <stdio.h>

int main(void) {
    float celsius, fahrenheit;

    printf("Enter temperature in Celsius: ");
    scanf("%f", &celsius);
    printf("%.2f C = %.2f F\n", celsius, celsius * 9 / 5 + 32);

    printf("Enter temperature in Fahrenheit: ");
    scanf("%f", &fahrenheit);
    printf("%.2f F = %.2f C\n", fahrenheit, (fahrenheit - 32) * 5 / 9);
    return 0;
}
