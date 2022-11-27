#include <bits/stdc++.h>
using namespace std;
int pairSum(int *arr, int n)
{
    int count = 0;
    unordered_map<int, int> map;

    for (int i = 0; i < n; i++)
    {
        int x = -arr[i];
        if (map.count(x) > 0)
        {
            count += map[x];
            // count++;
        }
        map[arr[i]]++;
    }
    return count;
}

int main()
{
    int n;
    cin >> n;

    int *arr = new int[n];

    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    cout << pairSum(arr, n);

    delete[] arr;
}