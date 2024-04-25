#include <iostream>
#include <queue>
#include <vector>

#define MAX 100

int adjacencyMatrix[MAX][MAX];
int visited[MAX];

// Function to perform DFS
void DFS(int v, int n) {
    visited[v] = 1;
    std::cout << v << " ";
    for (int i = 0; i < n; i++) {
        if (adjacencyMatrix[v][i] == 1 && visited[i] == 0)
            DFS(i, n);
    }
}

// Function to perform BFS
void BFS(int v, int n) {
    std::queue<int> q;
    visited[v] = 1;
    q.push(v);

    while (!q.empty()) {
        int current = q.front();
        q.pop();
        std::cout << current << " ";

        for (int i = 0; i < n; i++) {
            if (adjacencyMatrix[current][i] == 1 && visited[i] == 0) {
                visited[i] = 1;
                q.push(i);
            }
        }
    }
}

int main() {
    int n, x, a, b;
    std::cin >> n;
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++)
            adjacencyMatrix[i][j] = 0;
        visited[i] = 0;
    }

    for(int i = 0; i < n; i++) {
        std::cin >> a >> b;
        adjacencyMatrix[a][b] = adjacencyMatrix[b][a] = 1;
    }

    std::cin >> x;

    DFS(x, n);
    std::cout << std::endl;

    // Reset visited array
    for (int i = 0; i < n; ++i)
        visited[i] = 0;

    BFS(x, n);
    std::cout << std::endl;

    return 0;
}
