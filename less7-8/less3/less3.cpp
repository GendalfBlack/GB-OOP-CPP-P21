#include <iostream>
#include <Windows.h>
using namespace std;

class MyPoint {
public: int x; int y;
    MyPoint(): x(0), y(0) { }
    MyPoint(int _x, int _y) : x(_x), y(_y) {}
    MyPoint(const MyPoint &p) : x(p.x), y(p.y){ }
};
// Статичні методи(функції) класів
class MyPolygon {
    static int amount;
public:
    MyPoint** vertecies;
    int sides;
    MyPolygon() : vertecies(nullptr), sides(0) { }
    MyPolygon(MyPoint* points, int n) {
        vertecies = new MyPoint* [n];
        sides = n;
        for (int i = 0; i < n; i++) { vertecies[i] = &points[i]; }
        amount++;
    }
    static int distance(MyPoint p0, MyPoint p1) {
        return sqrt((p1.x - p0.x) * (p1.x - p0.x) + (p1.y - p0.y) * (p1.y - p0.y));
    }
    int perimeter3() {
        return distance(*vertecies[0], *vertecies[1]) + distance(*vertecies[1], *vertecies[2]) +
            distance(*vertecies[2], *vertecies[0]);
    }

    static int get_size() {
        return amount;
    }
};
int MyPolygon::amount = 0;

int main()
{
    MyPoint p1(0, 0); MyPoint p2(0, 2); MyPoint p3(3, 0);
    MyPoint* points = new MyPoint[3];
    points[0] = p1; points[1] = p2; points[2] = p3;
    MyPolygon triangle(points, 3);
    cout << triangle.perimeter3() << '\n';
    cout << MyPolygon::get_size() << '\n';
}
