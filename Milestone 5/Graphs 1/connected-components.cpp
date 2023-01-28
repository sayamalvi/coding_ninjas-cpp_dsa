// same as bfs/dfs for disconnected graph. we just need to store our vertices in a vector and return that vector for every disconnected edge.
#include <bits/stdc++.h>
using namespace std;
vector<int> printBFS(int **edges, int n, int sv, bool *visited)
{
    vector<int> ans;
    queue<int> seenVertices;
    seenVertices.push(sv);
    visited[sv] = true;
    while (!seenVertices.empty())
    {
        int currentVertex = seenVertices.front();
        seenVertices.pop();
        ans.push_back(currentVertex);
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
    return ans;
}
void BFS(int **edges, int n)
{
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
        visited[i] = false;
    for (int i = 0; i < n; i++)
    {
        vector<int> temp;
        if (!visited[i])
            temp = printBFS(edges, n, i, visited);
        sort(temp.begin(), temp.end());
        for (int i = 0; i < temp.size(); i++)
            cout << temp[i] << " ";
        cout << endl;
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
            edges[i][j] = 0;
        }
    }
    for (int i = 0; i < e; i++)
    {
        int firstVertex, secondVertex;
        cin >> firstVertex >> secondVertex;
        edges[firstVertex][secondVertex] = 1;
        edges[secondVertex][firstVertex] = 1;
    }

    BFS(edges, n);
    for (int i = 0; i < n; i++)
    {
        delete[] edges[i];
    }
    delete[] edges;
}