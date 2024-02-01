// Problem
// Implementing two insertion functions of linked list.

// Insertion at the head or the beginning of linked list.
// Insertion at the rear or the end of linked list.
// Then print all the nodes in the linked list to showcase the successful insertions.

// Insertion at the beginning
// Insertion at the end

// Input
// The input consists of seven lines:

// First Line: An integer 
// �
// 1
// n 
// 1
// ​
//   representing the number of nodes in the linked list. If insertion is not possible, the output will be 'Invalid'.
// Second Line: Choose an option by entering either 1 or 2. Use 1 for inserting at the beginning of the linked list and 2 for inserting at the end. If option is invalid, the output will be 'Invalid'.
// Third Line: Provide 
// �
// 2
// n 
// 2
// ​
//   integers, separated by spaces, representing the nodes of the linked lists.
// Output
// The output consists of

// First Line: Linked Lists after the insertion operation.

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
}Node;

void insertAtBeginning(Node **head, int data);
void insertAtEnd(Node **head, int data);

int main()
{
    int n, x;
    scanf("%d", &n);
    if (n < 1)
    {
        printf("Invalid");
        return 0;
    }
    scanf("%d", &x);
    if (x != 1 && x != 2)
    {
        printf("Invalid");
        return 0;
    }
    struct Node *head = NULL;
    for (int i = 0; i < n; i++)
    {
        int data;
        scanf("%d", &data);
        if (x == 1)
        {
            insertAtBeginning(&head, data);
        }
        else
        {
            insertAtEnd(&head, data);
        }
    }
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    return 0;
}

void insertAtBeginning(Node **head, int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

void insertAtEnd(Node **head, int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    struct Node *temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}