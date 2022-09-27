#include <iostream>
using namespace std;

int binarySearch(int input[], int start, int end, int element)
{
    if (start > end)
        return -1;
    int mid = (start + end) / 2;
    if (input[mid] == element)
        return mid;
    if (element > input[mid])
        return binarySearch(input, mid + 1, end, element);
    else if (element < input[mid])
        return binarySearch(input, start, mid - 1, element);
}

int binarySearch(int input[], int size, int element)
{
    if (size == 0)
        return -1;
    int start = 0, end = size - 1;
    return binarySearch(input, start, end, element);
}

int main()
{
}