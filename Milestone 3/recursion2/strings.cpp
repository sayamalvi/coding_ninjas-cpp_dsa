#include <iostream>
using namespace std;
int main()
{
    string s = "abc";
    // getline(cin, s);
    cout << s << endl;
    string s1;
    string *sp = new string;
    *sp = "efg";
    s1 = "def";
    s1[0] = 'a';
    cout << s1 << endl;
    cout << *sp << endl;
    s += s1;
    cout << s << endl;
    cout << s.substr(0, 3) << endl;
    cout << s.substr(3) << endl;
    cout << s.find('c');
}