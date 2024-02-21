#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> // ใช้ isalpha() เพื่อตรวจสอบว่าเป็นตัวอักษรหรือไม่

struct Node
{
    char data;
    int priority;
    struct Node *next;
};

struct Node *front = NULL;

void enqueue(char x, int p)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    if (temp == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }
    temp->data = x;
    temp->priority = p;
    temp->next = NULL;

    if (front == NULL || p > front->priority)
    {
        temp->next = front;
        front = temp;
    }
    else
    {
        struct Node *start = front;
        while (start->next != NULL && start->next->priority >= p)
        {
            start = start->next;
        }
        temp->next = start->next;
        start->next = temp;
    }
}

char dequeue()
{
    if (front == NULL)
    {
        printf("Queue is empty\n");
        exit(1);
    }
    struct Node *temp = front;
    front = front->next;
    char popped = temp->data;
    free(temp);
    return popped;
}

int main()
{
    printf("Enter a string: ");
    char str[100];
    fgets(str, sizeof(str), stdin); // ใช้ fgets แทน scanf เพื่อรับข้อมูลทั้งบรรทัดรวมช่องว่างได้

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (isalpha(str[i])) // ตรวจสอบว่าเป็นตัวอักษรหรือไม่
        {
            if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' || str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U')
            {
                enqueue(str[i], 3);
            }
            else
            {
                enqueue(str[i], 1);
            }
        }
        else
        {
            enqueue(str[i], 2);
        }
    }

    printf("Priority Queue Output: ");
    while (front != NULL)
    {
        printf("%c", dequeue());
    }
    return 0;
}
