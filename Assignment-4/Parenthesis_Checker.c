// Parenthesis Checker
// This question is all about parenthesis, by that here is the question. You will receive a string of parenthesis such as “(”, “)”, “{”, “}”, “[”, “]”. Then, your task is to check whether the string is balance or not. The expression is considered balanced with respect to the parenthesis if the same type of closing brackets is used to close open brackets "(", "{", "[". For example, string “{[()]}” can be considered as balanced due to the fact that each opening parenthesis has a corresponding closing parenthesis. On the contrary, string “()[]}{” is not balance because you can see that despite a majority of parenthesis is place correctly, the closing “}” bracket has been placed before the opening “{”, thus this is not balance. Plus, you must use stack in this question. You can use stack in form of array or linked list.

// The output can be in 2 scenarios:

// Output: “The string is balanced”
// Output: “The string is not balanced”
// Input
// A string “word” that in which has the length of 1 ≤ word ≤ 1000

// Output
// Print “The string is balanced” or “The string is not balanced”


#include<stdio.h>
#include<stdlib.h>

int main() {
    char word[1000]; 
    scanf("%s",word);
    int index = 0;
    while(word[index] != '\0') index++;
    index--;
    int isBalanced = 1;
    while(index >= 0) {
        int prevIndex = index;
        prevIndex--;
        if(word[index]=='}') {
            isBalanced = 0;
            while (prevIndex>=0) {
                if(word[prevIndex] == '{') {
                    word[prevIndex] = '\0';
                    word[index] = '\0';
                    isBalanced = 1;
                    break;
                }
                prevIndex--;
            }
            if(isBalanced == 0) {
                printf("The string is not balanced\n");
                return 0;
            }
        } else if(word[index] == ')') {
            isBalanced = 0;
            while (prevIndex>=0) {
                if(word[prevIndex] == '(') {
                    word[prevIndex] = '\0';
                    word[index] = '\0';
                    isBalanced = 1;
                    break;
                }
                prevIndex--;
            }
            if(isBalanced == 0) {
                printf("The string is not balanced\n");
                return 0;
            }
        } else if(word[index] == ']') {
            isBalanced = 0;
            while (prevIndex>=0) {
                if(word[prevIndex] == '[') {
                    word[prevIndex] = '\0';
                    word[index] = '\0';
                    isBalanced = 1;
                    break;
                }
                prevIndex--;
            }
            if(isBalanced == 0) {
                printf("The string is not balanced\n");
                return 0;
            }
        } else if(word[index] == '(' || word[index] == '{' || word[index] == '[') {
            printf("The string is not balanced\n");
            return 0;
        }
        index--;
    }
    if(isBalanced != 0) 
        printf("The string is balanced\n");
    else 
        printf("The string is not balanced\n");
    return 0;
}
