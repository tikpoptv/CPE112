// คุณได้รับมอบหมายให้สร้างโปรแกรมที่จำลอง Doubly Linked List โปรแกรมควรประมวลผลคำสั่งและข้อมูลในลำดับต่อไปนี้เพื่อสร้าง、ดำเนินการ และแสดงผล Doubly Linked List

// คำสั่งที่ต้องรองรับคือ:

// ADD x: สร้างโหนดที่มีค่า x และเพิ่มไปยังโหนดที่สร้างล่าสุด หากยังไม่มีโหนดที่สร้างไว้ก่อนหน้านี้ คำสั่งนี้จะสร้างโหนดแรก
// DEL x: ลบโหนดแรกที่มีค่าเท่ากับ x หากไม่พบโหนดที่มีค่าตรงกัน คำสั่งนี้จะถูกละเว้น
// SCH x: ค้นหาโหนดที่ต่อไปของโหนดแรกที่มีค่า x ซึ่งหมายถึงการค้นหาโหนดที่อยู่ก่อนและหลังของโหนดที่กำหนด หากไม่มีโหนดที่มีค่าที่ระบุ ให้พิมพ์ 'none'
// END: สัญญาณที่บอกถึงการสิ้นสุดการสร้างรายการ
// หลังจากประมวลผลคำสั่ง โปรแกรมควรพิมพ์ผลลัพธ์ที่สุดท้ายของ Doubly Linked List ในลำดับทั้งสิ้นและถอยหลัง

// ข้อมูลนำเข้า:

// ข้อมูลนำเข้าประกอบด้วยบรรทัดหลาย ๆ บรรทัด แต่ละบรรทัดมีคำสั่งและค่าข้อมูลที่คั่นด้วยช่องว่าง
// สิ้นสุดส่วนข้อมูลนำเข้าด้วยคำสั่ง 'END'
// ผลลัพธ์:

// เมื่อคำสั่งเป็น 'SCH' โปรแกรมควรพิมพ์ค่าของโหนดที่อยู่ก่อนและหลังโหนดที่ระบุ
// บรรทัดที่สองจากท้ายควรแสดงผลโหนดผลลัพธ์ในลำดับที่ผ่านมา
// บรรทัดสุดท้ายควรแสดงผลโหนดผลลัพธ์ในลำดับที่ถอยหลัง

// You are tasked with implementing a program that simulates a doubly linked list. The program should process a series of commands and data values to create, manipulate, and display the doubly linked list.

// The following commands should be supported:

// ADD x: Create a node with the value x and append it to the last node created. If no nodes have been created yet, this command will create the first node.

// DEL x: Delete the first node with a value equal to x. If no node with the matched value is found, this command is ignored.

// SCH x: Search for the neighbor nodes of the first node with the value x. This involves finding the nodes that come before and after the given node. If there is no node with the specified value, print 'none'.

// END: Signal the termination of creating the list.

// After processing the commands, the program should print the final result of the doubly linked list in both forward and backward orders.

// Input:

// The input consists of multiple lines, each containing a command and data value separated by whitespace.
// End the input section with the command 'END'.
// Output:

// When the command is 'SCH', the program should print the values of the nodes that come before and after the specified node.
// The second-to-last line of output should display the result node in forward order.
// The last line of output should display the result node in backward order.

// สร้างฟังชั่น ADD_x
// สร้างฟังชั่น DEL_x
// สร้างฟังชั่น SCH_x


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INT_MIN -999999
#define INT_MAX 999999

//  Node structure for linked list
typedef struct Node
{
    int value;
    struct Node *next;
    struct Node *prev;
} Node;

//  Head pointer to the first element on the list

Node *listHead = NULL;
Node *listTail = NULL;


//  Functions implementation
int size;
int k = 0;
int search[100000];

// Function to insert a new node with the given value at the end of the list
void insertNode(int value)
{
    // Create a new node
    Node *tmp = malloc(sizeof(Node));
    // Set the value of the new node
    tmp->value = value;
    // Set the next and previous pointers of the new node

    tmp->next = NULL;
    // If the list is empty, set both head and tail to the new node
    tmp->prev = NULL;

    // If the list is empty, set both head and tail to the new node
    if (listHead == NULL)
    {
        listHead = tmp;
        listTail = tmp;
    }
    else
    // Insert the new node at the end of the list
    {
        tmp->prev = listTail;
        listTail->next = tmp;
        listTail = tmp;
    }
    size++;
}



// Function to delete the node with the given value from the list
void deleteNode(int key)
{
    // Traverse the list to find the node with the specified value
    Node *ptr = listHead;
    // Find the node with the specified value
    while (ptr != NULL)
    {
        // Find the node with the specified value
        if (ptr->value == key)
        {
            Node *p1 = ptr->prev;
            Node *p2 = ptr->next;
            // Handle the case when the node to be deleted is the only node in the list
            if (size == 1)
            {
                listHead = listTail = NULL;
                size = 0;
                free(ptr);
                return;
            }
            // Update pointers to remove the node from the list
            if (ptr != listTail)
            {
                p2->prev = p1;
            }
            else
            {
                listTail = p1;
            }
            // Update pointers to remove the node from the list
            if (ptr != listHead)
            {
                p1->next = p2;
            }
            else
            {
                listHead = p2;
            }
            free(ptr);
            size--;
            return;
        }
        ptr = ptr->next;
    }
}

// Function to search for the node with the specified value
void searchNodes(int key)
{
    // Traverse the list to find the node with the specified value
    Node *ptr = listHead;
    // Find the node with the specified value
    while (ptr != NULL)
    {
        // Find the node with the specified value
        if (ptr->value == key)
        {// Store the previous and next values of the node with the specified value
            search[k++] = (ptr->prev == NULL) ? INT_MIN : ptr->prev->value;
            search[k++] = (ptr->next == NULL) ? INT_MIN : ptr->next->value;
            return;
        }
        ptr = ptr->next;
    }
    // If the node with the specified value is not found, store 'none' in the search array
    search[k++] = INT_MAX;
    search[k++] = INT_MAX;
}

int main()
{
    // Input the commands
    size = 0;

    // Process the commands
    while (1)
    {
        // Input the command and the value
        char mode[3];
        int value;

        scanf("%s", mode);

    // Process the commands
        if (strcmp(mode, "END") == 0)
        {
            break;
        }
        else if (strcmp(mode, "ADD") == 0)
        {
            scanf("%d", &value);
            insertNode(value);
        }
        else if (strcmp(mode, "DEL") == 0)
        {
            scanf("%d", &value);
            deleteNode(value);
        }
        else
        {
            scanf("%d", &value);
            searchNodes(value);
        }
    }

    // Print the search results
    // If the node with the specified value is not found, store 'none' in the search array
    for (int j = 0; j < k; j++)
    {
        
        if (search[j] == INT_MIN)
        {
            printf("NULL");
        }
        
        else if (search[j] == INT_MAX)
        {
            printf("none");
            j++;
        }
        else
        {
            printf("%d", search[j]);
        }
        if (j & 1)
        {
            printf("\n");
        }
        else
        {
            printf(" ");
        }
    }

    // Print the final linked list
    if (size == 0)
    {
        printf("none");
    }

    while (listHead != NULL)
    {
        printf("%d ", listHead->value);
        listHead = listHead->next;
    }

    printf("\n");

    if (size == 0)
    {
        printf("none");
    }

    // Print the remaining elements from the doubly linked list in reverse order
    while (listTail != NULL)
    {
        printf("%d ", listTail->value);
        listTail = listTail->prev;
    }
    return 0;
}
