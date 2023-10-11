#include <iostream>
using namespace std;

class Drib {
public:
    int ch;
    int zn;
    Drib(): ch(0), zn(1) { }
    Drib(int _ch, int _zn) : ch(_ch), zn(_zn) { }
    bool operator> (Drib& other) {
        return double(ch) / zn > double(other.ch) / other.zn;
    }
    bool operator< (Drib& other) {
        return double(ch) / zn < double(other.ch) / other.zn;
    }
    bool operator== (Drib& other) {
        return double(ch) / zn == double(other.ch) / other.zn;
    }
};
template <typename T>
class Point {
    T x;
    T y;
};
int main()
{
    Drib a(1, 3);
    Drib b(1, 4);
    cout << (a == b);
}