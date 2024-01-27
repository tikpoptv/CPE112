#include <stdio.h>

int main(void)
{
    int input[4] = {1,2,3,4};
    int *ptr;
    ptr = &input[0];

    for (int i = 0; i < 4; i++)
    {
        printf("%d",*(ptr + i));
    }
    
}