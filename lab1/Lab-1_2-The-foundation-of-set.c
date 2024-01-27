// Input
// The input consists of five lines
// First Line:
// Two integers m,n in which -10,000 ≤ m < n ≤ 10,000 as the range of the universe.
// Second Line:
// An integer p in which 0 ≤ p ≤100, stating the number of elements in an array A
// Thrid Line:
// A sequence of non-decreasing order array A of integer a1,a2 … ap separating between element with a whitespace.
// Fourth Line:
// An integer q in which 0 ≤ q ≤ 100, stating the number of elements in an array B
// Fifth Line:
// A sequence of non-decreasing order array B of integer b1,b2 … bq separating between element with a whitespace.

// Output
// First Line:
// The set SA which is equivalent to array A and is a subset of universe
// Second Line:
// The set SB which is equivalent to array B and is a subset of universe
// Third Line:
// The result from applying “Union” (SA∪SB)
// Fourth Line:
// The result from applying “Intersection” (SA∩SB)
// Fifth Line:
// The result from applying “Difference” (SA-SB)
// Sixth Line:
// The result from applying “Difference” (SB-SA)
// Seventh Line:
// The result from applying “Complement” (SA)'
// Eighth Line:
// The result from applying “Complement” (SB)'

#include <stdio.h>

// int subset();
//I'll just call the function because I like to write it below.
void subset(int arr[], int size, int n1, int n2, int output[], int *outputSize);
void Union(int subset1[], int size_subset1, int subset2[], int size_subset2);
void Intersection(int subset1[], int size_subset1, int subset2[], int size_subset2);
void Difference(int subset1[], int size_subset1, int subset2[], int size_subset2);
void Complement(int n1, int n2, int subset[], int size_subset);

int main(void) {
    int n1, n2, inputset1, inputset2;

    //n1 and n2 are used to define the boundaries of the set.
    //inputset1 and inputset2 are used to define the size of the set.
    //set1 and set2 are used to store the set.

    scanf("%d %d", &n1, &n2);
    //Set the scope of the set
    scanf("%d", &inputset1);
     //set1 and set2 are used to store the set.
    int set1[inputset1];
    //loop to fill in values
    for (int i = 0; i < inputset1; i++) {
        scanf("%d", &set1[i]);
    }

    scanf("%d", &inputset2);
    int set2[inputset2];
    for (int i = 0; i < inputset2; i++) {
        scanf("%d", &set2[i]);
    }
    //Create a subset variable to store subsets instead of sets to make it easier to use.
    int subset1[inputset1];
    //size_subset1 is used to store the size of the subset.
    int size_subset1;
    //Call the subset function to find the subset of the set.
    subset(set1, inputset1, n1, n2, subset1, &size_subset1);

    int subset2[inputset2];
    int size_subset2;
    subset(set2, inputset2, n1, n2, subset2, &size_subset2);


    // Print the subset If the value returned from the subset function has a value of size_subset = 0, assume that there is no value and return empty.
    if (size_subset1 == 0) {
        printf("empty\n");
    } else {
        for (int i = 0; i < size_subset1; i++) {
            printf("%d ", subset1[i]);
        }
        printf("\n");
    }
    // Print the subset If the value returned from the subset function has a value of size_subset = 0, assume that there is no value and return empty.
    if (size_subset2 == 0) {
        printf("empty\n");
    } else {
        for (int i = 0; i < size_subset2; i++) {
            printf("%d ", subset2[i]);
        }
        printf("\n");
    }

    //Call the Union function to find the union between subset1 and subset2.
    Union(subset1,size_subset1,subset2,size_subset2);
    //Call the Intersection function to find the Intersection between subset1 and subset2.
    Intersection(subset1,size_subset1,subset2,size_subset2);
    //Call the Union Difference to find the Difference between subset1 and subset2.
    Difference(subset1,size_subset1,subset2,size_subset2);
    //Call the Union Difference to find the Difference between subset2 and subset1.
    Difference(subset2,size_subset2,subset1,size_subset1);
    //Call the Complement function to find missing numbers n1 through n2 in subset1.
    Complement(n1,n2,subset1,size_subset1);
    //Call the Complement function to find missing numbers n1 through n2 in subset2.
    Complement(n1,n2,subset2,size_subset2);
    return 0;
}
// Function to find the subset of elements in the range [n1, n2]
void subset(int arr[], int size, int n1, int n2, int output[], int *outputSize) {
    //set is used to store the subset.
    int set[size], n = 0;
    //loop to find the subset.
    for (int i = 0; i < size; i++) {
        //If the value is in the range of n1 to n2, it will be stored in the set.
        if (arr[i] >= n1 && arr[i] <= n2) {
            int present = 0;
            //loop to check if the value is already in the set.
            for (int j = 0; j < n; j++) {
                if (arr[i] == set[j]) {
                    present = 1;
                    break;
                }
            }
            //If the value is not in the set, it will be stored in the set.
            if (!present) {
                set[n++] = arr[i];
            }
        }
    }
    //If the value is in the range of n1 to n2, it will be stored in the set.
    *outputSize = n;
    //loop to store the value in the output.
    for (int i = 0; i < n; i++) {
        output[i] = set[i];
        // printf("%d ", output[i]);
    }
}
// Function to find the union of two sets
void Union(int subset1[], int size_subset1, int subset2[], int size_subset2) {
    //unionSet is used to store the union of subset1 and subset2.
    int unionSet[size_subset1 + size_subset2];
    //unionSize is used to store the size of the unionSet.
    int unionSize = 0;
    //loop to find the union of subset1 and subset2.
    for (int i = 0; i < size_subset1; i++) {
        unionSet[unionSize++] = subset1[i];
    }
    for (int i = 0; i < size_subset2; i++) {
        int present = 0;

        for (int j = 0; j < unionSize; j++) {
            if (subset2[i] == unionSet[j]) {
                present = 1;
                break;
            }
        }
        //If the value is not in the unionSet, it will be stored in the unionSet.
        if (!present) {
            unionSet[unionSize++] = subset2[i];
        }
    }
    //If the value is in the range of n1 to n2, it will be stored in the set.
    if (unionSize == 0) {
        printf("empty\n");
    } else {
        //loop to sort the value in the unionSet.
        for (int i = 0; i < unionSize; i++)
        {
            for (int j = 0; j < unionSize; j++)
            {
                if (unionSet[j] > unionSet[i])  
                {
                    int temp = unionSet[i];
                    unionSet[i] = unionSet[j];
                    unionSet[j] = temp;
                }
            }
        }
        for (int i = 0; i < unionSize; i++) {
            printf("%d ", unionSet[i]);
        }
        printf("\n");
    }

}
 // Function to find the intersection of two sets   
