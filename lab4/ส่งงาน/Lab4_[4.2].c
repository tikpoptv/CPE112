#include <stdio.h>
#include <stdlib.h>

struct Node { //jedsadaporn pannok 66070503410
    int data;
    struct Node* next;
};

struct Node* top = NULL;

// Function to push an element onto the stack
void push(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); // Create a new node
    newNode->data = value; // Set the data of the new node
    newNode->next = top; // Set the next pointer of the new node to the current top
    top = newNode; // Update the top pointer to point to the new node
}

// Function to pop an element from the stack
void pop() {
    if (top == NULL) { // Check if the stack is empty
        printf("empty\n"); // Print "empty" if the stack is empty
        return;
    }
    struct Node* temp = top; // Store the current top node
    top = top->next; // Update the top pointer to the next node
    int deletedValue = temp->data; // Store the data of the node being deleted
    free(temp); // Free the memory allocated for the node
    printf("%d\n", deletedValue); // Print the deleted value
}

// Function to display the top element of the stack
void displayTop() {
    if (top == NULL) { // Check if the stack is empty
        printf("empty\n"); // Print "empty" if the stack is empty
        return;
    }
    printf("%d\n", top->data); // Print the data of the top node
}

// Function to check if the stack is empty
void isEmpty() {
    if (top == NULL) { // Check if the stack is empty
        printf("1\n"); // Print "1" to indicate that the stack is empty
    } else {
        printf("0\n"); // Print "0" to indicate that the stack is not empty
    }
}

int main() {
    char n;
    int val;

    while (1) {
        scanf(" %c", &n); // Input the operation character

        if (n == 'p') { // If the operation is push
            scanf("%d", &val); // Input the value to be pushed onto the stack
            push(val); // Call the push function
        } else if (n == 'o') { // If the operation is pop
            pop(); // Call the pop function
        } else if (n == 't') { // If the operation is to display the top element
            displayTop(); // Call the displayTop function
        } else if (n == 'e') { // If the operation is to check if the stack is empty
            isEmpty(); // Call the isEmpty function
        } else if (n == 'q') { // If the operation is to quit the program
            break; // Exit the loop
        }
    }

    return 0; // Return 0 to indicate successful program termination
}
