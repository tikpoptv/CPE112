// Input
// The input consists of size+2 lines
// First Line: An integer size in which 1≤size≤10 as the number of elements in an array.
// Second to size+1th lines: Two string, key and value separating between element with a whitespace, for inserting elements in the dictionary. Which their length is 1≤length≤100.
// size+2 line (last line)th: Two string, key and value separating between element with a whitespace, for edit the value in the dictionary by the key.

// Output
// The output consists of size lines
// First Line: The elements of dictionary after edited separated by whitespaces and colon ':’
// If there were no change the output consists of size+1 lines
// First Line: “No change” to indicate that no change was made.
// Second Line to size+1th line: The **original **elements in the dictionary, including keys and values separated by whitespaces and colon‘:'


#include <stdio.h>
#include <string.h>

#define MAX_SIZE 10
#define MAX_LENGTH 100

typedef struct {
    char key[MAX_LENGTH];
    char value[MAX_LENGTH];
} Dictionary;



int main() {
    int size;
    Dictionary dict[MAX_SIZE];


    scanf("%d", &size);
    for (int i = 0; i < size; i++) {
        scanf("%s %s", dict[i].key, dict[i].value);
    }

    char editKey[MAX_LENGTH];
    char editValue[MAX_LENGTH];

    scanf("%s %s", editKey, editValue);
    int edited = 0;
    for (int i = 0; i < size; i++) {
        if (strcmp(dict[i].key, editKey) == 0) {
            strcpy(dict[i].value, editValue);
            edited = 1;
            break;
        }
    }

    if (edited) {
        for (int i = 0; i < size; i++) {
            printf("%s : %s\n", dict[i].key, dict[i].value);
        }
    } else {
        printf("No change\n");
        for (int i = 0; i < size; i++) {
            printf("%s : %s\n", dict[i].key, dict[i].value);
        }
    }

    return 0;
}
