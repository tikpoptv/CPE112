#include <stdio.h>
#include <string.h>

#define MAX_SIZE 10
#define MAX_LENGTH 100

// Define a structure for the dictionary entry

// struct Dictionary{
//     char key[MAX_LENGTH];
//     char value[MAX_LENGTH];
// };

typedef struct {
    char key[MAX_LENGTH];
    char value[MAX_LENGTH];
} Dictionary; // Jedsadaporn Pannok 66070503410

int main() {
    int size;
    Dictionary dict[MAX_SIZE];

    // Read the size of the dictionary from the user
    scanf("%d", &size);

    // Read entries (key-value pairs) into the dictionary
    for (int i = 0; i < size; i++) {
        scanf("%s %s", dict[i].key, dict[i].value);
    }

    // Read the key and value to be edited
    char editKey[MAX_LENGTH];
    char editValue[MAX_LENGTH];
    scanf("%s %s", editKey, editValue);

    // Flag to track whether the entry was edited
    int edited = 0;

    // Loop through the dictionary to find and edit the entry
    for (int i = 0; i < size; i++) {
        if (strcmp(dict[i].key, editKey) == 0) {
            // If the key is found, update the associated value
            strcpy(dict[i].value, editValue);
            edited = 1;
            break;
        }
    }

    // Check if an entry was edited and print the updated dictionary
    if (edited) {
        for (int i = 0; i < size; i++) {
            printf("%s : %s\n", dict[i].key, dict[i].value);
        }
    } else {
        // If no entry was edited, print "No change"
        printf("No change\n");
        for (int i = 0; i < size; i++) {
            printf("%s : %s\n", dict[i].key, dict[i].value);
        }
    }

    return 0;
}
