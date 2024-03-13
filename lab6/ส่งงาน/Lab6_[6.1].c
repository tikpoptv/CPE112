
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Tree {  //Jedsadaporn Pannok No. 66070503410
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
