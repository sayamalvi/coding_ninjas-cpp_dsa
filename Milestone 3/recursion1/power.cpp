#include <iostream>
using namespace std;
int power(int x, int n)
{
    if (n == 0)
        return 1;
    int ans = power(x, n - 1);
    return ans * x;
}

int main()
{
}