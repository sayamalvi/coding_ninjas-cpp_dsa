#include <iostream>

char highestOccurringChar(char input[])
{
    int freq[256] = {0};
    for (int i = 0; input[i] != '\0'; i++)
    {
        freq[input[i]]++;
    }
    char ans = input[0];
    for (int i = 1; input[i] != '\0'; i++)
    {
        int count = freq[int(ans)];
        if (freq[input[i]] > count)
        {
            count = freq[input[i]];
            ans = input[i];
        }
    }
    return ans;
}
using namespace std;
int main()
{
}