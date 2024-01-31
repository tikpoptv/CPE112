// Spiral Array Printer
// The Spiral Array Printer problem in this code involves reading input from the user to determine the dimensions of a 2D array (num1 and num2) and then reading data from the user to populate the 2D array (arr[num1][num2]). The program is designed to print the array data in a spiral order, following the specified pattern in the problem.



// Hints
// Draw the path that the spiral makes. We know that the path should turn clockwise whenever it goes out of bounds or into an index that was previously visited!!!

// Input
// The input consists of two lines:

// First Line:
// Two integers in which as the row and column
// Second Line:
// Enter numbers into the matrix

// Output
// The output consists of one line:

// First Line:
// An output of spiral array printer

#include <stdio.h>
#include <stdlib.h>

struct Spiral_Array_Printer
{
    int *arr;
};

void Spiral_Array_Printer();
void moveRight();
void moveDown();
void moveLeft();
void moveUp();

int main(){
    int n, x;
    scanf("%d %d", &n, &x);
    struct Spiral_Array_Printer data;
    data.arr = (int*)malloc(n * x * sizeof(int));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < x; j++){
            scanf("%d", data.arr + i * x + j);
        }
    }

    Spiral_Array_Printer(data, n, x);


    free(data.arr);
    return 0;
}
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




void moveRight(struct Spiral_Array_Printer data, int n, int x, int top, int left, int right) {
    for (int i = left; i <= right; i++) {
        printf("%d ", *(data.arr + top * x + i));
    }
}

void moveDown(struct Spiral_Array_Printer data, int n, int x, int top, int bottom, int right) {
    for (int i = top; i <= bottom; i++) {
        printf("%d ", *(data.arr + i * x + right));
    }
}

void moveLeft(struct Spiral_Array_Printer data, int n, int x, int bottom, int left, int right) {
    for (int i = right; i >= left; i--) {
        printf("%d ", *(data.arr + bottom * x + i));
    }
}

void moveUp(struct Spiral_Array_Printer data, int n, int x, int top, int bottom, int left) {
    for (int i = bottom; i >= top; i--) {
        printf("%d ", *(data.arr + i * x + left));
    }
}



