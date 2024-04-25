// Palindrome checker
// Palindrome is word or sequence that reads forward the same as backward. You can see how we can check the sequence is palindrome or not from the pseudocode below



// Now. Your task is to check the entered sequence is palindrome or not by implementing "STACK" and applying the given pseudo code.

// Input
// First line : The word or sequence that we'll check

// Output
// The result whether the entered word is palindrome or not ("yes" or "no")

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char data;
    struct Node* next;
};

struct Node* top = NULL;

void push(char value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = top;
    top = newNode;
}

char pop() {
    if (top == NULL) {
        return '0';
    }
    struct Node* temp = top;
    top = top->next;
    char deletedValue = temp->data;
    free(temp);
    return deletedValue;
}

char peek() {
    if (top == NULL) {
        return '0';
    }
    return top->data;
}

int main() {
    char word[100];
    int i;
    int length;
    int mid;
    int isPalindrome = 1;

    scanf("%s", word);
    length = strlen(word);
    mid = length / 2;

    for (i = 0; i < mid; i++) {
        push(word[i]);
    }

    if (length % 2 != 0) {
        i++;
    }

    while (word[i] != '\0') {
        if (word[i] != pop()) {
            isPalindrome = 0;
            break;
        }
        i++;
    }

    if (isPalindrome) {
        printf("yes\n");
    } else {
        printf("no\n");
    }

    return 0;
}
