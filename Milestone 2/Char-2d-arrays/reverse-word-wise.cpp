#include <iostream>
using namespace std;
#include <cstring>
void reverseStringWordWise(char input[])
{

    int len = strlen(input);
    int i = 0, j = len - 1;
    while (i < j)
    {
        int temp = input[i];
        input[i] = input[j];
        input[j] = temp;
        i++;
        j--;
    }
    int start=0, end = 0;
    for (int k = 0; k <= len; k++)
    {
        if (input[k] == ' ' || input[k] == '\0')
        {
            end = k - 1;
            while (start < end)
            {
                int temp = input[start];
                input[start] = input[end];
                input[end] = temp;
                start++;
                end--;
            }
            start = k + 1;
        }
    }

    cout << input;
}
int main()
{
    char input[100];
    cin.getline(input, 100);
    reverseStringWordWise(input);
}