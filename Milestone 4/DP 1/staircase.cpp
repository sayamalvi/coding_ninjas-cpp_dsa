#include <bits/stdc++.h>
using namespace std;
int MOD = long(1e9 + 7);
long staircase(int n)
{
    long dp[n + 1];
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; i++)
    {
        dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3]) % MOD;
    }
    return dp[n] % MOD;
}
int main()
{
    int t = 0;
    cin >> t;
    int n;
    for (int i = 0; i < t; i++)
    {
        cin >> n;
        cout << staircase(n) << endl;
    }
}