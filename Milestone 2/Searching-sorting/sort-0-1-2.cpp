#include <iostream>
using namespace std;
void sort012(int *arr, int n)
{
    int nz = 0, nt = n - 1;

    int i = 0;
    while (i <= nt)
    {
        if (arr[i] == 0)
        {
            int temp = arr[i];
            arr[i] = arr[nz];
            arr[nz] = temp;

            nz++;
            i++;
        }

        else if (arr[i] == 2)
        {
            int temp = arr[i];
            arr[i] = arr[nt];
            arr[nt] = temp;

            nt--;
        }
        else
            i++;
    }
}
int main()
{
}