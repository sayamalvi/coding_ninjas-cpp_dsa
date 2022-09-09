#include <iostream>
using namespace std;
#include <cstring>
void removeConsecutiveDuplicates(char input[])
{
    int i = 1, j = 1;
    int len = strlen(input);
    int last = input[0];
    for (; i <= len; i++)
    {
        if (input[i] != last)
        {
            input[j] = input[i];
            last = input[i];
            j++;
        }
    }
    input[j + 1] = '\0';
}
int main()
{
}