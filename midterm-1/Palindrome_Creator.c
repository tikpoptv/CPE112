#include <stdio.h>
#include <stdlib.h> // jedsadaporn Pannok N0.66070503410

// Define the Node structure for the stack
typedef struct Node// creat Node
{
    char data;
    struct Node *next;
} Node;

// Function to push an element onto the stack
void push(Node **top, char data) // BIG O = O(1)
{
    Node *newNode = malloc(sizeof(Node));// allocate memory for the new node
    newNode->data = data;// set the data of the new node
    newNode->next = *top;// set the next of the new node to the top
    *top = newNode;//   set the top to the new node
}

// Function to pop an element from the stack
char pop(Node **top)// BIG O = O(1)
{ 
    if (*top == NULL) // if the stack is empty ทำให้มันว่าง
    {
        return '\0';
    }
    Node *temp = *top; // สร้างตัวแปรชื่อ temp แล้วเก็บค่าของ top ไว้ใน temp  คำนี้เขียนอังกฤษยางงาย
    *top = (*top)->next; // set the top to the next of the top
    char data = temp->data; // create a variable named data and store the value of temp->data in data.
    free(temp); // command used to remove memory reserved by malloc or calloc from memory.
    return data; // return data
}

// Function to check last character 
int check(char *input) // BIG O = O(n)
{
    int i = 0; // create a variable named i and set its value to 0.
    while (input[i] != '\0') // loop through the input string until the end of the string is reached.
    {
        i++; // increment the value of i by 1.
    }
    i--;
    for (int j = 0; j < i; j++) // loop through the input string until the second last character.
    {
        if (input[j] == input[i]) // lf the character at index j is equal to the character at index i
        {
            return 1; // return 1
        }
    }
    return 0;
}

// Function to print a string
void print_string(char *str) // BIG O = O(n)
{
    for (int i = 0; str[i] != '\0'; i++) // loop through the input string until the end of the string is reached.
    {
        printf("%c", str[i]); // print the character.
    }
}


void print_re(Node **data, char *input) // BIG O = O(n)
{
    print_string(input); // print the input string

    int i = 0;
    while (input[i] != '\0') // l;oop through the input string until the end of the string is reached.
    {
        if (input[i + 1] != '\0') // if the next character is not the end of the string
        {
            push(data, input[i]);  //  push the character onto the stack
        }
        i++;
    }
    i--; // i in the last character of the string

    if (check(input) == 1)
    {
        char temp; // Create a variable named temp
        while (temp != input[i])
        {
            temp = pop(data); // pop the character from the stack
        }
    }

    while (*data != NULL) // ;oop through the stack until the stack is empty
    {
        printf("%c", pop(data)); // pprint the character
    }
}

// Function to read the input string
void read_input(char *input) // BIG O = O(n)
{
    scanf("%[^\n]", input); // Read the input string
}

int main() // BIG O = O(n)
{
    char input[1000]; // create a character array named input with a size of 1000
    read_input(input); // read the input string

    Node *data = NULL; // create a pointer to a Node and set it to NULL
    print_re(&data, input); // print the string in reverse order

    return 0; // return 0 to indicate successful completion of the program
}
