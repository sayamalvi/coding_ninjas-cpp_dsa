#include <bits/stdc++.h>
using namespace std;

// Recursive
int countMinStepsRecursive(int n)
{
    if (n <= 1)
        return 0;
    int ans = countMinStepsRecursive(n - 1);
    int x = INT_MAX, y = INT_MAX;
    if (n % 2 == 0)
    {
        x = countMinStepsRecursive(n / 2);
    }
    if (n % 3 == 0)
    {
        y = countMinStepsRecursive(n / 3);
    }
    return min(ans, min(x, y)) + 1;
}

// Memoization
int countMinStepsMemo(int n, int *ans)
{
    if (n <= 1)
        return 0;
    if (ans[n] != -1)
        return ans[n];

    int x = countMinStepsMemo(n - 1, ans);
    int y = INT_MAX, z = INT_MAX;
    if (n % 2 == 0)
    {
        y = countMinStepsMemo(n / 2, ans);
    }
    if (n % 3 == 0)
    {
        z = countMinStepsMemo(n / 3, ans);
    }
    int output = min(x, min(y, z)) + 1;
    ans[n] = output;
    return output;
}
int countMinStepsMemo(int n)
{
    int *ans = new int[n + 1];
    for (int i = 0; i <= n; i++)
        ans[i] = -1;

    return countMinStepsMemo(n, ans);
}
// DP
int countMinStepsDP(int n)
{
    int *ans = new int[n + 1];
    ans[0] = ans[1] = 0;
    for (int i = 2; i <= n; i++)
    {
        int subtractOne = ans[i - 1];
        int divTwo = INT_MAX;
        int divThree = INT_MAX;
        if (i % 2 == 0)
            divTwo = ans[i / 2];
        if (i % 3 == 0)
            divThree = ans[i / 3];
        ans[i] = min(subtractOne, min(divTwo, divThree));
    }
    return ans[n];
}
int main()
{
    int n;
    cin >> n;
    // cout << countMinStepsRecursive(n);
    cout << countMinStepsMemo(n);
}