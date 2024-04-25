#include <stdio.h>
#include <stdlib.h> //Jedsadaporn Pannok 66070503410
#include <string.h>

// Define a structure for the stack
typedef struct Stack
{
    int top;         // Index of the top element in the stack
    int max_size;    // Maximum size of the stack
    char *array;     // Array to hold the elements of the stack
} Stack;

// Function to create a stack with the given size
Stack *createStack(int size)
{
    Stack *stack = (Stack *)malloc(sizeof(Stack));   // Allocate memory for the stack
    stack->max_size = size;                          // Set the maximum size of the stack
    stack->top = -1;                                 // Initialize the top index to -1 (empty stack)
    stack->array = (char *)malloc(stack->max_size * sizeof(char));   // Allocate memory for the stack array
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
void push(Stack *stack, char item)
{
    if (isFull(stack))   // Check if the stack is full
    {
        printf("invalid\n");   // Print "invalid" if the stack is full
        exit(0);   // Exit the program
    }
    stack->array[++stack->top] = item;   // Increment the top index and add the item to the stack
}

// Function to pop an element from the stack
char pop(Stack *stack)
{
    if (isEmpty(stack))   // Check if the stack is empty
    {
        printf("invalid\n");   // Print "invalid" if the stack is empty
        exit(0);   // Exit the program
    }
    return stack->array[stack->top--];   // Return the element at the top index and decrement the top index
}

// Function to peek at the top of the stack
char peek(Stack *stack)
{
    if (isEmpty(stack))   // Check if the stack is empty
    {
        return '0';   // Return '0' if the stack is empty
    }
    return stack->array[stack->top];   // Return the element at the top index of the stack
}

// Function to determine the precedence of operators
int precedence(char ch)
{
    if (ch == '^')
    {
        return 3;
    }
    else if (ch == '*' || ch == '/')
    {
        return 2;
    }
    else if (ch == '+' || ch == '-')
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

int main()
{
    char infix[9999];
    scanf("%s", infix);
    int len = strlen(infix);
    Stack *stack = createStack(len);   // Create a stack with the size of the infix expression
    char postfix[9999];
    int j = 0;
    for (int i = 0; i < len; i++)
    {
        if ((infix[i] >= 'a' && infix[i] <= 'z') || (infix[i] >= 'A' && infix[i] <= 'Z'))   // If the character is an operand
        {
            postfix[j++] = infix[i];   // Add it to the postfix expression
        }
        else if (infix[i] == '(')   // If the character is an opening parenthesis
        {
            push(stack, infix[i]);   // Push it onto the stack
        }
        else if (infix[i] == ')')   // If the character is a closing parenthesis
        {
            while (!isEmpty(stack) && peek(stack) != '(')   // Pop operators from the stack until an opening parenthesis is encountered
            {
                postfix[j++] = pop(stack);   // Add the popped operator to the postfix expression
            }
            if (peek(stack) == '(')   // If an opening parenthesis is found at the top of the stack
            {
                pop(stack);   // Pop it from the stack (remove it from the stack)
            }
        }
        else   // If the character is an operator
        {
            while (!isEmpty(stack) && precedence(infix[i]) <= precedence(peek(stack)))   // Pop operators from the stack with higher or equal precedence
            {
                postfix[j++] = pop(stack);   // Add the popped operator to the postfix expression
            }
            push(stack, infix[i]);   // Push the current operator onto the stack
        }
    }
    while (!isEmpty(stack))   // Pop remaining operators from the stack
    {
        postfix[j++] = pop(stack);   // Add the popped operator to the postfix expression
    }
    postfix[j] = '\0';   // Add null character to terminate the postfix expression string
    printf("%s\n", postfix);   // Print the postfix expression
}
