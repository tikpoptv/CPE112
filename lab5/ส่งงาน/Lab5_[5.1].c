#include <stdio.h>
#include <stdlib.h> //Jedadaporn Pannok N0.66070503410
#include <string.h>

// Define a structure for a node in the playlist
typedef struct Node
{
    char song[100];//Jedadaporn Pannok N0.66070503410
    char artist[100];
    int time;
    struct Node *next;
} Node;

// Function to insert a new song into the playlist
void insertNode(Node **head, char song[], char artist[], int time)
{
    Node *newNode = (Node *)malloc(sizeof(Node)); // Allocate memory for the new node
    strcpy(newNode->song, song); // Copy song name to the node
    strcpy(newNode->artist, artist); // Copy artist name to the node
    newNode->time = time; // Set the playtime of the song
    newNode->next = NULL; // Initialize next pointer

    // If the playlist is empty, make the new node the head of the list
    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        Node *temp = *head;
        // Traverse to the end of the list
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        // Insert the new node at the end
        temp->next = newNode;
    }
}

// Function to play the next song in the playlist
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
    free(temp); // Free memory of the dequeued node
}

// Function to print the list of songs in the playlist
void printList(Node *head)
{
    if (head == NULL)
    {//Jedadaporn Pannok N0.66070503410
        printf("No songs in the playlist\n");
        return;
    }
    Node *temp = head;
    printf("Songs in the playlist:\n");
    // Traverse the list and print each song
    while (temp != NULL)
    {
        printf("%s by %s %d\n", temp->song, temp->artist, temp->time);
        temp = temp->next;
    }
    // Calculate and print the remaining total playtime
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
    Node *head = NULL; // Initialize the playlist as empty
    char command[100];
    char song[100];
    char artist[100];
    int time;
    // Menu-driven loop to interact with the playlist
    while (1)
    {
        scanf("%s", command); // Read command from user
        if (strcmp(command, "add") == 0) // If command is to add a song
        {
            scanf(" %[^\n]", song); // Read song name
            scanf(" %[^\n]", artist); // Read artist name
            scanf("%d", &time); // Read playtime
            insertNode(&head, song, artist, time); // Insert the song into the playlist
        }
        else if (strcmp(command, "play") == 0) // If command is to play the next song
        {
            dequeue(&head); // Play the next song in the playlist
        }
        else if (strcmp(command, "sum") == 0) // If command is to print the playlist and remaining time
        {
            printList(head); // Print the list of songs and remaining time
            break;
        }//Jedadaporn Pannok N0.66070503410
    }
    return 0;
}
