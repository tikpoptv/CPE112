#include<stdio.h> // Jedsadaporn Pannok 66070503410

// Function to solve Tower of Hanoi problem recursively
// Parameters:
// - start: The starting peg
// - aux: The auxiliary peg
// - end: The destination peg
// - n: The number of disks to be moved
// - *cnt: Pointer to the variable storing the count of moves
void hanoi(char start, char aux, char end, int n, int *cnt) {
    // Base case: If there is only one disk to move
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", start, end); // Move the disk directly to the destination peg
        (*cnt)++; // Increment the move count
        return;
    }
    // Recursive case: If there are more than one disk
    else {
        // Move (n-1) disks from the starting peg to the auxiliary peg using the destination peg
        hanoi(start, end, aux, n - 1, cnt);
        // Move the nth disk from the starting peg to the destination peg
        printf("Move disk %d from %c to %c\n", n, start, end);
        // Move (n-1) disks from the auxiliary peg to the destination peg using the starting peg
        hanoi(aux, start, end, n - 1, cnt);
        (*cnt)++; // Increment the move count
    }
}

int main() {
    int n;
    scanf("%d", &n); // Accept the number of disks from the user
    int cnt = 0; // Initialize the move count
    hanoi('A', 'B', 'C', n, &cnt); // Call the hanoi function to solve the Tower of Hanoi problem
    printf("Total moves: %d\n", cnt); // Display the total number of moves performed
}
