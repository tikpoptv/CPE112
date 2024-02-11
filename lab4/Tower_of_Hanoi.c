// Tower of Hanoi
// Problem
// The Tower of Hanoi is also known as the Tower of Brahma or the Lucas Tower. It is a mathematical game or puzzle that consists of three rods with ’n’ number of disks of different diameters.

// The objective of the game is to shift the entire stack of disks from one rod to another rod following these three rules :

// Only one disk can be moved at a time.
// Only the uppermost disk from one stack can be moved on to the top of another stack or an empty rod.
// Larger disks cannot be placed on the top of smaller disks.
// Solve the Tower of Hanoi using Recursion and output steps that has been executed.

// Tower of Hanoi

// Input
// The input consists of one lines:

// First Line: Enter integers 
// �
// �
// X 
// i
// ​
//  ​ representing disks in the Tower of Hanoi.
// Output
// The output consists of

// N Line: Steps taken to solve the Tower of Hanoi puzzle for the given number of disks.
// Last Line: Number of steps that has been executed.


#include<stdio.h>

void hanoi(char start, char aux, char end,int n,int *cnt) {
    if(n == 1) {
        printf("Move disk 1 from %c to %c\n",start,end);
        (*cnt)++;
        return;
    }
    else {
        hanoi(start,end,aux,n-1,cnt);
        printf("Move disk %d from %c to %c\n",n,start,end);
        hanoi(aux,start,end,n-1,cnt);
        (*cnt)++;
    }
}

int main() {
    int n; scanf("%d",&n);
    int cnt=0;
    hanoi('A','B','C',n,&cnt);
    printf("Total moves: %d\n",cnt);
}