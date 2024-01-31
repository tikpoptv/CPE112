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

int main(){
    



    return 0;
}