#include <iostream>
using namespace std;
bool isSorted(int a[], int size)
{
    if (size == 1)
        return true;

    if (a[0] > a[1])
        return false;
    bool isSmallerSorted = isSorted(a + 1, size - 1);
    return isSmallerSorted;
}
bool isSorted2(int a[], int size)
{
    if (size == 1)
        return true;

    bool isSmallerSorted = isSorted(a + 1, size - 1);
    return isSmallerSorted;
    if (a[0] > a[1])
        return false;
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    bool ans = isSorted2(arr, 6);
    cout << ans;
}