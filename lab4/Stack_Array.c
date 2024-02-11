// Stack Array
// Implement a stack using an array. Write a program that allows users to perform various operations such as push, pop, and display the contents of the stack. Ensure appropriate error messages are displayed when necessary.

// Your task is to get the user command which includes:

// push()
// This function takes an integer value as input and pushes it onto the stack.
// If the stack is full, it displays "Stack Overflow." and terminates the program.
// pop()
// This function pops the top element from the stack.
// If the stack is empty, it displays "Stack Underflow." and terminates the program.
// show()
// This function displays the contents of the stack.
// If the stack is empty, it displays "Stack is empty." and terminates the program.
// isFull()
// This function checks if the stack is full.
// It returns true if the top pointer is equal to max_size - 1, indicating that the stack is full, otherwise, it returns false.
// isEmpty()
// This function checks if the stack is empty.
// It returns true if the top pointer is -1, indicating that the stack is empty, otherwise, it returns false.
// Input
// First line: An integer of size which represents the size of the stack, in which 1 ≤ size ≤ 1000000 if input size ≤ 0 will print "Please enter a positive number." and terminates the program

// Second line:
// Input integer 1, 2, 3, 4
// 1 is Push
// 2 is Pop
// 3 is Show Stack
// 4 is Exit
// If you type 1, you must type followed by the integer that you want to add to the stack.
// If you type 2, the number in the stack will be removed by 1 unit.
// If you type 3, Show all stacks and terminates the program.
// If you type 4, Exit program and print "Exiting...".
// If you type in addition to 1 - 4 will print "Invalid choice." and terminates the program.

// Output
// Show Stack or Various messages

// !!IMPORTANT!!

// Use #include <stdbool.h>
// Use malloc

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Stack
{
    int top;
    int max_size;
    int *array;
} Stack;

Stack *createStack(int size)
{
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->max_size = size;
    stack->top = -1;
    stack->array = (int *)malloc(stack->max_size * sizeof(int));
    return stack;
}

bool isFull(Stack *stack)
{
    return stack->top == stack->max_size - 1;
}

bool isEmpty(Stack *stack)
{
    return stack->top == -1;
}

void push(Stack *stack, int item)
{
    if (isFull(stack))
    {
        printf("Stack Overflow.\n");
        exit(0);
    }
    stack->array[++stack->top] = item;
}

int pop(Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack Underflow.\n");
        exit(0);
    }
    return stack->array[stack->top--];
}

void show(Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack is empty.\n");
        exit(0);
    }
    for (int i = 0; i <= stack->top; i++)
    {
        printf("%d ", stack->array[i]);
    }
    printf("\n");
}


int main()
{
    int size;
    scanf("%d", &size);
    if (size <= 0)
    {
        printf("Please enter a positive number.\n");
        return 0;
    }
    Stack *stack = createStack(size);
    int choice;
    while (1)
    {
        scanf("%d", &choice);
        if (choice == 1)
        {
            int item;
            scanf("%d", &item);
            push(stack, item);
        }
        else if (choice == 2)
        {
            pop(stack);
        }
        else if (choice == 3)
        {
            show(stack);
        }
        else if (choice == 4)
        {
            printf("Exiting...\n");
            break;
        }
        else
        {
            printf("Invalid choice.\n");
            break;
        }
    }
    return 0;
}