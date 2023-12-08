
#include <iostream>
using namespace std;

class A {
public:
    int x;
    int y;
    A(): x(0), y(0){}
    A(int _x, int _y): x(_x), y(_y){}
    friend static ostream& operator<<(ostream& os, const A& obj);
    // friend - це об'явлення метода в класі
};
// реалізація метода поза класом
static ostream& operator<<(ostream& os, const A& obj) {
    os << obj.x << ' ' << obj.y;
    return os;
}

int main()
{
    A a(10, 12);
    cout << a;
}
