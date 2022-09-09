#include <iostream>
#include <cmath>
using namespace std;
int subsequences(string input, string output[])
{
    if (input.empty())
    {
        output[0] == "";
        return 1;
    }
    string smallstring = input.substr(1);
    int small = subsequences(smallstring, output);
    for (int i = 0; i < small; i++)
    {
        output[i + small] = input[0] + output[i];
    }
    return 2 * small;
}
int main()
{
    string input;
    cin >> input;
    int size = pow(2, input.size());
    string *output = new string[size];
    int count = subsequences(input, output);
    for (int i = 0; i < count; i++)
    {
        cout << output[i] << endl;
    }
}