#include <stdio.h>
#include <stdlib.h>

struct Spiral_Array_Printer // Jedsadaporn Pannok 66070503410
{
    int *arr;
};

// Function prototypes
// Function prototypes for the spiral array printer and movement functions
void Spiral_Array_Printer();
void moveRight();
void moveDown();
void moveLeft();
void moveUp();

int main(){
    int n, x;
    // Read the dimensions of the arra
    scanf("%d %d", &n, &x);
    // Declare a struct Spiral_Array_Printer variable and allocate memory 
    struct Spiral_Array_Printer data;
    data.arr = (int*)malloc(n * x * sizeof(int));
    // Read the elements of the array
    for(int i = 0; i < n; i++){
        for(int j = 0; j < x; j++){
            scanf("%d", data.arr + i * x + j);
        }
    }
    // Call the Spiral_Array_Printer function to print the array in a spiral order
    Spiral_Array_Printer(data, n, x);

    free(data.arr);
    return 0;
}

// Function to print the spiral array
void Spiral_Array_Printer(struct Spiral_Array_Printer data, int n, int x) {
    int top = 0, bottom = n - 1, left = 0, right = x - 1;
    int direction = 0; // 0: move right, 1: move down, 2: move left, 3: move up

    while (top <= bottom && left <= right) {
        if (direction == 0) {
            moveRight(data, n, x, top, left, right);
            top++;
        } else if (direction == 1) {
            moveDown(data, n, x, top, bottom, right);
            right--;
        } else if (direction == 2) {
            moveLeft(data, n, x, bottom, left, right);
            bottom--;
        } else if (direction == 3) {
            moveUp(data, n, x, top, bottom, left);
            left++;
        }

        direction = (direction + 1) % 4;
    }
}

// Function to move right and print elements
void moveRight(struct Spiral_Array_Printer data, int n, int x, int top, int left, int right) {
    for (int i = left; i <= right; i++) {
        printf("%d ", *(data.arr + top * x + i));
    }
}

// Function to move down and print elements
void moveDown(struct Spiral_Array_Printer data, int n, int x, int top, int bottom, int right) {
    for (int i = top; i <= bottom; i++) {
        printf("%d ", *(data.arr + i * x + right));
    }
}

// Function to move left and print elements
void moveLeft(struct Spiral_Array_Printer data, int n, int x, int bottom, int left, int right) {
    for (int i = right; i >= left; i--) {
        printf("%d ", *(data.arr + bottom * x + i));
    }
}

// Function to move up and print elements
void moveUp(struct Spiral_Array_Printer data, int n, int x, int top, int bottom, int left) {
    for (int i = bottom; i >= top; i--) {
        printf("%d ", *(data.arr + i * x + left));
    }
}