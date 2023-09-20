#include <iostream>
#include <Windows.h>
using namespace std;

// Динамічний массив з об'єктів класів
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

int n = 10;
Point** arr = new Point*[n];
// Для динаміного массива, що зайвий раз не викличе конструктор класу, треба створити
// масив показчиків на об'єкти
int main()
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = new Point(rand()%10, rand()%10); // вибирати конструктор за допомогою new
		arr[i]->print(); // не можна писати через оператор доступу (.), треба оператор доступу
																	 // по показчику (->)
	}
}