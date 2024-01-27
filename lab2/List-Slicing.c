// Input
// First Line
// A number of elements 1 ≤ m < n ≤ 1,000,000 in list
// Second Line
// A sequence of integer (int) separating between element with a whitespace
// Third Line
// Three integers as start, end and step

// Output
// The output consist of one line, print out all the elements in the sliced list. If there is no element in the sliced list print “empty”

// Examples
// Input	
// 7
// 1 2 3 4 5 6 7 0 3 1	
// Output
// 1 2 3

// Input
// 1
// 1
// 0 1 1	
// Output 
// 1

// Input
// 8
// -2 -1 -1 0 4 5 7 9
// -1 -7 -2	
// Output
// 9 5 0 

// Input
// 5
// 9 3 6 0 1
// -12 8 1	
// Output
// 9 3 6 0 1


#include <stdio.h>
#include <stdlib.h>


struct input {
    int *arr;
};

void List_Slicing();


int main() {

    struct input set;
    int n,start,end,step;

    scanf("%d",&n);
    set.arr = (int*)malloc(n*sizeof(int));

    for(int i=0;i<n;i++) {
        scanf("%d",&set.arr[i]);
    }   

    scanf("%d %d %d",&start,&end,&step);

    List_Slicing(set.arr,start,end,step);
    
    free(set.arr);


}

void List_Slicing(int *arr, int start, int end, int step) {
    
        int i = start;
        int j = 0;
        int *new_arr;
    
        if (step > 0) {
            new_arr = (int*)malloc((end-start)/step*sizeof(int));
            while(i < end) {
                new_arr[j] = arr[i];
                i += step;
                j++;
            }
        }
        else if (step < 0) {
            new_arr = (int*)malloc((start-end)/step*sizeof(int));
            while(i > end) {
                new_arr[j] = arr[i];
                i += step;
                j++;
            }
        }
        else {
            printf("empty");
        }
    
        for(int i=0;i<j;i++) {
            printf("%d ",new_arr[i]);
        }
        printf("\n");

}