#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    int row, col;
    scanf("%d %d", &row, &col);

    if (row != col) {
        printf("ERROR\n");
        return 0;
    }

    int matrix[row][col];
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int primarySum = 0;
    int secondarySum = 0;
    for (int i = 0; i < row; i++) {
        primarySum += matrix[i][i];
        secondarySum += matrix[i][col - i - 1];
    }

    printf("Primary: %d\n", primarySum);
    printf("Secondary: %d\n", secondarySum);

    return 0;
}
