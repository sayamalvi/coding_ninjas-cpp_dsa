#include <bits/stdc++.h>
using namespace std;

// Recursion - Brute force
int minCostPathRecursive(int **input, int m, int n, int i, int j)
{
    // Base Case
    if (i == m - 1 && j == n - 1)
        return input[i][j];
    if (i >= m || j >= n)
        return INT_MAX;
    // Recursion
    int x = minCostPathRecursive(input, m, n, i, j + 1);
    int y = minCostPathRecursive(input, m, n, i + 1, j);
    int z = minCostPathRecursive(input, m, n, i + 1, j + 1);

    // Small Calculation
    int ans = input[i][j] + min(x, min(y, z));
    return ans;
}
int minCostPathRecursive(int **input, int m, int n)
{
    return minCostPathRecursive(input, m, n, 0, 0);
}

// Memoization
int minCostPathMemo(int **input, int m, int n, int i, int j, int **output)
{
    // Base Case
    if (i == m - 1 && j == n - 1)
        return input[i][j];
    if (i >= m || j >= n)
        return INT_MAX;
    // Check if answer already exists
    if (output[i][j] != -1)
        return output[i][j];

    // Recursion
    int x = minCostPathMemo(input, m, n, i, j + 1, output);
    int y = minCostPathMemo(input, m, n, i + 1, j, output);
    int z = minCostPathMemo(input, m, n, i + 1, j + 1, output);

    // Small Calculation
    int a = input[i][j] + min(x, min(y, z));
    // Save answer for future use
    output[i][j] = a;

    return a;
}
int minCostPathMemo(int **input, int m, int n)
{
    int **output = new int *[n];
    for (int i = 0; i < m; i++)
    {
        output[i] = new int[m];
        for (int j = 0; j < n; j++)
        {
            output[i][j] = -1;
        }
    }
    return minCostPathMemo(input, m, n, 0, 0, output);
}

// DP
int minCostPathDP(int **input, int m, int n)
{
    int **output = new int *[m];
    for (int i = 0; i < m; i++)
    {
        output[i] = new int[n];
    }

    // Fill the last cell - Destination
    output[m - 1][n - 1] = input[m - 1][n - 1];

    // Fill last row right to left
    for (int j = n - 2; j >= 0; j--)
    {
        output[m - 1][j] = output[m - 1][j + 1] + input[m - 1][j];
    }

    // Fill last column bottom to top
    for (int i = m - 2; i >= 0; i--)
    {
        output[i][n - 1] = output[i + 1][n - 1] + input[i][n - 1];
    }

    // Fill remaining cells
    for (int i = m - 2; i >= 0; i--)
    {
        for (int j = n - 2; j >= 0; j--)
        {
            output[i][j] = min(output[i][j + 1], min(output[i + 1][j], output[i+1][j+1])) + input[i][j];
        }
    }
    return output[0][0];
}
int main()
{
    int m, n;
    cin >> m >> n;
    int **input = new int *[m];
    for (int i = 0; i < m; i++)
    {
        input[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            cin >> input[i][j];
        }
    }
    cout << minCostPathMemo(input, m, n) << endl;
    cout << minCostPathRecursive(input, m, n) << endl;
    cout << minCostPathDP(input, m, n) << endl;
}