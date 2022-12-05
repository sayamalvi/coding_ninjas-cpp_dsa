#include <bits/stdc++.h>
using namespace std;
void heapSort(int arr[], int n)
{
    // build the heap in input array
    for (int i = 1; i < n; i++)
    {
        int childIndex = i;
        while (childIndex > 0)
        {
            int parentIndex = (childIndex - 1) / 2;
            if (arr[childIndex] < arr[parentIndex])
            {
                swap(arr[childIndex], arr[parentIndex]);
            }
            else
                break;
            childIndex = parentIndex;
        }
    }
    // remove element
    int size = n;
    while (size > 1)
    {

        swap(arr[0], arr[size - 1]);
        size--;

        int pi = 0;
        int lci = (2 * pi) + 1;
        int rci = (2 * pi) + 2;
        while (lci < size)
        {
            int mini = pi;
            if (arr[mini] > arr[lci])
                mini = lci;
            if (arr[mini] > arr[rci] && rci < size)
                mini = rci;
            if (mini == pi)
                break;
            swap(arr[pi], arr[mini]);
            pi = mini;
            lci = (2 * pi) + 1;
            rci = (2 * pi) + 2;
        }
    }
}
int main()
{
    int input[] = {5, 1, 2, 0, 8};
    heapSort(input, 5);
    for (int i = 0; i < 5; i++)
    {
        cout << input[i] << " ";
    }
}