#include <iostream>
#include <Windows.h>
// Конструктор копіювання
using namespace std;

class Point {
public:
    int x; // властивість х
    int y;
    Point() { x = 0; y = 0; cout << "Default"; } //Point() : x(0), y(0) { }
    Point(int _x, int _y) : x(_x), y(_y) { cout << "Normal"; } // : - це звернення до структури класу та властивостей класу
    Point(const Point& p) : x(p.x + 1), y(p.y + 1) { cout << "Copy"; } // перевантаження конструктора копіювання
                                                       // що буде контрольовано спрацьовувати тільки 
                                                       // у випадку, коли ми з одного об'єкта пишемо в інший
};

int main()
{
    Point p; // ініціалізація об'єкта класу викликає конструктор та записує значення в змінні
    cout << p.x << ' ' << p.y << '\n'; // px = 0, py = 0

    Point a(2,3);
    cout << a.x << ' ' << a.y << '\n';

    Point b = a;
    cout << b.x << ' ' << b.y << '\n';
}