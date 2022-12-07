#include <bits/stdc++.h>
using namespace std;
bool isMaxHeap(int arr[], int n)
{
    int pi = 0, lci = (2 * pi) + 1, rci = (2 * pi) + 2;
    while (lci < n)
    {
        if (arr[pi] > arr[lci] && arr[pi] > arr[rci])
        {
            pi++;
            lci = (2 * pi) + 1;
            rci = (2 * pi) + 2;
        }
        else
            return false;
    }
    return true;
}
int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << (isMaxHeap(arr, n) ? "true\n" : "false\n");

    delete[] arr;
}