// # Floyd-Warshall Algorithm

// ## Introduction
// The Floyd-Warshall algorithm is used to find the shortest path between all pairs of vertices in a graph.

// ## Algorithm Steps
// 1. Create a matrix `A0` of size `n*n`, where `n` is the number of vertices in the graph. Each cell `A[i][j]` represents the distance from vertex `i` to vertex `j`. If there is no path from vertex `i` to vertex `j`, the cell is set to infinity.

// 2. Create a matrix `A1` using `A0`. The first row and column remain unchanged. For each cell `A[i][j]`, calculate the distance from vertex `i` to vertex `j` through an intermediate vertex `k` (initially set to the first vertex). If this distance is shorter than the direct distance, update the cell with the new distance.

// 3. Repeat step 2 for each intermediate vertex `k` (from the second vertex to the last vertex).

// 4. The final matrix `A` represents the shortest path distances between all pairs of vertices.

// ## Input
// The input consists of `n+1` lines:
// - The first line contains an integer `n` (1 ≤ n ≤ 100), indicating the number of vertices.
// - The next `n` lines contain `n` integers each, representing the weights of the edges between the vertices. If there is no edge between two vertices, the weight is represented by -1.

// ## Output
// The output consists of `n` lines:
// - Each line represents a row of the matrix `A`, where the cell at the i-th row and j-th column represents the shortest path distance from vertex `i` to vertex `j`.

// ## Example
// Input:
// 3
// 0 1 43
// 1 0 6
// -1 -1 0

// Output:
// 0 1 7
// 1 0 6
// -1 -1 0



#include <iostream>
#include <vector>
#include <queue> //jedsadaporn pannok No. 66070503410
#include <climits>

#define MAX 100

int weight[MAX][MAX];
int shortest[MAX][MAX];

void floydWarshall(int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            shortest[i][j] = weight[i][j];
        }
    }

    for(int k = 0; k < n; k++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(shortest[i][k] != -1 && shortest[k][j] != -1) {
                    if(shortest[i][j] == -1 || shortest[i][k] + shortest[k][j] < shortest[i][j]) {
                        shortest[i][j] = shortest[i][k] + shortest[k][j];
                    }
                }
            }
        }
    }
}

int main() {
    int n, a;
    std::cin >> n;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            std::cin >> a;
            weight[i][j] = a;
        }
    }

    floydWarshall(n);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            std::cout << shortest[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}

