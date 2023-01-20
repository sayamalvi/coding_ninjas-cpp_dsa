#include <bits/stdc++.h>
using namespace std;
void printSol(int **sol, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << sol[i][j] << " ";
        }
    }
}
void mazeHelp(int maze[][20], int n, int **sol, int x, int y)
{
    if (x == n - 1 && y == n - 1)
    {
        sol[x][y] = 1;
        printSol(sol, n);
    }
    if (x >= n || x < 0 || y >= n || y < 0 || maze[x][y] == 0 || sol[x][y] == 1)
        return;

    sol[x][y] = 1;
    mazeHelp(maze, n, sol, x - 1, y);
    mazeHelp(maze, n, sol, x + 1, y);
    mazeHelp(maze, n, sol, x, y - 1);
    mazeHelp(maze, n, sol, x, y + 1);
    sol[x][y] = 0;
}
void ratInAMaze(int maze[][20], int n)
{
    int **sol = new int *[n];
    for (int i = 0; i < n; i++)
    {
        sol[i] = new int[n];
    }
    mazeHelp(maze, n, sol, 0, 0);
}
int main()
{
}