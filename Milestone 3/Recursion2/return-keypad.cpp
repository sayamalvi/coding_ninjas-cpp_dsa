#include <iostream>
using namespace std;
#include <string>
using namespace std;
int keypad(int num, string output[])
{

    if (num == 0)
    {
        output[0] == "";
        return 1;
    }
    int last = num % 10;
    int smallNum = num / 10;
    string input;
    int smallOutputSize = keypad(smallNum, output);
    switch (last)
    {
    case 2:
        input = "abc";
        break;
    case 3:
        input = "def";
        break;
    case 4:
        input = "ghi";
        break;
    case 5:
        input = "jkl";
        break;
    case 6:
        input = "mno";
        break;
    case 7:
        input = "pqrs";
        break;
    case 8:
        input = "tuv";
        break;
    case 9:
        input = "wxyz";
        break;
    }

    int ansSize = smallOutputSize * input.size();
    string temp[ansSize];
    int k = 0;
    for (int i = 0; i < smallOutputSize; i++)
    {
        for (int j = 0; j < input.size(); j++)
        {
            temp[k] = output[i] + input[j];
            k++;
        }
    }
    for (int i = 0; i < ansSize; i++)
    {
        output[i] = temp[i];
    }
    return smallOutputSize * input.size();
}

int main()
{
}