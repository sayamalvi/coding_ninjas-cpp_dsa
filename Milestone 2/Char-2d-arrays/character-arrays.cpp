#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    // char name[100], name2[100];
    // cin.getline(name, 100);
    // cin.getline(name2, 100);
    // cout << "Length " << strlen(name);
    // if (strcmp(name, name2) == 0)
    // {
    //     cout << "Equal";
    // }
    // else
    //     cout << "Not Equal";
    // cout << strcpy(name, name2);

    // print prefixes

    char input[50];
    cin.getline(input, 50);
    int len = strlen(input);
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len; j++)
        {
            int k;
            for (k = i; k <= j; k++)
            {
                cout << input[k];
            }
            cout << endl;
        }
    }
}
