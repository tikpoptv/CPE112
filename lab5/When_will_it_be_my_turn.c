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

int main() {
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
    if(q->front == q->rear) {
        int item = q->array[q->front];
        q->front=0;
        q->rear=-1;
        q->size = q->size - 1;
        return item;
    } else {
        int item = q->array[q->front];
        q->front = (q->front + 1) % q->capacity;
        q->size = q->size - 1;
        return item;
    }
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