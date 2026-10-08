/*
 * Experiment 11.4: free()
 * free(ptr) gives heap memory back to the system.
 */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int *p = malloc(sizeof(int));

    if (p == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    *p = 42;
    printf("Value stored in allocated memory: %d\n", *p);

    free(p);
    printf("Memory freed.\n");

    /* After free(), p is a "dangling pointer": it still holds the old address
       but the memory is no longer ours. Using *p now would be a bug.
       Setting p to NULL makes such mistakes easy to detect. */
    p = NULL;

    if (p == NULL) {
        printf("Pointer set to NULL, so it cannot be used by mistake.\n");
    }

    /* If we forgot free(), the memory would stay reserved until the program
       ends. In a long-running program this is called a memory leak. */
    return 0;
}
