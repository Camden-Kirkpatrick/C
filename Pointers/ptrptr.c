#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

// This tries to change the caller's pointer, but fails because the pointer is passed by value (copied)
// Since ptr is a copy, it has its own memory address, and reallocating it doesn't affect the original
void setToNewNode(Node *ptr)
{
    ptr = malloc(sizeof(Node)); // Only changes local copy
    ptr->data = 111;
    ptr->next = NULL;
}

// This successfully changes the caller's pointer by using a pointer to pointer
// Passing a Node** allows the function to modify the original pointer in main
void setToNewNodeCorrect(Node **ptr)
{
    *ptr = malloc(sizeof(Node)); // Changes the actual pointer in the caller
    (*ptr)->data = 222;
    (*ptr)->next = NULL;
}

int main()
{
    Node *a = NULL;
    Node *b = NULL;

    printf("Before setToNewNode():      a = %p\n", (void *)a);
    setToNewNode(a);
    printf("After setToNewNode():       a = %p\n", (void *)a); // Still NULL
    if (a)
        printf("  a->data = %d\n", a->data);

    printf("\nBefore setToNewNodeCorrect(): b = %p\n", (void *)b);
    // Pass the address of b, so the function can modify the original pointer
    setToNewNodeCorrect(&b);
    printf("After setToNewNodeCorrect():  b = %p\n", (void *)b); // Now points to new Node
    if (b)
        printf("  b->data = %d\n", b->data);

    // Free only if memory was allocated
    if (a)
        free(a);
    if (b)
        free(b);

    return 0;
}
