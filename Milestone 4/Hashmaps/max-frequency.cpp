#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int highestFrequency(int input[], int n)
{
    unordered_map<int, int> max;
    for (int i = 0; i < n; i++)
    {
        max[input[i]]++;
    }
    int key = 0;
    int value = 0;

    for (int i = 0; i < n; i++)
    {
        if (max[input[i]] > value)
        {
            key = input[i];
            value = max[input[i]];
        }
    }
    return key;
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

    cout << highestFrequency(arr, n);

    delete[] arr;
}