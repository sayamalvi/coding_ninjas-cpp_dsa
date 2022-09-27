#include <iostream>
using namespace std;
int main()
{
    // int *p = new int;
    // *p = 10;
    // cout << *p << endl;

    cout << "Enter num of elements";
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int max = -99999999;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    cout << max;
    delete[] arr;
}