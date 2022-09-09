#include <iostream>
using namespace std;
#include <cstring>
void removeAllOccurrencesOfChar(char input[], char c)
{
    int len = strlen(input);
    int i = 0, j = 0;
    for (; i <= len; i++)
    {
        if (input[i] != c)
        {
            input[j] = input[i];
            j++;
        }
    }
    input[j] = '\0';
}

int main()
{
}