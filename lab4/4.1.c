#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool isfull(int *cnt,int size) {
    if(size == *cnt) return true;
    else return false;
}

bool push(int *stack,int val,int *cnt,int size) {
    if(isfull(cnt,size)) return true;
    else {
        stack[*cnt] = val;
        (*cnt)++;
        return false;
    }
}

bool ismt(int *cnt) {
    if(*cnt ==0) return true;
    else return false;
}

bool pop(int *stack,int *cnt) {
    if(ismt(cnt)) {
        return false;
    }
    else {
        *(stack+(*cnt)) = -999;
        (*cnt)--;
        return true;
    }
}

int main() {
    int size; scanf("%d",&size);
    if(size <= 0) {
        printf("Please enter a positive number.\n");
        return 0;
    }
    int *stack = (int *)malloc(size * sizeof(int));
    int choice; scanf("%d",&choice);
    int cnt=0;
    while(1) {
        if(choice == 1) {//Insert
            int t; scanf("%d",&t);
            if(push(stack,t,&cnt,size)) {
                printf("Stack Overflow.\n");
                return 0;
            }
        }
        else if(choice == 2) {//pop out
            if(!pop(stack,&cnt)) {
                printf("Stack Underflow.\n");
                return 0;
            }
        }
        else if(choice == 3) {//print out the members
            if(ismt(&cnt)) {
                printf("Stack is empty.\n");
            }
            for(int i=cnt-1;i>=0;i--) {
                printf("%d\n",*(stack+i));
                pop(stack,&cnt);
            }
            return 0;
        }
        else if(choice == 4) {
            printf("Exiting...\n");
            break;
        }
        else {
            printf("Invalid choice.\n");
            return 0;
        }
        scanf("%d",&choice);
    }
    free(stack);
    return 0;
}
