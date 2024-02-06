// Circular table
// There are N numbers in a circle waiting to be removed. The counting out begins at some point in the circle and proceeds around the circle in a fixed direction. In each step, a certain number are skipped and the next number is removed. The elimination proceeds around the circle (which is becoming smaller and smaller as the number were removing), find the only the last number.

// Example:
// 1 2 3 4 5 with 2 steps
// 1st round (start at 1): 1 2 3 4 5 two got removed
// 2nd round (start at 3): 1 3 4 5 four got removed
// 3rd round (start at 5): 1 3 5 one got removed
// 4th round (start at 3): 3 5 five got removed
// and 3 is the answer.

// Input
// The input consists of 2 lines

// First Line: An integer size in which 1≤size≤100 as the number of elements in the linked list. And the number of step in which 1≤step≤100as the number that the step that take to remove a number upon last step. Both are seperated by whitespace.

// Second Line: The sequence of numbers, respectfully to the size, that assign on the circle in which 0≤a≤10000 and each of them are seperated by whitespace.

// Output
// The output consists of 1 line
// First Line: The last number remain


#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;           
    struct Node *next;  
} Node;

// ประกาศฟังก์ชัน
void insertAtEnd();

int main()
{
    int size, step;

    // รับขนาดของรายการและค่าของ step จากผู้ใช้
    scanf("%d %d", &size, &step);

    // กำหนดค่าเริ่มต้นของ linked list เป็น NULL
    Node *head = NULL;

    // เติมข้อมูลลงใน linked list จากผู้ใช้
    for (int i = 0; i < size; i++)
    {
        int data;
        scanf("%d", &data);
        insertAtEnd(&head, data);
    }

    // เชื่อมต่อ Node สุดท้ายกับ head 
    Node *x = head;
    while (x->next != NULL)
    {
        x = x->next;
    }
    x->next = head;

    Node *prepre = NULL;
    x = head;

    while (x->next != x)
    {
        // ขยับไปยัง Node ที่ต้องการลบ
        for (int i = 0; i < step - 1; i++)
        {
            prepre = x;
            x = x->next;
        }

        // นำ Node ปัจจุบันออกจาก linked list
        prepre->next = x->next;
        Node *temp = x;
        x = x->next;

        free(temp);
    }

    // พิมพ์ข้อมูลของ Node ที่เหลือสุดท้าย
    printf("%d", x->data);

    return 0;
}

// ฟังก์ชันเพื่อแทรก Node ใหม่ที่ท้าย linked list
void insertAtEnd(Node **head, int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL)
    {
        // ถ้า linked list ว่างเปล่า ให้ตั้ง Node ใหม่เป็น head
        *head = newNode;
    }
    else
    {
        // มิฉะนั้น ขยับไปที่ท้ายและเพิ่ม Node ใหม่
        Node *temp = *head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}
