#include <iostream>
using namespace std;
void swapAlternate(int *arr, int size)
{

    int i = 0;
    while (i < size - 1)
    {
        int temp = arr[i];
        arr[i] = arr[i + 1];
        arr[i + 1] = temp;
        i += 2;
    }

    // int i = 0, j = 1, temp;
    // while (i <= size - 2)
    // {
    //     temp = arr[i];
    //     arr[i] = arr[j];
    //     arr[j] = temp;
    //     i += 2;
    //     j += 2;
    // }

}

int main()
{
}