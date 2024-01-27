#include <stdio.h>

int main() {

    //0 3 1
    int y[] = {1, 2, 3, 4, 5, 6, 7};
    int y_size = sizeof(y) / sizeof(y[0]);
    for (int i = 0; i < 3 && i < y_size; i += 1) {
        printf("%d ", y[i]);
    }
    printf("\n");


    //-1 -7 -2
    int x[] = {-2, -1, -1, 0, 4, 5, 7, 9};
    int x_size = sizeof(x) / sizeof(x[0]);
    for (int i = x_size - 1; i > x_size - 7 && i >= 0; i -= 2) {
        printf("%d ", x[i]);
    }
    printf("\n");

    //-12 8 1
    int b[] = {9, 3, 6, 0, 1};
    int b_size = sizeof(b) / sizeof(b[0]);
    for (int i = 0; i < b_size && i < 8; i += 1) {
        printf("%d ", b[i]);
    }
    printf("\n");

    return 0;
}

