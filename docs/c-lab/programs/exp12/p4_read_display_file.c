/*
 * Experiment 12.4: Read and display file contents
 * Reads students.txt line by line and prints each line.
 */
#include <stdio.h>

int main(void) {
    FILE *fp;
    char line[100];

    fp = fopen("students.txt", "r");
    if (fp == NULL) {
        printf("Error: students.txt not found. Run the previous program first.\n");
        return 1;
    }

    printf("Contents of students.txt:\n");
    printf("Roll Name Marks\n");
    while (fgets(line, sizeof(line), fp) != NULL) {
        printf("%s", line);
    }

    fclose(fp);
    return 0;
}
