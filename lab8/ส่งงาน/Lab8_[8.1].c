#include<stdio.h> // jedsadaporn pannok 66070503410
#include<string.h>

// Definition of MinHeap data structure
typedef struct {
    int arr[100]; // Array to store heap elements
    int size;     // Current size of the heap
} MinHeap;

void swap(int *a, int *b);
void heapify(MinHeap *heap, int index);
int leftChild(int i);
int rightChild(int i);
void insertion(MinHeap *heap, int value);
void deletion(MinHeap *heap, int value);
void printHeap(MinHeap *heap);

int main() {
    MinHeap heap;
    heap.size = 0;

    char input[10];
    int data;

    do {
        // Read the command from user
        scanf("%s", input);
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
    } while (strcmp(input, "EXIT") != 0);

    return 0;
}

// Function to swap two integers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to heapify the MinHeap
void heapify(MinHeap *heap, int index) {
    int smallest = index;

    // Check left and right child values
    if (2 * index + 1 < heap->size && heap->arr[2 * index + 1] < heap->arr[smallest])
        smallest = 2 * index + 1;

    if (2 * index + 2 < heap->size && heap->arr[2 * index + 2] < heap->arr[smallest])
        smallest = 2 * index + 2;

    // If smallest is not the current index, swap and recursively heapify
    if (smallest != index) {
        swap(&heap->arr[index], &heap->arr[smallest]);
        heapify(heap, smallest);
    }
}

// Function to get the left child index of a node
int leftChild(int i) {
    return 2 * i + 1;
}

// Function to get the right child index of a node
int rightChild(int i) {
    return 2 * i + 2;
}

// Function to insert an element into the MinHeap
void insertion(MinHeap *heap, int value) {
    if (heap->size >= 100) {
        // Heap is full, cannot insert
        return;
    }

    int index = heap->size;
    heap->arr[index] = value;
    heap->size++;

    // Adjust the heap by moving the inserted element upwards
    while (index > 0 && heap->arr[index] < heap->arr[(index - 1) / 2]) {
        swap(&heap->arr[index], &heap->arr[(index - 1) / 2]);
        index = (index - 1) / 2;
    }
}

// Function to delete an element from the MinHeap
void deletion(MinHeap *heap, int value) {
    int found = 0, i;
    // Search for the value in the heap
    for (i = 0; i < heap->size; i++) {
        if (heap->arr[i] == value) {
            found = 1;
            break;
        }
    }

    if (!found) {
        // Value not found in heap
        return;
    }
    // Swap the value with the last element and decrease heap size
    swap(&heap->arr[i], &heap->arr[heap->size - 1]);
    heap->size--;
    // Heapify the heap starting from the root
    for (i = (heap->size / 2) - 1; i >= 0; i--) {
        heapify(heap, i);
    }
}

// Function to print the elements of the MinHeap
void printHeap(MinHeap *heap) {
    for (int i = 0; i < heap->size; ++i)
        printf("%d ", heap->arr[i]);
    printf("\n");
}