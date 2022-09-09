#include <iostream>
using namespace std;
class Student
{
    static int totalStudents; // this property doesn't belong to an object rather it belongs to a class so we will make is static , which means it belongs to the class. To access it we have to access it through class
public:
    int rollNumber;
    int age;
    Student()
    {
        totalStudents++;
    }
    int getRollNumber()
    {
        return rollNumber;
    }
    // static functions can only use static data members 
    // static functions don't have this keyword because we don't call static functions through an object (this stores address of object)
    static int getTotalStudents()
    {
        return totalStudents;
    }
};
// initialize static members outside the class
int Student ::totalStudents = 0;
int main()
{
    Student s1;
    Student s2;
    Student s3;
    Student s4;
    Student s5;
    // cout << Student ::totalStudents << endl;
    cout << Student::getTotalStudents();
}