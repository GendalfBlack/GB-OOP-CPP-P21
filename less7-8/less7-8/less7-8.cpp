#include <iostream>
#include <Windows.h>
using namespace std;

// Статичні елементи класу (функції, члени(властивості))

class Point {
	int id;
public:
	static int last_id;
	int x;
	int y;
	Point() :x(0), y(0) { id = last_id; last_id++; }
	Point(int _x, int _y) : x(_x), y(_y) { id = last_id; last_id++; }
	void print() { cout << id << ". " << "x: " << x << ", y: " << y << '\n'; }
};
int Point::last_id = 0;
int main()
{
	for (int i = 0; i < 10; i++)
	{
		Point p1;
		p1.print();
		Point p2(5, 6);
		p2.print();

	}
}