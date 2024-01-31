#include <stdio.h>
#include <stdlib.h>

struct Matrix // Jedsadaporn Pannok 66070503410
{
    int *arr;
};

// Function prototypes
int isSymmetric();
int isskew_symmetric();

int main()
{
    int n, x;
    // Input matrix size
    scanf("%d %d", &n, &x);

//// Declare a struct Matrix variable and allocate memory for the matrix
    struct Matrix matrix;
    matrix.arr = (int *)malloc(n * x * sizeof(int));

    // Input matrix elements
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < x; j++)
        {
            scanf("%d", matrix.arr + i * x + j);
        }
    }

    // Check if matrix is symmetric
    int result = isSymmetric(matrix, n);
    if (result == 1)
    {
        printf("The matrix is symmetric\n");
    }
    else
    {
        // Check if matrix is skew-symmetric
        result = isskew_symmetric(matrix, n);
        if (result == 1)
        {
            printf("The matrix is skew-symmetric\n");
        }
        else
        {
            printf("None\n");
        }
    }

    // Free dynamically allocated memory
    free(matrix.arr);
    return 0;
}

// Function to check if matrix is symmetric
int isSymmetric(struct Matrix matrix, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (*(matrix.arr + i * n + j) != *(matrix.arr + j * n + i))
            {
                return 0; // Not symmetric
            }
        }
    }
    return 1; // Symmetric
}

// Function to check if matrix is skew-symmetric
int isskew_symmetric(struct Matrix matrix, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (*(matrix.arr + i * n + j) != -(*(matrix.arr + j * n + i)))
            {
                return 0; // Not skew-symmetric
            }
        }
    }
    return 1; // Skew-symmetric
}
