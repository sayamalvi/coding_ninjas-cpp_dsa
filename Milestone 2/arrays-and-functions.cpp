#include <iostream>
using namespace std;
void printArray(int arr[], int n)
{

    for (int i = 0; i < n; i++)
    {
        cout << arr[i];
    }
}
int main()
{
    int n;
    cin >> n;
    int input[100];
    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
    }
    printArray(input, n);
}