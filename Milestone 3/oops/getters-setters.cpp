#include <iostream>
#include "StudentNew.cpp"
using namespace std;
int main()
{
    StudentNew s1;
    StudentNew *s2 = new StudentNew;
    // setter function
    s1.setAge(20, 123);
    s2->setAge(30, 123);

    s1.display();
    s2->display();

    // getter functions
    s1.getAge();
    s2->getAge();
}