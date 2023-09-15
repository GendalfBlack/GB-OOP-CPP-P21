#include <iostream>

class Point {
public:
    int x;
    int y;
    Point() {
        x = 0;
        y = 0;
    }
    Point(int x, int y) {
        this->x = x;
        this->y = y;
    }
    Point(int min_max){
        x = rand() % min_max;
        y = rand() % min_max;
    }
    void print() {
        printf("%d,%d ", x, y);
    }
};

int main()
{

    Point p1 = Point();
    p1.print();

    Point p2 = Point(5, 10);
    p2.print();
    p2.x += 3;
    p2.print();

    Point p3 = Point(10);
    p3.print();
}