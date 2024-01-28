#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct dict {
    char value[100];
    char key[100];
};

void editdict(struct dict *dic, int size) {
    char searchKey[100];
    printf("Enter the key to edit: ");
    scanf("%99s", searchKey);

    for (int i = 0; i < size; i++) {
        if (strcmp(dic[i].key, searchKey) == 0) {
            printf("Enter the new value: ");
            scanf("%99s", dic[i].value);
            printf("Value updated successfully.\n");
            return;
        }
    }

    printf("Key not found in the dictionary.\n");
}

void printdict(struct dict *dic, int size) {
    for (int i = 0; i < size; i++) {
        printf("%s : %s\n", dic[i].key, dic[i].value);
    }
}

int main() {
    int size;
    printf("Enter the size: ");
    scanf("%d", &size);

    if (size <= 0) {
        printf("Invalid size. Exiting program.\n");
        return 1;  // Return an error code
    }

    struct dict *dic = (struct dict *)malloc(size * sizeof(struct dict));

    if (dic == NULL) {
        printf("Memory allocation failed. Exiting program.\n");
        return 1;  // Return an error code
    }

    // Write your code here
    editdict(dic, size);

    printdict(dic, size);

    free(dic);

    return 0;
}
