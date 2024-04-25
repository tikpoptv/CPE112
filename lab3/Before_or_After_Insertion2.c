#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Doubly Linked List structure
struct DoublyLinkedList {
    struct Node* head;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Function to add a node to the end of the list
void add(struct DoublyLinkedList* dl_list, int data) {
    struct Node* new_node = createNode(data);
    if (dl_list->head == NULL) {
        dl_list->head = new_node;
    } else {
        struct Node* cur = dl_list->head;
        while (cur->next != NULL) {
            cur = cur->next;
        }
        cur->next = new_node;
        new_node->prev = cur;
    }
}

// Function to delete a node with a specific data value
void delNode(struct DoublyLinkedList* dl_list, int data) {
    struct Node* cur = dl_list->head;
    while (cur != NULL) {
        if (cur->data == data) {
            if (cur->prev != NULL) {
                cur->prev->next = cur->next;
            } else {
                dl_list->head = cur->next;
            }
            if (cur->next != NULL) {
                cur->next->prev = cur->prev;
            }
            free(cur);
            return;
        }
        cur = cur->next;
    }
}

// Function to search for a node with a specific data value and print its neighbors
void search(struct DoublyLinkedList* dl_list, int data) {
    struct Node* cur = dl_list->head;
    while (cur != NULL) {
        if (cur->data == data) {
            if (cur->prev != NULL) {
                printf("%d ", cur->prev->data);
            } else {
                printf("none ");
            }
            if (cur->next != NULL) {
                printf("%d\n", cur->next->data);
            } else {
                printf("none\n");
            }
            return;
        }
        cur = cur->next;
    }
}

// Function to print the doubly linked list
void printList(struct DoublyLinkedList* dl_list) {
    struct Node* cur = dl_list->head;
    while (cur != NULL) {
        printf("%d ", cur->data);
        cur = cur->next;
    }
    printf("\n");
    cur = dl_list->head;
    while (cur != NULL) {
        printf("%d ", cur->data);
        cur = cur->prev;
    }
    printf("\n");
}

// Main function
int main() {
    struct DoublyLinkedList dl_list;
    dl_list.head = NULL;

    while (1) {
        char command[5];
        scanf("%s", command);

        if (strcmp(command, "END") == 0) {
            break;
        } else if (strcmp(command, "ADD") == 0) {
            int data;
            scanf("%d", &data);
            add(&dl_list, data);
        } else if (strcmp(command, "DEL") == 0) {
            int data;
            scanf("%d", &data);
            delNode(&dl_list, data);
        } else if (strcmp(command, "SCH") == 0) {
            int data;
            scanf("%d", &data);
            search(&dl_list, data);
        } else if (strcmp(command, "PRINT") == 0) {
            printList(&dl_list);
        }
    }

    return 0;
}
