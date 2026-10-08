/*
 * Experiment 3.5: Develop a menu-driven calculator using switch
 * The menu repeats until the user chooses 5 (Exit).
 */
#include <stdio.h>

int main(void) {
    int choice;
    double a = 0, b = 0;

    do {
        printf("\n--- Calculator Menu ---\n");
        printf("1. Add\n2. Subtract\n3. Multiply\n4. Divide\n5. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            break;
        }

        if (choice >= 1 && choice <= 4) {
            printf("Enter two numbers: ");
            scanf("%lf %lf", &a, &b);
        }

        switch (choice) {
        case 1:
            printf("Result = %.2f\n", a + b);
            break;
        case 2:
            printf("Result = %.2f\n", a - b);
            break;
        case 3:
            printf("Result = %.2f\n", a * b);
            break;
        case 4:
            if (b != 0) {
                printf("Result = %.2f\n", a / b);
            } else {
                printf("Error: division by zero.\n");
            }
            break;
        case 5:
            printf("Goodbye!\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);
    return 0;
}
