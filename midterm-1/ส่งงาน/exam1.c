#include <stdlib.h> // jedsadaporn Pannok N0.66070503410
#include <stdio.h>
struct sortedset
{
    int *elements;
    int size;
};

// Function prototypes
void init(struct sortedset *s, int size); // BIG O = O(n)
int checkDuplicate(struct sortedset *s, int target);  // BIG O = O(n)
void insertElement(struct sortedset *s, int newNum); // BIG O = O(n)
void printArray(struct sortedset *s); // BIG O = O(n)

int main() // BIG O = O(n^2)
{
    struct sortedset set;
    int n, i, num; // 
    scanf("%d", &n);
    init(&set, n); // Initialize the sorted set with n elements
    for (i = 0; i < n; i++) // Loop through n elements
    {
        scanf("%d", &num);
        if (checkDuplicate(&set, num) == 0) // If the element is not a duplicate
        {
            insertElement(&set, num); // Insert the element into the set
        }
    }
    printArray(&set); // Print the set
    return 0;
}

// Function definitions
void init(struct sortedset *s, int size) // BIG O = O(n)
{
    s->elements = (int *)malloc(size * sizeof(int)); // Allocate memory for the elements
    s->size = 0; // size of the set to 0
}

int checkDuplicate(struct sortedset *s, int check) // BIG O = O(n)
{
    int i;
    // Loop through the elements of the set and see if there's any duplicates
    for (i = 0; i < s->size; i++)
    {
        if (s->elements[i] == check)// If the element is a duplicate
        {
            return 1;// return 1
        }
    }
    return 0;
}

// Insert the new element into the set in sorted order
void insertElement(struct sortedset *s, int newNum) // BIG O = O(n)
{
    int i, j;
    // Find the position to insert the new element
    for (i = 0; i < s->size; i++)
    {
        if (s->elements[i] > newNum) // If the element is greater than the new element
        {
            break;// break
        }
    }
    // Shift the elements to the right to make space for the new element
    for (j = s->size; j > i; j--)
    {
        s->elements[j] = s->elements[j - 1];// Shift the elements to the right
    }
    s->elements[i] = newNum;
    s->size++;
}

void printArray(struct sortedset *s) // BIG O = O(n)
{
    int i;
    printf("%d\n", s->size);// Print the size of the set
    printf("{");// Print the elements of the set
    for (i = 0; i < s->size; i++) // Loop through the elements of the set
    {
        printf("%d", s->elements[i]);
        if (i < s->size - 1)
        {
            printf(", ");
        }
    }
    printf("}");
}


