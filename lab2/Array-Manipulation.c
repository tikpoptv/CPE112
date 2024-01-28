// input:
// n1: An integer representing the number of elements in the first array (array1).
// Array1: n1 integers representing the elements of the first array.
// n2: An integer representing the number of elements in the second array (array2).
// Array2: n2 integers representing the elements of the second array.
// i_insert: An integer representing the index in array1 where an insertion operation is to be performed.
// insert_value: An integer to be inserted at the specified index in array1.
// i_delete: An integer representing the index in array1 where a deletion operation is to be performed.
// Output:
// Result array from insertion operation: The first line should contain the modified array1 after the insertion operation.
// Result array from deletion operation: The second line should contain the modified array1 after the deletion operation.
// Result array from merge operation: The third line should contain the merged array of array1 and array2.

#include <stdio.h>
#include <stdlib.h>
// Jedsadaporn Pannok 66070503410
struct input
{
    int size_set;
    int *set;
};

// Create a function above to be called later.
void insertion();
void deletion();
void merge();

int main(void)
{  
    // Declare a variable of type struct input.
    struct input set1;
    struct input set2;
    // Declare variables to store the input.
    int i_insert, insert_value, i_delete;

    // Read the input and store it in the declared variables.
    scanf("%d",&set1.size_set);
    // Allocate memory for the array.
    set1.set = (int*)malloc(set1.size_set*sizeof(int));
    // Read the input and store it in the array.
    for(int i = 0; i < set1.size_set; i++){
        scanf("%d",set1.set + i);
    }
    // Read the input and store it in the declared variables.
    scanf("%d",&set2.size_set);
    // Allocate memory for the array.
    set2.set = (int*)malloc(set2.size_set*sizeof(int));

    //printf("size_set2 = %d",input.size_set2);

    for(int i = 0; i < set2.size_set; i++){
        scanf("%d",set2.set + i);
    }

    // Read the input and store it in the declared variables.
    scanf("%d",&i_insert);   
    scanf("%d",&insert_value);
    scanf("%d",&i_delete);

    // Call the function to perform the operations.
    insertion(set1.set, &set1.size_set, i_insert, insert_value);
   // printf("size_set = %d",set1.size_set);
    deletion(set1.set, &set1.size_set,i_delete);
    
    merge(set1.set, set2.set, set1.size_set, set2.size_set);

}

// Implement the functions here.
// Function to insert a value at a specific position in an array
void insertion(int *input, int *sizeset, int posi, int value) {

    // Allocate memory for a temporary array with increased size
    int *temp = (int*)malloc((*sizeset + 1) * sizeof(int));

    // Copy elements from the original array to the temporary array
    for (int i = 0; i < *sizeset + 1; i++) {
        if (i < posi) {
            // Copy elements before the insertion position
            *(temp + i) = *(input + i);
        } else if (i == posi) {
            // Insert the new value at the specified position
            *(temp + i) = value;
        } else {
            // Copy elements after the insertion position, shifting one position to the right
            *(temp + i) = *(input + i - 1);
        }
    }

    // Print the elements of the temporary array (for debugging or verification)
    for (int i = 0; i < *sizeset + 1; i++) {
        printf("%d ", *(temp + i));
    }

    // Copy elements back from the temporary array to the original array
    for (int i = 0; i < *sizeset + 1; i++) {
        *(input + i) = *(temp + i);
    }

    // Update the size of the array
    *sizeset = *sizeset + 1;

    // Free the memory allocated for the temporary array
    free(temp);

    // Print a newline character for better output formatting
    printf("\n");
}


// Function to delete an element at a specific position from an array
void deletion(int *input, int *sizeset, int posi) {

    // Check if the index is out of bounds.
    if (posi + 1 > *sizeset) {
        printf("Index out of bounds\n");
        return;
    }

    // Allocate memory for a temporary array with decreased size
    int *temp = (int*)malloc((*sizeset - 1) * sizeof(int));

    // Copy elements from the original array to the temporary array, skipping the deleted element
    for (int i = 0; i < *sizeset - 1; i++) {
        if (i < posi) {
            // Copy elements before the deletion position
            *(temp + i) = *(input + i);
        } else {
            // Skip the element at the deletion position by copying the next element
            *(temp + i) = *(input + i + 1);
        }
    }

    // Print the elements of the temporary array (for debugging or verification)
    for (int i = 0; i < *sizeset - 1; i++) {
        printf("%d ", *(temp + i));
    }

    // Copy elements back from the temporary array to the original array
    for (int i = 0; i < *sizeset - 1; i++) {
        *(input + i) = *(temp + i);
    }

    // Update the size of the array
    *sizeset = *sizeset - 1;

    // Free the memory allocated for the temporary array
    free(temp);

    // Print a newline character for better output formatting
    printf("\n");
}

// Merge data from input1 and input2 into the temporary array temp
void merge(int *input1, int *input2, int sizeset1, int sizeset2) {

    // Allocate memory for the temporary array temp
    int *temp = (int*)malloc((sizeset1 + sizeset2) * sizeof(int));

    // Copy data from input1 and input2 to temp
    for (int i = 0; i < sizeset1 + sizeset2; i++) {
        if (i < sizeset1) {
            // Copy data from input1 if position i is less than sizeset1
            *(temp + i) = *(input1 + i);
        } else {
            // Copy data from input2 if position i is greater than or equal to sizeset1
            *(temp + i) = *(input2 + i - sizeset1);
        }
    }

    // Print data in the temp array (for verification)
    for (int i = 0; i < sizeset1 + sizeset2; i++) {
        printf("%d ", *(temp + i));
    }

    // Free the memory allocated for temp
    printf("\n");
    free(temp);
}
