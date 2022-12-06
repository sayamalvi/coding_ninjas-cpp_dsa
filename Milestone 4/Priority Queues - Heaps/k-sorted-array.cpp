#include <bits/stdc++.h>
using namespace std;
void kSortedArray(int arr[], int n, int k)
{
    priority_queue<int> pq;
    for (int i = 0; i < k; i++)
    {
        pq.push(arr[i]);
    }
    int j = 0;
    for (int i = k; i < n; i++)
    {
        arr[j] = pq.top();
        pq.pop();
        pq.push(arr[i]);
        j++;
    }
    while (!pq.empty())
    {
        arr[j] = pq.top();
        pq.pop();
    }
}
int main()
{
    int input[] = {10, 12, 6, 7, 9};
    kSortedArray(input, 5, 3);
    for (int i = 0; i < 5; i++)
    {
        cout << input[i] << " ";
    }
}