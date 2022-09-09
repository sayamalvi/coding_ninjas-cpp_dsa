#include <iostream>
using namespace std;
void bubbleSort(int arr[], int n)
{
    for (int j = 0; j < n - 1; j++)
    {
        for (int i = 0; i < n - 1 - j; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
            }
        }
    }
}

int main()
{
    int input[] = {32, 42, 6, 75, 345, 76};
    bubbleSort(input, 6);
    for (int i = 0; i < 6; i++)
    {
        cout << input[i] << " ";
    }
}