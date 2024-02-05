#include <stdio.h>
#include <stdlib.h>

// Define the Node structure for a linked list
typedef struct Node // Jedsadaporn Pannok No.66070503410
{
    int data;
    struct Node *next;
} Node;

// Function prototypes
void Delete_FIRST_NODE();
void Delete_LAST_NODE();
void Delete_VALUE_NODE();

int main()
{
    int n, i;
    char mode;
    int prepre, newData, nextData;

    Node *head = NULL;

    // Input the number of elements and create a linked list
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        int data;
        scanf("%d", &data);
        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode->data = data;
        newNode->next = NULL;

        // Insert at the end of the linked list
        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            Node *curr = head;
            while (curr->next != NULL)
            {
                curr = curr->next;
            }
            curr->next = newNode;
        }
    }

    // Process user commands until E (Exit) is entered
    while (1)
    {
        scanf(" %c", &mode);
        if (mode == 'E')
        {
            break;
        }

        // Process F (Delete First), L (Delete Last), or N (Delete Value) commands
        if (mode == 'F')
        {
            Delete_FIRST_NODE(&head);
        }
        else if (mode == 'L')
        {
            Delete_LAST_NODE(&head);
        }
        else if (mode == 'N')
        {
            scanf("%d", &prepre);
            Delete_VALUE_NODE(&head, prepre);
        }
    }

    // Print the final linked list
    Node *curr = head;
    if (curr == NULL)
    {
        printf("none");
    }
    while (curr != NULL)
    {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");

    // Free dynamically allocated memory for the linked list nodes
    curr = head;
    while (curr != NULL)
    {
        Node *temp = curr;
        curr = curr->next;
        free(temp);
    }

    return 0;
}

// Function to delete the first node in the linked list
void Delete_FIRST_NODE(Node **head)
{
    if (*head == NULL)
    {
        return;
    }
    Node *n = *head;
    *head = n->next;
    free(n);
}

// Function to delete the last node in the linked list
void Delete_LAST_NODE(Node **head)
{
    if (*head == NULL)
    {
        return;
    }
    if ((*head)->next == NULL)
    {
        free(*head);
        *head = NULL;
        return;
    }
    Node *n = *head;
    while (n->next->next != NULL)
    {
        n = n->next;
    }
    free(n->next);
    n->next = NULL;
}

// Function to delete a node with a specific value in the linked list
void Delete_VALUE_NODE(Node **head, int x)
{
    if (*head == NULL)
    {
        return;
    }
    if ((*head)->data == x)
    {
        Node *n = *head;
        *head = n->next;
        free(n);
        return;
    }
    Node *n = *head;
    while (n->next != NULL && n->next->data != x)
    {
        n = n->next;
    }
    if (n->next == NULL)
    {
        return;
    }
    Node *del = n->next;
    n->next = del->next;
    free(del);
}
