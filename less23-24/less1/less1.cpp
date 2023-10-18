#include <iostream>
#include "List.h"
using namespace std;
class Point {
public:
	int x;
	int y;
	Point() : x(0), y(0) {}
	Point(int _x, int _y) :x(_x), y(_y){}
	void print(int i) { cout << i+1 << "[" << x << ", " << y << "]"; }
};
List<Point> l;
void AddPoint(Point& p) {
    l.append(p);
}
void AddRandomPoint() {
	l.append(Point(rand() % 200 - 100, rand() % 200 - 100));
}
void PrintPoints() {
	for (int i = 0; i < l.getSize(); i++)
	{

	}
}
int main()
{
	Point p1(1, 2);
	AddPoint(p1);
	AddRandomPoint();
	/* Задача 1.
	Користуючись списком, створити список класів "Point". Реалізувати дві функції
	що будуть додавати одну точку у список, друга функція додасть рандомну точку
	з координатами від -100 до 100.

	Задача 2. 
	Зробити метод, що виведе всі елементи списку точок у вигляді таблички:
	1 [x, y]
	2 [x, y]

	Задача 3. 
	Зробити метод, що обраховує для кожного елементу списку відстань точки від початку
	координат і виводить на екран sqrt(x^2+y^2)

	Задача 4. Створити клас "Підписники Версальского договору". Створити в ньому 
	список країн, додати країни які підписали. В класі країни додати список міст
	що відійшли по довогору до цієї країни. Вивести підсумки довогору на екран.
	*/
	Country c1("Нікчемчина");
	c1.AddTown("Берлін");
	VersalAgreementSubscriber dogovir;
	dogovir.AddCountry(c1);
}
class VersalAgreementSubscriber {
public:
	List<Country>* countries;
	VersalAgreementSubscriber(): countries(new List<Country>){}
	void AddCountry(Country& c){
		
	}
};
class Country {
public:
	char* name;
	List<char*>* towns;
	Country(const char* name_): towns(nullptr) {
		int i = 0;
		for (const char* begin = name_; *begin != '\0'; begin++){ i++; }
		i++; name = new char[i];
		for (int j = 0; j < i; j++) { name[i] = name_[i]; }
		name[i - 1] = '\0';
	}
	void AddTown(const char* town_name){
		int i = 0;
		for (const char* begin = town_name; *begin != '\0'; begin++) { i++; }
		i++; char* town_name_ = new char[i];
		for (int j = 0; j < i; j++) { town_name_[i] = town_name[i]; }
		towns->append(town_name_);
	}
};