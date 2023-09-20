#include <iostream>

class MyArray {
public:
    int* begin; // початок массива
    int* end;   // кінець массива
    int getSize() { return end - begin; } // пошук довжини массива (кінець - початок)
    MyArray() : begin(nullptr), end(nullptr){} // конструктор за замовчуванням
    void Add(int n) { // метод додавання елемента
        int* newArr = new int[getSize() + 1]; // новий розширений массив в пам'яті
        for (int i = 0; i < getSize(); i++) { newArr[i] = begin[i]; } // перепис елементів в новий масив
        newArr[getSize()] = n; // додавання останнього елемента
        end = newArr + getSize() + 1; // запам'ятовуємо адресу останнього елементу
        delete[] begin; begin = newArr; // чистим пам'ять, оновлюємо адресу першого елементу
    }
    MyArray& operator=(const MyArray& other) { // оператор присвоювання, що перезаписує масив
        if (!(this == &other)) // якщо ми не на магаємось перезаписати самі в себе
        {
            delete[] begin; // звільняєм раніше зайняту пам'ять
            begin = other.begin; // запам'ятовуємо новий початок масива
            end = other.end; // запам'ятовуємо новий кінець масива
        }
        return *this; // в результаті повертаєм себе як готовий присвоєний масив
    }
    MyArray& operator+(int n) { Add(n); return *this; } // оператор додавання, що додасть один іnt в кінець масива
    MyArray& operator+(MyArray& other) { // реалізувати оператор додавання одного масива до іншого
        MyArray arr;
        for (int* start = begin; start < end; start++) { arr.Add(*start); }
        for (int* start = other.begin; start < other.end; start++) { arr.Add(*start); }
        return arr;
    }
    MyArray& operator+=(MyArray& other) { // реалізувати оператор додавання одного масива до іншого
        for (int i = 0; i < other.getSize(); i++) {Add(other.begin[i]); }
        return *this;
    } 
    MyArray& operator+=(int n) { return *this + n; }
    int operator[](int n) { return *(begin + n); }
    void print() { for (int* start = begin; start < end; start++) { printf("%d, ", *start); } printf("\b\b \n"); }
};

int main()
{
    MyArray arr1;
    arr1 += 5;
    arr1 += 3;
    arr1 += 4;
    arr1.print();
    MyArray arr2;
    arr2 += 1;
    arr2 += 7;
    arr2 += 4;
    arr2.print();
    arr1 += arr2;
    arr1.print();
    MyArray arr3 = arr1 + arr2;
    printf("%d", arr3[0]);
}