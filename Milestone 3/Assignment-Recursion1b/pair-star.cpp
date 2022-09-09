#include <iostream>
using namespace std;
#include <cstring>
void pairStar(char input[])
{
    int len = strlen(input);
    if (len <= 1)
        return;
    if (input[0] == input[1])
    {
        for (int j = len; j >= 0; j--)
        {
            input[j + 1] = input[j];
        }
        input[1] = '*';
    }
    return pairStar(input + 1);
}

int main()
{
}