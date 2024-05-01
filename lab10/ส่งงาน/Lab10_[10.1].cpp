#include <iostream> // jedsadaporn pannok No.66070503410
#include <climits> // For using INT_MAX

#define MAX 100

int weight[MAX][MAX]; // Adjacency matrix to store edge weights
int shortest[MAX][MAX]; // 2D array to store shortest distances

// Function to apply Floyd Warshall algorithm to find shortest paths
void floydWarshall(int n) {
    // Initialize shortest[][] with the same values as weight[][]
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            shortest[i][j] = weight[i][j];
        }
    }

    // Apply Floyd Warshall algorithm
    for(int k = 0; k < n; k++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                // Check if path through vertex k is shorter
                if(shortest[i][k] != -1 && shortest[k][j] != -1) {
                    // Update shortest path if shorter path found
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
    std::cin >> n; // Input number of vertices

    // Input weights for edges (adjacency matrix)
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            std::cin >> a;
            weight[i][j] = a;
        }
    }

    // Apply Floyd Warshall algorithm to find shortest paths
    floydWarshall(n);

    // Output the shortest distances between all pairs of vertices
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            std::cout << shortest[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
