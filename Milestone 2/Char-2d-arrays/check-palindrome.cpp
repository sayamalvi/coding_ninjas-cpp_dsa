#include <iostream>
using namespace std;
bool checkPalindrome(char str[])
{
    int length = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        length++;
    }
    int i = 0, j = length - 1, loop;
    bool isPal = false;
    if (length % 2 == 0)
        loop = length / 2;
    else
        loop = (length - 1) / 2;
    while (i <= loop && j >= loop)
    {
        if (str[i] == str[j])
        {
            isPal = true;
            i++;
            j--;
        }
        else
        {
            isPal = false;
            i++;
            j--;
        }
    }
    return isPal;
}

int main()
{
}