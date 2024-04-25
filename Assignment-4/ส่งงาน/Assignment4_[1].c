#include <stdio.h>
#include <stdlib.h>
//jedsadaporn Pannok No.66070503410


// Define a structure for a stack
typedef struct Stack
{
    int top;         // Index of the top element in the stack
    int max_size;    // Maximum size of the stack
    int *array;      // Array to hold the elements of the stack
} Stack;

// Function to create a stack with the given size
Stack *createStack(int size)
{
    Stack *stack = (Stack *)malloc(sizeof(Stack));   // Allocate memory for the stack
    stack->max_size = size;                          // Set the maximum size of the stack
    stack->top = -1;                                 // Initialize the top index to -1 (empty stack)
    stack->array = (int *)malloc(stack->max_size * sizeof(int));   // Allocate memory for the stack array
    return stack;                                    // Return a pointer to the created stack
}

// Function to check if the stack is full
int isFull(Stack *stack)
{
    return stack->top == stack->max_size - 1;    // Return true if the top index is at the maximum size
}

// Function to check if the stack is empty
int isEmpty(Stack *stack)
{
    return stack->top == -1;    // Return true if the top index is -1 (empty stack)
}

// Function to push an element onto the stack
void push(Stack *stack, int item)
{
    if (isFull(stack))    // Check if the stack is full
    {
        printf("invalid\n");   // Print "invalid" and exit if the stack is full
        exit(0);
    }
    stack->array[++stack->top] = item;   // Increment the top index and add the item to the stack
}

// Function to pop an element from the stack
int pop(Stack *stack)
{
    if (isEmpty(stack))   // Check if the stack is empty
    {
        printf("invalid\n");   // Print "invalid" and exit if the stack is empty
        exit(0);
    }
    return stack->array[stack->top--];   // Return the element at the top index and decrement the top index
}

// Function to display the elements of the stack
void show(Stack *stack)
{
    if (isEmpty(stack))   // Check if the stack is empty
    {
        printf("0\n");    // Print "0" if the stack is empty
        return;
    }
    while (!isEmpty(stack))   // Loop until the stack is empty
    {
        int temp = pop(stack);    // Pop an element from the stack
        if (temp < 10)
        {
            printf("%d", temp);   // Print the element if it's less than 10
        }
        else
        {
            printf("%c", temp + 55);   // Print the corresponding character if it's greater than or equal to 10
        }
    }
    printf("\n");    // Print a new line after displaying all elements
}

// Main function
int main()
{
    int n, x;
    scanf("%d %d", &n, &x);   // Read inputs for decimal number (n) and base (x)
    if (x < 2 || x > 36)      // Check if the base is valid (between 2 and 36 inclusive)
    {
        printf("invalid\n");   // Print "invalid" and return if the base is invalid
        return 0;
    }
    Stack *stack = createStack(100);   // Create a stack with a maximum size of 100
    while (n > 0)
    {
        push(stack, n % x);    // Push remainder of n divided by x onto the stack
        n /= x;                // Update n by dividing it by x
    }
    show(stack);   // Display the elements of the stack, representing the converted number
}
