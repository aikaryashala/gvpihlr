/*
 * Experiment 12.1: Demonstrate structures, unions and typedef.
 * A struct gives every member its own memory; a union shares one memory.
 */
#include <stdio.h>

/* typedef creates a shorter name for the type */
typedef struct {
    int roll;
    char name[20];
    float marks;
} Student;

typedef union {
    int i;
    float f;
    char c;
} Data;

int main(void) {
    Student s = {101, "Asha", 87.5f};
    Data d;

    printf("--- Structure ---\n");
    printf("Roll: %d\nName: %s\nMarks: %.1f\n", s.roll, s.name, s.marks);
    printf("Size of Student = %d bytes\n", (int)sizeof(Student));

    printf("\n--- Union ---\n");
    printf("Size of Data = %d bytes (size of its largest member)\n", (int)sizeof(Data));

    /* All members share the same memory, so only the last value written is valid */
    d.i = 65;
    printf("After d.i = 65:    d.i = %d, d.c = %c\n", d.i, d.c);

    d.f = 3.5f;
    printf("After d.f = 3.5:   d.f = %.1f (d.i is now meaningless)\n", d.f);

    d.c = 'Z';
    printf("After d.c = 'Z':   d.c = %c (d.f is now meaningless)\n", d.c);

    return 0;
}
