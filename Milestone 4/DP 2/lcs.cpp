#include <bits/stdc++.h>
using namespace std;
// Brute force - Recursion
int lcsRecursive(string s, string t)
{
    if (s.size() == 0 || t.size() == 0)
        return 0;

    if (s[0] == t[0])
    {
        return 1 + lcsRecursive(s.substr(1), t.substr(1));
    }
    else
    {
        int a = lcsRecursive(s.substr(1), t);
        int b = lcsRecursive(s, t.substr(1));
        int c = lcsRecursive(s.substr(1), t.substr(1));
        return max(a, max(b, c));
    }
}

// Memoization
int lcsMemo(string s, string t, int **output)
{
    int m = s.size();
    int n = t.size();
    // Base case
    if (s.size() == 0 || t.size() == 0)
        return 0;
    // Check if answer already exists
    if (output[m][n] != -1)
        return output[m][n];
    // Recursive calls
    int ans;
    if (s[0] == t[0])
    {
        ans = 1 + lcsMemo(s.substr(1), t.substr(1), output);
    }
    else
    {
        int a = lcsMemo(s.substr(1), t, output);
        int b = lcsMemo(s, t.substr(1), output);
        int c = lcsMemo(s.substr(1), t.substr(1), output);
        ans = max(a, max(b, c));
    }
    // Save your calculations
    output[m][n] = ans;
    return ans;
}
int lcsMemo(string s, string t)
{
    int m = s.size();
    int n = t.size();
    int **output = new int *[m + 1];
    for (int i = 0; i <= m; i++)
    {
        output[i] = new int[n + 1];
        for (int j = 0; j <= n; j++)
        {
            output[i][j] = -1;
        }
    }
    return lcsMemo(s, t, output);
}

// DP
int lcsDP(string s, string t)
{
    int m = s.size();
    int n = t.size();
    int **output = new int *[m + 1];
    for (int i = 0; i <= m; i++)
    {
        output[i] = new int[n + 1];
    }
    for (int j = 0; j <= n; j++)
    {
        output[0][j] = 0;
    }
    for (int i = 1; i <= m; i++)
    {
        output[i][0] = 0;
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s[m - i] == t[n - j])
            {
                output[i][j] = 1 + output[i - 1][j - 1];
            }
            else
            {
                int a = output[i - 1][j];
                int b = output[i][j - 1];
                int c = output[i - 1][j - 1];
                output[i][j] = max(a, max(a, b));
            }
        }
    }
    return output[m][n];
}
int main()
{
    string s, t;
    cin >> s >> t;
    // cout << lcsRecursive(s, t) << endl;
    cout << lcsMemo(s, t) << endl;
}