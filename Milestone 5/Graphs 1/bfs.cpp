#include <bits/stdc++.h>
using namespace std;

// BFS traversal
void printBFS(int **edges, int n, int sv)
{
    queue<int> seenVertices;
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
        visited[i] = false;
    seenVertices.push(sv);
    visited[sv] = true;
    while (!seenVertices.empty())
    {
        int currentVertex = seenVertices.front();
        seenVertices.pop();
        cout << currentVertex << " ";
        for (int i = 0; i < n; i++)
        {
            if (i == sv)
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