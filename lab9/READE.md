# BFS and DFS

## Problem Description

Your task is to perform undirected graph traversal using both Breadth-first search (BFS) and Depth-first search (DFS) algorithms, starting from a given node.

Given the following sequence of connections:

0 -> 1
0 -> 2
1 -> 3
1 -> 4
2 -> 4

The connections are listed from top to bottom. For example, node 1 will connect to node 3 before connecting to node 4.

After that, you will be provided with a starting node. For example, if we start at node 0, the sequence of Depth-first search traversal will be: 0 1 3 4 2, and the sequence of Breadth-first search traversal will be: 0 1 2 3 4.

Your task is to determine the sequence of both traversals.

## Input

The input consists of several lines:

- First Line: An integer 𝑛, which determines the number of edges.
- Next 𝑛 lines: The pair of connected vertices.
- Final line: An integer 𝑥, which states the starting node.

## Output

The output consists of two lines:

- First line: A sequence of Depth-first search traversal.
- Second line: A sequence of Breadth-first search traversal.

## Example

Input:
5
0 1
0 2
1 3
1 4
2 4
0

Output:
0 1 3 4 2
0 1 2 3 4
