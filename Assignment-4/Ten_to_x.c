// Ten to X
// This task is very simple, write a program that implement a stack for converting a non-negative integer in decimal to base-x integer.

// Since we are playing around with only number and English letter, the base that we will convert can cover up to base 2 to base 36 only. If there is any forbidden condition that can leads to an error, print 'invalid'

// IMPORTANT : This problem focuses only on non-negative integers. For the numbers below zero, we will learn how to implement it to a base-x form in CPE222 (DIGITAL ELECTRONICS AND LOGIC DESIGN)

// Input
// The input consists of two lines:

// First Line:
// An integer 
// �
// n as the decimal integer.
// Second Line:
// An integer 
// �
// x as the base to convert to.

// Output
// The output consists of only one line: The result of base-x conversion or the word 'invalid' for the forbidden condition.

#include <stdio.h>
#include <stdlib.h>

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

int isFull(Stack *stack)
{
    return stack->top == stack->max_size - 1;
}

int isEmpty(Stack *stack)
{
    return stack->top == -1;
}

void push(Stack *stack, int item)
{
    if (isFull(stack))
    {
        printf("invalid\n");
        exit(0);
    }
    stack->array[++stack->top] = item;
}

int pop(Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("invalid\n");
        exit(0);
    }
    return stack->array[stack->top--];
}

void show(Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("0\n");
        return;
    }
    while (!isEmpty(stack))
    {
        int temp = pop(stack);
        if (temp < 10)
        {
            printf("%d", temp);
        }
        else
        {
            printf("%c", temp + 55);
        }
    }
    printf("\n");
}

int main()
{
    int n, x;
    scanf("%d %d", &n, &x);
    if (x < 2 || x > 36)
    {
        printf("invalid\n");
        return 0;
    }
    Stack *stack = createStack(100);
    while (n > 0)
    {
        push(stack, n % x);
        n /= x;
    }
    show(stack);
}
