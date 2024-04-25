#include <stdio.h>
#include <stdlib.h>

// Define a structure for input data
struct input {
    int size;
    int *arry;
};// Jedsadaporn Pannok 66070503410

int main() {
    // Declare a variable of type struct input
    struct input input;

    // Read the size of the array from the user
    scanf("%d", &input.size);
    
    // Allocate memory for the array based on the input size
    input.arry = (int*)malloc(input.size * sizeof(int));

    // Read elements into the array
    for(int i = 0; i < input.size; i++) {
        scanf("%d", input.arry + i);
    }
    
    // Read the mode 
    int mode;
    scanf("%d", &mode);

    // Initialize a variable for checking if any elements are printed
    int check = 0;

    // Print elements based on the specified mode
    if (mode == 0) {
        // Print elements at even indices
        for (int i = 0; i < input.size; i += 2) {
            printf("%d ", *(input.arry + i));
            check++;
        }
    } else {
        // Print elements at odd indices
        for (int i = 1; i < input.size; i += 2) {
            printf("%d ", *(input.arry + i));
            check++;
        }
    }

    // If no elements are printed print none
    if (check == 0) {
        printf("none");
    }

    // Free the allocated memory for the array
    free(input.arry);

    return 0;
}
