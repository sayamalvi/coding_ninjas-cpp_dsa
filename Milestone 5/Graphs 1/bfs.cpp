#include <bits/stdc++.h>
using namespace std;

// BFS traversal
void printBFS(int **edges, int n, int sv)
{
    // first come first serve
    queue<int> seenVertices;
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
        visited[i] = false;
    // push starting vertex into queue and mark it as visited
    seenVertices.push(sv);
    visited[sv] = true;
    while (!seenVertices.empty())
    {
        // store first element and pop it, then print it.
        int currentVertex = seenVertices.front();
        seenVertices.pop();
        cout << currentVertex << " ";
        // check who has edges with the currentVertex
        for (int i = 0; i < n; i++)
        {
            if (i == currentVertex)
                continue;
            if (edges[currentVertex][i] == 1 && !visited[i])
            {
                visited[i] = true;
                seenVertices.push(i);
            }
        }
    }
}
int main()
{
    int n, e;
    cin >> n >> e;
    int **edges = new int *[n];
    for (int i = 0; i < n; i++)
    {
        edges[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            edges[i][j] = 0; // no edge
        }
    }
    for (int i = 0; i < e; i++)
    {
        int firstVertex, secondVertex;
        cin >> firstVertex >> secondVertex;
        edges[firstVertex][secondVertex] = 1;
        edges[secondVertex][firstVertex] = 1;
    }
    printBFS(edges, n, 0);
    for (int i = 0; i < n; i++)
    {
        delete[] edges[i];
    }
    delete[] edges;
}