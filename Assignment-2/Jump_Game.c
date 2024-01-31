// Jump Game
// The jump game assigns you to input an array. Then, the player will start at the first index ([0]), and the player’s maximum length is equal to the current index value (For example, if the current index is 5, the player can jump from 1 index to 5 index). If the player can reach the exact last index (not out of bound), then output the number of jumps (It must be minimum jumps!!!). If not, output “Not Possible”.

// Hints
// Start from the first element and recursively call for all the elements reachable from the first element. The minimum number of jumps to reach the end from the first can be calculated using the minimum value from the recursive calls.

// minJumps(start, end) = 1 + Min(minJumps(k, end)) for all k reachable from start.

// Input
// The input consists of two lines
// First Line:
// An integer n in which 0 ≤ n ≤ 1,000  as number of elements in an array
// Second Line:
// A sequence of integer a1 a2 … an separating between element with a whitespace

// Output
// The input consists of one line
// First Line:
// Number of minimum jumps / “Not Possible”


#include <stdio.h>
#include <stdlib.h>

struct data {  
    int *arr;
};

void jump();


int main(){
    
    int n;
    scanf("%d",&n);
    struct data data;
    data.arr = (int*)malloc(n*sizeof(int));
    for(int i = 0; i < n; i++){
        scanf("%d",data.arr + i);
    }

    jump(data,n);
    

    return 0;
}

void jump(struct data data, int n) {
    int jumps = 0;
    int current = 0;
    
    while (current < n - 1) {
        int max_jump = data.arr[current];
        
        if (max_jump == 0) {
            printf("Not Possible");
            return;
        }
        
        int next = current;
        int max_reachable = 0;
        
        for (int i = 1; i <= max_jump; i++) {
            if (current + i >= n - 1) {
                next = current + i;
                break;
            }
            
            if (data.arr[current + i] + i > max_reachable) {
                max_reachable = data.arr[current + i] + i;
                next = current + i;
            }
        }
        
        current = next;
        jumps++;
    }
    
    printf("%d", jumps);
}
