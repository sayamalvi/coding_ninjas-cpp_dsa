#include <iostream>
using namespace std;
class Student
{
public:
    int age;
    // const int roll = 101;
    // above  statement will intialize every object with 101 roll
    const int roll;
    int &x; // age reference variable
    Student(int r, int a) : roll(r), age(a), x(this->age)
    {
    }
};
int main()
{
}