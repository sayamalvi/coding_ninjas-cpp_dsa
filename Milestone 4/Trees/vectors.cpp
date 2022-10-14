#include <iostream>
#include <vector>
using namespace std;
int main()
{
    // static vector
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    // cout << v[0] << endl;
    // cout << v[1] << endl;
    // cout << v[2] << endl;
    // v[2] = 20;
    // cout << v[2] << endl;

    // v[3] = 40;
    // v[4] = 50;
    // v[5] = 60;
    // square brackets will not give any error even if access out of bounds elements so we should avoid using square brackets to access elements.

    // cout << v[3] << endl;
    // cout << v[4] << endl;
    // cout << v[5] << endl;

    // this will throw an out of range error because vectors didn't double it size. So we always should use push_back function for inserting elements in a vector and use at  function to get indexes
    // cout << v.at(3) << endl;
    // cout << v.at(4) << endl;
    // cout << v.at(5) << endl;

    v.pop_back();
    for (int i = 0; i < v.size(); i++)
    {
        cout << v.at(i) << endl;
    }


    // dynamic vector
    vector<int> *vp = new vector<int>();
}