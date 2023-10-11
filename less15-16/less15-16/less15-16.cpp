#include <iostream>

using namespace std;
// Поліморфізм - це властивіть класів використовувати різні типи даних для своїх властивостей, що спрощує роботу з класом, 
// та надає гнучкість в використанні пам'яті

// Шаблон класу - це універсальний спосіб створення об'єктів класу, які не залежать від типу даних

template <typename T, typename T2>
class Point {
public:
    T x;
    T2 y;
    Point() : x(0), y(0){}
    Point(T _x, T2 _y) : x(_x), y(_y){}
    void print() { cout << x << ' ' << y << endl; }
};

int main()
{
    Point<int, int> p1(1, 2);
    Point<float, float> p2(2.3, 6.4);
    Point<int, float> p3(2, 6.4);

    p1.print();
    p2.print();
    p3.print();
}
