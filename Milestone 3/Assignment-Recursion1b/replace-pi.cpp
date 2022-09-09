#include <iostream>
using namespace std;

#include <cstring>
void replacePi(char input[])
{
    int len = strlen(input);
    if (len == 1)
        return;

    if (input[0] == 'p' && input[1] == 'i')
    {

        for (int j = len; j >= 2; j--)
        {
            input[j + 2] = input[j];
        }

        input[0] = '3';
        input[1] = '.';
        input[2] = '1';
        input[3] = '4';
    }

    return replacePi(input + 1);
}

int main()
{
}