#include <iostream>
using namespace std;
void increment(int a, int b[], int n)
{
    a++;
    b[0]++;
}
int main()
{
    int a = 10, b[10] = {1, 2, 3};
    increment(a, b, 10);
    cout << a << endl;
    cout << b[0];
}