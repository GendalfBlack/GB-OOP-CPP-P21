#include <iostream>
#include <Windows.h>
using namespace std;

template <typename Uliana>
class Element {
    Uliana value;
    Element* next;
    Element* prev;
    Element() : value(0), next(nullptr), prev(nullptr) { }
    Element(int v) : value(v), next(nullptr), prev(nullptr) { }
};

template <typename T>
class DoubleLinkedList {
    Element<T>* begin;
    Element<T>* end;
    DoubleLinkedList(): begin(nullptr), end(nullptr){}
    DoubleLinkedList(T val) : begin(&val), end(&val) {}
    void append(T& val) {
        if (end == nullptr) { begin = &val; end = &val; return; }
        end->next = &val;
        end = &val;
    }
    int getSize() {
        int n = 0;
        Element<T>* current = begin;
        while (current->next != nullptr) {
            n++;
            current = current->next;
        }
        return n;
    }
    void print() {
        Element<T>* current = begin;
        while (current->next != nullptr) {
            cout << current->value;
            current = current->next;
        }
    }

    Element<T>* find(T val) {
        Element<T>* current = begin;
        while (current->next != nullptr) {
            if (current->value == val)
            {
                return current;
            }
            current = current->next;
        }
        return nullptr;
    }

    int index(T val) {
        int i = 0;
        Element<T>* current = begin;
        while (current->next != nullptr) {
            if (current->value == val)
            {
                return i;
            }
            i++; current = current->next;
        }
        return -1;
    }

    void pop() {
        if (end != nullptr)
        {
            Element<T>* link = end->prev;
            delete end;
            end = link;
            end->next = nullptr;
        }
        else if (end == begin) {
            delete begin;
            begin = nullptr;
            end = nullptr;
        }
    }
    void remove(T val) {
        Element<T>* current = begin;
        while (current->next != nullptr) {
            Element<T>* link = current->prev;
            Element<T>* link2 = current->next;
            current->prev->next = link2;
            current->next->prev = link;
            delete current;
        }
    }

};

int main()
{
    std::cout << "Hello World!\n";
}
