// Problem:

// You are tasked with creating a program to input a linked list and reverse its elements from a specified start point to an end point.

// List Structure:

// This is the structure of a linked list in this question:

// c
// Copy code
// typedef struct ListNode {
//     int val;
//     struct ListNode *next;
// } ListNode;
// Hint:

// Use strcmp() for comparing strings.
// Use atoi() for converting characters to integers.
// Input:

// The input consists of two lines:

// First Line: Enter integers X_i representing members of a linked list, where the index is equal to i, and ensure that -10000 ≤ X_i ≤ 10000. Use 'END' to signal the end of the input.
// Second Line: Enter integers Sp (Start Point) and Ep (End Point), where Sp ≤ Ep.
// Output:

// The output consists of:

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ListNode
{
    int val;
    struct ListNode *next;
} ListNode;

void insertAtEnd();
void printList();
void begin();

void Reverse();

int main()
{
    ListNode *head = NULL;
    ListNode *x = head;

    while (1)
    {
        char str[10];
        scanf("%s", str);
        if (strcmp(str, "END") == 0)
        {
            break;
        }
        else
        {
            int num = atoi(str);
            insertAtEnd(&head, num);
        }
    }

    int st,en; scanf("%d %d",&st,&en);
    ListNode *ptr = head;
    for(int i=1;i<st;i++) {
        printf("%d ",ptr->val);
        ptr = ptr->next;
    }
    ListNode *temp = NULL;
    for(int i=st;i<=en;i++) {
        begin(&temp,ptr->val);
        ptr = ptr->next;
    }
    ListNode *print = temp;
    while(print != NULL) {
        printf("%d ",print->val);
        print = print->next;
    }
    while(ptr != NULL) {
        printf("%d ",ptr->val);
        ptr = ptr->next;
    }


}

void insertAtEnd(ListNode **head, int num)
{
    ListNode *newNode = (ListNode *)malloc(sizeof(ListNode));
    newNode->val = num;
    newNode->next = NULL;

    if (*head == NULL)
    {
        *head = newNode;
        return;
    }

    ListNode *temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

void printList(ListNode **head)
{
    ListNode *temp = *head;
    while (temp != NULL)
    {
        printf("%d ", temp->val);
        temp = temp->next;
    }
}

void begin(ListNode **temp,int t) {
    ListNode *new = (ListNode *)malloc(sizeof(ListNode));
    new->val = t;
    new->next = *temp;
    *temp = new;
}

