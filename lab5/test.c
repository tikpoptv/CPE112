#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int front;
    int rear;
    int size;
    int *queue;
} Queue;

Queue* createQueue(int size) {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    if (q == NULL) {
        printf("Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    q->front = 0;
    q->rear = 0;
    q->size = size;
    q->queue = (int*)malloc(size * sizeof(int));
    if (q->queue == NULL) {
        printf("Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    return q;
}

void freeQueue(Queue* q) {
    free(q->queue);
    free(q);
}

int isFull(Queue *q) {
    return (q->rear + 1) % q->size == q->front;
}

int isEmpty(Queue *q) {
    return q->front == q->rear;
}

void insertQ(Queue *q, int value) {
    if (isFull(q)) {
        printf("Queue is full!!\n");
        return;
    }
    q->rear = (q->rear + 1) % q->size;
    q->queue[q->rear] = value;
}

int deleteQ(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty!!\n");
        return -1;
    }
    int value = q->queue[q->front];
    q->front = (q->front + 1) % q->size;
    return value;
}

void showQ(Queue *q) {
    int i, count;
    if (isEmpty(q)) {
        printf("Queue is empty!!\n");
        return;
    }
    printf("Front: %d\n", q->front);
    printf("Items: ");
    count = (q->rear - q->front + q->size) % q->size + 1;
    for (i = 0; i < count; i++) {
        printf("%d ", q->queue[(q->front + i) % q->size]);
    }
    printf("\nRear: %d\n", q->rear);
}

int main() {
    int size, value;
    char cmd;
    printf("Enter size of the queue: ");
    scanf("%d", &size);
    Queue* q = createQueue(size);

    while (1) {
        printf("Enter command (E to exit, I to insert, D to delete, S to show): ");
        scanf(" %c", &cmd);
        
        if (cmd == 'E') {
            break;
        } else if (cmd == 'I') {
            printf("Enter value to insert: ");
            scanf("%d", &value);
            insertQ(q, value);
        } else if (cmd == 'D') {
            printf("Deleted value: %d\n", deleteQ(q));
        } else if (cmd == 'S') {
            showQ(q);
        } else {
            printf("Invalid command!\n");
        }
    }

    freeQueue(q);
    return 0;
}
