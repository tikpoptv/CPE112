#include <stdio.h>
#include <stdlib.h>

int main() {
    int row, col; // Jedsadaporn Pannok 66070503410

    // Read the number of rows and columns from the user
    scanf("%d %d", &row, &col);

    // Check if the matrix is not square
    if (row != col) {
        printf("ERROR\n");
        return 0;
    }

    // Declare a 2D array for the matrix
    int matrix[row][col];

    // Read the elements into the matrix
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Initialize variables for the sums of the primary and secondary diagonals
    int primarySum = 0;
    int secondarySum = 0;

    // Calculate the sums of the primary and secondary diagonals
    for (int i = 0; i < row; i++) {
        primarySum += matrix[i][i];
        secondarySum += matrix[i][col - i - 1];
    }

    // Print the results
    printf("Primary: %d\n", primarySum);
    printf("Secondary: %d\n", secondarySum);

    return 0;
}
