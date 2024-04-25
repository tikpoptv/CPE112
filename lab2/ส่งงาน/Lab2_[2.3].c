#include <stdio.h>
#include <stdlib.h>

#define Maxnum 1000000 // Jedsadaporn Pannok 66070503410

int main() {
    char c;

    // Read a character from the user
    scanf("%c", &c);

    // Allocate memory for two arrays with Maxnum elements
    int* arr1 = (int*)malloc(Maxnum * sizeof(int));
    int* arr2 = (int*)calloc(Maxnum, sizeof(int));

    // Initialize variables for sum and diff
    long long sum = 0;
    long long diff = 0;

    // Populate arr1 and arr2 with values from 1 to Maxnum
    for (int i = 0; i < Maxnum; i++) {
        arr1[i] = i + 1;
        arr2[i] = i + 1;

        // Calculate the sum of arr1 and the negation of the sum of arr2
        sum += arr1[i];
        diff -= arr2[i];
    }

    
    printf("%lld \n", sum);
    printf("%lld \n", diff);

    free(arr1);
    free(arr2);

    return 0;
}
