#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *nextNode;
} Node;

Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode)
    {
        printf("A new node could not be created!\n");
        exit(EXIT_FAILURE);
    }

    newNode->data = data;
    newNode->nextNode = NULL;
    return newNode;
}

void deleteNode(Node **head, Node *nodeToDelete)
{
    if (!head || !(*head) || !nodeToDelete)
    {
        printf("The node could not be deleted!\n");
        return;
    }

    // If the node to delete is the head node
    if (*head == nodeToDelete)
    {
        *head = nodeToDelete->nextNode;
        free(nodeToDelete);
        return;
    }

    // Find the previous node
    Node *prev = *head;
    while (prev->nextNode && prev->nextNode != nodeToDelete)
    {
        prev = prev->nextNode;
    }

    // If nodeToDelete was found in the list
    if (prev->nextNode)
    {
        prev->nextNode = nodeToDelete->nextNode;
        free(nodeToDelete);
    }
    else
    {
        printf("Node not found in the list!\n");
    }
}

void deleteAllNodes(Node **head)
{
    // Use Node** if modifying head
    Node *current = *head;
    Node *next;

    while (current)
    {
        next = current->nextNode;
        free(current);
        current = next;
    }

    *head = NULL; // Now, head in main() is NULL, avoiding a dangling pointer
}

void printList(Node *head)
{
    while (head)
    {
        printf("%d -> ", head->data);
        head = head->nextNode;
    }
    printf("null\n");
}

int main()
{
    Node *head = createNode(3);
    Node *node1 = createNode(5);
    Node *node2 = createNode(13);
    Node *node3 = createNode(2);

    head->nextNode = node1;
    node1->nextNode = node2;
    node2->nextNode = node3;

    printf("Original list:\n");
    printList(head);
    printf("\n");

    // Delete node with value 13
    deleteNode(&head, node2);

    printf("After deleting node with value 13:\n");
    printList(head);

    // Delete all nodes
    deleteAllNodes(&head);

    return 0;
}
