#include <iostream>
using namespace std;
class Student
{
    int age, rollNumber;

public:
    // default constructor
    Student()
    {
        cout << "Constructor 1 called" << endl;
    }
    // parametrized constructor
    Student(int rollNumber)
    {
        // this is a special keyword(pointer) which stores address of the created object 
        this->rollNumber = rollNumber;
        cout << "Constructor 2 called" << endl;
    }
    Student(int r, int a)
    {
        rollNumber = r;
        age = a;
        cout << "Constructor 3 called" << endl;
    }

    void display()
    {
        cout << age << "  " << rollNumber << endl;
    }
    int getAge()
    {
        return age;
    }
    void setAge(int a, int password)
    {
        if (password != 123)
            return;
        if (a < 0)
            return;
        age = a;
    }
};
int main()
{
    Student s1;  // constructor 1 called
    Student s2(10); //  constructor 2 called
    Student s3(12,101); // constructor 3 called
    Student s4(s3); // copy constructor called
    s1 = s2; // no constructor will be called because both objects  already exists in memory;
    Student s5 = s4; // copy constructor will be called

}