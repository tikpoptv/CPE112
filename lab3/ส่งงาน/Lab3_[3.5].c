#include <stdio.h>
#include <stdlib.h>

// Define the structure for a circular linked list node
typedef struct Node // Jedsadaporn Pannok No.66070503410
{
    int data;
    struct Node *next;
} Node;

// Function prototypes
void Insert();
void Delete();

int main()
{
    char mode;
    int x;
    Node *head = NULL;

    // Process user commands until E (Exit) is entered
    while (1)
    {
        scanf(" %c", &mode);
        if (mode == 'E')
        {
            break;
        }

        // Insert node if command is I
        if (mode == 'I')
        {
            scanf("%d", &x);
            Insert(&head, x);
        }
        // Delete node if command is D
        else if (mode == 'D')
        {
            scanf("%d", &x);
            Delete(&head, x);
        }
    }

    Node *n = head;
    // Print the elements in the circular linked list
    if (n != NULL)
    {
        do
        {
            printf("%d ", n->data);
            n = n->next;
        } while (n != head);
    }
    else
    {
        printf("Empty");
    }

    return 0;
}

// Function to insert a new node at the end of the circular linked list
void Insert(Node **head, int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    // If the circular linked list is empty, make the new node the head
    if (*head == NULL)
    {
        *head = newNode;
        newNode->next = *head;
    }
    else
    {
        // Traverse to the end of the circular linked list
        Node *n = *head;
        while (n->next != *head)
        {
            n = n->next;
        }

        // Insert the new node at the end
        n->next = newNode;
        newNode->next = *head;
    }
}

// Function to delete a node with the specified data from the circular linked list
void Delete(Node **head, int data)
{
    // If the circular linked list is empty, do nothing
    if (*head == NULL)
    {
        return;
    }

    Node *n = *head;
    Node *x = NULL;

    // Traverse the circular linked list
    do
    {
        // If the node with the specified data is found
        if (n->data == data)
        {
            // If the node is not the first node in the circular linked list
            if (x != NULL)
            {
                x->next = n->next;

                // If the node to be deleted is the head, update the head
                if (n == *head)
                {
                    *head = n->next;
                }
            }
            else
            {
                // Only one node in the list
                if (n->next == *head)
                {
                    free(n);
                    *head = NULL;
                    return;
                }
                else
                {
                    // More than one node in the list
                    Node *last = n;
                    while (last->next != *head)
                    {
                        last = last->next;
                    }
                    *head = n->next;
                    last->next = *head;
                }
            }

            // Free the memory allocated for the node and return
            free(n);
            return;
        }

        // Move to the next node
        x = n;
        n = n->next;
    } while (n != *head);
}
