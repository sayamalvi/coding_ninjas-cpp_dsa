#include <iostream>
using namespace std;
int main()
{
    // int i = 10;
    // int *p = &i;
    // cout << p << endl;
    // cout << *p << endl;

    // float f = 10.2;
    // float *b = &f;
    // cout << b << endl;
    // cout << *b << endl;

    // -------------------------------------------------------

    // int i = 10;
    // int *p = &i;

    // cout << sizeof(p) << endl;
    // cout << i << endl;
    // cout << *p << endl;

    // i++;

    // cout << i << endl;
    // cout << *p << endl;

    // int a = i;
    // a++;
    // cout << i << endl;

    // int b = *p;
    // a++;
    // cout << i << endl;

    // i = 12;
    // *p = 23;
    // cout << i << endl;

    // int *q = p;
    // cout << *q << endl;

    // ----------------------------------------------------------------

    // int i;
    // cout << i << endl;
    // i++;
    // cout << i << endl;

    // int *p = 0;
    // cout << *p << endl;
    // cout << p << endl;

    int a = 100, b = 200;
    int *p = &a, *q = &b;
    p = q;

    cout << p << endl
         << q;
}