#include <iostream>
#include <Windows.h>
using namespace std;

// ������ 1. �������� ����, �� ���� ��������� ����. ���� �� �����.
// ������ ����� ��������� ������� ���� �� �����. ��� �������� ����
// ��������� �� ����� ������ ������ �� 0. 

const double PI = 3.141592;

class Circle {
public:
    double radius;
    double x; 
    double y;
    
    Circle() { radius = 1; x = 0; y = 0; }
    Circle(double r) {
        if (r > 0) { radius = r; x = 0; y = 0; }
        else { printf("����� ���� �� ��������!"); Circle(); }
    }
    Circle(double r, double u_x, double u_y) {
        if (r > 0) { radius = r; }
        else { printf("����� ���� �� ��������!"); Circle(); }
        x = u_x; y = u_y;
    }
    double getArea() { return radius * radius * PI; }
    double getLength() { return radius * 2 * PI; }
};

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    Circle c1 = Circle(4, 2, 2);
    cout << c1.getArea();
}
