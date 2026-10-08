/*
 * Experiment 13.3: Demonstrate enumerations (e.g., days of week, traffic light states)
 * An enum gives readable names to integer constants.
 */
#include <stdio.h>

enum Day { MON, TUE, WED, THU, FRI, SAT, SUN };   /* MON = 0 ... SUN = 6 */
enum Light { RED, YELLOW, GREEN };

int main(void) {
    int d, l;
    enum Day day;
    enum Light light;

    printf("Enter day number (0=Mon ... 6=Sun): ");
    if (scanf("%d", &d) != 1 || d < MON || d > SUN) {
        printf("Invalid day\n");
        return 1;
    }
    day = (enum Day)d;

    switch (day) {
    case SAT:
    case SUN:
        printf("Day %d is a weekend\n", day);
        break;
    default:
        printf("Day %d is a weekday\n", day);
        break;
    }

    printf("Enter traffic light state (0=Red, 1=Yellow, 2=Green): ");
    if (scanf("%d", &l) != 1 || l < RED || l > GREEN) {
        printf("Invalid state\n");
        return 1;
    }
    light = (enum Light)l;

    switch (light) {
    case RED:
        printf("RED: Stop\n");
        break;
    case YELLOW:
        printf("YELLOW: Get ready\n");
        break;
    case GREEN:
        printf("GREEN: Go\n");
        break;
    }
    return 0;
}
