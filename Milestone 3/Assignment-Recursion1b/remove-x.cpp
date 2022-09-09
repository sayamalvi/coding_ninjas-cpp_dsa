#include <iostream>
using namespace std;
#include <cstring>
void removeX(char input[])
{
    int len = strlen(input);
    if (len == 0)
        return;
    removeX(input + 1);
    if (input[0] == 'x')
    {
        int i = 0;
        for (; i < len; i++)
        {
            input[i] = input[i + 1];
        }
        input[i] = '\0';
    }
    return;
}

int main()
{
    
}