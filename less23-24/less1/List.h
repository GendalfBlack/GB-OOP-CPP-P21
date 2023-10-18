#pragma once
using namespace std;
template <class T>
class Element {
public:
    T value;
    Element<T>* next;
    Element<T>* prev;
    Element() : value(0), next(nullptr), prev(nullptr) { }
    Element(T v) : value(v), next(nullptr), prev(nullptr) { }
};

template <class T>
class List {
    Element<T>* begin;
    Element<T>* end;
public:
    List() : begin(nullptr), end(nullptr) {}
    void append(T val) {
        Element<T>* new_el = new Element<T>(val);
        if (end == nullptr) { begin = new_el; end = new_el; return; }
        end->next = new_el;
        new_el->prev = end;
        end = new_el;
    }
    void insert(T val, int index)
    {
        Element<T>* new_element = new Element<T>(val);
        if (index == 0)
        {
            new_element->next = begin;
            begin->prev = new_element;
            begin = new_element;
        }
        else if (index == getSize() - 1)
        {
            end->next = new_element;
            new_element->prev = end;
            end = new_element;
        }
        else
        {
            Element<T>* current = begin->next;
            int i = 1;
            while (current->next != nullptr)
            {
                if (index == i) {
                    Element<T>* link = current->prev;
                    Element<T>* link2 = current;
                    link->next = new_element;
                    new_element->prev = link;
                    new_element->next = link2;
                    link2->prev = new_element;
                }
                current = current->next;
                i++;
            }
        }
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
        while (current != nullptr) {
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
    T at(int index) {
        int i = 0;
        Element<T>* current = begin;
        while (current != nullptr) {
            if (i == index)
            {
                return current->value;
            }
            i++; current = current->next;
        }
    }
    T operator[](int index) { return at(index); }

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
        if (begin->value == val)
        {
            Element<T>* link = begin->next;
            delete begin;
            begin = link;
            return;
        }
        Element<T>* current = begin->next;
        while (current->next != nullptr) {
            if (current->value == val && current->next != nullptr)
            {
                Element<T>* link = current->prev;
                Element<T>* link2 = current->next;
                current->prev->next = link2;
                current->next->prev = link;
                delete current;
                return;
            }
            current = current->next;
        }
        if (current->value == val)
        {
            Element<T>* link = current->prev;
            Element<T>* link2 = current->next;
            current->prev->next = link2;
            delete current;
            end = link;
        }
    }
    void removeAt(int index) {
        int i = 0;
        if (index == 0)
        {
            Element<T>* link = begin->next;
            delete begin;
            begin = link;
            return;
        }
        Element<T>* current = begin;
        while (current->next != nullptr) {
            if (index == i && i != 0 && current->next != nullptr)
            {
                Element<T>* link = current->prev;
                Element<T>* link2 = current->next;
                current->prev->next = link2;
                current->next->prev = link;
                delete current;
                return;
            }
            current = current->next;
            i++;
        }
        if (i == getSize() - 1)
        {
            Element<T>* link = current->prev;
            Element<T>* link2 = current->next;
            current->prev->next = link2;
            delete current;
            end = link;
        }
    }
    void removeAll(T val) {
        if (begin->value == val)
        {
            Element<T>* link = begin->next;
            delete begin;
            begin = link;
        }
        Element<T>* current = begin->next;
        while (current->next != nullptr) {
            if (current->value == val && current->next != nullptr)
            {
                Element<T>* link = current->prev;
                Element<T>* link2 = current->next;
                current->prev->next = link2;
                current->next->prev = link;
                delete current;
            }
            current = current->next;
        }
        if (current->value == val)
        {
            Element<T>* link = current->prev;
            Element<T>* link2 = current->next;
            current->prev->next = link2;
            delete current;
            end = link;
        }
    }
};