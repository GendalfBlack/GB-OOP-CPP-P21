#pragma once
#include <iostream>
#include <Windows.h>
using namespace std;
template <typename Uliana>
class Element {
public:
	Uliana value;
	Element* next;
	Element* prev;
	Element() : value(0), next(nullptr), prev(nullptr) { }
	Element(Uliana v) : value(v), next(nullptr), prev(nullptr) { }
};
template <typename T>
class DobleList {
public:
	Element<T>* begin;
	Element<T>* end;
	DobleList() : begin(nullptr), end(nullptr) { }
	DobleList(T val) : begin(&val), end(&val) { }
	void append(T val) {
		Element<T>* new_el = new Element<T>(val);
		if (end == nullptr) { begin = new_el; end = new_el; return; }
		end->next = new_el;
		new_el->prev = end;
		end = new_el;
	}
	void append2(T val) {
		Element<T>* new_el = new Element<T>(val);
		if (end == nullptr) { begin = new_el; end = new_el; return; }
		begin->prev = new_el;
		new_el->next = begin;
		begin = new_el;
	}
	int getSize() {
		int n = 0;
		Element<T>* current = begin;
		while (current != nullptr) {
			n++;
			current = current->next;
		}
		return n;
	}
	void print() {
		Element<T>* current = begin;
		while (current != nullptr) {
			cout << current->value << ' ';
			current = current->next;
		}
	}
	Element<T>* find(T val) {
		Element<T>* current = begin;
		while (current != nullptr) {
			if (current->value == val)
			{
				return current;
			}
			current = current->next;
		}
		return nullptr;
	}
	Element<T>* at(int index) {
		int i = 0;
		Element<T>* current = begin;
		while (current != nullptr) {
			if (i == index)
			{
				return current;
			}
			i++; current = current->next;
		}
		return nullptr;
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
		Element<T>* current = begin;
		if (begin->value == val)
		{
			Element<T>* link = current->next;
			delete begin;
			begin = link;
			return;
		}
		while (current != nullptr) {
			if (current->value == val && current != nullptr)
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
		if (end->value == val)
		{
			Element<T>* link = current->prev;
			Element<T>* link2 = current->next;
			current->prev->next = link2;
			delete current;
			end = link;
			return;
		}
	}
	void removeAt(int index) {
		Element<T>* current = begin;
		int i = 0;
		if (index == 0)
		{
			Element<T>* link = current->next;
			delete begin;
			begin = link;
			return;
		}
		while (current->next != nullptr) {
			if (index == i && i != 0 && current != nullptr)
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
			current->next->prev = link;
			delete current;
			end = link;
			return;
		}
	}

	void insert(T val, int index)
	{
		Element<T>* new_element = new Element<T>(val);
		if (index == 0)
		{
			begin->prev = new_element;
			new_element->next = begin;
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

	void bubbleSort() {
		for (int i = 0; i < getSize(); i++) {
			Element<T>* current = begin;
			Element<T>* link = current->next;
			for (int j = 0; j < getSize() - 1; j++) {
				if (current->value > link->value && link != nullptr) {
					swap(current->value, link->value);
				}
				current = link;
				link = link->next;
			}
		}
	}
};

