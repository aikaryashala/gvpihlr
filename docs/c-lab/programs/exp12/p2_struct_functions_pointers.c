/*
 * Experiment 12.2: Pass structures to functions and manipulate structures using pointers.
 * By value the function gets a copy; by pointer it can change the original.
 */
#include <stdio.h>

typedef struct {
    int roll;
    char name[50];
    float marks;
} Student;

void display(Student s);                  /* call by value */
void add_bonus(Student *s, float bonus);  /* call by pointer */

int main(void) {
    Student s;
    float bonus;

    printf("Enter roll number, name and marks: ");
    if (scanf("%d %49s %f", &s.roll, s.name, &s.marks) != 3) {
        printf("Invalid input\n");
        return 1;
    }
    printf("Enter bonus marks: ");
    if (scanf("%f", &bonus) != 1) {
        printf("Invalid input\n");
        return 1;
    }

    printf("\nBefore bonus:\n");
    display(s);

    add_bonus(&s, bonus);

    printf("\nAfter bonus:\n");
    display(s);
    return 0;
}

void display(Student s) {
    printf("Roll: %d, Name: %s, Marks: %.1f\n", s.roll, s.name, s.marks);
}

void add_bonus(Student *s, float bonus) {
    s->marks = s->marks + bonus;   /* same as (*s).marks */
}
