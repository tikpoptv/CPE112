#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
    char option;
} node;

void insertbefore(struct node *input, int pos, int val) {
    struct node *newNode, *ptr, *prePtr;

    newNode = (struct node*)malloc(sizeof(node));
    newNode -> data = val;
    newNode->next = NULL;

    if (input == NULL) {
        printf("List is empty\n");
        return;
    }

    if (pos == 0) {
        newNode->next = input;
        input = newNode;
        return;
    }

    ptr = input;
    prePtr = NULL;
    int i = 0;
    while (ptr != NULL && i < pos) {
        prePtr = ptr;
        ptr = ptr->next;
        i++;
    }

    if (ptr == NULL) {
        printf("Position out of range\n");
        return;
    }

    newNode->next = ptr;
    prePtr->next = newNode;
}

void printList(struct node *head) {
    struct node *ptr = head;
    while (ptr != NULL) {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

int main() {
    struct node *head = NULL;
    insertbefore(head, 0, 10);
    insertbefore(head, 0, 20);
    insertbefore(head, 1, 30);
    insertbefore(head, 2, 40);
    printList(head);
    return 0;
}