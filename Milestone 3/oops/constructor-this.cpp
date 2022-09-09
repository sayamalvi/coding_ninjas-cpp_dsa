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
    Student s1;
    s1.display();

    Student s2;
    Student *s3 = new Student;
    s3->display();

    cout << "Parametrized constructor called" << endl;
    Student s4(10);
    // for every object only one constructor gets called

    Student *s5 = new Student(101);
    s5->display();

    Student s6(12, 20);
    s6.display();
}