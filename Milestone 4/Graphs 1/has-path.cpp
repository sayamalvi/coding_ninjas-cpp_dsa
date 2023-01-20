#include <bits/stdc++.h>
using namespace std;
bool hasPath(int **edges, int n, bool *visited, int v1, int v2)
{
    if(edges[v1][v2] == 1) return true;

    bool result = false;
    visited[v1] = true;
    for (int i = 0; i < n; i++)
    {

        if (i == v1)
            continue;
        if (edges[v1][i] == 1)
        {
            if (visited[i])
                continue;
           result = hasPath(edges, n, visited, i, v2);
        } 
        if(result == true) return true;
    }
    return result;
}
int main() {
    int v,e;
    cin >> v >> e;
    int **edges = new int*[v];
    for(int i = 0; i<v; i++ ){
        edges[i] = new int[v];
        for(int j = 0; j<v; j++){
            edges[i][j] = 0;
        }
    }
    for(int i = 0; i<e; i++){
        int f, s;
        cin >> f >> s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }
    int v1, v2;
    cin >> v1 >> v2;
    bool *visited = new bool[v];
    for(int i = 0; i<v; i++){
        visited[i] = false;
    }
    hasPath(edges, v, visited, v1, v2) == true ? cout << "true" : cout << "false";
    delete [] visited;
    for(int i = 0; i<v; i++) delete [] edges[i];
    delete [] edges;
}