#include <bits/stdc++.h>
using namespace std;

// Brute force
int knapsackRecursive(int *weight, int *values, int n, int maxWeight)
{
    if (n == 0 || maxWeight == 0)
        return 0;
    if (weight[0] > maxWeight)
        return knapsackRecursive(weight + 1, values + 1, n - 1, maxWeight);

    int x = knapsackRecursive(weight + 1, values + 1, n - 1, maxWeight - weight[0]) + values[0];
    int y = knapsackRecursive(weight + 1, values + 1, n - 1, maxWeight);

    return max(x, y);
}
// Memoization
int knapsackMemo(int *weights, int *values, int n, int maxWeight, int **dp)
{
    if (n == 0 || maxWeight == 0)
        return 0;
    if (dp[maxWeight][n] != -1)
        return dp[maxWeight][n];
    if (weights[0] > maxWeight)
        return knapsackMemo(weights + 1, values + 1, n - 1, maxWeight, dp);
    int x = knapsackMemo(weights + 1, values + 1, n - 1, maxWeight - weights[0], dp) + values[0];
    int y = knapsackMemo(weights + 1, values + 1, n - 1, maxWeight, dp);

    dp[maxWeight][n] = max(x, y);
    return max(x, y);
}
int knapsackMemo(int *weights, int *values, int n, int maxWeight)
{
    int **dp = new int *[maxWeight + 1];
    for (int i = 0; i <= maxWeight; i++)
    {
        dp[i] = new int[n + 1];
        for (int j = 0; j <= n; j++)
        {
            dp[i][j] = -1;
        }
    }
    return knapsackMemo(weights, values, n, maxWeight, dp);
}
// DP
int knapsackDP(int *wt, int *values, int n, int W)
{
    int **dp = new int *[n + 1];
    for (int i = 0; i <= n; i++)
    {
        dp[i] = new int[W + 1];
        for (int j = 0; j <= W; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
            else
            {
                if (wt[i - 1] > j)
                    dp[i][j] = dp[i - 1][j];
                else
                    dp[i][j] = max(values[i - 1] + dp[i - 1][j - wt[i - 1]], dp[i - 1][j]);
            }
        }
    }
    return dp[n][W];
}
int main()
{
    int n;
    int weights[] = {5, 1, 8, 9, 2};
    int values[] = {4, 10, 2, 3, 1};
    int w = 15;
    cout << knapsackRecursive(weights, values, 5, w);
}