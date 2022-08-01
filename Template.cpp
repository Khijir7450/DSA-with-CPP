#include <iostream>
using namespace std;
template <typename T>
class Pair
{
    T x;
    T y;

public:
    void setX(T x)
    {
        this->x = x;
    }
    T getX()
    {
        return x;
    }
    void setY(T y)
    {
        this->y = y;
    }
    T getY()
    {
        return y;
    }
};
int main()
{
    Pair<int> p1;
    p1.setX(10);
    p1.setY(15);
    cout << p1.getX() << " " << p1.getY() << endl;
    Pair<double> p2;
    p2.setX(10.5);
    p2.setY(12.6);
    cout << p2.getX() << " " << p2.getY() << endl;
    Pair<char> p3;
    p3.setX('x');
    p3.setY('x');
    cout << p3.getX() << " " << p3.getY() << endl;
    return 0;
}