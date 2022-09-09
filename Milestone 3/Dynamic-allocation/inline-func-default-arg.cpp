#include <iostream>
using namespace std;
inline int max(int a, int b = 0)
{
    return (a > b) ? a : b;
}
int sum(int a[], int size, int si = 0)
{
    int ans = 0;
    for (int i = si; i < size; i++)
    {
        ans += a[i];
    }
    return ans;
}
int sum2(int a, int b, int c = 10, int d = 0)
{
    return a + b + c + d;
}
int main()
{
    // int a, b;
    // cin >> a >> b;
    // int c = max(a, b);
    // cout << c;
    // int x, y;
    // x = 12, y = 43;
    // int z = max(x, y);
    // cout << z;

    // int arr[5];
    // for (int i = 0; i < 5; i++)
    // {
    //     cin >> arr[i];
    // }
    // cout << sum(arr, 5, 3) << endl;

    int ans = sum2(10, 20);
    cout << ans;
}