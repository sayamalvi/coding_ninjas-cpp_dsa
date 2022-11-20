#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;
int main()
{
    // Insert
    unordered_map<string, int> ourMap;
    pair<string, int> p("abc", 1);
    ourMap.insert(p);
    ourMap["def"] = 2;

    // access
    cout << ourMap["abc"] << endl;
    cout << ourMap.at("abc") << endl;
    // cout << ourMap.at("ghi") << endl;
    cout << "size: " << ourMap.size() << endl;

    cout << ourMap["ghi"] << endl;

    // check presence
    if (ourMap.count("ghi") > 0)
    {
        cout << "ghi is present" << endl;
    }

    cout << "size: " << ourMap.size() << endl;

    // erase
    ourMap.erase("ghi");
    if (ourMap.count("ghi") > 0)
    {
        cout << "ghi is present" << endl;
    }
}