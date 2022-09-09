#include <iostream>
using namespace std;
void rotate(int *input, int d, int n)
{
    int temp[d], j = 0;
    for (int i = 0; i < d; i++)
    {
        temp[i] = input[i];
    }
    for (int i = 0; i < n; i++)
    {
        input[i] = input[i + d];
    }
    for (int i = n - d; i < n; i++)
    {
        input[i] = temp[j];
        j++;
    }
}
int main()
{
}