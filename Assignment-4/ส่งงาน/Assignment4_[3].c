#include<stdio.h>
#include<stdlib.h> //Jedsadaporn Pannok 66070503410

int main() {
    char word[1000]; // Array to store the input string
    scanf("%s", word); // Read the input string

    // Find the length of the input string
    int index = 0;
    while(word[index] != '\0') 
        index++;
    index--;

    int isBalanced = 1; // Flag to indicate if the string is balanced, initially set to true

    // Iterate through the string backwards
    while(index >= 0) {
        int prevIndex = index;
        prevIndex--;

        // If the current character is '}', search for its matching '{'
        if(word[index]=='}') {
            isBalanced = 0; // Assume the string is not balanced
            // Search for '{' in the string
            while (prevIndex>=0) {
                if(word[prevIndex] == '{') { // If '{' is found
                    word[prevIndex] = '\0'; // Nullify '{'
                    word[index] = '\0'; // Nullify '}'
                    isBalanced = 1; // Set flag to indicate string is balanced
                    break;
                }
                prevIndex--; // Move to the previous character
            }
            // If no matching '{' is found, print that the string is not balanced
            if(isBalanced == 0) {
                printf("The string is not balanced\n");
                return 0;
            }
        } 
        // If the current character is ')', search for its matching '('
        else if(word[index] == ')') {
            isBalanced = 0; // Assume the string is not balanced
            // Search for '(' in the string
            while (prevIndex>=0) {
                if(word[prevIndex] == '(') { // If '(' is found
                    word[prevIndex] = '\0'; // Nullify '('
                    word[index] = '\0'; // Nullify ')'
                    isBalanced = 1; // Set flag to indicate string is balanced
                    break;
                }
                prevIndex--; // Move to the previous character
            }
            // If no matching '(' is found, print that the string is not balanced
            if(isBalanced == 0) {
                printf("The string is not balanced\n");
                return 0;
            }
        } 
        // If the current character is ']', search for its matching '['
        else if(word[index] == ']') {
            isBalanced = 0; // Assume the string is not balanced
            // Search for '[' in the string
            while (prevIndex>=0) {
                if(word[prevIndex] == '[') { // If '[' is found
                    word[prevIndex] = '\0'; // Nullify '['
                    word[index] = '\0'; // Nullify ']'
                    isBalanced = 1; // Set flag to indicate string is balanced
                    break;
                }
                prevIndex--; // Move to the previous character
            }
            // If no matching '[' is found, print that the string is not balanced
            if(isBalanced == 0) {
                printf("The string is not balanced\n");
                return 0;
            }
        } 
        // If the current character is '(', '{', or '[', print that the string is not balanced
        else if(word[index] == '(' || word[index] == '{' || word[index] == '[') {
            printf("The string is not balanced\n");
            return 0;
        }
        index--; // Move to the previous character
    }

    // If the string is balanced, print that the string is balanced
    if(isBalanced != 0) 
        printf("The string is balanced\n");
    // If the string is not balanced, print that the string is not balanced
    else 
        printf("The string is not balanced\n");
    
    return 0;
}
