/*
 * Experiment 13.2: Demonstrate bit fields in a structure
 * A bit field stores a member in a fixed number of bits to save memory.
 */
#include <stdio.h>

struct Date {
    unsigned int day   : 5;   /* 0 to 31 */
    unsigned int month : 4;   /* 0 to 15 */
    unsigned int year  : 7;   /* 0 to 127, years since 2000 */
};

struct NormalDate {
    unsigned int day;
    unsigned int month;
    unsigned int year;
};

int main(void) {
    struct Date d;
    int day, month, year;

    printf("Enter day, month and year (2000 to 2127): ");
    if (scanf("%d %d %d", &day, &month, &year) != 3 ||
        day < 1 || day > 31 || month < 1 || month > 12 || year < 2000 || year > 2127) {
        printf("Invalid date\n");
        return 1;
    }

    d.day = (unsigned int)day;
    d.month = (unsigned int)month;
    d.year = (unsigned int)(year - 2000);

    printf("Date stored: %u/%u/%u\n", d.day, d.month, d.year + 2000);
    printf("Size of struct with bit fields (uses 5+4+7 = 16 bits) = %d bytes\n", (int)sizeof(struct Date));
    printf("Size of the same struct without bit fields       = %d bytes\n", (int)sizeof(struct NormalDate));
    return 0;
}
