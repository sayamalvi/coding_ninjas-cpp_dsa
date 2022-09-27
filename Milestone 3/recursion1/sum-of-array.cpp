#include <iostream>
using namespace std;
int sum(int input[], int n)
{
    if (n == 1)
        return input[0];
    int smallOutput = sum(input + 1, n - 1);
    int output = smallOutput + input[0];
}

int main()
{
}