#pragma once
using namespace std;
template <class T>
class ElementS {
public:
    T value;
    ElementS<T>* next;
    ElementS() : value(0), next(nullptr) {}
    ElementS(T v) : value(v), next(nullptr) {}
    operator int() { return value; }
};
template <class T>
class SingleList {
    ElementS<T>* begin;
public:
    SingleList() : begin(nullptr) {}
    void append(T number) {
        if (begin == nullptr)
        {
            ElementS<T>* e = new ElementS<T>(number);
            begin = e;
        }
        else
        {
            ElementS<T>* current = begin;
            while (current->next != nullptr)
            {
                current = current->next;
            }
            ElementS<T>* e2 = new ElementS<T>(number);
            current->next = e2;
        }
    }
    int getSize() {
        int n = 0;
        ElementS<T>* current = begin;
        while (current->next != nullptr) { current = current->next; n++; }
        return n;
    }
    void insert(T place, int number) {
        if (place - 1 < getSize())
        {
            int i = 0;
            ElementS<T>* current = begin;
            while (i != place - 1) { current = current->next; i++; }
            ElementS<T>* e = new ElementS<T>(number);
            ElementS<T>* e2 = current->next;
            current->next = e;
            e->next = e2;
        }
    }

    ElementS<T>* find(T v) {
        ElementS* current = begin;
        while (current->next != nullptr) { if (current->value == v) { return current; } current = current->next; }
        return nullptr;
    }

    int index(int v) {
        ElementS<T>* current = begin;
        int i = 0;
        while (current->next != nullptr) {
            if (current->value == v) { return i; } i++; current = current->next;
        }
        return -1;
    }
    ElementS<T>* at(int index) {
        int i = 0;
        ElementS<T>* current = begin;
        while (current != nullptr) {
            if (i == index)
            {
                return current;
            }
            i++; current = current->next;
        }
        return nullptr;
    }
    void remove(T v) {
        if (begin->value == v)
        {
            ElementS* link = begin->next;
            delete begin;
            begin = link;
            return;
        }
        ElementS<T>* current = begin;
        while (current->next != nullptr) {
            if (current->next->value == v)
            {
                ElementS<T>* link = current->next->next;
                delete current->next;
                current->next = link;
                return;
            }
            current = current->next;
        }
    }

    void pop() {
        ElementS<T>* current = begin;
        while (current->next != nullptr)
        {
            current = current->next;
        }
        delete current->next;
        current->next = nullptr;
    }

    void print() {
        ElementS<T>* current = begin;
        while (current->next->next != nullptr) {
            cout << current->value;
            current = current->next;
        }
    }
};