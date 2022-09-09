#include <iostream>
using namespace std;
class Fraction
{
private:
    int num;
    int den;

public:
    Fraction(int num, int den)
    {
        this->num = num;
        this->den = den;
    }
    void print()
    {
        cout << this->num << " / " << den << endl;
    }
    void simplify()
    {
        int gcd = 1;
        int j = min(this->num, this->den);
        for (int i = 1; i <= j; i++)
        {
            if (this->num % i == 0 && this->den % i == 0)
            {
                gcd = i;
            }
        }
        this->num = this->num / gcd;
        this->den = this->den / gcd;
    }

    // operator overloading
    Fraction operator+(Fraction const &f2) const
    {
        int lcm = den * f2.den;
        int x = lcm / den;
        int y = lcm / f2.den;
        int number = x * num + (y * f2.num);

        Fraction fNew(number, lcm);
        fNew.simplify();
        return fNew;
    }
    // we can make these functions const because the are not changing or altering any data members
    Fraction operator*(Fraction const &f2) const
    {
        int n = num * f2.num;
        int d = den * f2.den;
        Fraction fNew(n, d);
        fNew.simplify();
        return fNew;
    }
    bool operator==(Fraction const &f2) const
    {
        return (num == f2.num && den == f2.den);
    }
    // pre increment
    Fraction &operator++()
    {
        num += den;
        simplify();
        return *this;
    }
    // post increment
    Fraction operator++(int)
    {
        Fraction fnew(num, den);
        num += den;
        simplify();
        fnew.simplify();
        return fnew;
    }
    Fraction &operator+=(Fraction const &f2)
    {
        int lcm = den * f2.den;
        int x = lcm / den;
        int y = lcm / f2.den;
        int number = x * num + (y * f2.num);

        num = number;
        den = lcm;
        simplify();
        return *this;
    }
};

int main()
{

    Fraction f1(10, 3);
    Fraction f2(5, 2);

    // Fraction f3 = f1 + f2;
    // f1.print();
    // f2.print();
    // f3.print();

    // Fraction f4 = f1 * f2;
    // f4.print();
    // if (f1 == f2)
    // {
    //     cout << "Equal" << endl;
    // }
    // else
    //     cout << "Not equal" << endl;

    // Fraction f5 = ++(++f1);
    // f1.print();
    // f3.print();

    // Fraction f3 = f1++;
    // f1.print();
    // f3.print();

    f1+=f2;
    f1.print();
    f2.print();
}