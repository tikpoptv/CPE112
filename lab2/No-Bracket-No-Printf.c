#include <stdio.h>
#include <stdlib.h>


struct input
{
    int size;
    int *arr;
};

void output();

int main(void)
{  
    struct input input;
    
    scanf("%d",&input.size);
    input.arr = (int*)malloc(input.size*sizeof(int));

    for(int i = 0; i < input.size; i++){
        scanf("%d",input.arr + i);
    }


    int 
    max=*(input.arr),
    min=*(input.arr),
    posimax=0,
    posimin=0;

    for (int i = 0; i < input.size; i++)
    {
        if (*(input.arr+i)>max)
        {
            max = *(input.arr+i);
            posimax = i;
        }
        if (*(input.arr+i)<min)
        {
           min = *(input.arr+i);
            posimin = i;
        }
    }
    output(max,posimax);
    output(min,posimin);
    
    free(input.arr);

    return 0;
}
void output(int input, int posi) {
    printf("%d %d\n",input ,posi);
}