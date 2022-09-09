#include <iostream>
#include <limits.h>
// using climits instead of limits.h throws error of namespace std
using namespace std;
int main()
{
    int n;
    cin >> n;

    int input[50];
    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
    }
    int max = INT_MIN;
    // INT_MIN = Largest negative value =  -( 2 ^ 31 )
    for (int i = 0; i < n; i++)
    {
        if (input[i] > max)
        {
            max = input[i];
        }
    }
    cout << max << endl;
}