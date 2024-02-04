#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void addNode(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

void delNode(Node** head, int data) {
    Node* temp = *head;
    while (temp != NULL) {
        if (temp->data == data) {
            if (temp->prev != NULL) {
                temp->prev->next = temp->next;
            } else {
                *head = temp->next;
            }
            if (temp->next != NULL) {
                temp->next->prev = temp->prev;
            }
            free(temp);
            return;
        }
        temp = temp->next;
    }
}

void schNode(Node* head, int data) {
    Node* temp = head;
    while (temp != NULL) {
        if (temp->data == data) {
            if (temp->prev != NULL) {
                printf("%d ", temp->prev->data);
            } else {
                printf("none ");
            }
            if (temp->next != NULL) {
                printf("%d\n", temp->next->data);
            } else {
                printf("none\n");
            }
            return;
        }
        temp = temp->next;
    }
    printf("none none\n");
}

void printList(Node* head) {
    Node* temp = head;
    printf("Forward: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
    temp = head;
    printf("Backward: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;
    char command[4];
    int data;
    while (1) {
        scanf("%s", command);
        if (strcmp(command, "END") == 0) {
            break;
        }
        scanf("%d", &data);
        if (strcmp(command, "ADD") == 0) {
            addNode(&head, data);
        } else if (strcmp(command, "DEL") == 0) {
            delNode(&head, data);
        } else if (strcmp(command, "SCH") == 0) {
            schNode(head, data);
        }
    }
    printList(head);
    return 0;
}