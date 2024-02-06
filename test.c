#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node
{
    int data;
    struct node *next;
}node;

void insertnode(node **start, int value)
{
    node *newnode = (node*)malloc(sizeof(node));
    newnode ->data = value;
    newnode ->next = NULL;

    if(*start==NULL)
    {
        *start = newnode;
        return;
    }
    node *temp = *start;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newnode;

}

int main(void){
    int start, end;

    node *mook = NULL;

    while (1)
    {
        char value[10];
        scanf("%s", &value);
        if (strcmp(value, "END") == 0)
        {
            break;
        } else {
            scanf("%d", &value);
            insertnode(&mook,value);
        }
    }
    // scanf("%d %d",&start, &end);

    // for(int i=mook;i<start;i++)
    // {
    //     printf("%d",value);
    // }

    // node *temp = mook;
    //         while (temp -> next != NULL)
    //         {
    //             temp = temp->next ;  
    //         }


    

}