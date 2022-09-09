#include <iostream>
#include "Student.cpp"
using namespace std;
int main()
{
    // create objects statically
    Student s1;
    Student s2;

    // create objects dynamically
    Student *s3 = new Student;

    // can't change private class members
    // s1.age = 24;
    s1.rollNumber = 2242125;

    cout << s1.rollNumber << endl;

    // derefer first
    // (*s3).age = 34;
    // same as above
    s3->rollNumber = 1234;
}
