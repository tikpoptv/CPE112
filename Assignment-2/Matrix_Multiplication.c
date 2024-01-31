// Matrix Multiplication
// Now that we have learned about multi-dimensional arrays, we will apply the knowledge to solve this problem. Matrix multiplication, also known as matrix product or multiplication of two matrices, creates a single matrix. It's a type of binary operation, in which if A and B are two matrices, the product of the two matrices can be expressed as X = AB. Not only that, the matrix can be multiplied if and only if their dimensions are compatible. For instance, if A = [aij] is a m × n  matrix and B = bij is a n × p  matrix. AB = cij, where cij = ai1b1j + ai2b2j + ai3b3j + … + ainbnj.

// Hints:
// Multiplication of two matrices is done by multiplying corresponding elements from the rows of the first matrix with the corresponding elements from the columns of the second matrix and then adding these products.
// The number of columns in the first matrix must be equal to the number of rows in the second matrix.
// Input
// The input consists of one line:

// First Line:
// Contains two space-separated integers, m, and n, representing the dimensions of the first matrix A. (1 ≤ m,n ≤ 10)
// Second Line:
// The next m lines each contain n space-separated integers, representing the elements of matrix A. The values are in the range (-1000 ≤ Aij ≤ 1000)
// m + 2nd Line:
// The (m + 2)th line contains two space-separated integers, k, and l, representing the dimensions of the second matrix B. (1 ≤ k,l ≤ 10)
// m + 3 to m + k + 2 Line:
// The next k lines each contain p space-separated integers, representing the elements of matrix B. The values are in the range (-1000 ≤ Bij ≤ 1000)

// Output
// The output consists of one line:

// First Line:
// Number of minimum jumps / “Not Compatible”

#include <stdio.h>
#include <stdlib.h>

struct Matrix_Multiplication
{
    int **matrix1;
    int **matrix2;
};

void jumps();
void Multiplication();

int main() {
    int m1, m2, m3, m4;

    scanf("%d %d", &m1, &m2);
    struct Matrix_Multiplication matrix;
    matrix.matrix1 = (int **)malloc(m1 * sizeof(int *));
    for (int i = 0; i < m1; i++) {
        matrix.matrix1[i] = (int *)malloc(m2 * sizeof(int));
    }

    for (int i = 0; i < m1; i++) {
        for (int j = 0; j < m2; j++) {
            scanf("%d", &matrix.matrix1[i][j]);
        }
    }

    scanf("%d %d", &m3, &m4);
    matrix.matrix2 = (int **)malloc(m3 * sizeof(int *));
    for (int i = 0; i < m3; i++) {
        matrix.matrix2[i] = (int *)malloc(m4 * sizeof(int));
    }

    for (int i = 0; i < m3; i++) {
        for (int j = 0; j < m4; j++) {
            scanf("%d", &matrix.matrix2[i][j]);
        }
    }


    jumps(matrix, m1, m2, m3, m4);

    for (int i = 0; i < m1; i++) { // ทำเพื่อปลดหน่วยคำนวณทีละแถวไม่งั้น เดี๋ยวมัน leak
        free(matrix.matrix1[i]);
    }
    free(matrix.matrix1);

    for (int i = 0; i < m3; i++) {
        free(matrix.matrix2[i]);
    }
    free(matrix.matrix2);

    return 0;
}

void jumps(struct Matrix_Multiplication matrix, int m1, int m2, int m3, int m4) {
    if (m2 != m3) {
        printf("Not Compatible");
        return;
    }

    Multiplication(matrix, m1, m2, m3, m4);
}

void Multiplication(struct Matrix_Multiplication matrix, int m1, int m2, int m3, int m4) {
    int result[m1][m4];

    for (int i = 0; i < m1; i++) {
        for (int j = 0; j < m4; j++) {
            result[i][j] = 0;
            for (int k = 0; k < m2; k++) {
                result[i][j] += matrix.matrix1[i][k] * matrix.matrix2[k][j];
            }
        }
    }

    for (int i = 0; i < m1; i++) {
        for (int j = 0; j < m4; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
}
