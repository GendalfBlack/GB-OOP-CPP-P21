#include <iostream>
using namespace std; 


class Vector {
public:
    int x;
    int y;
    Vector() : x(0), y(0){}
    Vector(int _x, int _y) : x(_x), y(_y){}
    void print() { printf("%d, %d", x, y); }
    Vector operator+(Vector v2) { return Vector(x + v2.x, y + v2.y); }
    Vector operator*(int scale) { return Vector(x * scale, y * scale); }
};

int main()
{
    Vector v1(1, 2);
    Vector v2(2, 3);
    Vector v3 = v1 + v2;
    Vector v4 = v3 * 2;
    v4.print();
}
