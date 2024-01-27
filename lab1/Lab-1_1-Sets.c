// Input
// The input consists of two lines
// First Line:
// An integer 𝑛 in which 1 ≤ 𝑛 ≤ 1,000 as the number of elements in an array.
// Second Line:
// A sequence of non-decreasing order array of integer 𝑎1, 𝑎2 … 𝑎n separating between element with a whitespace.

// Output
// The output consists of two lines
// First Line:
// An integer 𝑚 which is the number of elements in the set.
// Second Line:
// A sequence of the elements in set

#include <stdio.h>
//I'll just call the function because I like to write it below.
void set(int arry[], int size);

int main() {
    //n is the size of the array
    int n;
    //input is the array
    scanf("%d", &n);
    //set the array
    int input[n];
    //loop to fill in values
    for (int i = 0; i < n; i++) {
        scanf("%d", &input[i]);
    }
    //call the function
    set(input, n);

    return 0;
}
// The function to find the principle set is to eliminate duplicates.
void set(int arry[], int size) {
    //set is the principle set
    int set[size], n = 0;
    //loop to find the principle set
    for (int i = 0; i < size; i++) {
        //present is used to check if the value is already in the set
        int present = 0;
        //loop to check if the value is already in the set
        for (int j = 0; j < n; j++) {
            //If there are duplicates, present = 1 and exit the loop to do it again.
            if (arry[i] == set[j]) {
                present = 1;
                break;
            }
        }
        //If there are no duplicates, add the value to the set.
        if (!present) {
            set[n++] = arry[i];
        }
    }
    //print the size of the set
    printf("%d\n", n);
    //print the set
    // for (int i = 0; i < n; i++) {
    //     //If it is not the last element, print a space after the element.
    //     if (i < n-1)
    //     {
    //         printf("%d ", set[i]);
    //     }else{
    //         printf("%d", set[i]);
    //     }
    // }
     //print the set
    for (int i = 0; i < n; i++) {
        printf("%d ", set[i]);
    }
}
