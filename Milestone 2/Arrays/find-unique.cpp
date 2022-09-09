#include <iostream>
using namespace std;
int findUnique(int *arr, int size)
{

    bool isUni = true;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (i == j)
                continue;
            if (arr[i] == arr[j])
            {
                isUni = false;
                break;
            }
            else
                isUni = true;
        }
        if (isUni == true)
            return arr[i];
    }

    // bool isUni = true;
    // for (int i = 0; i < size; i++)
    // {
    //     for (int j = 0; j < size; j++)
    //     {
    //         if (size == 1)
    //             return arr[i];
    //         if (i == j)
    //             continue;
    //         if (arr[i] == arr[j])
    //         {
    //             isUni = false;
    //             break;
    //         }
    //         else
    //             isUni = true;
    //     }
    //     if (isUni == true)
    //         return arr[i];
    // }
}

int main()
{
}