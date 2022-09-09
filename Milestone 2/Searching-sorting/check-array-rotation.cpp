#include <iostream>
using namespace std;
int arrayRotateCheck(int *input, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (input[i] < input[i - 1])
            return i;
    }
    return 0;
}
int main()
{
}