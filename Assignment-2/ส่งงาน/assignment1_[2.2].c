#include <stdio.h>
#include <stdlib.h>

// Define a structure to hold an integer array
struct data { // Jedsadaporn Pannok 66070503410
    int *arr;
};

// Function prototype for the 'jump' function
void jump(struct data, int);

// Main function where the program starts execution
int main() {
    int n;
    // Read the size of the array from the user
    scanf("%d", &n);

    // Declare a struct data variable and allocate memory for an integer array of size n
    struct data data;
    data.arr = (int*)malloc(n * sizeof(int));

    // Read n integers from the user and store them in the array
    for (int i = 0; i < n; i++) {
        scanf("%d", data.arr + i);
    }

    // Call the 'jump' function with the input data and size
    jump(data, n);

    return 0;
}

// Function to calculate the minimum number of jumps needed to reach the end of the array
void jump(struct data data, int n) {
    int jumps = 0;
    int current = 0;

    // Continue jumping until the end of the array is reached
    while (current < n - 1) {
        int max_jump = data.arr[current];

        if (max_jump == 0) {
            printf("Not Possible");
            return;
        }

        int next = current;
        int max_reachable = 0;

        // Find the next position to jump to by considering possible jumps
        for (int i = 1; i <= max_jump; i++) {
            if (current + i >= n - 1) {
                next = current + i;
                break;
            }

            // Update the maximum reachable position based on the jump
            if (data.arr[current + i] + i > max_reachable) {
                max_reachable = data.arr[current + i] + i;
                next = current + i;
            }
        }

        // Move to the next position and increment the jump count
        current = next;
        jumps++;
    }

    printf("%d", jumps);
}
