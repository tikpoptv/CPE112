// Welcome to the Circular Linked List Master Challenge!

// Commands:
// 'I x': Insert the element x into the last node in the circular linked list.
// 'D x': Delete the first occurrence of the element x in the circular linked list. If x is not in your circular linked list, ignore the command.
// 'E': End the changing mode and display all nodes in the circular linked list.

// Example:
// Enter command: I 5
// Enter command: I 8
// Enter command: D 5
// Enter command: I 10
// Enter command: E

// Circular Linked List after commands:
// 8 10

// Congratulations! You have mastered the Circular Linked List. You are now the Circular Linked List Master!

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

void Insert();
void Delete();

int main()
{
    char mode;
    int x;
    Node *head = NULL;

    while (1)
    {
        scanf(" %c", &mode);
        if (mode == 'E')
        {
            break;
        }

        if (mode == 'I')
        {
            scanf("%d", &x);
            Insert(&head, x);
        }
        else if (mode == 'D')
        {
            scanf("%d", &x);
            Delete(&head, x);
        }
    }

    Node *n = head;
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

void Insert(Node **head, int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL)
    {
        *head = newNode;
        newNode->next = *head;
    }
    else
    {
        Node *n = *head;
        while (n->next != *head)
        {
            n = n->next;
        }
        n->next = newNode;
        newNode->next = *head;
    }
}

void Delete(Node **head, int data)
{
    if (*head == NULL)
    {
        return;
    }

    Node *n = *head;
    Node *x = NULL;

    do
    {
        if (n->data == data)
        {
            if (x != NULL)
            {
                x->next = n->next;
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
                    Node *last = n;
                    while (last->next != *head)
                    {
                        last = last->next;
                    }
                    *head = n->next;
                    last->next = *head;
                }
            }

            free(n);
            return;
        }

        x = n;
        n = n->next;
    } while (n != *head);
}
