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
    virtual void print() { printf("%s(%d, %d)", name, x, y); } // метод що може бути перезаписаний нащадками (дочірніми класами)
    virtual void printPoint() final { Point::print(); }
};

class Circle : public Point {
public:
    int radius;
    Circle() : Point(), radius(0){ }
    Circle(int x_, int y_, const char* name_, int radius_) : Point(x_, y_, name_), radius(radius_) { }
    // перезапис батьківського методу 
    void print() override { printf("Circle: %s, Center: (%d,%d), Radius: %d", name, x, y, radius); } 
    float area() { return 3.14f * radius * radius; }
    float length() { return 2 * 3.14f * radius; }
};

/*Задача 1. Зробити нащадка класу Point, що буде точкою в 3д просторі і отримає ще одну змінну z для
відповідної координати. Оновити усі методи в класі "Point" згідно новій змінній (Конструктори та print)

Задача 2. Зробити нащадка класу Point, що буде прямокутником і отримає ще 2 змінні x2,y2 для координат другої точки. 
Реалізувати методи area, perimert, diagonal, що будуть рахувати відповідні величини. Оновити усі методи в класі 
"Point" згідно новим змінним (Конструктори та print)

Задача 3. Зробити нащадка класу прямокутника, що буде трикутником і отримає ще 2 змінні для координат третьої точки.
Оновити усі методи в класі прямокутника згідно новим змінним (Конструктори та print, area, perimert)

Задача 4. Зробити нащадка класу 3д точки, що буде паралелепіпедом, та отримає ще 3 змінні для другої точки
що визначає паралелепіпед (протилежний кут). Реалізувати методи area, volume. Оновити усі методи в класі 
згідно новим змінним (Конструктори та print).

Задача 5. Зробити нащадка класу Point, що буде многокутником і отримає масив змінних, що будуть 
відповідати координатам кутів многокутника. Реалізувати методи perimetr. Оновити конструктор та print
щоб можна було виводити усі точки прямокутника підряд, та приймати масив в конструктор.

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