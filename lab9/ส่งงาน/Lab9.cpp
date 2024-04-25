#include <iostream>
#include <queue>
#include <vector> //jedsadaporn pannok 66070503410

#define MAX 100 // Maximum size of the graph

int adjacencyMatrix[MAX][MAX]; // Grid to show connections between points
int visited[MAX]; // Keeps track of visited points

// Depth First Search (DFS) function
void DFS(int v, int n) {
    visited[v] = 1; // Mark the current point as visited
    std::cout << v << " "; // Print the current point
    // Look at all points connected to the current point
    for (int i = 0; i < n; i++) {
        // If a connected point hasn't been visited explore it
        if (adjacencyMatrix[v][i] == 1 && visited[i] == 0)
            DFS(i, n);
    }
}

// Breadth First Search (BFS) function
void BFS(int v, int n) {
    std::queue<int> q; // Queue to keep track of points to visit
    visited[v] = 1; // Mark the starting point as visited
    q.push(v); // Add the starting point to the queue

    while (!q.empty()) {
        int current = q.front(); // Get the first point in the queue
        q.pop(); // Remove the first point from the queue
        std::cout << current << " "; // Print the point

        // Look at all points connected to the current point
        for (int i = 0; i < n; i++) {
            // If a connected point hasn't been visited mark it as visited and add it to the queue
            if (adjacencyMatrix[current][i] == 1 && visited[i] == 0) {
                visited[i] = 1;
                q.push(i);
            }
        }
    }
}

int main() {
    int n, x, a, b;
    std::cin >> n; // Input the number of points

    // Initialize the grid and visited array
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++)
            adjacencyMatrix[i][j] = 0; // Set all connections to 0
        visited[i] = 0; // Mark all points as not visited
    }

    // Input connections between points and update the grid
    for(int i = 0; i < n; i++) {
        std::cin >> a >> b;
        adjacencyMatrix[a][b] = adjacencyMatrix[b][a] = 1; // Mark the connection between points
    }

    std::cin >> x; // Input the starting point for exploration

    // Explore the graph using Depth First Search DFS from the starting point x
    DFS(x, n);
    std::cout << std::endl;

    // Reset the visited array for exploring the graph using Breadth First Search BFS
    for (int i = 0; i < n; ++i)
        visited[i] = 0;

    // Explore the graph using Breadth First Search BFS from the starting point x
    BFS(x, n);
    std::cout << std::endl;

    return 0;
}
