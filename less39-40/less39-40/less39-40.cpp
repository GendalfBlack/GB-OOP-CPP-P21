#include <iostream>
using namespace std;
// �����������
class Animal { // ����������� ����, �� ���� �������� ��������� ������ �� ���� ��� ���� � ��� ������� �����
public:
    void eat() {
        cout << "Animal is eating" << endl;
    }

    void sleep() {
        cout << "Animal is sleeping" << endl;
    }
};

class Dog : public Animal { // ������� ����, �� ������ߪ ��������� ������������ ����� � ���� ��������������� ���� ���������
public:
    void bark() {
        cout << "Dog is barking" << endl;
    }
};

int main()
{
    Animal a;
    a.eat();

    Dog d;
    d.bark();
    d.eat();
}
