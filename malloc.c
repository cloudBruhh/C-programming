/*
 * malloc.c - Understanding Dynamic Memory Allocation in C
 *
 * malloc() = memory allocate
 * Allocates a block of memory on the HEAP at runtime.
 * Returns a void pointer (void *) to the first byte of the block.
 * Returns NULL if allocation fails.
 * Memory is NOT initialized (contains garbage values).
 * You MUST free() the memory when done to avoid memory leaks.
 *
 * Syntax:
 *   void *malloc(size_t size);
 *
 * Compare with stack memory:
 *   int arr[5];  <-- stack: fixed size, auto-freed when scope ends
 *   int *arr = malloc(5 * sizeof(int));  <-- heap: dynamic, YOU manage it
 */

#include <stdio.h>
#include <stdlib.h>  /* required for malloc(), free(), realloc() */
#include <string.h>  /* required for strcpy() */

/* -----------------------------------------------------------
 * 1. Basic malloc usage: allocating a single integer
 * ----------------------------------------------------------- */
void demo_single_int() {
    printf("--- 1. Allocate a single integer ---\n");

    int *p = (int *)malloc(sizeof(int));  /* allocate 4 bytes */

    if (p == NULL) {                      /* ALWAYS check for NULL */
        printf("Memory allocation failed!\n");
        return;
    }

    *p = 42;                              /* store a value */
    printf("Value stored at heap address %p : %d\n", (void *)p, *p);

    free(p);                              /* release memory back to OS */
    p = NULL;                             /* good practice: avoid dangling pointer */
    printf("\n");
}

/* -----------------------------------------------------------
 * 2. malloc for a dynamic array of integers
 * ----------------------------------------------------------- */
void demo_dynamic_array() {
    printf("--- 2. Dynamic array of integers ---\n");

    int n = 5;
    int *arr = (int *)malloc(n * sizeof(int));  /* allocate 5 ints */

    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    /* fill the array */
    for (int i = 0; i < n; i++) {
        arr[i] = (i + 1) * 10;  /* 10, 20, 30, 40, 50 */
    }

    /* print the array */
    printf("Dynamic array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
    arr = NULL;
    printf("\n");
}

/* -----------------------------------------------------------
 * 3. malloc for a string (char array)
 * ----------------------------------------------------------- */
void demo_dynamic_string() {
    printf("--- 3. Dynamic string ---\n");

    int len = 20;
    char *str = (char *)malloc(len * sizeof(char));  /* 20 chars */

    if (str == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    strcpy(str, "Hello, malloc!");
    printf("String on heap: %s\n", str);

    free(str);
    str = NULL;
    printf("\n");
}

/* -----------------------------------------------------------
 * 4. realloc - resize a previously allocated block
 * ----------------------------------------------------------- */
void demo_realloc() {
    printf("--- 4. realloc - resizing memory ---\n");

    int *arr = (int *)malloc(3 * sizeof(int));  /* start with 3 ints */

    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    arr[0] = 1; arr[1] = 2; arr[2] = 3;

    printf("Before realloc (3 elements): ");
    for (int i = 0; i < 3; i++) printf("%d ", arr[i]);
    printf("\n");

    /* resize to 6 ints - old data is preserved */
    int *tmp = (int *)realloc(arr, 6 * sizeof(int));

    if (tmp == NULL) {
        printf("realloc failed!\n");
        free(arr);   /* free original block on failure */
        return;
    }

    arr = tmp;       /* update pointer only after successful realloc */
    arr[3] = 4; arr[4] = 5; arr[5] = 6;

    printf("After  realloc (6 elements): ");
    for (int i = 0; i < 6; i++) printf("%d ", arr[i]);
    printf("\n");

    free(arr);
    arr = NULL;
    printf("\n");
}

/* -----------------------------------------------------------
 * 5. calloc vs malloc
 *    calloc initializes memory to ZERO; malloc does NOT.
 * ----------------------------------------------------------- */
void demo_calloc_vs_malloc() {
    printf("--- 5. calloc vs malloc ---\n");

    int n = 5;

    int *with_malloc = (int *)malloc(n * sizeof(int));
    int *with_calloc = (int *)calloc(n, sizeof(int));  /* calloc(count, size) */

    if (!with_malloc || !with_calloc) {
        printf("Allocation failed!\n");
        free(with_malloc);
        free(with_calloc);
        return;
    }

    printf("malloc (uninitialized, garbage values): ");
    for (int i = 0; i < n; i++) printf("%d ", with_malloc[i]);
    printf("\n");

    printf("calloc (initialized to 0)            : ");
    for (int i = 0; i < n; i++) printf("%d ", with_calloc[i]);
    printf("\n");

    free(with_malloc);
    free(with_calloc);
    printf("\n");
}

/* -----------------------------------------------------------
 * 6. malloc for a struct
 * ----------------------------------------------------------- */
typedef struct {
    char name[30];
    int  age;
    float gpa;
} Student;

void demo_struct_malloc() {
    printf("--- 6. malloc for a struct ---\n");

    Student *s = (Student *)malloc(sizeof(Student));

    if (s == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    strcpy(s->name, "Alice");
    s->age = 20;
    s->gpa = 3.9f;

    printf("Student: %s | Age: %d | GPA: %.1f\n", s->name, s->age, s->gpa);

    free(s);
    s = NULL;
    printf("\n");
}

/* -----------------------------------------------------------
 * main
 * ----------------------------------------------------------- */
int main() {
    printf("========================================\n");
    printf("   Understanding malloc in C\n");
    printf("========================================\n\n");

    demo_single_int();
    demo_dynamic_array();
    demo_dynamic_string();
    demo_realloc();
    demo_calloc_vs_malloc();
    demo_struct_malloc();

    printf("========================================\n");
    printf(" Key rules to remember:\n");
    printf("  1. Always check if malloc returns NULL\n");
    printf("  2. Always free() what you malloc()\n");
    printf("  3. Set pointer to NULL after free()\n");
    printf("  4. Use realloc() to resize a block\n");
    printf("  5. calloc() zero-initializes memory\n");
    printf("========================================\n");

    return 0;
}
