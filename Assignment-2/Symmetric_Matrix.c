// Symmetric Matrix
// A matrix is an arrangement of numbers into rows and columns. Which one of the properties of the matrix is symmetric matrix, it is a matrix that has equal value to its transpose (BT = B).

// For example:


// On top of that, a skew-symmetric matrix is when the matrix has an equal opposite value to its transpose matrix (BT = -B), but when i = j, Bij needs to be 0.

// For example:



// Further information can be found via: https://byjus.com/maths/what-is-symmetric-matrix-and-skew-symmetric-matrix/

// Now that the essential information has been introduced, here is the assignment.

// Use multi-dimensional array to construct a matrix and find whether it is a “symmetric matrix” or “skew-symmetric matrix”. Moreover, in case that the matrix is neither a symmetric matrix nor a skew-symmetric matrix, print “None”.

// So, the Output will be in Three Scenarios:

// If the matrix is symmetric, the output will be “The matrix is symmetric”
// If the matrix is skew-symmetric, the output will be “The matrix is skew-symmetric”
// If the matrix is neither symmetric matrix nor skew-symmetric, the output will be “None”
// Input
// The input consists of:

// First Line:
// Two integers m,n in which -10,000 ≤ m, n ≤ 10,000 as the columns (m) and the rows (n) of the matrix

// Second Line:
// List of “m” elements in the first row (separated by “ ”)

// Third Line:
// List of “m” elements in the second row (separated by “ ”)

// nth Line:
// List of “m” elements in the n row (separated by “ ”)

// Output
// The output consists of:

// First Line:
// The result of the matrix


#include <stdio.h>

int main(){
    int n;
    scanf("%d",&n);

    int matrix[n][n];
    
}