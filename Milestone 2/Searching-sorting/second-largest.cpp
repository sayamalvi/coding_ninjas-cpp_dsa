#include <iostream>
#include <limits.h>
using namespace std;
int findSecondLargest(int *input, int n)

{
    int max = INT_MIN, secMax = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (input[i] > max)
        {
            secMax = max;
            max = input[i];
        }
        else if (input[i] > secMax && input[i] != max)
        {
            secMax = input[i];
        }
    }
    return secMax;
}
int main()
{
}