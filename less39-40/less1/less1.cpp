#include <iostream>
using namespace std;

class Point {
public:
    int x;
    int y;
    char* name;
    Point(): x(0), y(0), name(new char[2]{'-', '\0'}){ }
    Point(int x_, int y_, const char* name_) : x(x_), y(y_) {
        int i = 0;
        for (const char* current = name_; *current != '\0'; current++){ i++; }
        name = new char[i+1]; i = 0;
        for (const char* current = name_; *current != '\0'; current++) { name[i] = *current; i++; }
        name[i] = '\0';
    }
    virtual void print() { printf("%s(%d, %d)", name, x, y); } // ����� �� ���� ���� ������������� ��������� (�������� �������)
    virtual void printPoint() final { Point::print(); }
};

class Circle : public Point {
public:
    int radius;
    Circle() : Point(), radius(0){ }
    Circle(int x_, int y_, const char* name_, int radius_) : Point(x_, y_, name_), radius(radius_) { }
    // ��������� ������������ ������ 
    void print() override { printf("Circle: %s, Center: (%d,%d), Radius: %d", name, x, y, radius); } 
    float area() { return 3.14f * radius * radius; }
    float length() { return 2 * 3.14f * radius; }
};

/*������ 1. ������� ������� ����� Point, �� ���� ������ � 3� ������� � ������ �� ���� ����� z ���
�������� ����������. ������� �� ������ � ���� "Point" ����� ���� ����� (������������ �� print)

������ 2. ������� ������� ����� Point, �� ���� ������������� � ������ �� 2 ���� x2,y2 ��� ��������� ����� �����. 
���������� ������ area, perimert, diagonal, �� ������ �������� ������� ��������. ������� �� ������ � ���� 
"Point" ����� ����� ������ (������������ �� print)

������ 3. ������� ������� ����� ������������, �� ���� ����������� � ������ �� 2 ���� ��� ��������� ������ �����.
������� �� ������ � ���� ������������ ����� ����� ������ (������������ �� print, area, perimert)

������ 4. ������� ������� ����� 3� �����, �� ���� ��������������, �� ������ �� 3 ���� ��� ����� �����
�� ������� ������������ (����������� ���). ���������� ������ area, volume. ������� �� ������ � ���� 
����� ����� ������ (������������ �� print).

������ 5. ������� ������� ����� Point, �� ���� ������������� � ������ ����� ������, �� ������ 
��������� ����������� ���� ������������. ���������� ������ perimetr. ������� ����������� �� print
��� ����� ���� �������� �� ����� ������������ �����, �� �������� ����� � �����������.

*/

int main()
{
    Point p;
    p.print(); cout << endl;
    Point p2(10, -3, "A");
    p2.print(); cout << endl;

    Circle c1;
    c1.print(); cout << endl;
    Circle c2(4, 3, "O", 10);
    c2.print(); cout << endl;
    c2.printPoint();
}