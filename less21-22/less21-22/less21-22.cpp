#include <iostream>
#include <Windows.h>
using namespace std;

class Element { 
public:
    int value;
    Element* next;
    Element() : value(0), next(nullptr) {}
    Element(int v) : value(v), next(nullptr) {}
    operator int() { return value; }
};
class List {
    Element* begin;
public:
    List() : begin(nullptr) {}
    void append(int number) {
        if (begin == nullptr)
        {
            Element* e = new Element(number);
            begin = e;
        }
        else
        {
            Element* current = begin;
            while (current->next != nullptr)
            {
                current = current->next;
            }
            Element* e2 = new Element(number);
            current->next = e2;
        }
    }
    int getSize() {
        int n = 0;
        Element* current = begin;
        while (current->next != nullptr) { current = current->next; n++; }
        return n;
    }
    void insert(int place, int number) {
        if (place - 1 < getSize())
        {
            int i = 0;
            Element* current = begin;
            while (i != place - 1) { current = current->next; i++; }
            Element* e = new Element(number);
            Element* e2 = current->next;
            current->next = e;
            e->next = e2;
        }
    }
    void print() {
        Element* current = begin;
        while (current != nullptr)
        {
            cout << current->value;
            current = current->next;
        };
    }
};
int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    List l;
    l.append(1);
    l.print();
    cout << "\n";
    l.append(2);
    l.print();


}