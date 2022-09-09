#include <iostream>
using namespace std;
void increment(int &n)
{
    n++;
}
void func(int i, int &j, int p)
{
    i++;
    j++;
    p++;
}

int main()
{
    // int i = 10;
    // increment(i);
    // cout << i << endl;
    // int &j = i;
    // i++;
    // cout << j << endl;
    // j++;
    // cout << i << endl;

    // int k = 100;
    // j = k;
    // cout << j << endl;

    int i = 10;
    int j = 6;
    int &p = i;
    func(i, j, p);
    cout << i << " " << j << " " << p;
}