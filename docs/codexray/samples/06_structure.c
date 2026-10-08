/*
 * Structures
 * A struct groups related values (roll number, name, marks) under one name.
 */
#include <stdio.h>

struct Student {
    int roll;
    char name[20];
    int marks[3];
};

int main(void) {
    struct Student s = {101, "Asha", {85, 90, 78}};
    int i, total = 0;

    for (i = 0; i < 3; i++) {
        total += s.marks[i];
    }

    printf("Roll    : %d\n", s.roll);
    printf("Name    : %s\n", s.name);
    printf("Total   : %d\n", total);
    printf("Average : %.2f\n", total / 3.0);
    return 0;
}
