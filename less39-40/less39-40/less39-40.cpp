#include <iostream>
using namespace std;
// Ќасл≥дуванн€
class Animal { // Ѕатьк≥вський клас, що вм≥щаЇ «ј√јЋ№Ќ” реал≥зац≥ю метод≥в та пол≥в дл€ себе ≥ ус≥х доч≥рн≥х клас≥в
public:
    void eat() {
        cout << "Animal is eating" << endl;
    }

    void sleep() {
        cout << "Animal is sleeping" << endl;
    }
};

class Dog : public Animal { // ƒоч≥рн≥й клас, що –ќ«Ў»–я™ можливост≥ батьк≥вського класу ≥ може використовувати його реал≥зац≥ю
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
