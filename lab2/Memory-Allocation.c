// In C programming, memory can be allocated in two ways: stack memory and heap memory. Stack memory is limited and is used to store local variables and function call information. Heap memory, on the other hand, is slower but provides more flexibility as it can be dynamically allocated and deallocated during runtime.

// Two functions that allocate memory in heap memory are malloc() and calloc(). malloc() allocates a single block of memory with the specified size, while calloc() allocates multiple blocks of memory with the specified size. Both functions return a pointer to the first byte of the allocated memory.

// If you need to reallocate the size of memory you allocated before, you can use the realloc() function. This function changes the size of the memory block pointed to by the pointer to the new size specified.
// It’s important to note that after you’re done using the allocated memory, you should free it using the free() function. This ensures that the memory is returned to the operating system and can be used by other programs.

// Output
// The output consists of

// First Line: A result from summation of 1 – 1,000,000.
// Second Line: A result from difference of 1 – 1,000,000.
// Example
// Input
//	
// Output
// 500000500000
// -500000500000




#include <stdio.h>
#include <stdlib.h>

int main() {
    int* arr1 = (int*)malloc(1000000 * sizeof(int));
    int* arr2 = (int*)calloc(1000000, sizeof(int));

    long long sum = 0;
    long long diff = 0;

    for (int i = 0; i < 1000000; i++) {
        arr1[i] = i + 1;
        arr2[i] = i + 1;
        sum += arr1[i];
        diff -= arr2[i];
    }

    printf("%lld\n", sum);
    printf("%lld\n", diff);

    free(arr1);
    free(arr2);

    return 0;
}
