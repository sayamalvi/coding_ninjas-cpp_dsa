#include <iostream>
using namespace std;
int main()
{
    // int ror = 15 | 30;
    // int rand = 15 & 30;
    // int rnot = ~15;
    // int rxor = 15 ^ 30;
    // int rls = 15 << 2;
    // int rrs = 15 >> 2;
    // cout << ror << endl
    //      << rand << endl
    //      << rnot << endl
    //      << rxor << endl
    //      << rls << endl
    //      << rrs << endl;

    // ----------------------------------------------------------

    // int a = 10;
    // cout << ++a << endl
    //      << a++ << endl << a;

    // int x = 10;
    // int y = 20;
    // if (x++ > 10 || ++y > 20)
    // {
    //     cout << "Inside if ";
    // }
    // else
    // {
    //     cout << "Inside else ";
    // }
    // cout << x << " " << y;

    // ----------------------------------------------------------

    // Print the nth number of the fibonacci series

    // int n;
    // cin >> n;
    // int n1 = 0, n2 = 1;
    // if (n == 0)
    // {
    //     cout << 0;
    // }
    // else if (n == 1)
    // {
    //     cout << 1;
    // }
    // else
    // {
    //     for (int i = 2; i <= n; i++)
    //     {
    //         int n3 = n1 + n2;
    //         n1 = n2;
    //         n2 = n3;
    //         if (n == i)
    //         {
    //             cout << n3;
    //         }
    //     }
    // }

    // ----------------------------------------------------------

    // All prime numbers from 2 to n

    // int n;
    // cin >> n;
    // for (int i = 2; i <= n; i++)
    // {
    //     bool isPrime = false;
    //     for (int j = 2; j <= i / 2; j++)
    //     {
    //         if (i % j == 0)
    //         {
    //             isPrime = true;
    //             continue;
    //         }
    //     }
    //     if (isPrime == false)
    //     {
    //         cout << i << endl;
    //     }
    // }

    // ----------------------------------------------------------

    // Count characters numbers and whitespace from given characters

    // char c;
    // c = cin.get();
    // int charCount = 0, numCount = 0, extraCount = 0;
    // while (c != '$')
    // {
    //     if (c >= 'a' && c <= 'z')
    //     {
    //         charCount++;
    //     }
    //     else if (c >= '0' && c <= '9')
    //     {
    //         numCount++;
    //     }
    //     else
    //     {
    //         extraCount++;
    //     }
    //     c = cin.get();
    // }
    // cout << charCount << " " << numCount << " " << extraCount;

    // ----------------------------------------------------------

    // Sum or product

    // int n;
    // cin >> n;
    // int c;
    // cin >> c;
    // int sum = 0, product = 1;
    // if (c == 1)
    // {
    //     for (int i = 1; i <= n; i++)
    //     {
    //         sum += i;
    //     }
    //     cout << sum;
    // }
    // else if (c == 2)
    // {
    //     for (int i = 1; i <= n; i++)
    //     {
    //         product *= i;
    //     }
    //     cout << product;
    // }
    // else
    // {
    //     cout << -1;
    // }

    // ----------------------------------------------------

    // Term of an AP

    // int x;
    // cin >> x;
    // int count = 0;
    // for (int i = 1; i <= count + x; i++)
    // {
    //     int series = 3 * i + 2;
    //     if (series % 4 != 0)
    //     {
    //         cout << series << " ";
    //     }
    //     else
    //     {
    //         count++;
    //     }
    // }

    // -----------------------------------------------

    // Reverse of a number

    // int n, rem, rev = 0;
    // cin >> n;
    // while (n != 0)
    // {
    //     rem = n % 10;
    //     rev = rev * 10 + rem;
    //     n = n / 10;
    // }
    // cout << rev;

    // -----------------------------------------------

    // Binary to Decimal

    // int n, pv = 1, ans = 0;
    // cin >> n;
    // while (n != 0)
    // {

    //     int last = n % 10;
    //     ans = ans + last * pv;
    //     n = n / 10;
    //     pv = pv * 2;
    // }

    // cout << ans;

    // -----------------------------------------

    // Decimal to binary

    // long n, rem = 0, ans = 0, pv = 1;
    // cin >> n;
    // while (n != 0)
    // {
    //     rem = n % 2;
    //     ans = ans + rem * pv;
    //     n = n / 2;
    //     pv = pv * 10;
    // }
    // cout << ans;

    // --------------------------------------

    // Root of a number

    // int n;
    // cin >> n;
    // int root = 0;
    // for (int i = 1; i * i <= n; i++)
    // {
    //     root = i;
    // }
    // cout << root;

    // --------------------------------------

    // Increasing Decreasing sequence

    // int n;
    // cin >> n;
    // int prev;
    // cin >> prev;
    // bool isDec = true, isValid = true;
    // for (int i = 1; i < n; i++)
    // {
    //     int curr;
    //     cin >> curr;
    //     if (curr == prev)
    //     {
    //         isValid = false;
    //         break;
    //     }
    //     else if (curr > prev)
    //     {
    //         isDec = false;
    //     }
    //     else if (curr < prev)
    //     {

    //         if (isDec == false)
    //         {
    //             isValid = false;
    //             break;
    //         }
    //     }
    //     prev = curr;
    // }
    // if (isValid)
    // {
    //     cout << "true";
    // }
    // else
    // {
    //     cout << "false";
    // }
}