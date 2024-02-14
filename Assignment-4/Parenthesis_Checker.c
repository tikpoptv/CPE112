// Parenthesis Checker
// This question is all about parenthesis, by that here is the question. You will receive a string of parenthesis such as “(”, “)”, “{”, “}”, “[”, “]”. Then, your task is to check whether the string is balance or not. The expression is considered balanced with respect to the parenthesis if the same type of closing brackets is used to close open brackets "(", "{", "[". For example, string “{[()]}” can be considered as balanced due to the fact that each opening parenthesis has a corresponding closing parenthesis. On the contrary, string “()[]}{” is not balance because you can see that despite a majority of parenthesis is place correctly, the closing “}” bracket has been placed before the opening “{”, thus this is not balance. Plus, you must use stack in this question. You can use stack in form of array or linked list.

// The output can be in 2 scenarios:

// Output: “The string is balanced”
// Output: “The string is not balanced”
// Input
// A string “word” that in which has the length of 1 ≤ word ≤ 1000

// Output
// Print “The string is balanced” or “The string is not balanced”

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Stack
{
    int top;
    int max_size;
    char *array;
} Stack;

Stack *createStack(int size)
{
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->max_size = size;
    stack->top = -1;
    stack->array = (char *)malloc(stack->max_size * sizeof(char));
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

void push(Stack *stack, char item)
{
    if (isFull(stack))
    {
        printf("invalid\n");
        exit(0);
    }
    stack->array[++stack->top] = item;
}

char pop(Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("invalid\n");
        exit(0);
    }
    return stack->array[stack->top--];
}

char peek(Stack *stack)
{
    if (isEmpty(stack))
    {
        return '0';
    }
    return stack->array[stack->top];
}

int main()
{
    char word[1000];
    scanf("%s", word);
    Stack *stack = createStack(strlen(word));
    for (int i = 0; i < strlen(word); i++)
    {
        if (word[i] == '(' || word[i] == '{' || word[i] == '[')
        {
            push(stack, word[i]);
        }
        else
        {
            if (isEmpty(stack))
            {
                printf("The string is not balanced\n");
                return 0;
            }
            char temp = pop(stack);
            if (word[i] == ')' && temp != '(')
            {
                printf("The string is not balanced\n");
                return 0;
            }
            else if (word[i] == '}' && temp != '{')
            {
                printf("The string is not balanced\n");
                return 0;
            }
            else if (word[i] == ']' && temp != '[')
            {
                printf("The string is not balanced\n");
                return 0;
            }
        }
    }
    if (isEmpty(stack))
    {
        printf("The string is balanced\n");
    }
    else
    {
        printf("The string is not balanced\n");
    }
    return 0;
}