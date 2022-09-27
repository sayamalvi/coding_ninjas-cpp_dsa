#include <iostream>
using namespace std;
int main()
{
    int a[10];
    cout << a << endl;
    cout << &a[0] << endl;

    a[0] = 5;
    a[1] = 6;
    // value of first element
    cout << *a << endl;
    // value of second element
    cout << *(a + 1) << endl;

    int *p = &a[0];
    cout << a << endl;
    cout << p << endl;

    cout << &p << endl;
    cout << &a << endl;

    cout << sizeof(a) << endl;
    cout << sizeof(p) << endl;
    p = a;
    cout << p << endl;
    
}