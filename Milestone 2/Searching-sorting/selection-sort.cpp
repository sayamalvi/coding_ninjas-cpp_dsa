#include <iostream>
using namespace std;
void selectionSort(int input[], int n)
{
    // Outer loop represents which round are we working on , 0 to n-2,total rounds = n-1 , size of array = n
    for (int i = 0; i < n - 1; i++)
    {
        // min element in array and index of min element. Min element will start from i because we are skipping one element as we are progressing in rounds
        int min = input[i], minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (input[j] < min)
            {
                min = input[j];
                minIndex = j;
            }
        }
        // swap min element with its correct position
        int temp = input[i];
        input[i] = input[minIndex];
        input[minIndex] = temp;
    }
}
int main()
{
    int input[] = {32, 42, 6, 75, 345, 76};
    selectionSort(input, 6);
    for (int i = 0; i < 6; i++)
    {
        cout << input[i] << " ";
    }
}
