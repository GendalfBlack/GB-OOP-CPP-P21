#include <iostream>
using namespace std;

uint8_t _hash(const char* str) {
    uint8_t hash_number = 0;
    for (const char* current = str; *current != '\0'; current++)
    {
        hash_number += *current;
    }
    return hash_number;
}
uint8_t _hash(char* str) {
    uint8_t hash_number = 0;
    for (char* current = str; *current != '\0'; current++)
    {
        hash_number += *current;
    }
    return hash_number;
}
bool strcmp2_0(char* str1, char* str2) {
    char* current1 = str1;
    char* current2 = str2;
    for (; *current1 != '\0' && *current2 != '\0';) { if (*current1 != *current2) { return false; } current1++; current2++; }
    if (*current1 == '\0' && *current2 == '\0') { return true; }
    return false;
}

class HashTable {
public:
    char** table;
    HashTable(): table(new char*[256]){
        for (int i = 0; i < 256; i++)
        {
            table[i] = new char[2];
            table[i][0] = '-';
            table[i][1] = '\0';
        }
    }
    void AddValue(char* value) {
        int counter = 0;
        int hindex = _hash(value);
        if (table[hindex][0] == '-') { table[hindex] = value; return; }
        while (table[hindex][0] != '-') 
        { 
            hindex++; if (hindex == 256) { hindex = 0; } // якщо таблиця по черзі доходить до кінця таблиці і не може додати, повертається на початок
            counter++; if (counter >= 256) { return; } // якщо таблиця робить в спробах додати елемент повний круг(таблиця повна) додавання не відбувається
        } 
        table[hindex] = value; return;
    }
    void AddValue(const char* value) {
        char* str; int i = 0;
        for (const char* current = value; *current != '\0'; current++) { i++; }
        str = new char[i + 1];
        int j = 0;
        for (const char* current = value; *current != '\0'; current++) { str[j] = *current; j++; }
        str[i] = '\0';
        AddValue(str);
    }

