// Spotify
// From learning queue in the lecture session, what you need to be able to do is to apply it. Everyone must have listened to the music once in life. So we are encouraging you to make your own streaming platform, like Spotify, by managing the playlist according to the commands below.

// Get the user input in this format:

// add

// song name
// artist
// time (in seconds)
// This will add the song to the queue (enqueue)

// play

// This will dequeue the frontmost music and show the result: 'Now playing: xxxxx by xxxxx'. If there is no songs, print out 'No songs in the playlist'

// sum

// This will show all remaining songs in the queue in this format:
// Songs in the playlist:
// xxx by xxxx xxxsec
// //If there is no songs, print out 'No songs in the playlist' and end the program.
// Remaining Time: xxxsec

// The input section will end with a character '\n'


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    char song[100];
    char artist[100];
    int time;
    struct Node *next;
} Node;

void insertNode(Node **head, char song[], char artist[], int time)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    strcpy(newNode->song, song);
    strcpy(newNode->artist, artist);
    newNode->time = time;
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

void dequeue(Node **head)
{
    if (*head == NULL)
    {
        printf("No songs in the playlist\n");
        return;
    }
    Node *temp = *head;
    *head = (*head)->next;
    printf("Now playing: %s by %s\n", temp->song, temp->artist);
    free(temp);
}

void printList(Node *head)
{
    if (head == NULL)
    {
        printf("No songs in the playlist\n");
        return;
    }
    Node *temp = head;
    printf("Songs in the playlist:\n");
    while (temp != NULL)
    {
        printf("%s by %s %d\n", temp->song, temp->artist, temp->time);
        temp = temp->next;
    }
    temp = head;
    int sum = 0;
    while (temp != NULL)
    {
        sum += temp->time;
        temp = temp->next;
    }
    printf("Remaining Time: %d\n", sum);
}

int main()
{
    Node *head = NULL;
    char command[100];
    char song[100];
    char artist[100];
    int time;
    while (1)
    {
        scanf("%s", command);
        if (strcmp(command, "add") == 0)
        {
            scanf(" %[^\n]", song);
            scanf(" %[^\n]", artist);
            scanf("%d", &time);
            insertNode(&head, song, artist, time);
        }
        else if (strcmp(command, "play") == 0)
        {
            dequeue(&head);
        }
        else if (strcmp(command, "sum") == 0)
        {
            printList(head);
            break;
        }
    }
    return 0;
}
