#include <stdio.h>
#include <stdlib.h>

struct Matrix_Multiplication // Jedsadaporn Pannok 66070503410
{
    int **matrix1;
    int **matrix2;
};
// Function prototype
void jumps();  
void Multiplication();

int main() {
    int m1, m2, m3, m4;

    // Input the dimensions of the first matrix
    scanf("%d %d", &m1, &m2);

    // Allocate memory for the first matrix
    struct Matrix_Multiplication matrix;
    matrix.matrix1 = (int **)malloc(m1 * sizeof(int *));
    for (int i = 0; i < m1; i++) {
        matrix.matrix1[i] = (int *)malloc(m2 * sizeof(int));
    }

    // Input the elements of the first matrix
    for (int i = 0; i < m1; i++) {
        for (int j = 0; j < m2; j++) {
            scanf("%d", &matrix.matrix1[i][j]);
        }
    }

    // Input the dimensions of the second matrix
    scanf("%d %d", &m3, &m4);

    // Allocate memory for the second matrix
    matrix.matrix2 = (int **)malloc(m3 * sizeof(int *));
    for (int i = 0; i < m3; i++) {
        matrix.matrix2[i] = (int *)malloc(m4 * sizeof(int));
    }

    // Input the elements of the second matrix
    for (int i = 0; i < m3; i++) {
        for (int j = 0; j < m4; j++) {
            scanf("%d", &matrix.matrix2[i][j]);
        }
    }

    // Call the jumps function to perform matrix multiplication
    jumps(matrix, m1, m2, m3, m4);

    // Free the memory allocated for the matrices
    for (int i = 0; i < m1; i++) {
        free(matrix.matrix1[i]);  // ทำเพื่อปลดหน่วยคำนวณทีละแถวไม่งั้น เดี๋ยวมัน leak
    }
    free(matrix.matrix1);

    for (int i = 0; i < m3; i++) {
        free(matrix.matrix2[i]);
    }
    free(matrix.matrix2);

    return 0;
}

void jumps(struct Matrix_Multiplication matrix, int m1, int m2, int m3, int m4) {
    // Check if the matrices are compatible for multiplication
    if (m2 != m3) {
        printf("Not Compatible");
        return;
    }

    // Call the Multiplication function to perform matrix multiplication
    Multiplication(matrix, m1, m2, m3, m4);
}

void Multiplication(struct Matrix_Multiplication matrix, int m1, int m2, int m3, int m4) {
    // Create a result matrix to store the multiplication result
    int result[m1][m4];

    // Perform matrix multiplication
    for (int i = 0; i < m1; i++) {
        for (int j = 0; j < m4; j++) {
            result[i][j] = 0;
            for (int k = 0; k < m2; k++) {
                result[i][j] += matrix.matrix1[i][k] * matrix.matrix2[k][j];
            }
        }
    }

    // Print the result matrix
    for (int i = 0; i < m1; i++) {
        for (int j = 0; j < m4; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
}