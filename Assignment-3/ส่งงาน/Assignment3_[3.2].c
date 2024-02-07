#include <stdio.h>
#include <stdlib.h>

// Define the structure for a Node
typedef struct Node
{
    int data;           // Data of the node
    struct Node *next;  // Pointer to the next node in the linked list
} Node;

// Function declaration
void insertAtEnd();

int main()
{
    int size, step;

    // Read the size of the list and the step value from the user
    scanf("%d %d", &size, &step);

    // Set the initial value of the linked list to NULL
    Node *head = NULL;

    // Insert data into the linked list from the user
    for (int i = 0; i < size; i++)
    {
        int data;
        scanf("%d", &data);
        insertAtEnd(&head, data);
    }

    // Connect the last Node to the head of the list
    Node *x = head;
    while (x->next != NULL)
    {
        x = x->next;
    }
    x->next = head;

    Node *prepre = NULL;
    x = head;

    while (x->next != x)
    {
        // Move to the Node to be deleted
        for (int i = 0; i < step - 1; i++)
        {
            prepre = x;
            x = x->next;
        }

        // Remove the current Node from the linked list
        prepre->next = x->next;
        Node *temp = x;
        x = x->next;

        free(temp);
    }

    // Print the data of the remaining last Node
    printf("%d", x->data);

    return 0;
}

// Function to insert a new Node at the end of the linked list
void insertAtEnd(Node **head, int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL)
    {
        // If the linked list is empty, set the new Node as the head
        *head = newNode;
    }
    else
    {
        // Otherwise, move to the end and add the new Node
        Node *temp = *head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}
