#include <stdio.h>
#include <stdbool.h> //Jedsadaporn Pannok 66070503410
#include <stdlib.h>

// Function to check if the stack is full
bool isfull(int *cnt, int size) {
    if (size == *cnt) // Check if the count of elements equals the size of the stack
        return true; // Return true if the stack is full
    else
        return false; // Return false if there is still space in the stack
}

// Function to push an element onto the stack
bool push(int *stack, int val, int *cnt, int size) {
    if (isfull(cnt, size)) // Check if the stack is full
        return true; // Return true (stack overflow) if the stack is full
    else {
        stack[*cnt] = val; // Insert the value into the stack
        (*cnt)++; // Increment the count of elements in the stack
        return false; // Return false to indicate successful insertion
    }
}

// Function to check if the stack is empty
bool ismt(int *cnt) {
    if (*cnt == 0) // Check if the count of elements is zero
        return true; // Return true if the stack is empty
    else
        return false; // Return false if the stack is not empty
}

// Function to pop an element from the stack
bool pop(int *stack, int *cnt) {
    if (ismt(cnt)) // Check if the stack is empty
        return false; // Return false (stack underflow) if the stack is empty
    else {
        *(stack + (*cnt)) = -999; // Remove the top element from the stack
        (*cnt)--; // Decrement the count of elements in the stack
        return true; // Return true to indicate successful pop operation
    }
}

int main() {
    int size;
    scanf("%d", &size); // Input the size of the stack

    if (size <= 0) { // Check if the size is non-positive
        printf("Please enter a positive number.\n"); // Print an error message
        return 0;
    }

    int *stack = (int *)malloc(size * sizeof(int)); // Dynamically allocate memory for the stack
    int choice;
    scanf("%d", &choice); // Input the initial choice of operation

    int cnt = 0; // Initialize the count of elements in the stack
    while (1) {
        if (choice == 1) { // Insert operation
            int t;
            scanf("%d", &t); // Input the value to be pushed onto the stack
            if (push(stack, t, &cnt, size)) { // Attempt to push the value onto the stack
                printf("Stack Overflow.\n"); // Print an error message if the stack is full
                return 0; // Exit the program
            }
        } else if (choice == 2) { // Pop operation
            if (!pop(stack, &cnt)) { // Attempt to pop an element from the stack
                printf("Stack Underflow.\n"); // Print an error message if the stack is empty
                return 0; // Exit the program
            }
        } else if (choice == 3) { // Print operation
            if (ismt(&cnt)) { // Check if the stack is empty
                printf("Stack is empty.\n"); // Print a message indicating that the stack is empty
            }
            for (int i = cnt - 1; i >= 0; i--) { // Iterate through the elements of the stack
                printf("%d\n", *(stack + i)); // Print the current element
                pop(stack, &cnt); // Pop the element from the stack (not necessary)
            }
            return 0; 
        } else if (choice == 4) { // Exit operation
            printf("Exiting...\n"); // Print a message indicating that the program is exiting
            break; // Exit the loop
        } else {
            printf("Invalid choice.\n"); // Print an error message for an invalid choice
            return 0; 
        }
        scanf("%d", &choice); // Input the next choice of operation
    }

    free(stack); // Free dynamically allocated memory
    return 0; 
}
