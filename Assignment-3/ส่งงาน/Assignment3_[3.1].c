#include <stdio.h>
#include <stdlib.h>

// Define the structure for a Node
typedef struct Node
{
    int val;            // Value of the node
    int score;          // Score of the node
    struct Node *next;  // Pointer to the next node in the linked list
} Node;

// Function to insert a new node into the linked list
void insertNode(Node **head, int val, int score)
{
    // Create a new node
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->val = val;
    newNode->score = score;
    newNode->next = NULL;

    // If the linked list is empty
    if (*head == NULL)
    {
        // Set the new node as the head of the linked list
        *head = newNode;
    }
    else
    {
        // Find the last position in the linked list
        Node *temp = *head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        // Connect the new node to the last position in the linked list
        temp->next = newNode;
    }
}

// Function to sort the linked list using bubble sort based on a specified mode
void sortList(Node **head, int mode)
{
    // If the linked list is empty or has only one node, no need to sort
    if (*head == NULL || (*head)->next == NULL)
    {
        return;
    }

    Node *n = *head;
    Node *prev = NULL;
    int swap;

    // Perform bubble sort and swap nodes based on the specified mode
    do
    {
        swap = 0;
        n = *head;

        while (n->next != prev)
        {
            if ((mode == 0 && n->val > n->next->val) || (mode == 1 && n->score > n->next->score))
            {
                // Swap the values of the nodes if they are out of order
                int tempVal = n->val;
                int tempScore = n->score;
                n->val = n->next->val;
                n->score = n->next->score;
                n->next->val = tempVal;
                n->next->score = tempScore;
                swap = 1;
            }
            n = n->next;
        }
        prev = n;
    } while (swap);
}

// Function to print the linked list
void printList(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->score);
        temp = temp->next;
    }
    printf("\n");
}


int main()
{
    int size;
    scanf("%d", &size);  // Read the number of nodes from the user

    Node *head = NULL;  // Initialize the head of the linked list to NULL

    // Read values and insert nodes into the linked list
    for (int i = 0; i < size; i++)
    {
        int val, score;
        scanf("%d %d", &val, &score);
        insertNode(&head, val, score);  // Insert the node at the end of the linked list
    }

    int mode;
    scanf("%d", &mode);  // Read the sorting mode from the user

    // Sort the linked list based on the specified mode
    sortList(&head, mode);

    // Print the sorted linked list
    printList(head);

    return 0;
}
