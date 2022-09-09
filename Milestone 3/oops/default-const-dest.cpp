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
        cout << "Constructor 3 of object " << this << endl;
    }
    ~Student()
    {
        cout << "Destructor of object " << this << endl;
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
    // copy constructor
    Student s1(10, 1001);
    cout << "S1 : ";
    s1.display();
    // parametrized constructor won't be called because copy constructor is already called 
    Student s2(s1);
    cout << "S2 : ";
    s2.display();

    Student *s3 = new Student(20, 2001);
    cout << "S3 : ";
    s3->display();
    Student s4(*s3);

    Student *s5 = new Student(*s3);
    Student *s6 = new Student(s1);

    // copy assignment operator
    Student s7(30, 3001);
    Student *s8 = new Student(40, 4001);
    *s8 = s7;
    s8->display();
    // we have to manually call the destructor for dynamically created objects
    delete s3;
    delete s5;
    delete s6;
    delete s8;
}