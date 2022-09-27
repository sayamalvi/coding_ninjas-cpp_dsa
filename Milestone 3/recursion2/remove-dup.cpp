#include <iostream>
using namespace std;
#include <cstring>
void removeConsecutiveDuplicates(char *input)
{
    int len = strlen(input);
    if (len <= 1)
        return;
    removeConsecutiveDuplicates(input + 1);
    if (input[0] == input[1])
    {
        for (int i = 1; i <= len; i++)
        {
            input[i - 1] = input[i];
        }
    }
}
int main()
{
}