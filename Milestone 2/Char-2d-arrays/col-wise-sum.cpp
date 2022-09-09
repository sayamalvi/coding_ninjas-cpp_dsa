#include <iostream>
using namespace std;

int main()
{
    int m, n;
    cin >> m >> n;
    int a[m][n];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }

    int j = 0, sum = 0;
    while (j < n)
    {
        int i = 0;
        while (i < m)
        {
            sum = sum + a[i][j];
            i++;
        }
        cout << sum << " ";
        sum = 0;
        j++;
    }

    // int sum = 0;
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         sum += a[j][i];
    //     }
    //     cout << sum << " ";
    //     sum = 0;
    // }
}
