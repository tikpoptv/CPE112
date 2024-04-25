// Infix to Postfix
// Write the program to convert the Infix expression into Postfix expression including the character of 'a-z' or 'A-Z' as the elements and operators '+', '-', '*', '/' in the expression. Also, the bracket '()' for giving the most priority for that operation

// Infix expression: The expression of the form “a operator b” (a + b) e.g., when an operator is in-between every pair of operands.
// Postfix expression: The expression of the form “a b operator” (ab+) e.g., When every pair of operands is followed by an operator.

// Bemindful for the operator priority E.g the operation for the '*', '/' should come before '+','-' and the operation inside the brackets '()' should be the top priority

// 1. Scan the infix expression from left to right. 
// 2. If the scanned character is an operand, put it in the postfix expression. 
// 3. Otherwise, do the following 
// 	- If the precedence and associativity of the scanned operator are greater than the precedence and associativity of the operator in the stack [or the stack is empty or the stack contains a ‘(‘ ], then push it in the stack. [‘^‘ operator is right associative and other operators like ‘+‘,’–‘,’*‘ and ‘/‘ are left-associative].
// 		- Check especially for a condition when the operator at the top of the stack and the scanned operator both are ‘^‘. In this condition, the precedence of the scanned operator is higher due to its right associativity. So it will be pushed into the operator stack. 
// 		- In all the other cases when the top of the operator stack is the same as the scanned operator, then pop the operator from the stack because of left associativity due to which the scanned operator has less precedence. 
// 	- Else, Pop all the operators from the stack which are greater than or equal to in precedence than that of the scanned operator.
// 		- After doing that Push the scanned operator to the stack. (If you encounter parenthesis while popping then stop there and push the scanned operator in the stack.) 
// 4. If the scanned character is a "(" , push it to the stack. 
// 5. If the scanned character is a ")", pop the stack and output it until a ‘(‘ is encountered, and discard both the parenthesis. 
// 6. Repeat steps 2-5 until the infix expression is scanned. 
// 7. Once the scanning is over, Pop the stack and add the operators in the postfix expression until it is not empty.
// 8. Finally, print the postfix expression.
// Example: from "a+b/c" -> "abc/+"

// enter image description here

// Input
// The input consists of 1 lines

// First Line: A string of infix which has a length less than 1000 characters including the alphabet character and operators '+', '-', '*', '/' which '*', '/' has a greater priority than '+', '-' and the bracket '()' for the top priority

// Output
// The output consists of 1 line
// First Line: A string of postfix including the alphabet character and operators

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
    Stack *stack = createStack(len);
    char postfix[9999];
    int j = 0;
    for (int i = 0; i < len; i++)
    {
        if ((infix[i] >= 'a' && infix[i] <= 'z') || (infix[i] >= 'A' && infix[i] <= 'Z'))
        {
            postfix[j++] = infix[i];
        }
        else if (infix[i] == '(')
        {
            push(stack, infix[i]);
        }
        else if (infix[i] == ')')
        {
            while (!isEmpty(stack) && peek(stack) != '(')
            {
                postfix[j++] = pop(stack);
            }
            if (peek(stack) == '(')
            {
                pop(stack);
            }
        }
        else
        {
            while (!isEmpty(stack) && precedence(infix[i]) <= precedence(peek(stack)))
            {
                postfix[j++] = pop(stack);
            }
            push(stack, infix[i]);
        }
    }
    while (!isEmpty(stack))
    {
        postfix[j++] = pop(stack);
    }
    postfix[j] = '\0';
    printf("%s\n", postfix);
}