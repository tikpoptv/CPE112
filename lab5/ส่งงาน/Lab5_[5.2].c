#include <stdio.h>//Jedadaporn Pannok N0.66070503410
#include <stdlib.h>//Jedadaporn Pannok N0.66070503410

// Data structure declaration
typedef struct Queue
{
    int front, rear, size;          // Index pointing to the front and rear of the queue, and current size of the queue
    unsigned capacity;              // Capacity of the queue
    int *array;                     // Pointer to the array storing queue data
} Queue;

void enqueue(Queue *q, int data);   // Function for adding elements into the queue
int dequeue(Queue *q);              // Function for removing elements from the queue
void show(Queue *q);                // Function for displaying elements in the queue
Queue *createQueue(unsigned capacity);  // Function for creating a new queue
int isFull(Queue *q);               // Function for checking if the queue is full
int isEmpty(Queue *q);              // Function for checking if the queue is empty

int main() {
    int size;
    char command;
    int data;
    scanf("%d", &size);             // Get the size of the queue from the user
    Queue *q = createQueue(size);   // Create a queue with the given size
    while (1)
    {
        scanf(" %c", &command);     // Get the command from the user
        if (command == 'I')         // If the command is 'I' (Insert)
        {
            scanf("%d", &data);     // Get the data to be inserted into the queue
            if (isFull(q))          // Check if the queue is full
            {
                printf("Queue is full!!\n");  // Print a message indicating that the queue is full
            }
            else
            {
                enqueue(q, data);    // Add data into the queue
            }
        }
        else if (command == 'D')    // If the command is 'D' (Delete)
        {
            if (isEmpty(q))         // Check if the queue is empty
            {
                printf("Queue is empty!!\n"); // Print a message indicating that the queue is empty
            }
            else
            {
                printf("%d\n", dequeue(q));  // Remove data from the queue and print the removed value
            }
        }
        else if (command == 'S')    // If the command is 'S' (Show)
        {
            if (isEmpty(q))         // Check if the queue is empty
            {
                printf("Queue is empty!!\n"); // Print a message indicating that the queue is empty
            }
            else
            {
                show(q);             // Display the data in the queue
            }
        }
        else if (command == 'E')    // If the command is 'E' (Exit)
        {
            break;                  // Exit the loop
        }
    }
    return 0;
}

// Function to create a new queue
Queue *createQueue(unsigned capacity)
{
    Queue *queue = (Queue *)malloc(sizeof(Queue));     // Allocate memory for the Queue structure
    queue->capacity = capacity;                        // Set the capacity of the queue
    queue->front = queue->size = 0;                    // Initialize front index and size
    queue->rear = capacity - 1;                        // Initialize rear index
    queue->array = (int *)malloc(queue->capacity * sizeof(int));  // Allocate memory for the data array
    return queue;                                      // Return the created queue to the caller
}

// Function to check if the queue is full
int isFull(Queue *q)
{
    return (q->size == q->capacity);                  // If the size of the queue equals its capacity, it's full
}

// Function to check if the queue is empty
int isEmpty(Queue *q)
{
    return (q->size == 0);    //Jedadaporn Pannok N0.66070503410                         // If the size of the queue is zero, it's empty
}

// Function to add data into the queue
void enqueue(Queue *q, int data)
{
    q->rear = (q->rear + 1) % q->capacity;              // Move rear index to the next position
    q->array[q->rear] = data;                           // Insert data at the position after the rear
    q->size = q->size + 1;                              // Increase the size of the queue
}

// Function to remove data from the queue
int dequeue(Queue *q)
{
    if(q->front == q->rear) {                           // If front and rear point to the same position
        int item = q->array[q->front];                  // Store the data to be removed
        q->front=0;                                      // Reset front and rear indices
        q->rear=-1;
        q->size = q->size - 1;                           // Decrease the size of the queue
        return item;                                     // Return the removed item
    } else {
        int item = q->array[q->front];                  // Store the data to be removed
        q->front = (q->front + 1) % q->capacity;        // Move front index to the next position
        q->size = q->size - 1;                           // Decrease the size of the queue
        return item;                                     // Return the removed item
    }
}

// Function to display data in the queue
void show(Queue *q)
{
    printf("Front: %d\n", q->front);                    // Display the front index
    printf("Items: ");
    for (int i = 0; i < q->size; i++)                   // Loop to display all elements in the queue
    {
        printf("%d ", q->array[(q->front + i) % q->capacity]);  // Display the data
    }
    printf("\nRear: %d\n", q->rear);                    // Display the rear index
}
