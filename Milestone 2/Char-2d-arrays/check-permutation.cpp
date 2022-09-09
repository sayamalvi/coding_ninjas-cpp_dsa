#include <iostream>
using namespace std;
#include <cstring>
bool isPermutation(char input1[], char input2[])
{

    int freq1[256] = {0};

    for (int i = 0; input1[i] != '\0'; i++)
    {
        freq1[input1[i]]++;
    }
    for (int j = 0; input2[j] != '\0'; j++)
    {
        freq1[input2[j]]--;
        ;
    }
    for (int i = 0; i < 256; i++)
    {
        if (freq1[i] != 0)
            return false;
    }
    return true;

    // int freq[256] = {0};
    // int len1 = strlen(input1), len2 = strlen(input2);
    // if (len1 != len2)
    //     return false;
    // for (int i = 0; i < len1; i++)
    // {
    //     freq[input1[i]]++;
    // }
    // for (int i = 0; i < len2; i++)
    // {
    //     freq[input2[i]]--;
    // }
    // for (int i = 0; i < 256; i++)
    // {
    //     if (freq[i] != 0)
    //     {
    //         return false;
    //     }
    // }
    // return true;
}
int main()
{
}