#include <stdio.h>
#include <stdlib.h>

// Define the Node structure for a linked list
typedef struct Node {
    int data;
    struct Node* next; // Jedsadaporn Pannok No.66070503410
} Node;

// Function prototypes
void addAfter();
void addBefore();

int main() {
    int n, i;
    char mode;
    int prepre, newData, nextData;

    Node* head = NULL;

    // Input the number of elements and create a linked list
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        int data;
        scanf("%d", &data);
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->data = data;
        newNode->next = NULL;

        // Insert at the end of the linked list
        if (head == NULL) {
            head = newNode;
        } else {
            Node* curr = head;
            while (curr->next != NULL) {
                curr = curr->next;
            }
            curr->next = newNode;
        }
    }

    // Process user commands until E (Exit) is entered
    while (1) {
        scanf(" %c", &mode);
        if (mode == 'E') {
            break;
        }

        // Process A (Add After) or B (Add Before) commands
        if (mode == 'A' || mode == 'B') {
            scanf("%d %d", &prepre, &newData);
        }

        // Call the appropriate function based on the command
        if (mode == 'A') {
            addAfter(head, prepre, newData);
        } else if (mode == 'B') {
            addBefore(&head, prepre, newData);
        }
    }

    // Print the final linked list
    Node* curr = head;
    while (curr != NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");

    // Free dynamically allocated memory for the linked list nodes
    curr = head;
    while (curr != NULL) {
        Node* temp = curr;
        curr = curr->next;
        free(temp);
    }

    return 0;
}

// Function to add a new node after a specific value in the linked list
void addAfter(Node* head, int prepre, int newData) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = newData;
    newNode->next = NULL;

    Node* curr = head;
    while (curr != NULL) {
        if (curr->data == prepre) {
            newNode->next = curr->next;
            curr->next = newNode;
            return;
        }
        curr = curr->next;
    }
}

// Function to add a new node before a specific value in the linked list
void addBefore(Node** head, int nextData, int newData) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = newData;
    newNode->next = NULL;

    // Check if the linked list is empty
    if (*head == NULL) {
        printf("Error\n");
        free(newNode);
        return;
    }

    // Check if the new node should be inserted at the beginning
    if ((*head)->data == nextData) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    // Traverse the linked list to find the node with the specified value
    Node* curr = *head;
    while (curr->next != NULL && curr->next->data != nextData) {
        curr = curr->next;
    }

    // If the specified value is not found in the linked list
    if (curr->next == NULL) {
        free(newNode);
        return;
    }

    // Insert the new node before the node with the specified value
    newNode->next = curr->next;
    curr->next = newNode;
}
