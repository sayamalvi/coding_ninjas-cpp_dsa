#include <bits/stdc++.h>
using namespace std;
vector<int> kLargest(int arr[], int n, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < k; i++)
    {
        pq.push(arr[i]);
    }
    for (int i = k; i < n; i++)
    {
        if (arr[i] > pq.top())
        {
            pq.push(arr[i]);
            pq.pop();
        }
    }

    vector<int> ans;
    while (!pq.empty())
    {
        ans.push_back(pq.top());
        pq.pop();
    }
    return ans;
}

int main()
{
    int size;
    cin >> size;

    int *input = new int[size];

    for (int i = 0; i < size; i++)
    {
        cin >> input[i];
    }

    int k;
    cin >> k;

    vector<int> output = kLargest(input, size, k);
    sort(output.begin(), output.end());

    for (int i = 0; i < output.size(); i++)
    {
        cout << output[i] << " ";
    }

    delete[] input;
}