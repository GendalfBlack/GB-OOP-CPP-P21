#include <iostream>
#include <fstream>

using namespace std;

// Перевантаження унарних операторів (унарний оператор це оператор, що працює з одним значенням)

class MyArray {
public:
    char** names; // массив слів
    int* values; // массив чисел
    int size; // розмір для обох масивів
    MyArray() : names(nullptr), values(nullptr), size(0) { } // конструктор за замовчуванням
    void Add(const char* name, int value) { // метод для додавання елементу
        char** new_names = new char* [size + 1]; // розширення масиву слів
        int* new_values = new int[size + 1]; // разширення масиву чисел
        for (int i = 0; i < size; i++) { new_names[i] = names[i]; new_values[i] = values[i]; } // копіювання в розширені масиви
        int i = 0; // лічильник для символів нового слова
        for (const char* pointer = name; *pointer != '\0' && *pointer != '\n'; pointer++){ i++; } i++; // рахуємо букви, плюс \0
        char* new_word = new char[i]; // виділення пам'яті для нового слова
        for (int k = 0; k < i; k++) { new_word[k] = name[k]; } // переписування слова з переданого у функцію
        new_names[size] = new_word; // додавання нового слова в масив слів
        new_values[size] = value; // додавання нового числа в масив чисел
        delete[] names; delete[] values; // звільнення попередньо занятої пам'яті
        names = new_names; values = new_values; // перезапис показчиків на масиви на нові розширені масиви
        size++; // збільшення розміру
    }
    // вивід обох масивів
    void print() { for (int i = 0; i < size; i++) { printf("%s : %d, ", names[i], values[i]); } cout << '\n'; } 
    int& operator[](const char*);
};
int& MyArray::operator[](const char* key) { // тіло перевантаженного оператора
    int index = 0; // за замовчуванням повертаємо індекс 0 
    for (int i = 0; i < size; i++) // для кожного слова в масиві names
    {
point:
        char* name = names[i]; // робимо показчик на першу букву слова з індексом "і"
        for (const char* pointer = key; *pointer != '\0'; pointer++) // для всіх букв переданого слова "key"
        { if (*pointer != *name) // якщо буква не співпадає
        { i++; goto point; } // продовжуємо до наступного слова
        name++; } // працюємо з іншою буквою
        index = i; break; // інакше запам'ятовуємо індекс і виходимо з цикла
    }
    return values[index]; // повертаємо елемент з масива чисел під тим же індексом що 
                          // і елемент з масива слів зі словом що передали в функцію
}
int main()
{
    MyArray m;
    m.Add("Danil", 1);
    m.Add("Denis", 12);
    cout << m["Denis"];
}
