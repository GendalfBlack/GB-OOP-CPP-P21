#include <iostream>
#include <fstream>

using namespace std;

// Перевантаження унарних операторів (унарний оператор це оператор, що працює з одним значенням)

class Vector {
public:
	int x; 
	int y;
	Vector() : x(0), y(0){ }
	Vector(int _x, int _y): x(_x), y(_y){ }
	void operator++(int);
	Vector operator-() const; // const - визначення УНАРНОГО мінуса, бо є БІНАРНИЙ мінус (число - число)
	void print() { printf("%d, %d\n", x, y); }
};
void Vector::operator++(int) { x++; y++; }
Vector Vector::operator-() const { Vector v;  v.x = -x; v.y = -y; return v; }

int main() {
	Vector a(2, 4);
	a.print();
	a++;
	a.print();
	Vector b = -a;
	b.print();
}