#include <bits/stdc++.h>
using namespace std;
// DFS traversal
void print(int **edges, int startingVertex, bool *visited, int n)
{
    /*
      0 -> 2 -> 3 -> 1
    */
    cout << startingVertex << " ";
    visited[startingVertex] = true;
    for (int i = 0; i < n; i++)
    {
        if (i == startingVertex)
            continue;
        if (edges[startingVertex][i] == 1)
        {
            // print only if i is not visited
            if (visited[i] == true)
                continue;
            print(edges, i, visited, n);
        }
    }
}
int main()
{
    // Implementation with adjacency matrix
    int n, e;
    cin >> n >> e;
    // 2d array to store all the edges
    int **edges = new int *[n];
    for (int i = 0; i < n; i++)
    {
        edges[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            edges[i][j] = 0; // no edge
        }
    }
    // Take e edges input
    for (int i = 0; i < e; i++)
    {
        int firstVertex, secondVertex;
        cin >> firstVertex >> secondVertex;
        // Mark the edges in matrix, suppose the input is 1 2 which means there is and edge between 1 and 2. So in the edges matrix, mark edges[1][2] and edges[2][1] as 1
        edges[firstVertex][secondVertex] = 1;
        edges[secondVertex][firstVertex] = 1;
    }
    // If we don't use visited array our print function will get stuck in a loop of two vertices because two vertices will be adjacent to each other,i.e., they will have and edge between them
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    print(edges, 0, visited, n);
    delete[] visited;
    for (int i = 0; i < n; i++)
    {
        delete[] edges[i];
    }
    delete[] edges;
}