#include <iostream>
#include <Windows.h>
using namespace std;

class Line {
public:
    int x1;
    int y1;
    int x2;
    int y2;
    Line() { x1 = 0; y1 = 0; x2 = 1, y2 = 1; }
    Line(int ax, int ay, int bx, int by) {
        if (ax!=bx && ay!=by) { x1 = ax; y1 = ay; x2 = bx; y2 = by; }
        else { printf("Пряма не може бути створена з однієї точки!\n"); Line(); }
    }
    void printEq() {
        int a = 2 * (x2 - x1);
        int b = 2 * (y2 - y1);
        int c = x1 * x1 - x2 * x2 + y1 * y1 - y2 * y2;
        printf("(%d)x+(%d)y+(%d)=0\n", a, b, c);
    }
};

void Cross(Line l1, Line l2) {
    int a1 = 2 * (l1.x2 - l1.x1);
    int b1 = 2 * (l1.y2 - l1.y1);
    int c1 = l1.x1 * l1.x1 - l1.x2 * l1.x2 + l1.y1 * l1.y1 - l1.y2 * l1.y2;

    int a2 = 2 * (l2.x2 - l2.x1);
    int b2 = 2 * (l2.y2 - l2.y1);
    int c2 = l2.x1 * l2.x1 - l2.x2 * l2.x2 + l2.y1 * l2.y1 - l2.y2 * l2.y2;

    double x = (c2 * b1 - c1 * b2) / (b2 * a1 - a1 * b1);
    double y = (-a1 * x - c2) / b2;
    printf("x: %.2f, y: %.2f", x, y);
}

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    Line l1 = Line(1, 1, 5, 4);
    Line l2 = Line(-9, 7, 1, 2);
    l1.printEq();
    l2.printEq();
    Cross(l1, l2);
}