#include <stdio.h>
#include <stdlib.h>

// Function to print an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Function to adjust start and end values if negative or out of bounds
void adjustStartEnd(int* start, int* end, int n, int* index) {
    // If start is negative, set it to 0 or the nearest valid index
    if (*start < 0) {
        if (*start < *(index + 0))
            *start = 0;
        for (int i = 0; i < n; i++)
            if (*start == *(index + i))
                *start = i;
    }

    // If end is negative, set it to 0 or the nearest valid index
    if (*end < 0) {
        if (*end < *(index + 0))
            *end = 0;
        for (int i = 0; i < n; i++)
            if (*end == *(index + i))
                *end = i;
    }
}

// Function to print the subarray based on start, end, and step values
void printSubarray(int arr[], int start, int end, int step, int n) {
        // Check conditions for valid subarray
    if ((start < end && step > 0) || (start > end && step < 0)) {
        // Adjust start and end values if they exceed the array size
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
    adjustStartEnd(&start, &end, n, index);

    // Print the subarray based on start, end, and step values
    printSubarray(arr, start, end, step, n);

    // Free the allocated memory
    free(index);
    free(arr);

    return 0;
}
