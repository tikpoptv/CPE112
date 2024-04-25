#include <stdio.h>
#include <stdlib.h>

struct input {
    int size;
    int *arr;
};// Jedsadaporn Pannok 66070503410

// Declare the output function
void output(int input, int posi);

int main(void) {
    // Declare a variable of type struct input
    struct input input;
    
    // Read the size of the array from the user
    scanf("%d", &input.size);
    
    // Allocate memory for the array based on the input size
    input.arr = (int*)malloc(input.size * sizeof(int));

    // Read elements into the array
    for(int i = 0; i < input.size; i++) {
        scanf("%d", input.arr + i);
    }

    // Initialize variables for maximum, minimum, and their positions
    int max = *(input.arr),
        min = *(input.arr),
        posimax = 0,
        posimin = 0;

    // Find the maximum and minimum values along with their positions
    for (int i = 0; i < input.size; i++) {
        if (*(input.arr + i) > max) {
            max = *(input.arr + i);
            posimax = i;
        }
        if (*(input.arr + i) < min) {
            min = *(input.arr + i);
            posimin = i;
        }
    }

    // Output the results using the output function
    output(max, posimax);
    output(min, posimin);

    free(input.arr);

    return 0;
}

// Definition of the output function
void output(int input, int posi) {
    printf("%d %d\n", input, posi);
}
