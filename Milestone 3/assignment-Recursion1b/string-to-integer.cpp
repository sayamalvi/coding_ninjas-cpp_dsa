#include <iostream>
using namespace std;
#include <cstring>
#include <cmath>
int stringToNumber(char input[])
{
    int len = strlen(input);
    if (len == 0)
        return 0;
    int a = stringToNumber(input + 1);
    int b = input[0];
    b = b - '0';
    return b * pow(10, len - 1) + a;
}

int main()
{
}