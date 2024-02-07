#include <stdio.h>
#include <stdlib.h>
#include <string.h> // Jedsadaporn Pannok No.66070503410

// Define the structure for a ListNode
typedef struct ListNode
{
    int val;                // Value of the node
    struct ListNode *next;  // Pointer to the next node in the linked list
} ListNode;

// Function declarations
void insertAtEnd();     // Function to insert a new node at the end of the linked list
void begin();             // Function to insert a new node at the beginning of the linked list
void printList();                // Function to print the linked list

int main() // Jedsadaporn Pannok No.66070503410
{
    ListNode *head = NULL;  // Initialize the head of the linked list to NULL
    ListNode *x = head;     // Pointer to traverse the linked list (not used in this implementation)

    // Read integers until "END" is encountered and insert them at the end of the linked list
    while (1)
    {
        char str[10];
        scanf("%s", str);
        if (strcmp(str, "END") == 0)  // Exit loop if END is encountered
        {
            break;
        }
        else
        {
            int num = atoi(str);  // Convert the string to an integer
            insertAtEnd(&head, num);  // Insert the integer at the end of the linked list
        }
    }

    // Read start and end indices
    int st, en;
    scanf("%d %d", &st, &en);

    ListNode *ptr = head;
    for (int i = 1; i < st; i++) {
        printf("%d ", ptr->val);  // Print values before the sublist
        ptr = ptr->next;  // Move to the next node
    }

    // Reverse a sublist from st to en and print it
    ListNode *temp = NULL;  // Temporary linked list to hold the reversed sublist
    for (int i = st; i <= en; i++) {
        begin(&temp, ptr->val);  // Insert the current node's value at the beginning of temp
        ptr = ptr->next;  // Move to the next node
    }

    ListNode *print = temp;
    while (print != NULL) {
        printf("%d ", print->val);  // Print values of the reversed sublist
        print = print->next;  // Move to the next node
    }

    // Print the rest of the list after the sublist
    while (ptr != NULL) {
        printf("%d ", ptr->val);  // Print values of the remaining nodes
        ptr = ptr->next;  // Move to the next node
    }

    return 0;
}

// Function to insert a new node at the end of the linked list
void insertAtEnd(ListNode **head, int num)
{
    ListNode *newNode = (ListNode *)malloc(sizeof(ListNode));  // Allocate memory for the new node
    newNode->val = num;  // Set the value of the new node
    newNode->next = NULL;  // Set the next pointer of the new node to NULL (as it will be the last node)

    if (*head == NULL)  // If the linked list is empty
    {
        *head = newNode;  // Set the new node as the head of the linked list
        return;
    }

    ListNode *temp = *head;
    while (temp->next != NULL)  // Traverse to the end of the linked list
    {
        temp = temp->next;
    }
    temp->next = newNode;  // Connect the new node to the last node
}

// Function to insert a new node at the beginning of the linked list
void begin(ListNode **temp, int t)
{
    ListNode *new = (ListNode *)malloc(sizeof(ListNode));  // Allocate memory for the new node
    new->val = t;  // Set the value of the new node
    new->next = *temp;  // Set the next pointer of the new node to the current head of the sublist
    *temp = new;  // Update the head of the sublist to the new node
}

// Function to print the linked list
void printList(ListNode **head)
{
    ListNode *temp = *head;
    while (temp != NULL)
    {
        printf("%d ", temp->val);  // Print the value of each node
        temp = temp->next;  // Move to the next node
    }
}
