#include <iostream>
using namespace std;
#include <cstring>
bool checkAB(char input[])
{
    int len = strlen(input);
    if (len == 0)
        return true;

    if (input[0] == 'a' && input[1] == '\0')
        return true;

    if (input[0] != 'a')
        return false;

    if (input[1] == 'b' && input[2] == 'b')
        return checkAB(input + 3);
    else
        return checkAB(input + 1);
}

int main()
{
}
