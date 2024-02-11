// Stack as linked list
// This problem is about the basic stack by implementing linked list. It is like linked list but you can only add the new node(push) and delete node(pop) in the front. Furthermore, it contains the special function that you can see the recently added node(top) and check its emptiness.

// Your task is to get the user command which includes
// 'p 
// �
// x' : (push) push the value in stack where 
// −
// �
// �
// �
// _
// �
// �
// �
// <
// �
// <
// �
// �
// �
// _
// �
// �
// �
// −INT_MAX<x<INT_MAX
// 'o' : (pop) delete the recently added node and display the deleted value. In case of the empty stack display "empty"
// 't' : (top) display the recently added node. In case of the empty stack display "empty"
// 'e' : (empty) return and display the emptiness of the stack. if the stack is empty, print "1". if not, print "0"
// 'q' : to end the program

// Input
// Multiple lines : The command mentioned above
// Last line : 'q' to end the program

// Output
// The result regrading to entered commands



#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;

void push(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = top;
    top = newNode;
}

void pop() {
    if (top == NULL) {
        printf("empty\n");
        return;
    }
    struct Node* temp = top;
    top = top->next;
    int deletedValue = temp->data;
    free(temp);
    printf("%d\n", deletedValue);
}

void displayTop() {
    if (top == NULL) {
        printf("empty\n");
        return;
    }
    printf("%d\n", top->data);
}

void isEmpty() {
    if (top == NULL) {
        printf("1\n");
    } else {
        printf("0\n");
    }
}

int main() {
    char n;
    int val;

    while (1) {
        scanf(" %c", &n);

        if (n == 'p') {
            scanf("%d", &val);
            push(val);
        } else if (n == 'o') {
            pop();
        } else if (n == 't') {
            displayTop();
        } else if (n == 'e') {
            isEmpty();
        } else if (n == 'q') {
            break;
        }
    }

    return 0;
}
