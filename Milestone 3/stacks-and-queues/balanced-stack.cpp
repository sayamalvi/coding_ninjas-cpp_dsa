#include <iostream>
#include <string>
using namespace std;
#include <stack>
//--------------------------------------------------
bool isBalanced(string exp)
{
    stack<char> s;
    char x;
    for (int i = 0; i < exp.length(); i++)
    {
        if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{')
        {
            s.push(exp[i]);
            continue;
        }

        if (s.empty())
            return false;

        if (exp[i] == ')' && s.top() == '(' || exp[i] == '}' && s.top() == '{' || exp[i] == ']' && s.top() == '[')
            s.pop();
    }
    return (s.empty());
}
//--------------------------------------------------
int main()
{
    string input;
    cin >> input;
    cout << ((isBalanced(input)) ? "true" : "false");
}