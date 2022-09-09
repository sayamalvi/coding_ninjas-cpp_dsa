#include <iostream>
using namespace std;
void print(int *p)
{
    cout << *p << endl;
}
void incrementPointer(int *p)
{
    p++;
}
void increment(int *p)
{
    (*p)++;
}
int sum(int *a, int size)
{
    int ans = 0;
    for (int i = 0; i < size; i++)
    {
        ans += a[i];
    }
    return ans;
}
void fun(int a[])
{
    cout << a[0] << " ";
}
void square(int *p)
{
    int a = 10;
    p = &a;
    *p = (*p) * (*p);
}
int main()
{
    // int i = 10;
    // int *p = &i;
    // print(p);

    // cout << p << endl;
    // incrementPointer(&i);
    // cout << p << endl;

    // cout << *p << endl;
    // increment(p);
    // cout << *p << endl;

    // int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    // cout << sum(a + 8, 2);

    // int a[] = {1, 2, 3, 4};
    // fun(a + 1);
    // cout << a[0];

    int a = 10;
    square(&a);
    cout << a << endl;
}