#include <iostream>
using namespace std;

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
