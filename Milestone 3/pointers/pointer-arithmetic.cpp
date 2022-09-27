#include <iostream>
using namespace std;
int main()
{
    // int i = 10;
    // int *p = &i;
    // cout << p << endl;
    // p++;
    // cout << p << endl;

    int a = 7;
    int *c = &a;
    c = c + 1;
    cout << a << "  " << *c << endl;
}