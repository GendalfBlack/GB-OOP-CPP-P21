#include <fstream>
#include <iostream>
using namespace std;
class Abonent {
public:
    char* PIB;
    Abonent(): PIB(new char[50]){}
    Abonent(const char* name) {
        PIB = new char[50]; char* p2 = PIB;
        for (const char* p = name; *p != '\0' && *p != '\n'; p++) { *p2 = *p; p2++; }
        *p2 = '\0';
    }
    void print() { printf("%s", PIB); }
};

class Book {
public:
    Abonent* abonents;
    int size;
    Book() : abonents(new Abonent[0]), size(0){}
    void Add(Abonent& abonent) {
        Abonent* abonents2 = new Abonent[size + 1];
        for (int i = 0; i < size; i++){ abonents2[i] = abonents[i]; }
        abonents2[size] = abonent; delete[] abonents;
        abonents = abonents2;
        size++;
    }
    void Add(const char* path) {
        ifstream file;
        file.open(path, ifstream::in | ios::binary);
        Abonent a = Abonent();
        file.read(a.PIB, 50);
        file.close();
        Add(a);
    }
    void print() { for (int i = 0; i < size; i++) { printf("%d %s\n", i+1, abonents[i].PIB); } }
    
};

int main()
{
    Book book = Book();
    Abonent a1("Vladik");
    book.Add(a1);
    book.Add(R"(Z:\PKO\C++\OOP\P21\less09-10\less2\name.txt)");
    book.print();
}
