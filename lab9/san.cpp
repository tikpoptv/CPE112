#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adjacencyMatrix[MAX][MAX];
int visited[MAX];
int queue[MAX];
int front = -1, rear = -1;

void enqueue(int data);
int dequeue();
void DFS(int v, int n);
void BFS(int v, int n);

int main() {
    int n, x, a, b;
    scanf("%d", &n);
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++)
            adjacencyMatrix[i][j] = 0;
        visited[i] = 0;
    }

    for(int i = 0; i < n; i++) {
        scanf("%d %d", &a, &b);
        adjacencyMatrix[a][b] = adjacencyMatrix[b][a] = 1;
    }

    scanf("%d", &x);
    DFS(x, n);
    printf("\n");
    for(int i = 0; i < n; i++)
        visited[i] = 0;
    BFS(x, n);
    return 0;
}

void enqueue(int data) {
    if(front == -1)
        front = 0;
    rear++;
    queue[rear] = data;
}

int dequeue() {
    int data = queue[front];
    front++;
    if(front > rear)
        front = rear = -1;
    return data;
}

void DFS(int v, int n) {
    visited[v] = 1;
    printf("%d ", v);
    for(int i = 0; i < n; i++) {
        if(adjacencyMatrix[v][i] == 1 && visited[i] == 0)
            DFS(i, n);
    }
}

void BFS(int v, int n) {
    visited[v] = 1;
    enqueue(v);

    while(front != -1) {
        int current = dequeue();
        printf("%d ", current);
        for(int i = 0; i < n; i++) {
            if(adjacencyMatrix[current][i] == 1 && visited[i] == 0) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
}