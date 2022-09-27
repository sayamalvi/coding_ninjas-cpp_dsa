#include <iostream>
using namespace std;
template <typename T, typename V>
class Pair
{
    T x;
    V y;

public:
    void setX(T x)
    {
        this->x = x;
    }
    T getX()
    {
        return x;
    }
    void setY(V y)
    {
        this->y = y;
    }
    V getY()
    {
        return y;
    }
};

int main()
{
    Pair<int, int> p1;
    p1.setX(10);
    p1.setY(20);
    cout << p1.getX() << " " << p1.getY() << endl;

    Pair<double, double> p2;
    p2.setX(30.44);
    p2.setY(40.6789);
    cout << p2.getX() << " " << p2.getY() << endl;

    Pair<int, double> p3;
    p3.setX(10);
    p3.setY(20.1234);
    cout << p3.getX() << " " << p3.getY() << endl;

    Pair<Pair<int, int>, int> p4;
    p4.setY(10);
    Pair<int, int> p5;
    p5.setX(20);
    p5.setY(30);
    p4.setX(p5);
    cout << p4.getX().getX() << " " << p4.getX().getY() << " " << p4.getY();
}