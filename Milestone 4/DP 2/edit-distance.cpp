#include <bits/stdc++.h>
using namespace std;

// Bruteforce
int editDistance(string s1, string s2)
{
    if (s1.size() == 0 || s2.size() == 0)
    {
        return max(s1.size(), s2.size());
    }
    if (s1[0] == s2[0])
    {
        return editDistance(s1.substr(1), s2.substr(1));
    }
    else
    {
        int x = editDistance(s1, s2.substr(1)) + 1;
        int y = editDistance(s1.substr(1), s2) + 1;
        int z = editDistance(s1.substr(1), s2.substr(1)) + 1;
        return min(x, min(y, z));
    }
}
// Memoization
int editDistanceMemo(string s1, string s2, int **output)
{
    int m = s1.size();
    int n = s2.size();

    if (s1.size() == 0 || s2.size() == 0)
    {
        return max(s1.size(), s2.size());
    }

    if (output[m][n] != -1)
        return output[m][n];
    int ans;
    if (s1[0] == s2[0])
    {
        ans = editDistanceMemo(s1.substr(1), s2.substr(1), output);
    }
    else
    {
        int x = editDistanceMemo(s1, s2.substr(1), output) + 1;
        int y = editDistanceMemo(s1.substr(1), s2, output) + 1;
        int z = editDistanceMemo(s1.substr(1), s2.substr(1), output) + 1;
        ans = min(x, min(y, z));
    }
    output[m][n] = ans;
    return ans;
}
int editDistanceMemo(string s1, string s2)
{
    int m = s1.size();
    int n = s2.size();
    int **output = new int *[m + 1];
    for (int i = 0; i <= m; i++)
    {
        output[i] = new int[n + 1];
        for (int j = 0; j <= n; j++)
        {
            output[i][j] = -1;
        }
    }
    return editDistanceMemo(s1, s2, output);
}
// DP
int editDistanceDP(string s, string t)
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
        output[0][j] = j;
    }
    for (int i = 1; i <= m; i++)
    {
        output[i][0] = i;
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s[m - i] == t[n - j])
            {
                output[i][j] = output[i - 1][j - 1];
            }
            else
            {
                int a = output[i - 1][j] + 1;
                int b = output[i][j - 1] + 1;
                int c = output[i - 1][j - 1] + 1;

                output[i][j] = min(a, min(b, c));
            }
        }
    }
    return output[m][n];
}
int main()
{
    string s1;
    string s2;

    cin >> s1;
    cin >> s2;

    cout << editDistance(s1, s2);
}