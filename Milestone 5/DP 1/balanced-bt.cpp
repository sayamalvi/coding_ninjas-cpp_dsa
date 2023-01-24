#include <bits/stdc++.h>
using namespace std;
// recursive
int balancedBtRec(int h)
{
    if (h <= 1)
        return 1;
    int mod = (int)(pow(10, 9)) + 7;
    int x = balancedBtRec(h - 1);
    int y = balancedBtRec(h - 2);
    int a = (int)(((long)(x)*x) % mod);
    int b = (int)((2 * (long)(x)*y) % mod);
    int ans = (a + b) % mod;
    return ans;
}
// dp
int balancedBTDP(int h)
{
    int mod = (int)(pow(10, 9)) + 7;
    int ans[h + 1];
    ans[0] = 1;
    ans[1] = 1;
    for (int i = 2; i <= h; i++)
    {
        ans[i] = ((int)(((long)(ans[i - 1]) * ans[i - 1]) % mod) +
                  (int)(2 * ((long)(ans[i - 1]) * ans[i - 2]) % mod)) %
                 mod;
    }
    return ans[h];
}
int main()
{
    int h;
    cin >> h;
    cout << balancedBtRec(h) << endl;
}