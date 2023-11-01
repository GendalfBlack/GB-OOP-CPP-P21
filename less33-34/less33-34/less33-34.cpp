#include <iostream>
#include "BinaryTree.h"
#include "SingleList.h"

template <class T>
SingleList<T> mergeLists(SingleList<T>*& l1, SingleList<T>*& l2) {
	SingleList<T> l;
	for (int i = 0; i < l1->getSize(); i++){ l.append(l1->at(i)->value); }
	for (int i = 0; i < l2->getSize(); i++){ l.append(l2->at(i)->value); }
	return l;
}
template <class T>
DobleList<T> mergeLists(DobleList<T>*& l1, DobleList<T>*& l2) {
	DobleList<T> l;
	for (int i = 0; i < l1->getSize(); i++) { l.append(l1->at(i)->value); }
	for (int i = 0; i < l2->getSize(); i++) { l.append(l2->at(i)->value); }
	return l;
}
BinaryTreeNoRepeat* mergeTrees(BinaryTreeNoRepeat*& t1, BinaryTreeNoRepeat*& t2)
{
	DobleList<Node*> list1;
	t1->root->getElements(list1);
	DobleList<Node*> list2;
	t2->root->getElements(list2);
	BinaryTreeNoRepeat* t = new BinaryTreeNoRepeat();
	for (int i = 0; i < list1.getSize(); i++){	t->addValue(list1.at(i)->value->value); }
	for (int i = 0; i < list2.getSize(); i++){	t->addValue(list2.at(i)->value->value); }
	return t;
}

class MyString {
public:
	SingleList<char>* str;
	MyString() : str(new SingleList<char>()) { }
	MyString(const char* raw) : str(new SingleList<char>()) {
		const char* current = raw;
		for (; *current != '\0'; current++)	{ str->append(*current); }
		str->append(*current);
		str->append('\0');
	}
	void lower() {
		for (int i = 0; i < str->getSize(); i++)
		{
			if (str->at(i)->value >= 65 && str->at(i)->value <= 90) {
				str->at(i)->value += 32;
			}
		}
	}
	void upper() {
		for (int i = 0; i < str->getSize(); i++)
		{
			if (str->at(i)->value >= 97 && str->at(i)->value <= 122) {
				str->at(i)->value -= 32;
			}
		}
	}
	bool isAlpha() {
		for (int i = 0; i < str->getSize()-1; i++)
		{
			char c = str->at(i)->value;
			if (!((c >= 65 && c <= 90) || (c >= 97 && c <= 122))) {
				return false;
			}
		}
		return true;
	}
	bool isNumber() {
		for (int i = 0; i < str->getSize() - 1; i++)
		{
			char c = str->at(i)->value;
			if (!(c >= 48 && c <= 57)) {
				return false;
			}
		}
		return true;
	}
	void capitalize() {
		lower();
		if (str->at(0)->value >= 97 && str->at(0)->value <= 122) {
			str->at(0)->value -= 32;
		}
	}
	operator char* const() {
		char* s = new char[str->getSize()];
		for (int i = 0; i < str->getSize(); i++)
		{
			s[i] = str->at(i)->value;
		}
		return s;
	}
	void print() {
		str->print();
	}
};

int main()
{
	/*BinaryTreeNoRepeat* t1 = new BinaryTreeNoRepeat();
	BinaryTreeNoRepeat* t2 = new BinaryTreeNoRepeat();
	for (int i = 0; i < 5; i++)
	{
		t1->addValue(rand() % 100);
		t2->addValue(rand() % 100);
	}
	t1->print(); cout << '\n';
	t2->print(); cout << '\n';
	BinaryTreeNoRepeat* t = mergeTrees(t1,t2);
	t->print();*/

	MyString s("Hello World");
	s.print(); cout << '\n';
	s.lower();
	s.print(); cout << '\n';
	s.upper();
	s.print();
}