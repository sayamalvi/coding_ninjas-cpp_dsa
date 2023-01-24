#include <bits/stdc++.h>
using namespace std;

int fiboHelper(int n, int *ans)
{
    if (n <= 1)
        return n;
    if (ans[n] != -1)
        return ans[n];
    int a = fiboHelper(n - 1, ans);
    int b = fiboHelper(n - 1, ans);
    ans[n] = a + b;
    return ans[n];
}
// Memoization
int fibo(int n)
{
    int *ans = new int[n + 1];
    for (int i = 0; i < n; i++)
    {
        ans[i] = -1;
    }
    return fiboHelper(n, ans);
}
// DP
int fibo2(int n)
{
    int *ans = new int[n + 1];
    ans[0] = 0;
    ans[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        ans[i] = ans[i - 1] + ans[i - 2];
    }
}
int main()
{
}