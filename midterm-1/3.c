#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the queue
typedef struct node
{
    int data;
    struct node *next;
} node;

// Define the structure for the queue
typedef struct queue
{
    node *front;
    node *rear;
} queue;

// Initialize the queue
void init(queue *q)
{
    q->front = NULL;
    q->rear = NULL;
}

// Insert a new node at the end of the queue
void insert_C(queue *q, int letter)
{
    node *ptr = (node *)malloc(sizeof(node));
    ptr->data = letter;
    ptr->next = NULL;
    if (q->rear == NULL)
    {
        q->front = ptr;
        q->rear = ptr;
    }
    else
    {
        q->rear->next = ptr;
        q->rear = ptr;
    }
}

// Dequeue and print the integers from the queue while the sum is less than or equal to 4
int print_dequeue(queue *q, int *sum)
{
    if (q->front == NULL)
        return -1;

    // reverse the queue
    node *prev = NULL;
    node *current = q->front;
    node *next;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    q->front = prev;

    node *ptr = q->front;
    while (ptr != NULL && *sum + ptr->data <= 4)
    {
        printf("%d", ptr->data);
        *sum += ptr->data;
        q->front = ptr->next;
        free(ptr);
        ptr = q->front;
        if(ptr != NULL) printf(" ");
    }
    printf("\n"); // print newline character here

    // reverse the queue back to its original order
    prev = NULL;
    current = q->front;
    next = NULL;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    q->front = prev;

    return 0;
}
int main()
{
    int n, i, num;
    scanf("%d", &n);
    queue q;
    init(&q);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &num);
        insert_C(&q, num);
    }

    int sum = 0;
    while (q.front != NULL)
    {
        if (print_dequeue(&q, &sum) == -1)
            break;
        if (q.front == NULL) // print newline character only after the last call to print_dequeue
            printf("\n");
        else
            sum = 0;
    }

    return 0;
}