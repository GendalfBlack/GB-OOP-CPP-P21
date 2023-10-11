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

    Element* find(int v) {
        Element* current = begin;
        while (current->next != nullptr) { if (current->value == v) { return current; } current = current->next; }
        return nullptr;
    }

    int index(int v) {
        Element* current = begin;
        int i = 0;
        while (current->next != nullptr) { 
            if (current->value == v) { return i;} i++; current = current->next;
        }
        return -1;
    }

    void remove(int v) {
        if (begin->value == v)
        {
            Element* link = begin->next;
            delete begin;
            begin = link;
            return;
        }
        Element* current = begin;
        while (current->next != nullptr) { 
            if (current->next->value == v) 
            { 
                Element* link = current->next->next;
                delete current->next;
                current->next = link;
                return;
            } 
            current = current->next; 
        }
    }

    void pop() {
        Element* current = begin;
        while (current->next != nullptr) 
        { 
            current = current->next; 
        }
        delete current->next;
        current->next = nullptr;
    }

    void print() {
        Element* current = begin;
        while (current->next->next != nullptr) { 
            cout << current->value;
            current = current->next; 
        }
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