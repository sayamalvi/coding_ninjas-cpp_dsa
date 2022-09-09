#include <iostream>
using namespace std;
void merge(int *arr1, int size1, int *arr2, int size2, int *ans)
{
    int i = 0, j = 0, k = 0;
    while (i < size1 && j < size2)
    {

        if (arr1[i] < arr2[j])
        {
            ans[k++] = arr1[i++];
        }

        else
        {
            ans[k++] = arr2[j++];
        }
    }
    while (i < size1)
    {
        ans[k++] = arr1[i++];
    }
    while (j < size2)
    {
        ans[k++] = arr2[j++];
    }
}

int main()
{
    int arr1[] = {1, 3, 6, 11, 12, 17}, arr2[] = {2, 8, 12, 16, 19}, ans[] = {};
    merge(arr1, 6, arr2, 5, ans);
}