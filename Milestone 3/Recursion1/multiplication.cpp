#include <iostream>
int multiplyNumbers(int m, int n)
{
    if (m == 0 || n == 0)
        return 0;
    int small = multiplyNumbers(m, n - 1);
    int ans = m + small;
    return ans;
}

using namespace std;
int main()
{
}