// Secret Code Only You and I Know
// When you are entering a phrase or a sentence in some occasion, it will be transform into a sequence of string.

// This problem we suggest a transformation with a priority queue

// The rule of transformation is:

// Every English CONSONANTS will be considered a priority of 1
// Every English VOWELS will be considered a priority of 3
// The other characters that is not English alphabet will be considered a priority of 2
// The priority is ordered with the largest value as the most priority.
// For the character with the same priority, will be ordered as First come, first serve.

// เช่น
// INPUT
// I loVe You!
// // OUTPUT
// Ioeou  !lVY

// หรือ

// INPUT 
// Yesterday is Valentine's Day. The one who is looking this sentences will have a good and wonderful relation with his/her loved one.
// OUTPUT
// eeaiaeieaeoeoiooiieeeiaeaooaoeueaioiieoeoe  ' .                /  .YstrdysVlntnsDyThnwhslkngthssntncswllhvgdndwndrflrltnwthhshrlvdn


#include <stdio.h>
#include <stdlib.h>

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
    struct Node *temp = front;
    front = front->next;
    char popped = temp->data;
    free(temp);
    return popped;
}

int main()
{
    char str[999];
    scanf("%[^\n]", str);
    for (int i = 0; str[i] != '\0'; i++)
    {
        if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
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
    while (front != NULL)
    {
        printf("%c", dequeue());
    }
    return 0;
}