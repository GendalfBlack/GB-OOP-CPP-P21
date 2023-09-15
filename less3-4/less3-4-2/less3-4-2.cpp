#include <iostream>
#include <Windows.h>
using namespace std;
class RightTriange {
public:
    double a;
    double b;
    double c;
    RightTriange(double u_a, double u_b, double u_c) {
        if (u_a * u_a + u_b * u_b == u_c * u_c) { a = u_a; b = u_b; c = u_c; }
        else { printf("Це не прямокутний трикутник!\n"); RightTriange(); }
    }
    RightTriange() {
        a = 1; b = 1; c = sqrt(2);
        printf("Створено прямокутник за замовчуванням!\n");
    }
    double getArea() {
        return a * b / 2;
    }
};

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    RightTriange t1 = RightTriange();
    RightTriange t2 = RightTriange(3, 4, 5);
    cout << t1.getArea() << '\n';
    cout << t2.getArea() << '\n';
}