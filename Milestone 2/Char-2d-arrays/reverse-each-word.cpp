#include <iostream>
#include <cstring>
void reverseEachWord(char input[])
{
    int len = strlen(input);
    int start = 0, end = 0;
    for (int k = 0; k <= len; k++)
    {
        if (input[k] == ' ' || input[k] == '\0')
        {
            end = k - 1;
            while (start < end)
            {
                int temp = input[start];
                input[start] = input[end];
                input[end] = temp;
                start++;
                end--;
            }
            start = k + 1;
        }
    }
}
using namespace std;
int main()
{
}