void Intersection(int subset1[], int size_subset1, int subset2[], int size_subset2) {
    int intersectionSet[size_subset1 + size_subset2];
    int intersectionSize = 0;
    //loop to find the intersection of subset1 and subset2.
    for (int i = 0; i < size_subset1; i++) {
        for (int j = 0; j < size_subset2; j++) {
            if (subset1[i] == subset2[j]) {
                intersectionSet[intersectionSize++] = subset1[i];
                break;
            }
        }
    }
    //If the value is in the range of n1 to n2, it will be stored in the set.
    if (intersectionSize == 0) {
        printf("empty\n");
    } else {
        //loop to sort the value in the intersectionSet.
        for (int i = 0; i < intersectionSize; i++) {
            printf("%d ", intersectionSet[i]);
        }
        printf("\n");
    }
}
// Function to find the set difference (subset1 - subset2)
void Difference(int subset1[], int size_subset1, int subset2[], int size_subset2) {
    int differenceSet[size_subset1];
    int differenceSize = 0;
    //loop to find the difference of subset1 and subset2.
    for (int i = 0; i < size_subset1; i++) {
        int present = 0;

        for (int j = 0; j < size_subset2; j++) {
            if (subset1[i] == subset2[j]) {
                present = 1;
                break;
            }
        }
        if (!present) {
            differenceSet[differenceSize++] = subset1[i];
        }
    }
    //If the value is in the range of n1 to n2, it will be stored in the set.
    if (differenceSize == 0) {
        printf("empty\n");
    } else {
        for (int i = 0; i < differenceSize; i++) {
            printf("%d ", differenceSet[i]);
        }
        printf("\n");
    }
}
// Function to find the complement of a set in the range [n1, n2]
void Complement(int n1, int n2, int subset[], int size_subset) {
    int complementSet[n2 - n1 + 1];
    int complementSize = 0;
    //loop to find the complement of subset.
    for (int i = n1; i <= n2; i++) {
        //If the value is not in the subset, it will be stored in the complementSet.
        int present = 0;
        for (int j = 0; j < size_subset; j++) {
            if (subset[j] == i) {
                present = 1;
                break;
            }
        }
        if (present == 0) {
            complementSet[complementSize++] = i;
        }
    }
    //If the value is in the range of n1 to n2, it will be stored in the set.
    if (complementSize == 0) {
        printf("empty\n");
    } 
    else {
        //loop to sort the value in the complementSet.
        for (int i = 0; i < complementSize; i++) {
            printf("%d ", complementSet[i]);
        }
        printf("\n");
    }
}
