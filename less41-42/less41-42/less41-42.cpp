#include <iostream>
#include <Windows.h>
using namespace std;
#include "SingleList.h"

class Student {
public:
    char* name;
    char* surname;
    char* age;
    char* group;
    Student() : name(new char[60]), surname(new char[60]), age(new char[10]), group(new char[10]) { }
};

unsigned int _hash(Student& s, int size) {
    unsigned int hash = 0;
    for (char* current = s.name; *current != '\0'; current++)
    {
        hash += *current;
    }
    for (char* current = s.surname; *current != '\0'; current++)
    {
        hash += *current;
    }
    for (char* current = s.age; *current != '\0'; current++)
    {
        hash += *current;
    }
    for (char* current = s.group; *current != '\0'; current++)
    {
        hash += *current;
    }
    return hash % size;
}

template <class T>
class ListHashTable {
public:
    SingleList<T>** table;
    int size;
    ListHashTable() : table(new SingleList<T>* [256]), size(256) {
        for (int i = 0; i < 256; i++)
        {
            table[i] = nullptr;
        }
    }

    ListHashTable(int _size) : table(new SingleList<T>* [_size]), size(_size) {
        for (int i = 0; i < size; i++)
        {
            table[i] = nullptr;
        }
    }
    void AddElement(T value) {
        int hash = _hash(value, size);
        cout << hash;
        if (table[hash] != nullptr) { table[hash]->append(value); }
        else {
            table[hash] = new SingleList<T>();
            table[hash]->append(value);
        }
    }

    int find(Student& s) {
        int hash = _hash(s, size);
        if (table[hash] != nullptr) {
            return hash;
        }
        else { return -1; }
    }
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    ListHashTable<Student> t;
    Student s1 = Student();
    Student s2 = Student();
    cin >> s1.name;
    cin >> s1.surname;
    cin >> s1.age;
    cin >> s1.group;
    t.AddElement(s1);
    cout << "\nПошук елемента(який є): ";
    int a = t.find(s1);
    cout << a;
    cout << "\nПошук елемента(якого немає): ";
    int b = t.find(s2);
    cout << b;
}