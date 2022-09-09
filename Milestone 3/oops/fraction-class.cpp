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
        // divide fraction with hcf or gcd and update
        this->num = this->num / gcd;
        this->den = this->den / gcd;
    }
    // we will reference of the object in order to avoid making a different copy. And we used const so that properties of f1 cannot be changed by f2
    void add(Fraction const &f2)
    {

        // this->den means same as den so we can use den also. Now this step will put 2*4 = 8 in lcm
        int lcm = den * f2.den;

        // divide by denominator and multiply by numerator is what we do in fraction addition
        int x = lcm / den;
        int y = lcm / f2.den;
        int number = x * num + (y * f2.num);

        num = number;
        den = lcm;

        simplify();
    }
    void multiply(Fraction const &f2)
    {
        num = num * f2.num;
        den = den * f2.den;
        simplify();
    }
};

int main()
{
    Fraction f1(10, 2);
    Fraction f2(15, 4);
    f1.add(f2);
    f1.print();
    f2.print();
    f1.multiply(f2);
    f1.print();
    f2.print();
}