#include <iostream>
#include <Windows.h>
// ����������� ���������
using namespace std;

class Point {
public:
    int x; // ���������� �
    int y;
    Point() { x = 0; y = 0; cout << "Default"; } //Point() : x(0), y(0) { }
    Point(int _x, int _y) : x(_x), y(_y) { cout << "Normal"; } // : - �� ��������� �� ��������� ����� �� ������������ �����
    Point(const Point& p) : x(p.x + 1), y(p.y + 1) { cout << "Copy"; } // �������������� ������������ ���������
                                                       // �� ���� ������������� ������������� ����� 
                                                       // � �������, ���� �� � ������ ��'���� ������ � �����
};

int main()
{
    Point p; // ����������� ��'���� ����� ������� ����������� �� ������ �������� � ����
    cout << p.x << ' ' << p.y << '\n'; // px = 0, py = 0

    Point a(2,3);
    cout << a.x << ' ' << a.y << '\n';

    Point b = a;
    cout << b.x << ' ' << b.y << '\n';
}