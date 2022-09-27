#include <iostream>
using namespace std;
void merge(int a[], int si, int mid, int ei)
{
    int k = 0;
    int size = ei - si + 1;
    int output[size] = {0};
    int i = si, j = mid + 1;
    while (i <= mid && j <= ei)
    {
        if (a[i] < a[j])
            output[k++] = a[i++];
        else
            output[k++] = a[j++];
    }

    while (j <= ei)
        output[k++] = a[j++];

    while (i <= mid)
        output[k++] = a[i++];

    k = 0;
    for (int i = si; i <= ei; i++)
    {
        a[i] = output[k];
        k++;
    }
}

void merge_sort(int a[], int si, int ei)
{
    if (si >= ei)
        return;
    int mid;
    if (si < ei)
    {
        mid = (si + ei) / 2;
        merge_sort(a, si, mid);
        merge_sort(a, mid + 1, ei);
        merge(a, si, mid, ei);
    }
}

void mergeSort(int input[], int size)
{
    if (size <= 1)
        return;
    merge_sort(input, 0, size - 1);
}

int main()
{
}