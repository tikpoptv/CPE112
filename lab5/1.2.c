// When will it be my turn???
// Now that you guys have learned about queues, it is crucial to also understand the concept of circular queues. Thus, in this lab, you guys will have to try to code the circular queue. In this task, you guys are staff at a dental clinic, in which due to budget cuts, there are only a small number of chairs. Therefore, you guys have to design a queue system in order to manage the queuing system properly. Luckily, the manager already designs all the functions and their uses.

// Circular Queue Operations
// The circular queue work as follows:

// two pointers FRONT and REAR
// FRONT track the first element of the queue
// REAR track the last elements of the queue
// initially, set value of FRONT and REAR to -1
// 1. Enqueue Operation

// check if the queue is full
// for the first element, set value of FRONT to 0
// circularly increase the REAR index by 1 (i.e. if the rear reaches the end, next it would be at the start of the queue)
// add the new element in the position pointed to by REAR
// 2. Dequeue Operation

// check if the queue is empty
// return the value pointed by FRONT
// circularly increase the FRONT index by 1
// or the last element, reset the values of FRONT and REAR to -1
// However, the check for full queue has a new additional case:

// Case 1: FRONT = 0 && REAR == SIZE - 1
// Case 2: FRONT = REAR + 1
// The second case happens when REAR starts from 0 due to circular increment and when its value is just 1 less than FRONT, the queue is full.
// Circular Queue
// The function that the manager designs includes:

// insertq():

// This function takes an integer value as input and pushes it onto the queue.
// In case that the queue is full, print “Queue is full!!”
// dequeue():

// This function removes an element from the system.
// In case that the queue is empty, print “Queue is empty!!”
// show():

// This function shows the list of queues (THIS IS FOR VISUALIZATION, DO NOT DEQUEUE THEM)
// Also, the function can show the indexes of the chair that are at the front and rear of the queue.
// In case that the queue is empty, print “Queue is empty!!”
// PS: We want you to use a circular queue and it is important is remember the FIFO (First In First Out) principle

// The operation used in the program:
// 'I 
// �
// x': insert the element in the queue
// D: dequeue the first element in the queue (print the first element in the queue and remove it)
// S: show front index, display the element in the queue and show the rear index in this format.
// E: Exit the program

// Front: 0              // Front Index
// Items: 1 2 3 4 5 // the element in the queue sorting from the first to be out (dequeue)
// Rear: 4              // Rear Index
// Input
// First line: The Size of the queue 1≤ size ≤ 10
// Multiple lines: The command mentioned above
// Last line: 'E' to end the program

// Output
// The result regrading to entered commands

#include <stdio.h>
#include <stdlib.h>

// ประกาศโครงสร้างข้อมูล
typedef struct Queue
{
    int front, rear, size;
    unsigned capacity;
    int *array;
} Queue;
void enqueue(Queue *q, int data);                   // Function for Insert Elements
int dequeue(Queue *q);                              // Function for Remove Elements
void show(Queue *q);                                // Function for Show Elements
Queue *createQueue(unsigned capacity);              // Function for Create Queue
int isFull(Queue *q);                               // Function for Check Full Queue
int isEmpty(Queue *q);                              // Function for Check Empty Queue
int main()
{
    int size;
    char command;
    int data;
    scanf("%d", &size);
    Queue *q = createQueue(size);
    while (1)
    {
        scanf(" %c", &command);
        if (command == 'I')
        {
            scanf("%d", &data);
            if (isFull(q))
            {
                printf("Queue is full!!\n");
            }
            else
            {
                enqueue(q, data);
            }
        }
        else if (command == 'D')
        {
            if (isEmpty(q))
            {
                printf("Queue is empty!!\n");
            }
            else
            {
                printf("%d\n", dequeue(q));
            }
        }
        else if (command == 'S')
        {
            if (isEmpty(q))
            {
                printf("Queue is empty!!\n");
            }
            else
            {
                show(q);
            }
        }
        else if (command == 'E')
        {
            break;
        }
    }
    return 0;
}
Queue *createQueue(unsigned capacity)
{
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
    queue->array = (int *)malloc(queue->capacity * sizeof(int));
    return queue;
}
int isFull(Queue *q)
{
    return (q->size == q->capacity);
}
int isEmpty(Queue *q)
{
    return (q->size == 0);
}
void enqueue(Queue *q, int data)
{
    q->rear = (q->rear + 1) % q->capacity;
    q->array[q->rear] = data;
    q->size = q->size + 1;
}
int dequeue(Queue *q)
{
    int item = q->array[q->front];
    q->front = (q->front + 1) % q->capacity;
    q->size = q->size - 1;
    return item;
}
void show(Queue *q)
{
    printf("Front: %d\n", q->front);
    printf("Items: ");
    for (int i = 0; i < q->size; i++)
    {
        printf("%d ", q->array[(q->front + i) % q->capacity]);
    }
    printf("\nRear: %d\n", q->rear);
}
