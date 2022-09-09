#include <iostream>
using namespace std;
int main()
{
    // int n, i = 1;
    // cout << "Enter n";
    // cin >> n;
    // while (i <= n)
    // {
    //     cout << i << endl;
    //     i++;
    // }
    int n, d = 2;
    cout << "Enter n" << endl;
    cin >> n;
    while (d < n)
    {
        if (n % d == 0)
        {
            cout << "Not prime";
        }
        d++;
    }
    if (d >= n)
    {
        cout << "Prime";
    }

    return 0;
}