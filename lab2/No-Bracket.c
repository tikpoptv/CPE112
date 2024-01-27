
#include <stdio.h>
#include <stdlib.h>


struct input
{
    int size;
    int *arry;
};

int main(){
    struct input input;

    scanf("%d",&input.size);
    
    input.arry = (int*)malloc(input.size*sizeof(int));

    for(int i = 0; i < input.size; i++){
        scanf("%d",input.arry + i);
    }
    
    int mode;
    scanf("%d",&mode);

    int check = 0;
    if (mode == 0)
    {
        for (int i = 0; i < input.size; i+=2)
        {
            printf("%d ",*(input.arry + i));
            check++;
        }
    }else {
        for (int i = 1; i < input.size; i+=2)
        {
            printf("%d ",*(input.arry + i));
            check++;
        }
    }
    if (check == 0) printf("none");
    

    free(input.arry);

    return 0;
}

