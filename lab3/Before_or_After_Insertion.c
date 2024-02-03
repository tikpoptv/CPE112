// ห้เขียนโปรแกรมที่สร้าง linked list จากข้อมูลที่กำหนดและทำตามคำสั่งที่รับเข้ามาตามนี้:

// 'A [รหัสก่อนหน้า] [ข้อมูลใหม่]': เพิ่มข้อมูลใหม่หลังจากข้อมูลที่มีรหัสตามที่กำหนด
// 'B [รหัสถัดไป] [ข้อมูลใหม่]': เพิ่มข้อมูลใหม่ก่อนข้อมูลที่มีรหัสตามที่กำหนด
// 'E': หยุดการป้อนคำสั่งและพิมพ์ข้อมูลใน linked list ที่ได้รับการปรับปรุง
// ข้อมูลนำเข้า:
// บรรทัดแรก:
// จำนวนเต็ม n ซึ่ง n ≥ 1 เป็นจำนวนของโหนดใน linked list ต้นฉบับ

// บรรทัดที่สอง:
// n จำนวนเต็มที่เป็นโหนดใน linked list โดยแยกแต่ละข้อมูลด้วย 'whitespace'

// บรรทัดถัดไป:
// Mode สำหรับการแทรก ประกอบด้วยเพียงสี่ตัวเลือก: 'A', 'B' และ 'E'

// ผลลัพธ์:
// ข้อมูลใน linked list ที่ได้รับการปรับปรุงโดยแยกด้วย 'whitespace'



// Write a program that constructs a linked list from the given elements and follows the entered commands as follows:

// 'A [previous code] [new data]': Insert [new data] after the node with the specified code.
// 'B [next code] [new data]': Insert [new data] before the node with the specified code.
// 'E': Stop entering insert commands and print the elements in the finalized linked list.
// Input:
// The input consists of:
// First Line:
// An integer n where n ≥ 1 as the number of nodes in the original linked list.
// Second Line:
// n integers that represent nodes in the linked list, separated by 'whitespace'.
// The next following lines:
// Mode for insertion, which consists of only four choices: 'A', 'B', and 'E'.

// Output:
// The elements in the finalized linked list separated by 'whitespace'.

#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
} Node;

void addAfter();

void addBefore();

int main() {
    int n, i;
    char mode;
    int prepre, newData, nextData;

    Node* head = NULL;

    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        int data;
        scanf("%d", &data);
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->data = data;
        newNode->next = NULL;

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

    while (1) {
        scanf(" %c", &mode);
        if (mode == 'E') {
            break;
        }

        if (mode == 'A' || mode == 'B') {
            scanf("%d %d", &prepre, &newData);
        }

        if (mode == 'A') {
            addAfter(head, prepre, newData);
        } else if (mode == 'B') {
            addBefore(&head, prepre, newData);
        }
    }

    Node* curr = head;
    while (curr != NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");

    return 0;
}


void addAfter(Node* head, int prepre, int newData) {
    // Allocate memory for new node
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = newData;
    newNode->next = NULL;


    // Initialize current node to head
    Node* curr = head;
    // Traverse the list until end
    while (curr != NULL) {
        // If current node's data matches prepre
        if (curr->data == prepre) {
            newNode->next = curr->next;
            // Set current node's next to newNode
            curr->next = newNode;
            return;
        }
        // Move to next node

        curr = curr->next;
    }

}

void addBefore(Node** head, int nextData, int newData) {
    // Allocate memory for new node
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = newData;
    newNode->next = NULL;

    // Check if list is empty
    if (*head == NULL) {
        printf("Error\n");
        free(newNode);
        return;
    }

    // Add new node at beginning of list
    if ((*head)->data == nextData) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    Node* curr = *head;
    // Traverse list to find position before nextData
    while (curr->next != NULL && curr->next->data != nextData) {
        curr = curr->next;
    }

    // Error if nextData not found in list
    if (curr->next == NULL) {
        // printf("Error");
        free(newNode);
        return;
    }


    // Add new node before node with data = nextData
    newNode->next = curr->next;
    curr->next = newNode;
}
