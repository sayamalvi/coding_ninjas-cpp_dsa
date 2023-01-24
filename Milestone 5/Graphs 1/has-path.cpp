#include <bits/stdc++.h>
using namespace std;

bool hasPathBFS(int n, int **edges, int sv, int v1, int v2)
{
    bool visited[n] = {false};
    queue<int> q;
    q.push(sv);
    visited[sv] = true;
    while (!q.empty())
    {
        int cv = q.front();
        q.pop();
        for (int i = 0; i < n; i++)
        {
            if (i == cv)
                continue;
            if (edges[cv][i] && !visited[i])
            {
                visited[i] = true;
                q.push(i);
            }
        }
    }
    if (visited[v1] && visited[v2])
        return true;
    else
        return false;
}

bool checkPathDFS(int n, int **edges, int sv, int v1, int v2, bool *visited)
{
    if (visited[v1] && visited[v2])
        return true;
    visited[sv] = true;
    bool res;
    for (int i = 0; i < n; i++)
    {
        if (i == sv)
            continue;
        if (!visited[i] && edges[sv][i] == 1)
        {
            visited[i] = true;
            res = checkPathDFS(n, edges, i, v1, v2, visited);
            if (res)
                return true;
        }
    }
    return false;
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
    int v1, v2;
    cin >> v1 >> v2;
    hasPathBFS(n, edges, 0, v1, v2) ? cout << "true" : cout << "false";
}