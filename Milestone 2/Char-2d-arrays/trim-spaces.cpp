#include <iostream>
using namespace std;
#include <cstring>
void trimSpaces(char input[])
{
    int len = strlen(input);
    int i = 0, c = 0;
    while (i <= len)
    {
        if (input[i] != ' ')
        {
            input[c] = input[i];
            c++;
        }
        i++;
    }
    input[c] = '\0';

    // int len = strlen(input);
    // int c = 0;
    // for (int i = 0; i < len; i++)
    // {
    //     if (input[i] != ' ')
    //     {
    //         input[c] = input[i];
    //         c++;
    //     }
    // }
    // input[c] = '\0';
}

int main()
{
}