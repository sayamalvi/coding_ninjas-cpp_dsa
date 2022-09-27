#include <iostream>
using namespace std;
void swap(char *x, char *y)
{
    char *t = x;
    x = y;
    y = t;
}
void Q(int z)
{
    z += z;
    cout << z << " ";
}

void P(int *y)
{
    int x = *y + 2;
    Q(x);
    *y = x - 1;
    cout << x << " ";
}
int main()
{
    // int i = 10;
    // int *p = &i;
    // int **p2 = &p;

    // cout << p2 << endl;
    // cout << &p << endl;

    // cout << p << endl;
    // cout << *p2 << endl;
    // cout << &i << endl;

    // cout << i << endl;
    // cout << *p << endl;
    // cout << **p2 << endl;
    // int arr[] = {4, 5, 6, 7};
    // int *p = (arr + 1);
    // cout << *arr + 9;
    // return 0;

    // char arr[20];
    // int i;
    // for (i = 0; i < 10; i++)
    // {
    //     *(arr + i) = 65 + i;
    // }
    // *(arr + i) = '\0';
    // cout << arr;

    // char *x = "geeksquiz";
    // char *y = "geeksforgeeks";
    // char *t;
    // swap(x, y);
    // cout << x << " " << y;
    // t = x;
    // x = y;
    // y = t;
    // cout << " " << x << " " << y;

    // float arr[5] = {12.5, 10.0, 13.5, 90.5, 0.5};
    // float *ptr1 = &arr[0];
    // float *ptr2 = ptr1 + 3;
    // cout << *ptr2 << " ";
    // cout << ptr2 - ptr1;

    // char st[] = "ABCD";
    // for (int i = 0; st[i] != '\0'; i++)
    // {
    //     cout << st[i] << *(st) + i << *(i + st) << i[st];
    // }

    // int x = 5;
    // P(&x);
    // cout << x;

    // int a = 10;
    // int *p = &a;
    // int **q = &p;
    // int b = 20;
    // *q = &b;
    // (*p)++;
    // cout << a << " " << b << endl;

    int a = 100;
    int *p = &a;
    int **q = &p;
    int b = (**q)++ + 4;
    cout << a << " " << b << endl;
}