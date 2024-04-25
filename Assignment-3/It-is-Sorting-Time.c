// Assignment: Sorting Students

// You've recently learned about linked lists, and now it's time to apply your knowledge to a simple assignment. Your task is to create a singly linked list that stores student data, consisting of a student ID and a score. Once the list is populated, you need to implement sorting based on either the student ID or the score.

// Input

// The input will be provided in the following format:

// The first line contains an integer size, indicating the number of students. (1 ≤ size ≤ 100)
// The next size lines contain two integers each: n and m, representing the student ID (1000 ≤ n ≤ 9999) and the student score (0 ≤ m ≤ 100), separated by a single space.
// The last line contains an integer mode, where mode = 0 indicates sorting by student IDs, and mode = 1 indicates sorting by scores.
// Output

// Your program should output a single line:

// The sorted list of scores according to the chosen mode (if mode = 0, output the sorted scores; if mode = 1, output the sorted scores).
// Example

// Input:

// yaml
// Copy code
// 5
// 1001 90
// 1002 85
// 1003 95
// 1004 80
// 1005 88
// 1

// Output:

// Copy code
// 80 85 88 90 95
// Notes

// In the example input, there are 5 students with their IDs and scores provided. The mode is set to 1, indicating sorting by scores. So, the output displays the scores sorted in ascending order.

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int val;
    int score;
    struct Node *next;
} Node;

void insertNode(Node **head, int val, int score)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->val = val;
    newNode->score = score;
    newNode->next = NULL;

    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        Node *temp = *head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void sortList(Node **head, int mode)
{
    if (*head == NULL || (*head)->next == NULL)
    {
        return;
    }

    Node *current = *head;
    Node *prev = NULL;
    int swapped;

    do
    {
        swapped = 0;
        current = *head;

        while (current->next != prev)
        {
            if ((mode == 0 && current->val > current->next->val) || (mode == 1 && current->score > current->next->score))
            {
                int tempVal = current->val;
                int tempScore = current->score;
                current->val = current->next->val;
                current->score = current->next->score;
                current->next->val = tempVal;
                current->next->score = tempScore;
                swapped = 1;
            }
            current = current->next;
        }
        prev = current;
    } while (swapped);
}

void printList(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->score);
        temp = temp->next;
    }
    printf("\n");
}


int main()
{
    int size;
    scanf("%d", &size);

    Node *head = NULL;

    for (int i = 0; i < size; i++)
    {
        int val, score;
        scanf("%d %d", &val, &score);
        insertNode(&head, val, score);
    }

    int mode;
    scanf("%d", &mode);

    sortList(&head, mode);
    printList(head);

    return 0;
}


