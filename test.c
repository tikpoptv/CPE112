#include <stdio.h>

int main() {
    int number, i;

    printf("Enter a positive integer: ");
    scanf("%d", &number);

    printf("Multiplication Table for %d:\n", number);

    for (i = 1; i <= 12; i++) {
        printf("%d x %d = %d\n", number, i, number * i);
    }

    return 0;
}