    int find(char* value) {
        int hindex = _hash(value);
        if (strcmp2_0(value, table[hindex])) { return hindex; }
        int counter = 0;
        while (!strcmp2_0(value, table[hindex]) && table[hindex][0] != '-') {
            hindex++; if (hindex == 256) { hindex = 0; }
            counter++; if (counter >= 256) { return -1; }
        }
        if (table[hindex][0] == '-') { return -1; }
        return hindex;
    }
    int find(const char* value) {
        char* str; int i = 0;
        for (const char* current = value; *current != '\0'; current++) { i++; }
        str = new char[i + 1];
        int j = 0;
        for (const char* current = value; *current != '\0'; current++) { str[j] = *current; j++; }
        str[i] = '\0';
        return find(str);
    }
    void print() {
        int k = 0;
        for (int i = 0; i < 16; i++)
        {
            for (int j = 0; j < 16; j++)
            {
                cout << table[k] << " ";
                k++;
            }
            cout << '\n';
        }
    }
};
int main()
{
    HashTable t;
    //t.print();

    t.AddValue("Sasha Garmash");
    t.AddValue("Vladislav Dem`yanchuk");
    t.AddValue("Ulya Goncharova");
    t.AddValue("Artem Popov");
    t.AddValue("Bogdan Shalovilo");
    t.AddValue("Bogdan Iskachov");
    t.AddValue("Danylo Mikhnevych");
    t.AddValue("Oleksandr Kovalenko");
    t.AddValue("Anastasiia Shevchenko");
    t.AddValue("Vladyslav Ivanov");
    t.AddValue("Yuliia Petrova");
    t.AddValue("Artem Pavlov");
    t.AddValue("Danylo Kozlov");
    t.AddValue("Iryna Moroz");
    t.AddValue("Mykola Sidorov");
    t.AddValue("Kateryna Vasilieva");
    t.AddValue("Ivan Makarov");
    t.AddValue("Mariia Zakharova");
    t.AddValue("Serhii Romanov");
    t.AddValue("Nataliia Kuznetsova");
    t.AddValue("Petro Kuzmin");
    t.AddValue("Olena Vorobiova");
    t.AddValue("Volodymyr Smirnov");
    t.AddValue("Tetiana Orlova");
    t.AddValue("Mykhailo Popov");
    t.AddValue("Anna Sokolova");
    t.AddValue("Yurii Mikhaylov");
    t.AddValue("Olha Fedorova");
    t.AddValue("Andrii Vasilev");
    t.AddValue("Yana Aleksandrova");
    t.AddValue("Dmytro Nikolaev");
    t.AddValue("Svitlana Ivanova");
    t.AddValue("Viktor Petrov");
    t.AddValue("Liudmyla Makarova");
    t.AddValue("Bohdan Sidorov");
    t.AddValue("Viktoria Kovalenko");
    t.AddValue("Stepan Zakharov");
    t.AddValue("Iuliia Shevchenko");
    t.AddValue("Oleksii Romanov");
    t.AddValue("Alina Kuznetsova");
    t.AddValue("Maksym Kuzmin");
    t.AddValue("Sofia Vorobiova");
    t.AddValue("Denys Smirnov");
    t.AddValue("Veronika Orlova");
    t.AddValue("Illia Popov");
    t.AddValue("Polina Sokolova");
    t.AddValue("Roman Mikhaylov");
    t.AddValue("Valeriia Fedorova");
    t.AddValue("Hlib Vasilev");
    t.AddValue("Karina Aleksandrova");
    t.AddValue("Artem Nikolaev");
    t.AddValue("Daria Ivanova");
    t.AddValue("Mykola Petrov");
    t.AddValue("Anastasiia Makarova");
    t.AddValue("Vladyslav Sidorov");
    t.AddValue("Yuliia Kovalenko");
    t.AddValue("Ivan Zakharov");
    t.AddValue("Mariia Shevchenko");
    t.AddValue("Serhii Romanov");
    t.AddValue("Nataliia Kuznetsova");
    t.AddValue("Petro Kuzmin");
    t.AddValue("Olena Vorobiova");
    t.AddValue("Volodymyr Smirnov");
    t.AddValue("Tetiana Orlova");
    t.AddValue("Mykhailo Popov");
    t.AddValue("Anna Sokolova");
    t.AddValue("Yurii Mikhaylov");
    t.AddValue("Olha Fedorova");
    t.AddValue("Andrii Vasilev");
    t.AddValue("Yana Aleksandrova");
    t.AddValue("Dmytro Nikolaev");
    t.AddValue("Svitlana Ivanova");
    t.AddValue("Viktor Petrov");
    t.AddValue("Liudmyla Makarova");
    t.AddValue("Bohdan Sidorov");
    t.AddValue("Viktoria Kovalenko");
    t.AddValue("Stepan Zakharov");
    t.AddValue("Iuliia Shevchenko");
    t.AddValue("Oleksii Romanov");
    t.AddValue("Alina Kuznetsova");
    t.AddValue("Maksym Kuzmin");
    t.AddValue("Sofia Vorobiova");
    t.AddValue("Denys Smirnov");
    t.AddValue("Veronika Orlova");
    t.AddValue("Illia Popov");
    t.AddValue("Polina Sokolova");
    t.AddValue("Roman Mikhaylov");
    t.AddValue("Valeriia Fedorova");
    t.AddValue("Hlib Vasilev");
    t.AddValue("Karina Aleksandrova");
    t.AddValue("Artem Nikolaev");
    t.AddValue("Daria Ivanova");
    t.AddValue("Mykola Petrov");
    t.AddValue("Anastasiia Makarova");
    t.AddValue("Vladyslav Sidorov");
    t.AddValue("Yuliia Kovalenko");
    t.AddValue("Ivan Zakharov");
    t.AddValue("Mariia Shevchenko");
    t.AddValue("Serhii Romanov");
    t.AddValue("Nataliia Kuznetsova");
    t.AddValue("Petro Kuzmin");
    t.AddValue("Olena Vorobiova");
    t.AddValue("Volodymyr Smirnov");
    t.AddValue("Tetiana Orlova");
    t.AddValue("Mykhailo Popov");
    t.AddValue("Anna Sokolova");
    t.AddValue("Yurii Mikhaylov");
    t.AddValue("Olha Fedorova");
    t.AddValue("Andrii Vasilev");
    t.AddValue("Yana Aleksandrova");
    t.AddValue("Dmytro Nikolaev");
    t.AddValue("Svitlana Ivanova");
    t.AddValue("Viktor Petrov");
    t.AddValue("Liudmyla Makarova");
    t.AddValue("Bohdan Sidorov");
    t.AddValue("Viktoria Kovalenko");
    t.AddValue("Stepan Zakharov");
    t.AddValue("Iuliia Shevchenko");
    t.AddValue("Oleksii Romanov");
    t.AddValue("Alina Kuznetsova");
    t.AddValue("Maksym Kuzmin");
    t.AddValue("Sofia Vorobiova");
    t.AddValue("Denys Smirnov");
    t.AddValue("Veronika Orlova");
    t.AddValue("Illia Popov");
    t.AddValue("Polina Sokolova");
    t.AddValue("Roman Mikhaylov");
    t.AddValue("Valeriia Fedorova");
    t.AddValue("Hlib Vasilev");
    t.AddValue("Karina Aleksandrova");
    t.AddValue("Artem Nikolaev");
    t.AddValue("Daria Ivanova");
    t.AddValue("Mykola Petrov");
    t.AddValue("Anastasiia Makarova");
    t.AddValue("Vladyslav Sidorov");
    t.AddValue("Yuliia Kovalenko");
    t.AddValue("Ivan Zakharov");
    t.AddValue("Mariia Shevchenko");
    t.AddValue("Serhii Romanov");
    t.AddValue("Nataliia Kuznetsova");
    t.AddValue("Petro Kuzmin");
    t.AddValue("Olena Vorobiova");
    t.AddValue("Volodymyr Smirnov");
    t.AddValue("Tetiana Orlova");
    t.AddValue("Mykhailo Popov");
    t.AddValue("Anna Sokolova");
    t.AddValue("Yurii Mikhaylov");
    t.AddValue("Olha Fedorova");
    t.AddValue("Andrii Vasilev");
    t.AddValue("Yana Aleksandrova");
    t.AddValue("Dmytro Nikolaev");
    t.AddValue("Svitlana Ivanova");
    t.AddValue("Viktor Petrov");
    t.AddValue("Liudmyla Makarova");
    t.AddValue("Bohdan Sidorov");
    t.AddValue("Viktoria Kovalenko");
    t.AddValue("Stepan Zakharov");
    t.AddValue("Iuliia Shevchenko");
    t.AddValue("Oleksii Romanov");
    t.AddValue("Alina Kuznetsova");
    t.AddValue("Maksym Kuzmin");
    t.AddValue("Sofia Vorobiova");
    t.AddValue("Denys Smirnov");
    t.print();

    /*
    Задача 1. За допомогою хеш таблиці зберегти інформацію про номери 
    автомобілів(генеруються по принципу "АА" дві літери "0000" чотири цифри "АА" дві літери ). Реалізувати приклад пошуку автомобіля 
    заздалегіть відомого в таблиці, і випадкового. Вивести індекси результату.

    Задача 2. Модифікувати хеш таблицю, або створити новий клас, що буде зберігати свій розмір (степені двійки 256, 512 ...) та використовувати 
    в усіх місцях необхідних де у нас було число "256" чи його складові для роботи хеш таблиці. В якості прикладу створити таблицю на 
    1024 та 2048. (треба буде написати свою _hash функцію, щоб вона повертала число від 0 до 1024, та від 0 до 2048)

    Задача 3. Модифікувати хеш таблицю, або створити новий клас, що буде зберігати данні будь-якого типу. Для прикладу створити 
    хеш таблицю що зберігає "int", "float". (треба буде написати свою _hash функцію, приймала int та float і повертала число
    потрібного діапазону в залежності від розміру таблиці)

    Задача 4. Зробити хеш таблицю, що буде в якості шаблона приймати клас. Зробити хеш-таблицю базового класу "Point" з коо-
    рдинатами float x, float y .(треба буде написати свою _hash функцію, приймала класс Point і повертала число потрібного 
    діапазону в залежності від розміру таблиці)
    */
}
