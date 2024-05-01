# Kruskal's Algorithm

Your task is to perform Kruskal's Algorithm to create a minimum spanning tree from the given graph.

## Graph

The graph has 8 nodes and 10 edges. Each edge is represented by a pair of connected vertices and their corresponding weight.

- 1 -> 7 with weight 7
- 1 -> 2 with weight 27
- 1 -> 3 with weight 8
- 2 -> 3 with weight 30
- 2 -> 5 with weight 17
- 3 -> 5 with weight 42
- 4 -> 5 with weight 10
- 5 -> 7 with weight 14
- 5 -> 6 with weight 5
- 6 -> 7 with weight 15

## Minimum Spanning Tree

After performing Kruskal's Algorithm, the final minimum spanning tree is shown in the image below:

![Minimum Spanning Tree](path/to/image.png)

The total weight of the minimum spanning tree is 61.

## Input

The input consists of `p + 1` lines.

First Line:
An integer `n` (1 ≤ n ≤ 100) indicating the number of vertices.
An integer `p` (1 ≤ p ≤ 100) indicating the number of edges.

Next `p` lines:
The pair of connected vertices and their edge weight in the following format: `start end weight`

## Output

The output consists of one line:
The total weight of the minimum spanning tree.

## Example

Example of input and output
Input:
8 10
1 7 7
1 2 27
1 3 8
2 3 30
2 5 17
3 5 42
4 5 10
5 7 14
5 6 5
6 7 15

Output:
61