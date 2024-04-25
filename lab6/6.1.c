// Planting Binary tree with array
// Now we are going to implement basic function with array representation of binary tree. The basic functions are: Creating tree, Creating root, Insertion and Display.

// Your task is to create a Binary Tree by using these commands:

// ROOT 
// �
// x: To create a root node with a value of 
// �
// x. If there is already a root, print cannot create duplicated root
// INSL 
// �
// �
// �
// par 
// �
// �
// �
// val: To insert a node with value = 
// �
// �
// �
// val as a left child of a node that has a value of 
// �
// �
// �
// par
// INSR 
// �
// �
// �
// par 
// �
// �
// �
// val: To insert a node with value = 
// �
// �
// �
// val as a right child of a node that has a value of 
// �
// �
// �
// par
// END: To print all the nodes in a binary tree, ordered by the level-order (or print all the element in the array) and terminate the program.
// The insertion part can be canceled if

// There is already a node in which you want to insert, print node already presented
// If there is no node in which the parent is matched to the input, print not found
// If the target index is out of bound of the array, print overflow
// Note that if that node is empty, the value inside will be null (You can represent null with an integer code -999)

// All value in the binary will be guarunteed distinct.

// Input
// The input consists of several lines
// First Line:
// An integer 
// �
// n in which 
// �
// ≥
// 1
// n≥1 to state the number of maximum node in the binary tree.
// Next Lines From now on:
// The command and the value associated with the command (You can see examples for clarification). End the input section with command END

// Output
// The output section is dependent with the input, if there's any case that the command has to output an error message.
// At the last line of output, print all the nodes in the tree by Level-Order

// Example of input and output
// Input	Output
// 31
// ROOT 10
// INSL 10 78
// INSL 78 12
// INSR 10 59
// INSR 10 4865
// INSL 59 40
// INSR 78 68
// INSL 40 8
// INSL 8 9
// INSL 9 100
// END	node already presented
// overflow
// 10 78 59 12 68 40 null null null null null 8 null null null null null null null null null null null 9 null null null null null null null

// 7
// ROOT 10
// ROOT 488
// ROOT 1
// INSR 10 60
// INSL 798 102
// INSR 60 26
// INSL 60 64
// INSL 10 49
// INSL 49 72
// INSL 49 62
// INSR 49 62
// END	cannot create duplicated root
// cannot create duplicated root
// not found
// node already presented
// 10 49 60 72 62 64 26

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Tree {
    int *arr;
    int size;
} Tree;


void init(Tree *t, int n) {
    t->arr = (int *)malloc(sizeof(int) * n);
    t->size = n;
    for (int i = 0; i < n; i++) {
        t->arr[i] = -999;
    }
}

void createRoot(Tree *t, int x) {
    if (t->arr[0] != -999) {
        printf("cannot create duplicated root\n");
    } else {
        t->arr[0] = x;
    }
}

void insertLeft(Tree *t, int x, int y) {
    int i = 0;
    while (t->arr[i] != x) {
        i++;
        if (i >= t->size) {
            printf("not found\n");
            return;
        }
    }
    if (i * 2 + 1 >= t->size) {
        printf("overflow\n");
    } else if (t->arr[i * 2 + 1] != -999) {
        printf("node already presented\n");
    } else {
        t->arr[i * 2 + 1] = y;
    }
}
 
// โหนดลูกด้านซ้าย 2*0 + 1 = 1
// โหนดลูกด้านขวา 2*0 + 2 = 2
// โหนดลูกด้านซ้าย 2*1 + 1 = 3
// โหนดลูกด้านขวา 2*1 + 2 = 4

void insertRight(Tree *t, int x, int y) {
    int i = 0;
    while (t->arr[i] != x) {
        i++;
        if (i >= t->size) {
            printf("not found\n");
            return;
        }
    }
    if (i * 2 + 2 >= t->size) {
        printf("overflow\n");
    } else if (t->arr[i * 2 + 2] != -999) {
        printf("node already presented\n");
    } else {
        t->arr[i * 2 + 2] = y;
    }
}

void printTree(Tree *t) {
    for (int i = 0; i < t->size; i++) {
        if (t->arr[i] != -999) {
            printf("%d ", t->arr[i]);
        } else {
            printf("null ");
        }
    }
    printf("\n");
}

int main() {
    int n;
    scanf("%d", &n);
    Tree t;
    init(&t, n);
    char input[5];
    int x, y;
    while (1) {
        scanf("%s", input);
        if (strcmp(input, "ROOT") == 0) {
            scanf("%d", &x);
            createRoot(&t, x);
        } else if (strcmp(input, "INSL") == 0) {
            scanf("%d %d", &x, &y);
            insertLeft(&t, x, y);
        } else if (strcmp(input, "INSR") == 0) {
            scanf("%d %d", &x, &y);
            insertRight(&t, x, y);
        } else if (strcmp(input, "END") == 0) {
            printTree(&t);
            break;
        }
    }
    
    free(t.arr);
    return 0;
}
