#include <iostream>
using namespace std;
class Fraction
{

    int num;
    int den;

public:
    Fraction()
    {
    }
    Fraction(int num, int den)
    {
        this->num = num;
        this->den = den;
    }
    int getNumerator() const
    {
        return num;
    }

    int getDenominator() const
    {
        return den;
    }
    void print()
    {
        cout << this->num << " / " << den << endl;
    }
};

int main()
{
    Fraction f1(10, 2);
    Fraction f2(20, 4);

    Fraction const f3;

    // we can only call constant functions for a constant object
    cout << f3.getNumerator() << " " << f3.getDenominator() << endl;
  
    
}