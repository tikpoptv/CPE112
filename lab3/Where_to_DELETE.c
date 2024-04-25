// // สิตท่านไหนสามารถเขียนโปรแกรมทำการลบโหนดจาก Linked List แบบต่าง ๆ ได้บ้าง? ตอบโจทย์นี้เพื่อทดสอบความเข้าใจของคุณในการทำงานกับ Linked List แบบเชื่อมต่อเดียว (Singly Linked List) รู้จักกับรูปแบบการลบต่าง ๆ ที่ระบุด้านล่าง:

// // Input:

// // บรรทัดแรก: จำนวนเต็ม n (1 ≤ n) แทนจำนวนโหนดใน Linked List ต้นฉบับ
// // บรรทัดที่สอง: n จำนวนเต็ม, แต่ละตัวคั่นด้วยช่องว่าง, แทนค่าของโหนดใน Linked List
// // บรรทัดต่อมา: รายการ Mode สำหรับการลบ โดยมีตัวเลือกเป็น 'F' (ลบโหนดแรก), 'L' (ลบโหนดท้าย), 'N' (ลบโหนดที่มีค่า x), 'E' (สิ้นสุดการลบ)
// // Output:

// // แสดงค่าของโหนดที่เหลือใน Linked List หลังจากการลบตาม Mode ที่กำหนด
// // หากไม่มีโหนดใด ๆ เหลือ, ให้แสดง 'none'

// Which students can write a program to perform various deletion operations on a singly linked list? Answer this question to assess your understanding of working with a Singly Linked List. Familiarize yourself with the specified deletion modes outlined below:

// Input:

// First Line: An integer 'n' (1 ≤ n) representing the number of nodes in the original linked list.
// Second Line: 'n' integers, each separated by a space, representing the values of the nodes in the linked list.
// Subsequent Lines: Deletion modes, consisting of only four choices: 'F' (delete the first node), 'L' (delete the last node), 'N' (delete the first node with the value 'x'), and 'E' (terminate deletion). When using the 'N' mode, the user must input an integer 'x' to specify which value to delete.
// Output:

// Display the remaining nodes in the linked list after performing the specified deletions.
// If no nodes are left in the list, print 'none'.

// สร้างฟังชั่น Delete_FIRST_NODE
// สร้างฟังชั่น Delete_LAST_NODE
// สร้างฟังชั่น Delete_VALUE_NODE

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

void Delete_FIRST_NODE();
void Delete_LAST_NODE();
void Delete_VALUE_NODE();

int main()
{
    int n, i;
    char mode;
    int prepre, newData, nextData;

    Node *head = NULL;

    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        int data;
        scanf("%d", &data);
        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode->data = data;
        newNode->next = NULL;

        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            Node *curr = head;
            while (curr->next != NULL)
            {
                curr = curr->next;
            }
            curr->next = newNode;
        }
    }

    while (1)
    {
        scanf(" %c", &mode);
        if (mode == 'E')
        {
            break;
        }

        if (mode == 'F')
        {
            Delete_FIRST_NODE(&head);
        }
        else if (mode == 'L')
        {
            Delete_LAST_NODE(&head);
        }
        else if (mode == 'N')
        {
            scanf("%d", &prepre);
            Delete_VALUE_NODE(&head, prepre);
        }
    }

    Node *curr = head;
    if (curr == NULL)
    {
        printf("none");
    }
    while (curr != NULL)
    {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");

    return 0;
}

void Delete_FIRST_NODE(Node **head)
{
    if (*head == NULL)
    {
        return;
    }
    Node *n = *head;
    *head = n->next;
    free(n);
}


void Delete_LAST_NODE(Node **head)
{
    if (*head == NULL)
    {
        return;
    }
    if ((*head)->next == NULL)
    {
        free(*head);
        *head = NULL;
        return;
    }
    Node *n = *head;
    while (n->next->next != NULL)
    {
        n = n->next;
    }
    free(n->next);
    n->next = NULL;
}

void Delete_VALUE_NODE(Node **head, int x)
{
    if (*head == NULL)
    {
        return;
    }
    if ((*head)->data == x)
    {
        Node *n = *head;
        *head = n->next;
        free(n);
        return;
    }
    Node *n = *head;
    while (n->next != NULL && n->next->data != x)
    {
        n = n->next;
    }
    if (n->next == NULL)
    {
        return;
    }
    Node *del = n->next;
    n->next = del->next;
    free(del);
}