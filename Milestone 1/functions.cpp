#include <iostream>
using namespace std;

int factorial(int n)
{
    int ans = 1;
    int i = 1;
    while (i <= n)
    {
        ans = ans * i;
        i++;
    }
    return ans;
}

int isPrime(int n)
{
    int d = 2;
    while (d < n)
    {
        if (d % n == 0)
        {
            return false;
        }
        d++;
    }
    return true;
}

void oneToN(int n)
{
    for (int i = 1; i <= n; i++)
    {
        cout << i << endl;
    }
}

int multi(int x, int y)
{
    return x * y;
}

void printTable(int start, int end, int step)
{
    while (start <= end)
    {
        int cel = (5.0 / 9) * (start - 32);
        cout << start << " " << cel << endl;
        start += step;
    }
}

bool checkMember(int n)
{

    cin >> n;
    int n1 = 0, n2 = 1;
    if (n == 0 || n == 1)
    {
        return true;
    }

    else
    {
        for (int i = 2; i <= n; i++)
        {
            int n3 = n1 + n2;
            n1 = n2;
            n2 = n3;
            if (n == i)
            {
                return true;
            }
        }
    }
}


void increment(int a)
{
    a = a + 10;
}

int main()
{
    // int r, n;
    // cin >> n >> r;
    // int fact_r = factorial(r);
    // int fact_n = factorial(n);
    // int fact_n_r = factorial(n - r);

    // int ans = fact_n / (fact_r * fact_n_r);
    // cout << ans << endl;

    // bool check = isPrime(31);
    // cout << check << endl;

    // oneToN(10);

    // cout << multi(4, 3) << endl;

    int n = 10;
    increment(n);
    cout << n << endl;
}