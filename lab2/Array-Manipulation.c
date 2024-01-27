// input:
// n1: An integer representing the number of elements in the first array (array1).
// Array1: n1 integers representing the elements of the first array.
// n2: An integer representing the number of elements in the second array (array2).
// Array2: n2 integers representing the elements of the second array.
// i_insert: An integer representing the index in array1 where an insertion operation is to be performed.
// insert_value: An integer to be inserted at the specified index in array1.
// i_delete: An integer representing the index in array1 where a deletion operation is to be performed.
// Output:
// Result array from insertion operation: The first line should contain the modified array1 after the insertion operation.
// Result array from deletion operation: The second line should contain the modified array1 after the deletion operation.
// Result array from merge operation: The third line should contain the merged array of array1 and array2.


#include <stdio.h>
#include <stdlib.h>

struct input
{
    int size_set;
    int *set;
};

void insertion();
void deletion();
void merge();

int main(void)
{  

    struct input set1;
    struct input set2;
    
    int i_insert, insert_value, i_delete;

    scanf("%d",&set1.size_set);
    set1.set = (int*)malloc(set1.size_set*sizeof(int));

    for(int i = 0; i < set1.size_set; i++){
        scanf("%d",set1.set + i);
    }

    scanf("%d",&set2.size_set);
    set2.set = (int*)malloc(set2.size_set*sizeof(int));

    //printf("size_set2 = %d",input.size_set2);

    for(int i = 0; i < set2.size_set; i++){
        scanf("%d",set2.set + i);
    }
    scanf("%d",&i_insert);   
    scanf("%d",&insert_value);
    scanf("%d",&i_delete);

    insertion(set1.set, &set1.size_set, i_insert, insert_value);
   // printf("size_set = %d",set1.size_set);
    deletion(set1.set, &set1.size_set,i_delete);
    
    merge(set1.set, set2.set, set1.size_set, set2.size_set);

}


void insertion(int *input, int *sizeset, int posi, int value) {

    int *temp = (int*)malloc((*sizeset + 1)*sizeof(int));

    for (int i = 0; i < *sizeset+1; i++)
    {
        if (i<posi)
        {
            *(temp+i) = *(input+i);
        }else if (i == posi)
        {
            *(temp+i) = value;
        }else
        {
            *(temp+i) = *(input+i-1);
        }
    }
    for (int i = 0; i < *sizeset+1; i++)
    {
        printf("%d ",*(temp+i));
    }
    for (int i = 0; i < *sizeset+1; i++)
    {
        *(input+i) = *(temp+i);
    }

    *sizeset = *sizeset + 1;

    printf("\n");
    free(temp);
}

void deletion(int *input, int *sizeset, int posi) {

    if (posi+1 > *sizeset)
    {
        printf("Index out of bounds\n");
        return;
    }
    

    int *temp = (int*)malloc((*sizeset-1)*sizeof(int));

    for (int i = 0; i < *sizeset-1; i++)
    {
        if (i<posi)
        {
            *(temp+i) = *(input+i);
        }else
        {
            *(temp+i) = *(input+i+1);
        }
    }
    for (int i = 0; i < *sizeset-1; i++)
    {
        printf("%d ",*(temp+i));
    }
    for (int i = 0; i < *sizeset-1; i++)
    {
        *(input+i) = *(temp+i);
    }


    *sizeset = *sizeset - 1;
    printf("\n");
    free(temp);
}

void merge(int *input1, int *input2, int sizeset1, int sizeset2) {

    int *temp = (int*)malloc((sizeset1+sizeset2)*sizeof(int));

    for (int i = 0; i < sizeset1+sizeset2; i++)
    {
        if (i<sizeset1)
        {
            *(temp+i) = *(input1+i);
        }else
        {
            *(temp+i) = *(input2+i-sizeset1);
        }
    }
    for (int i = 0; i < sizeset1+sizeset2; i++)
    {
        printf("%d ",*(temp+i));
    }

    printf("\n");
    free(temp);
}

// 