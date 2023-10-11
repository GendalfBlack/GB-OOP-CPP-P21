#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <Windows.h>
#include<fstream>
using namespace std;



ifstream file;
class Car {
public:
    int number;
    char* brand;
    int places;
    int  max_fuel;
    int now_fuel;
    double f_c; // витрати пального на км
    static int size;



    Car() : number(0), brand(nullptr), places(0), max_fuel(0), now_fuel(0), f_c(0) {} // Конструктор за замовчуванням
    Car(int number,
        const char* brand,
        int places,
        int max_fuel,
        int now_fuel,
        double f_c) {



        this->number = number;
        int count = 0;
        for (const char* counter = brand; *counter != '\0' && *counter != '\n'; counter++) { count++; }
        this->brand = new char[count + 1];
        char* count1 = this->brand;
        for (const char* counter = brand; *counter != '\0' && *counter != '\n'; counter++) { *count1 = *counter; count1++; }
        *count1 = '\0';



        this->places = places;
        this->max_fuel = max_fuel;
        this->now_fuel = now_fuel;
        this->f_c = f_c;  // Конструктор за замовчуванням що приймає в якості параметри
    }
    Car(const Car& other) { // Копіювальний конструктор, що копіює вміст одної машини на іншу
        number = other.number;
        int count = 0;
        for (const char* counter = other.brand; *counter != '\0' && *counter != '\n'; counter++) { count++; }
        this->brand = new char[count + 1];
        char* count1 = this->brand;
        for (const char* counter = count1; *counter != '\0' && *counter != '\n'; counter++) { *count1 = *counter; count1++; }
        *count1 = '\0';
        places = other.places;
        max_fuel = other.max_fuel;
        now_fuel = other.now_fuel;
        f_c = other.f_c;
    }
    static int get_cars() {
        return size;
    }
    inline void add_car() {
        cout << "Введіть номер авто: ";
        fgets(brand, 40, stdin);
        cout << "Введіть бренд авто: ";
        cin >> brand;
        cout << "Введіть кількість місць авто: ";
        cin >> places;
        cout << "Введіть об'ем бака авто: ";
        cin >> max_fuel;
        cout << "Введіть запас пального авто: ";
        cin >> now_fuel;
        cout << "Введіть витрату пального авто: ";
        cin >> f_c;
    }
    double get_distance() { return now_fuel / f_c; }
    void show_car() {
        cout << "Номер авто: " << number << endl;
        cout << "Бренд авто: " << brand << endl;
        cout << "Введіть кількість місць авто: " << places << endl;
        cout << "Введіть об'ем бака авто: " << max_fuel << endl;
        cout << "Введіть запас пального авто: " << now_fuel << endl;
        cout << "Введіть витрату пального авто: " << f_c << endl;
    }
    void infile() {
        const char* path = "E:/Нова папка/file.txt";
        ofstream file;
        file.open(path, ofstream::out | ios::binary);



        char* number_t = new char[10];
        _itoa(number, number_t, 10);
        file.write(number_t, 10);



        char* brand_t = new char[10];
        for (int i = 0; i < 10; i++) { brand_t[i] = brand[i]; }
        file.write(brand_t, 10);



        char* places_t = new char[10];
        _itoa(places, places_t, 10);
        file.write(places_t, 10);



        char* max_fuel_t = new char[10];
        _itoa(max_fuel, max_fuel_t, 10);
        file.write(max_fuel_t, 10);



        char* now_fuel_t = new char[10];
        _itoa(now_fuel, now_fuel_t, 10);
        file.write(now_fuel_t, 10);



        char* c_f_t = new char[10];
        _itoa(int(f_c * 100), c_f_t, 10);
        file.write(c_f_t, 10);



        file.close();
    }
    int  just_read() {
        char str[10];
        file.read(str, 10);
        return atoi(str);
    }
    void read() {
        const char* path = "F:/C++ project/25.09 classwork/25.09 classwork/file.txt";
        file.open(path, ofstream::out | ios::binary);
        number = just_read();
        char brand_t[10];
        file.read(brand_t, 10);
        places = just_read();
        max_fuel = just_read();
        now_fuel = just_read();
        f_c = just_read() / 100.0;
        file.close();
    }
    ~Car() {
        delete[] brand;
    }
};



