#include <iostream>
int lastIndex(int input[], int size, int x)
{

    if (size == 0)
        return -1;
    int ans = lastIndex(input + 1, size - 1, x);
    // if (ans == x)
    //     return ans + 1;
    if (ans == -1)
    {
        if (x == input[0])
            return 0;
        else
            return -1;
    }
    return ans + 1;
}

using namespace std;
int main()
{
}