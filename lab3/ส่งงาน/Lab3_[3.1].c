#include <stdio.h>
#include <stdlib.h>

// Define a Node structure for a linked list
typedef struct Node
{
    int data;
    struct Node *next;
} Node;

// Function to insert a node at the beginning of the linked list
void insertAtBeginning();

// Function to insert a node at the end of the linked list
void insertAtEnd();

int main()
{
    int n, x;

    // Input the number of elements and the insertion position
    scanf("%d", &n);

    // Validate the input for the number of elements
    if (n < 1)
    {
        printf("Invalid");
        return 0;
    }

    // Input the insertion position (1 for beginning, 2 for end)
    scanf("%d", &x);

    // Validate the input for the insertion position
    if (x != 1 && x != 2)
    {
        printf("Invalid");
        return 0;
    }

    // Initialize the head of the linked list
    struct Node *head = NULL;

    // Input data and insert nodes based on the specified position
    for (int i = 0; i < n; i++)
    {
        int data;
        scanf("%d", &data);

        // Insert at the beginning if x is 1, else insert at the end
        if (x == 1)
        {
            insertAtBeginning(&head, data);
        }
        else
        {
            insertAtEnd(&head, data);
        }
    }

    // Traverse the linked list and print the data
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    // Return 0 to indicate successful execution
    return 0;
}

// Function to insert a node at the beginning of the linked list
void insertAtBeginning(Node **head, int data)
{
    // Create a new node and allocate memory
    Node *newNode = (Node *)malloc(sizeof(Node));

    // Set data and link it to the current head
    newNode->data = data;
    newNode->next = *head;

    // Update the head to the new node
    *head = newNode;
}

// Function to insert a node at the end of the linked list
void insertAtEnd(Node **head, int data)
{
    // Create a new node and allocate memory
    Node *newNode = (Node *)malloc(sizeof(Node));

    // Set data and initialize the next pointer to NULL
    newNode->data = data;
    newNode->next = NULL;

    // If the list is empty, update the head to the new node
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }

    // Traverse the list to find the last node
    struct Node *temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    // Update the next pointer of the last node to the new node
    temp->next = newNode;
}
