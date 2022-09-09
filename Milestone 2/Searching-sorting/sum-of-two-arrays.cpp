#include <iostream>
using namespace std;
void sumOfTwoArrays(int *input1, int size1, int *input2, int size2, int *output)
{
    int size3;
    if (size1 > size2)
        size3 = size1 + 1;
    else
        size3 = size2 + 1;
    int sum = 0, carry = 0, i = size1 - 1, j = size2 - 1, k = size3 - 1;

    while (i >= 0 && j >= 0)
    {
        sum = input1[i--] + input2[j--] + carry;
        output[k--] = sum % 10;
        carry = sum / 10;
    }
    while (i >= 0)
    {
        output[k--] = input1[i--];
    }
    while (j >= 0)
    {
        output[k--] = input2[j--];
    }
    while (k >= 0)
    {
        output[k--] = carry;
    }

    // int i = size1 - 1, j = size2 - 1;
    // int carry = 0;
    // int k;
    // if (size1 < size2)
    // {
    //     k = size2;
    // }
    // else if (size2 > size1)
    // {
    //     k = size1;
    // }
    // else
    //     k = size1;

    // while (k >= 0)
    // {
    //     output[k] = (input1[i] + input2[j] + carry) % 10;
    //     carry = (input1[i] + input2[j] + carry) / 10;
    //     if (i > 0)f
    //         i--;
    //     else
    //     {

    //         input1[i] = 0;
    //     }

    //     if (j > 0)
    //         j--;
    //     else
    //     {

    //         input2[j] = 0;
    //     }
    //     k--;
    // }
}

int main()
{
}