

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INT_MIN -999999 // Jedsadaporn Pannok No.66070503410
#define INT_MAX 999999

//  Node structure for linked list
typedef struct Node
{
    int value;
    struct Node *next;
    struct Node *prev;
} Node;

//  Head pointer to the first element on the list

Node *listHead = NULL;
Node *listTail = NULL;


//  Functions implementation
int size;
int k = 0;
int search[100000];

// Function to insert a new node with the given value at the end of the list
void insertNode(int value)
{
    // Create a new node
    Node *tmp = malloc(sizeof(Node));
    // Set the value of the new node
    tmp->value = value;
    // Set the next and previous pointers of the new node

    tmp->next = NULL;
    // If the list is empty, set both head and tail to the new node
    tmp->prev = NULL;

    // If the list is empty, set both head and tail to the new node
    if (listHead == NULL)
    {
        listHead = tmp;
        listTail = tmp;
    }
    else
    // Insert the new node at the end of the list
    {
        tmp->prev = listTail;
        listTail->next = tmp;
        listTail = tmp;
    }
    size++;
}



// Function to delete the node with the given value from the list
void deleteNode(int key)
{
    // Traverse the list to find the node with the specified value
    Node *ptr = listHead;
    // Find the node with the specified value
    while (ptr != NULL)
    {
        // Find the node with the specified value
        if (ptr->value == key)
        {
            Node *p1 = ptr->prev;
            Node *p2 = ptr->next;
            // Handle the case when the node to be deleted is the only node in the list
            if (size == 1)
            {
                listHead = listTail = NULL;
                size = 0;
                free(ptr);
                return;
            }
            // Update pointers to remove the node from the list
            if (ptr != listTail)
            {
                p2->prev = p1;
            }
            else
            {
                listTail = p1;
            }
            // Update pointers to remove the node from the list
            if (ptr != listHead)
            {
                p1->next = p2;
            }
            else
            {
                listHead = p2;
            }
            free(ptr);
            size--;
            return;
        }
        ptr = ptr->next;
    }
}

// Function to search for the node with the specified value
void searchNodes(int key)
{
    // Traverse the list to find the node with the specified value
    Node *ptr = listHead;
    // Find the node with the specified value
    while (ptr != NULL)
    {
        // Find the node with the specified value
        if (ptr->value == key)
        {// Store the previous and next values of the node with the specified value
            search[k++] = (ptr->prev == NULL) ? INT_MIN : ptr->prev->value;
            search[k++] = (ptr->next == NULL) ? INT_MIN : ptr->next->value;
            return;
        }
        ptr = ptr->next;
    }
    // If the node with the specified value is not found, store 'none' in the search array
    search[k++] = INT_MAX;
    search[k++] = INT_MAX;
}

int main()
{
    // Input the commands
    size = 0;

    // Process the commands
    while (1)
    {
        // Input the command and the value
        char mode[3];
        int value;

        scanf("%s", mode);

    // Process the commands
        if (strcmp(mode, "END") == 0)
        {
            break;
        }
        else if (strcmp(mode, "ADD") == 0)
        {
            scanf("%d", &value);
            insertNode(value);
        }
        else if (strcmp(mode, "DEL") == 0)
        {
            scanf("%d", &value);
            deleteNode(value);
        }
        else
        {
            scanf("%d", &value);
            searchNodes(value);
        }
    }

    // Print the search results
    // If the node with the specified value is not found, store 'none' in the search array
    for (int j = 0; j < k; j++)
    {
        
        if (search[j] == INT_MIN)
        {
            printf("NULL");
        }
        
        else if (search[j] == INT_MAX)
        {
            printf("none");
            j++;
        }
        else
        {
            printf("%d", search[j]);
        }
        if (j & 1)
        {
            printf("\n");
        }
        else
        {
            printf(" ");
        }
    }

    // Print the final linked list
    if (size == 0)
    {
        printf("none");
    }

    while (listHead != NULL)
    {
        printf("%d ", listHead->value);
        listHead = listHead->next;
    }

    printf("\n");

    if (size == 0)
    {
        printf("none");
    }

    // Print the remaining elements from the doubly linked list in reverse order
    while (listTail != NULL)
    {
        printf("%d ", listTail->value);
        listTail = listTail->prev;
    }
    return 0;
}
