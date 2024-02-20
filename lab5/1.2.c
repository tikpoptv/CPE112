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

#include <stdio.h>
#include <stdlib.h>

struct CircularQueue
{
    int size;
    int *arr;
    int front;
    int rear;
};

