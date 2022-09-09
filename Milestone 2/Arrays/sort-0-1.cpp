#include <iostream>
using namespace std;
void sortZeroesAndOne(int *input, int size)
{
    int nz = 0;
    for (int i = 0; i < size; i++)
    {
        if (input[i] == 0)
        {
            int temp = input[i];
            input[i] = input[nz];
            input[nz] = temp;
            nz++;
        }
    }

    // second approach
    // int i = 0, j = size - 1;
    // for (; i <= j; i++)
    // {
    //     if (input[i] == 0)
    //     {
    //         continue;
    //     }
    //     else
    //     {
    //         for (; j > i; j--)
    //         {
    //             if (input[j] == 1)
    //             {
    //                 continue;
    //             }
    //             else
    //             {
    //                 int temp = input[i];
    //                 input[i] = input[j];
    //                 input[j] = temp;
    //                 break;
    //             }
    //         }
    //     }
    // }
}
int main()
{
}