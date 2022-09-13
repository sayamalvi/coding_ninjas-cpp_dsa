#include <iostream>
using namespace std;
class Polynomial
{
public:
    int *degCoeff;
    int capacity;
    // Print function
    void print()
    {
        for (int i = 0; i <= capacity; i++)
        {
            cout << degCoeff[i] << "x" << i << " ";
        }
        cout << endl;
    }
    // Default constructor
    Polynomial()
    {
        capacity = 5;
        degCoeff = new int[capacity];
        *degCoeff = {0};
    }
    // Copy constructor
    Polynomial(Polynomial const &p)
    {
        int *newDeg = new int[p.capacity];
        for (int i = 0; i < p.capacity; i++)
        {
            newDeg[i] = degCoeff[i];
        }
        this->degCoeff = newDeg;
        this->capacity = p.capacity;
    }
    // setCoefficient
    void setCoefficient(int deg, int coeff)
    {
        if (deg > capacity)
        {
            int newCapacity = deg;
            int *newDeg = new int[newCapacity];
            for (int i = 0; i < newCapacity; i++)
            {
                newDeg[i] = degCoeff[i];
            }
            degCoeff = newDeg;
            capacity = newCapacity;
            degCoeff[deg] = coeff;
        }
        else
            degCoeff[deg] = coeff;
    }
    // = Operator overloading
    Polynomial
    operator=(Polynomial const &p)
    {
        int *newDeg = new int[p.capacity];
        for (int i = 0; i < p.capacity; i++)
        {
            newDeg[i] = degCoeff[i];
        }
        degCoeff = newDeg;
        capacity = p.capacity;
    }
    // + Operator overloading
    Polynomial operator+(Polynomial const &p)
    {
        int *temp = new int[capacity * 2];
        for (int i = 0; i < capacity; i++)
        {
            temp[i] = degCoeff[i] + p.degCoeff[i];
        }
        degCoeff = temp;
        return *this;
    }
    // - Operator overloading
    Polynomial operator+(Polynomial const &p)
    {
        int *temp = new int[capacity * 2];
        for (int i = 0; i < capacity; i++)
        {
            temp[i] = degCoeff[i] - p.degCoeff[i];
        }
        degCoeff = temp;
        return *this;

    }
    // * Operator overloading
    Polynomial operator+(Polynomial const &p)
    {
        
    }
};
int main()
{
}