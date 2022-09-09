#include <iostream>
using namespace std;
void printArray(int a[][100], int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << a[i][j];
        }
        cout << endl;
    }
}
int main()
{
    int a[100][100];
    int m, n;
    cin >> m >> n;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }
    printArray(a, m, n);
    // Row wise printing
    // int sum = 0;
    // for (int i = 0; i < m; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         sum = sum + a[i][j];
    //     }
    //     cout << sum;
    // }
    // Column wise printing
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         cout << a[j][i];
    //     }
    //     cout << endl;
    // }
}