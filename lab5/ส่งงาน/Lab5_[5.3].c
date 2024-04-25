#include <stdio.h>
#include <stdlib.h>//Jedadaporn Pannok N0.66070503410

// Node structure for the linked list
struct Node
{
    char data;//Jedadaporn Pannok N0.66070503410
    int priority;
    struct Node *next;//Jedadaporn Pannok N0.66070503410
};

struct Node *front = NULL; // Global variable to keep track of the front of the queue

// Function to enqueue a character with a priority
void enqueue(char x, int p)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node)); // Allocate memory for the new node
    temp->data = x; // Set the data
    temp->priority = p; // Set the priority
    temp->next = NULL; // Set the next pointer to NULL

    // If the queue is empty or the new node has higher priority than the front
    if (front == NULL || p > front->priority)
    {
        temp->next = front; // Make the new node the new front
        front = temp;
    }
    else
    {
        struct Node *start = front;
        // Traverse the queue until finding the appropriate position to insert the new node
        while (start->next != NULL && start->next->priority >= p)
        {
            start = start->next;
        }
        temp->next = start->next; // Insert the new node
        start->next = temp;
    }
}

// Function to dequeue a character
char dequeue()
{
    struct Node *temp = front; // Store the front node
    front = front->next; // Move the front pointer to the next node
    char popped = temp->data; // Get the data of the dequeued node
    free(temp); // Free the memory of the dequeued node
    return popped; // Return the dequeued data
}

int main()
{
    char str[999];
    scanf("%[^\n]", str); // Read a string input from the user

    // Enqueue characters based on their priority
    for (int i = 0; str[i] != '\0'; i++)
    {
        if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
        {
            if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' || str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U')
            {
                enqueue(str[i], 3); // Vowels have highest priority (3)
            }
            else
            {
                enqueue(str[i], 1); // Consonants have medium priority (1)
            }
        }
        else
        {
            enqueue(str[i], 2); // Other characters have lowest priority (2)
        }
    }

    // Dequeue and print characters until the queue is empty
    while (front != NULL)
    {
        printf("%c", dequeue());
    }
    return 0;
}
