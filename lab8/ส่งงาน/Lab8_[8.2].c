#include <stdio.h>
#include <string.h> //jedsadaporn pannok 66070503410

// Define a struct for the heap
typedef struct {
    int arr[100]; // Array to store heap elements
    int size;     // Current size of the heap
} Heap;

// Function prototypes
void swap(int *a, int *b);
void heapify(Heap *heap, int i);
int leftChild(int i);
int rightChild(int i);
void insertion(Heap *heap, int value);
void deletion(Heap *heap, int value);
void printHeap(Heap *heap);

int main() {
    Heap heap;
    heap.size = 0; // Initialize the heap size to 0

    char input[10];
    int data;

    do {
        scanf("%s", input); // Read command from user
        if (strcmp(input, "INSERT") == 0) {
            // Insert elements into the heap
            while (scanf("%d", &data) == 1)
                insertion(&heap, data);
        } else if (strcmp(input, "DELETE") == 0) {
            // Delete an element from the heap
            scanf("%d", &data);
            deletion(&heap, data);
        } else if (strcmp(input, "PRINT") == 0) {
            // Print the elements of the heap
            printHeap(&heap);
        } else if (strcmp(input, "EXIT") != 0) {
            // Invalid command
            printf("INVALID\n");
        }
    } while (strcmp(input, "EXIT") != 0); // Continue until user inputs "EXIT"

    return 0;
}

// Function to swap two integers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to heapify the heap
void heapify(Heap *heap, int index) {
    int largest = index;

    if (leftChild(index) < heap->size && heap->arr[leftChild(index)] > heap->arr[largest])
        largest = leftChild(index);

    if (rightChild(index) < heap->size && heap->arr[rightChild(index)] > heap->arr[largest])
        largest = rightChild(index);

    if (largest != index) {
        // Swap values and recursively heapify
        swap(&heap->arr[index], &heap->arr[largest]);
        heapify(heap, largest);
    }
}

// Function to get the index of the left child
int leftChild(int i) {
    return 2 * i + 1;
}

// Function to get the index of the right child
int rightChild(int i) {
    return 2 * i + 2;
}

// Function to insert an element into the heap
void insertion(Heap *heap, int value) {
    int i;
    if (heap->size == 0) {
        // If heap is empty, insert at index 0
        heap->arr[0] = value;
        heap->size += 1;
    } else {
        // Otherwise, insert at the end and heapify
        heap->arr[heap->size] = value;
        heap->size += 1;
        for (i = (heap->size / 2) - 1; i >= 0; i--)
            heapify(heap, i);
    }
}

// Function to delete an element from the heap
void deletion(Heap *heap, int value) {
    int found = 0, i;
    // Search for the value in the heap
    for (i = 0; i < heap->size; i++) {
        if (heap->arr[i] == value) {
            found = 1;
            break;
        }
    }

    if (!found)
        return; // Value not found

    // Swap with last element and decrease heap size
    swap(&heap->arr[i], &heap->arr[heap->size - 1]);
    heap->size -= 1;
    // Re-heapify from the root
    for (i = (heap->size / 2) - 1; i >= 0; i--)
        heapify(heap, i);
}

// Function to print the elements of the heap
void printHeap(Heap *heap) {
    for (int i = 0; i < heap->size; ++i)
        printf("%d ", heap->arr[i]);
    printf("\n");
}
