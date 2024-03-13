
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct AVL {
    int *arr;
    int size;
    int key;
    int height;
} AVL;

void init(AVL *t, int n) {
    t->arr = (AVL *)malloc(sizeof(AVL) * n);
    t->size = n;
    for (int i = 0; i < n; i++) {
        t->arr[i] = NULL;
    }
}

void createRoot(AVL *t, int x) {
    if (t->arr[0] != NULL) {
        printf("cannot create duplicated root\n");
    } else {
        t->arr[0] = x;
    }
}

void insertLeft(AVL *t, int x, int y) {
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
    } else if (t->arr[i * 2 + 1] != NULL) {
        printf("node already presented\n");
    } else {
        t->arr[i * 2 + 1] = y;
    }
}

void insertRight(AVL *t, int x, int y) {
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
    } else if (t->arr[i * 2 + 2] != NULL) {
        printf("node already presented\n");
    } else {
        t->arr[i * 2 + 2] = y;
    }
}

void leftRotate(AVL *t, int x) {
    int i = 0;
    while (t->arr[i] != x) {
        i++;
        if (i >= t->size) {
            printf("not found\n");
            return;
        }
    }
    if (i * 2 + 2 >= t->size) {
        printf("cannot rotate\n");
    } else if (t->arr[i * 2 + 2] == NULL) {
        printf("cannot rotate\n");
    } else {
        int temp = t->arr[i];
        t->arr[i] = t->arr[i * 2 + 2];
        t->arr[i * 2 + 2] = t->arr[i * 2 + 2 * 2 + 1];
        t->arr[i * 2 + 2 * 2 + 1] = temp;
    }
}

void rightRotate(AVL *t, int x) {
    int i = 0;
    while (t->arr[i] != x) {
        i++;
        if (i >= t->size) {
            printf("not found\n");
            return;
        }
    }
    if (i * 2 + 1 >= t->size) {
        printf("cannot rotate\n");
    } else if (t->arr[i * 2 + 1] == NULL) {
        printf("cannot rotate\n");
    } else {
        int temp = t->arr[i];
        t->arr[i] = t->arr[i * 2 + 1];
        t->arr[i * 2 + 1] = t->arr[i * 2 + 1 * 2 + 2];
        t->arr[i * 2 + 1 * 2 + 2] = temp;
    }
}

void printTree(AVL *t) {
    for (int i = 0; i < t->size; i++) {
        if (t->arr[i] != NULL) {
            printf("%d ", t->arr[i]);
        } else {
            printf("NULL ");
        }
    }
}

int main() {
    AVL t;
    int n;
    scanf("%d", &n);
    init(&t, n);
    char cmd[10];
    while (1) {
        scanf("%s", cmd);
        if (strcmp(cmd, "INSERT") == 0) {
            int x, y;
            scanf("%d %d", &x, &y);
            createRoot(&t, x);
            insertLeft(&t, x, y);
            insertRight(&t, x, y);
        } else if (strcmp(cmd, "DELETE") == 0) {
            int x;
            scanf("%d", &x);
            leftRotate(&t, x);
            rightRotate(&t, x);
        } else if (strcmp(cmd, "PRINT") == 0) {
            printTree(&t);
        } else if (strcmp(cmd, "EXIT") == 0) {
            break;
        } else {
            printf("Invalid Command.\n");
        }
    }
    free(t.arr);
}
