#include <iostream>
using namespace std;
void pushZeroesEnd(int *input, int size)
{
    int j = 0;
    for (int i = 0; i < size; i++)
    {
        if (input[i] != 0)
        {
            int temp = input[i];
            input[i] = input[j];
            input[j] = temp;
            j++;
        }
    }

    // int i = 0, j = 0;
    // while (i < size)
    // {
    //     if (input[i] != 0)
    //     {
    //         int temp = input[i];
    //         input[i] = input[j];
    //         input[j] = temp;
    //         i++;
    //         j++;
    //     }
    //     else
    //         i++;
    // }
}

int main()
{
}