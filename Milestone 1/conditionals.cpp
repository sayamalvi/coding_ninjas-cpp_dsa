#include <iostream>
using namespace std;
int main()
{
    // int x = 15;
    // if (x <= 15)
    // {
    //     cout << "Inside If";
    // }
    // else if (x == 15)
    // {
    //     cout << "Inside else if";
    // }
    // cout << x;

    // int var1 = 5;
    // int var2 = 6;
    // if ((var2 = 1) == var1)
    // {
    //     cout << var2;
    // }
    // else
    // {
    //     cout << (var2 + 1);
    // }

    // int a = 10, b = 20, c = 100;
    // if(a <= b || c <= b) {
    //     cout << "hello" << endl;
    // }
    // else if(a <= b || a <= c) {
    //     cout << "hi" << endl;
    // }
    // else {
    //     cout << "hey" << endl;
    // }

    // int a = 10, b = 20, c = 30;
    // if(a <= b && !b) {
    //     cout << "hello";
    // }
    // else if(c >= a && c >= b) {
    //     cout << "hi";
    // }
    // else {
    //     cout << "hey";
    // }
    char ch;
    cout << "Enter a character";
    cin >> ch;
    if (ch >= 'a' && ch<= 'z')
    {
        cout << 0;
    }
    else if (ch >= 'A' && ch<= 'Z')
    {
        cout << 1;
    }
    else
    {
        cout << -1;
    }
}