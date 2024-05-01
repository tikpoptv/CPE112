#include <stdio.h> // jedsadaporn pannok No.66070503410
#include <stdlib.h>

// Comparator function to use in sorting
int comparator(const void* p1, const void* p2)
{ // jedsadaporn pannok No.66070503410
    const int(*x)[3] = p1;
    const int(*y)[3] = p2;

    return (*x)[2] - (*y)[2];
}

// Initialization of parent[] and rank[] arrays
void makeSet(int parent[], int rank[], int n) // jedsadaporn pannok No.66070503410
{
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        rank[i] = 0;
    }
}

// Function to find the parent of a node
int findParent(int parent[], int component)
{
    if (parent[component] == component)
        return component;

    return parent[component]
        = findParent(parent, parent[component]);
}

// Function to unite two sets
void unionSet(int u, int v, int parent[], int rank[], int n)
{
    // Finding the parents
    u = findParent(parent, u);
    v = findParent(parent, v);

    if (rank[u] < rank[v]) {
        parent[u] = v;
    }
    else if (rank[u] > rank[v]) {
        parent[v] = u;
    }
    else {
        parent[v] = u;

        // Since the rank increases if
        // the ranks of two sets are same
        rank[u]++;
    }
}

// Function to find the MST
int kruskalAlgo(int n, int edge[][3])
{
    // First we sort the edge array in ascending order
    // so that we can access minimum distances/cost
    qsort(edge, n, sizeof(edge[0]), comparator);

    int parent[n];
    int rank[n];

    // Function to initialize parent[] and rank[]
    makeSet(parent, rank, n);

    // To store the minimum cost
    int minCost = 0;

    for (int i = 0; i < n; i++) {
        int v1 = findParent(parent, edge[i][0]);
        int v2 = findParent(parent, edge[i][1]);
        int wt = edge[i][2];

        // If the parents are different that
        // means they are in different sets so
        // union them
        if (v1 != v2) {
            unionSet(v1, v2, parent, rank, n);
            minCost += wt;
        }
    }

    return minCost;
}

// Function to check if the graph is already an MST
int isMST(int vertices_num, int edges_num, int mat[edges_num][3])
{
    int count_edges = 0;
    for (int i = 0; i < edges_num; i++) {
        if (mat[i][0] != mat[i][1])
            count_edges++;
    }

    if (count_edges == vertices_num - 1)
        return 1; // Graph is already an MST
    else
        return 0; // Graph is not an MST
}

// Driver code
int main()
{
    int n, p;
    scanf("%d %d", &n, &p);

    int edge[p][3];
    for (int i = 0; i < p; i++) {
        scanf("%d %d %d", &edge[i][0], &edge[i][1], &edge[i][2]);
    }

    // Check if the graph is already an MST
    if (isMST(n, p, edge)) {
        // If it is already an MST, calculate the weight directly
        int weight = 0;
        for (int i = 0; i < p; i++) {
            weight += edge[i][2];
        }
        printf("%d\n", weight);
    } else {
        // If it's not an MST, find the MST using Kruskal's algorithm
        int minCost = kruskalAlgo(p, edge);
        printf("%d\n", minCost);
    }

    return 0;
}
