#include <bits/stdc++.h>
using namespace std;
void printBFS(int **edges, int n, int sv, bool *visited)
{
    queue<int> seenVertices;
    seenVertices.push(sv);
    visited[sv] = true;
    while (!seenVertices.empty())
    {
        int currentVertex = seenVertices.front();
        seenVertices.pop();
        cout << currentVertex << " ";
        for (int i = 0; i < n; i++)
        {
            if (i == currentVertex)
                continue;
            if (edges[i][currentVertex] == 1 && !visited[i])
            {
                seenVertices.push(i);
                visited[i] = true;
            }
        }
    }
}
void BFS(int **edges, int n)
{
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
        visited[i] = false;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
            printBFS(edges, n, i, visited);
    }
    delete[] visited;
}
void printDFS(int **edges, int n, int sv, bool *visited)
{
    cout << sv << " ";
    visited[sv] = true;
    for (int i = 0; i < n; i++)
    {
        if (sv == i)
            continue;
        if (edges[i][sv] == 1 && !visited[i])
        {
            printDFS(edges, n, i, visited);
        }
    }
}
void DFS(int **edges, int n)
{
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
        visited[i] = false;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
            printDFS(edges, n, i, visited);
    }
    delete[] visited;
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
    cout << "DFS" << endl;
    DFS(edges, n);
    cout << endl;
    cout << "BFS" << endl;
    BFS(edges, n);
    for (int i = 0; i < n; i++)
    {
        delete[] edges[i];
    }
    delete[] edges;
}