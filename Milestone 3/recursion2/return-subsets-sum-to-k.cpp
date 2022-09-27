#include <iostream>
using namespace std;

// This approach didn't work for some reason, tried my ass off 
// int subsetSumToK(int input[], int n, int output[][50], int k)
// {
//     if (n == 0)
//     {
//         if (k == 0)
//         {
//             output[0][0] = 0;
//             return 1;
//         }
//         else
//             return 0;
//     }

//     int so1[1000][50], so2[1000][50], size1, size2;
//     size1 = subsetSumToK(input + 1, n - 1, so1, k - input[0]);
//     size2 = subsetSumToK(input + 1, n - 1, so2, k);

//     for (int i = 0; i < size1; i++)
//     {
//         output[i][0] = so1[i][0] + 1;
//         output[i][1] = input[0];

//         for (int j = 0; j < output[i][0]; j++)
//         {
//             output[i][j + 2] = so1[i][j + 1];
//         }
//     }
//     for (int i = 0; i < size2; i++)
//     {
//         for (int j = 0; j < so2[i][0]; j++)
//         {
//             output[i + size1][j] = so2[i][j];
//         }
//     }
//     return size1 + size2;
// }


int subsetSumToK(int input[], int n, int output[][50], int k)
{

    if (n == 0)
    {
        if (k == 0)
        {
            output[0][0] = 0;
            return 1;
        }
        else
            return 0;
    }
    int small1 = subsetSumToK(input + 1, n - 1, output, k);
    int small2 = subsetSumToK(input + 1, n - 1, output + small1, k - input[0]);

    int small = small1 + small2;
    for (int i = small1; i < small; i++)
    {
        for (int j = output[i][0]; j > 0; j--)
        {
            output[i][j + 1] = output[i][j];
        }
        output[i][1] = input[0];
        output[i][0]++;
    }

    return small;
}
int main()
{
}