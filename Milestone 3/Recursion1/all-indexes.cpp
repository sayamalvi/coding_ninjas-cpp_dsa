#include <iostream>

int allIndexes(int input[], int size, int x, int output[])
{

    if (size == 0)
        return 0;
    int ans = allIndexes(input, size - 1, x, output);
    if (input[size - 1] == x)
    {
        output[ans] = size - 1;
        return ans + 1;
    }
    return ans;
}

using namespace std;
int main()
{
}