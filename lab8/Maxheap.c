#include<stdio.h>
#include<string.h>

typedef struct {
    int arr[100];
    int size;
} MinHeap;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(MinHeap *heap, int index) {
    int smallest = index;

    if (2 * index + 1 < heap->size && heap->arr[2 * index + 1] < heap->arr[smallest])
        smallest = 2 * index + 1;

    if (2 * index + 2 < heap->size && heap->arr[2 * index + 2] < heap->arr[smallest])
        smallest = 2 * index + 2;

    if (smallest != index) {
        swap(&heap->arr[index], &heap->arr[smallest]);
        heapify(heap, smallest);
    }
}

int leftChild(int i) {
    return 2 * i + 1;
}

int rightChild(int i) {
    return 2 * i + 2;
}

void insertion(MinHeap *heap, int value) {
    if (heap->size >= 100) {
       // printf("Heap is full. Cannot insert.\n");
        return;
    }

    int index = heap->size;
    heap->arr[index] = value;
    heap->size++;

    while (index > 0 && heap->arr[index] < heap->arr[(index - 1) / 2]) {
        swap(&heap->arr[index], &heap->arr[(index - 1) / 2]);
        index = (index - 1) / 2;
    }
}

void deletion(MinHeap *heap, int value) {
    int found = 0, i;
    for (i = 0; i < heap->size; i++) {
        if (heap->arr[i] == value) {
            found = 1;
            break;
        }
    }

    if (!found) {
       // printf("Value not found in heap.\n");
        return;
    }
    swap(&heap->arr[i], &heap->arr[heap->size - 1]);
    heap->size--;
    for (i = (heap->size / 2) - 1; i >= 0; i--) {
        heapify(heap, i);
    }
}

void printHeap(MinHeap *heap) {
    for (int i = 0; i < heap->size; ++i)
        printf("%d ", heap->arr[i]);
    printf("\n");
}

int main() {
    MinHeap heap;
    heap.size = 0;

    char input[10];
    int data;

    do {
        scanf("%s", input);
        if (strcmp(input, "INSERT") == 0) {
            while (scanf("%d", &data) == 1)
                insertion(&heap, data);
        } else if (strcmp(input, "DELETE") == 0) {
            scanf("%d", &data);
            deletion(&heap, data);
        } else if (strcmp(input, "PRINT") == 0) {
            printHeap(&heap);
        } else if (strcmp(input, "EXIT") != 0) {
            printf("INVALID\n");
        }
    } while (strcmp(input, "EXIT") != 0);

    return 0;
}