class CarStop {
    static int cars_placed;
public:
    int max_cars;
    int price = 50;
    int money = 0;
    int size;
    Car** cars;
    CarStop(int size) : max_cars(size), cars(nullptr) {}
    void Add(Car& car) {
        Car** new_cars = new Car * [size + 1];
        for (int i = 0; i < size; i++) { new_cars[i] = cars[i]; }
        new_cars[size] = &car;
        delete[]cars;
        cars = new_cars;
        size++;
        money += price;
    }



    void show_numbers() {
        for (int i = 0; i < size; i++)
        {
            cout << "Місце машини: " << i + 1 << " Номер машини " << cars[i]->number << endl;
        }
    }
    void show_cars() {
        for (int i = 0; i < size; i++)
        {
            cout << "Місце машини: " << i + 1 << endl;
            cars[i]->show_car();
        }
    }
    void del(Car*& car) {
        int del_car = -1;
        for (int i = 0; i < size; i++) {
            if (cars[i] == car) {
                del_car = i;
                break;
            }
        }
        if (del_car != -1) {
            for (int i = del_car; i < size - 1; i++) {
                cars[i] = cars[i + 1];
            }
            Car** new_cars = new Car * [size-1];
            for (int i = 0; i < size-1; i++) {
                new_cars[i] = cars[i];
            }
            delete[] cars;
            cars = new_cars;
            size--;
        }
        else {
            cout << "Немає такої машини!";



        }
    }
    /*void write_numbers() {
        const char* path = "Artemko/radada";
        ofstream file;
        file.open(path, ofstream::out | ios::binary);
        for (int i = 0; i < size; i++)
        {
            char* numbert = new char[10];
            _itoa(cars[i]->number, numbert, 10);
            file.write(numbert, 10);
        }
        file.close();
    }*/
    bool car_isinthe_carstop(int numberr) {
        bool caris = false;
        for (int i = 0; i < size; i++)
        {
            if (cars[i]->number == numberr) {
                caris = true;
                return true;
            }
        }
        if (caris == false) { return false; }
    }
    Car* get_car_isinthe_carstop(int numberr) {
        bool caris = false;
        for (int i = 0; i < size; i++)
        {
            if (cars[i]->number == numberr) {
                caris = true;
                return cars[i];
            }
        }
        if (caris == false) { return nullptr; }
        return nullptr;
    }
    CarStop operator+=(Car& car1) {
        Add(car1); return *this;
    }

    /*
    ~CarStop() {
        for (int i = 0; i < size; i++) {
            delete[] cars[i]->brand;
        }
        delete[] cars;
    }*/
};



int Car::size = 0;
int CarStop::cars_placed = 0;



int main()
{
    SetConsoleOutputCP(1251);



    Car car1(101, "BMW", 4, 60, 30, 8.5);
    Car car2(007, "Ferari", 5, 70, 40, 9.0);



    car1.infile(); // Запис машини car1 в файл
    car2.infile(); // Запис машини car2 в файл



    Car car3;
    car3.read();



    CarStop carStop(10);
    carStop += car1;
    carStop += car2;
    /* carStop += car3;*/



    cout << "Машини в автостоянці: " << endl;
    carStop.show_cars();



    cout << "Номера машин, які перебувають в автостоянці: " << endl;
    carStop.show_numbers();



    int carNumber;
    cout << "Введіть номер машини, яку видалити: ";
    cin >> carNumber;



    if (carStop.car_isinthe_carstop(carNumber)) {
        Car* carToRemove;
        carToRemove = carStop.get_car_isinthe_carstop(carNumber);
        carStop.del(carToRemove);
        cout << "Машина з номером " << carNumber << " видалена з автостоянки" << endl;
    }
    else {
        cout << "Машина з номером " << carNumber << " не знайдена в автостоянці" << endl;
    }



    cout << "Машини після видалення:" << endl;
    carStop.show_cars();
}
// Не працює деструктор
//
   // і carStop += car3; чи читання або проблема з записуванням*/
    // не видаляється машина