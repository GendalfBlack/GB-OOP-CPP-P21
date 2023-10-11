#include <iostream>

using namespace std;
// Поліморфізм - це властивіть класів використовувати різні типи даних для своїх властивостей, що спрощує роботу з класом, 
// та надає гнучкість в використанні пам'яті

// Шаблон класу - це універсальний спосіб створення об'єктів класу, які не залежать від типу даних

 // в якості шаблону можна використовувати ТІЛЬКИ типи даних
class Point2D {
public:
    int x;
    int y;
    Point2D() : x(0), y(0) {}
    Point2D(int _x, int _y) : x(_x), y(_y) {}
    void print() { cout << x << ' ' << y << endl; }
};
class Point3D {
public:
    int x;
    int y;
    int z;
    Point3D() : x(0), y(0), z(0) {}
    Point3D(int _x, int _y, int _z) : x(_x), y(_y), z(_z) {}
    void print() { cout << x << ' ' << y << ' ' << z << endl; }
};

template <class T> // в якості шаблону, можна використовувати КЛАСИ
class Figure {
public:
    T** points;
    int size;
    Figure(): points(nullptr), size(0){}
    void Add(T& point) {
        T** new_points = new T*[size + 1];
        for (int i = 0; i < size; i++) { new_points[i] = points[i]; }
        new_points[size] = &point;
        delete[]points; points = new_points;
        size++;
    }
    void print() { for (int i = 0; i < size; i++) { points[i]->print(); } }
};

int main()
{
    Point2D p1(10, 10); Point2D p2(5, 5);
    Figure<Point2D> f1;
    f1.Add(p1); f1.Add(p2); f1.print();

    Point3D p3(10, 10, 10); Point3D p4(5, 5, 5);
    Figure<Point3D> f2;
    f2.Add(p3); f2.Add(p4); f2.print();
}
