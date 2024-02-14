#include <stdio.h>
#include <stdlib.h> //Jedsadaporn Pannok 66070503410
#include <string.h>

// Node structure for linked list
struct Node {
    char data;          // Data of the node
    struct Node* next;  // Pointer to the next node
};

// Global variable to maintain the top of the stack
struct Node* top = NULL;

// Function to push a character onto the stack
void push(char value) {
    // Create a new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;    // Set the data of the new node
    newNode->next = top;      // Link the new node to the current top of the stack
    top = newNode;            // Update the top of the stack
}

// Function to pop a character from the stack
char pop() {
    if (top == NULL) {
        return '0';   // Return '0' if the stack is empty
    }
    struct Node* temp = top;  // Store the current top of the stack
    top = top->next;          // Update the top of the stack
    char deletedValue = temp->data;  // Get the data of the deleted node
    free(temp);               // Free the memory of the deleted node
    return deletedValue;      // Return the deleted value
}

// Function to peek at the top of the stack
char peek() {
    if (top == NULL) {
        return '0';   // Return '0' if the stack is empty
    }
    return top->data;   // Return the data of the top node
}

// Main function
int main() {
    char word[100];   // Array to store the input word
    int i;
    int length;
    int mid;
    int isPalindrome = 1;   // Flag to indicate if the word is a palindrome, initially set to true

    scanf("%s", word);   // Read the input word
    length = strlen(word);   // Calculate the length of the word
    mid = length / 2;    // Calculate the middle index of the word

    // Push the first half of the word onto the stack
    for (i = 0; i < mid; i++) {
        push(word[i]);
    }

    // Adjust index if the length of the word is odd
    if (length % 2 != 0) {
        i++;
    }

    // Compare the remaining characters in the word with the characters popped from the stack
    while (word[i] != '\0') {
        if (word[i] != pop()) {
            isPalindrome = 0;   // Set the flag to false if characters do not match
            break;
        }
        i++;
    }

    // Print "yes" if the word is a palindrome, otherwise print "no"
    if (isPalindrome) {
        printf("yes\n");
    } else {
        printf("no\n");
    }

    return 0;
}
