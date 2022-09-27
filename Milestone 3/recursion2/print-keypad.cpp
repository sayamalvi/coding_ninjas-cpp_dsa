#include <iostream>
#include <string>
using namespace std;
void keypad(int num, string output)
{
    if (num == 0)
    {
        cout << output << endl;
        return;
    }
    int small = num / 10;
    int last = num % 10;
    string input;
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
    for (int i = 0; i < input.length(); i++)
    {
        keypad(small, input[i] + output);
    }
}
void printKeypad(int num)
{
    keypad(num, "");
}

int main()
{
}