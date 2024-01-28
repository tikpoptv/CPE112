#include <stdio.h>
#include <stdlib.h>

#define Maxnum 1000000

int main() {

    char c;
    scanf("%c", &c);

    int* arr1 = (int*)malloc(Maxnum * sizeof(int));
    int* arr2 = (int*)calloc(Maxnum, sizeof(int));

    long long sum = 0;
    long long diff = 0;

    for (int i = 0; i < Maxnum; i++) {
        arr1[i] = i + 1;
        arr2[i] = i + 1;
        sum += arr1[i];
        diff -= arr2[i];
    }

    printf("%lld \n", sum);
    printf("%lld \n", diff);

    free(arr1);
    free(arr2);

    return 0;
}
