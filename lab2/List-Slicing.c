// Input
// First Line
// A number of elements 1 ≤ m < n ≤ 1,000,000 in list
// Second Line
// A sequence of integer (int) separating between element with a whitespace
// Third Line
// Three integers as start, end and step

// Output
// The output consist of one line, print out all the elements in the sliced list. If there is no element in the sliced list print “empty”

// Examples
// Input	
// 7
// 1 2 3 4 5 6 7 0 3 1	
// Output
// 1 2 3

// Input
// 1
// 1
// 0 1 1	
// Output 
// 1

// Input
// 8
// -2 -1 -1 0 4 5 7 9
// -1 -7 -2	
// Output
// 9 5 0 

// Input
// 5
// 9 3 6 0 1
// -12 8 1	
// Output
// 9 3 6 0 1
#include <stdio.h>
#include <stdlib.h>

// Function to print an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int n, start, end, step;

    // Read the size of the array from the user
    scanf("%d", &n);

    // Allocate memory for an index array with values from -n to -1
    int* index = (int*)calloc(n, sizeof(int));
    int re_index = -n;
    for (int i = 0; i < n; i++)
        *(index + i) = re_index++;

    // Allocate memory for the array
    int* arr = (int*)malloc(n * sizeof(int));
    
    // Read elements into the array
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    // Read start, end, and step values
    scanf("%d", &start);
    scanf("%d", &end);
    scanf("%d", &step);

    // Adjust start and end values if negative or out of bounds
    if (start < 0) {
        if (start < *(index + 0))
            start = 0;
        for (int i = 0; i < n; i++)
            if (start == *(index + i))
                start = i;
    }

    if (end < 0) {
        if (end < *(index + 0))
            end = 0;
        for (int i = 0; i < n; i++)
            if (end == *(index + i))
                end = i;
    }

    // Print the subarray based on start, end, and step values
    if ((start < end && step > 0) || (start > end && step < 0)) {
        if (start > n)
            start = n - 1;
        if (end > n)
            end = n;

        if (start < end && step > 0)
            for (int i = start; i < end; i += step)
                printf("%d ", arr[i]);
        else if (start > end && step < 0)
            for (int i = start; i > end; i += step)
                printf("%d ", arr[i]);
    } else {
        printf("empty");
    }

    // Free the allocated memory
    free(index);
    free(arr);

    return 0;
}

