#include <iostream>
#include <cstring>
using namespace std;
class Student
{
    int age;
    char *name;

public:
    Student(int age, char *name)
    {
        this->age = age;
        // shallow copy-only copy base address of array - avoid
        // this->name = name;

        // deep copy-copy whole array
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
    }
    void display()
    {
        cout << name << " " << age << endl;
    }
};
int main()
{
    char name[] = "abcde";
    Student s1(19, name);
    s1.display();
    name[0] = 'b';
    Student s2(20, name);
    s2.display();
    s1.display();
}