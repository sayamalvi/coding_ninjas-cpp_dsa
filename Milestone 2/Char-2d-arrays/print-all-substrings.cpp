#include <iostream>
using namespace std;
#include <cstring>
void printSubstrings(char input[])
{

    int len = strlen(input);
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len; j++)
        {
            for (int k = i; k <= j; k++)
            {
                cout << input[k];
            }
            cout << endl;
        }
    }

    // int len = strlen(input);
    // for (int i = 1; i <= len; i++)
    // {
    //     for (int j = 0; j <= len - i; j++)
    //     {
    //         for (int k = j; k <= (i + j) - 1; k++)
    //         {
    //             cout << input[k];
    //         }
    //         cout << endl;
    //     }
    // }
}

int main()
{
}