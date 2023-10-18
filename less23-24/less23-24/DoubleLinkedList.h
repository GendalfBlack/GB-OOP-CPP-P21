#pragma once
using namespace std;
template <class T>
class Element {
public:
    T value;
    Element<T>* next;
    Element() : value(0), next(nullptr) {}
    Element(T v) : value(v), next(nullptr) {}
    operator int() { return value; }
};
template <class T>
class List {
    Element<T>* begin;
public:
    List() : begin(nullptr) {}
    void append(T number) {
        if (begin == nullptr)
        {
            Element<T>* e = new Element<T>(number);
            begin = e;
        }
        else
        {
            Element<T>* current = begin;
            while (current->next != nullptr)
            {
                current = current->next;
            }
            Element<T>* e2 = new Element<T>(number);
            current->next = e2;
        }
    }
    int getSize() {
        int n = 0;
        Element<T>* current = begin;
        while (current->next != nullptr) { current = current->next; n++; }
        return n;
    }
    void insert(T place, int number) {
        if (place - 1 < getSize())
        {
            int i = 0;
            Element<T>* current = begin;
            while (i != place - 1) { current = current->next; i++; }
            Element<T>* e = new Element<T>(number);
            Element<T>* e2 = current->next;
            current->next = e;
            e->next = e2;
        }
    }

    Element<T>* find(T v) {
        Element* current = begin;
        while (current->next != nullptr) { if (current->value == v) { return current; } current = current->next; }
        return nullptr;
    }

    int index(int v) {
        Element<T>* current = begin;
        int i = 0;
        while (current->next != nullptr) {
            if (current->value == v) { return i; } i++; current = current->next;
        }
        return -1;
    }

    void remove(T v) {
        if (begin->value == v)
        {
            Element* link = begin->next;
            delete begin;
            begin = link;
            return;
        }
        Element<T>* current = begin;
        while (current->next != nullptr) {
            if (current->next->value == v)
            {
                Element<T>* link = current->next->next;
                delete current->next;
                current->next = link;
                return;
            }
            current = current->next;
        }
    }

    void pop() {
        Element<T>* current = begin;
        while (current->next != nullptr)
        {
            current = current->next;
        }
        delete current->next;
        current->next = nullptr;
    }

    void print() {
        Element<T>* current = begin;
        while (current->next->next != nullptr) {
            cout << current->value;
            current = current->next;
        }
    }
};