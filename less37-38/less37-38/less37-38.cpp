#include <iostream>
#include "List.h"
using namespace std;

class Point {
public:
    float x;
    float y;
    float z;
    Point() : x(0), y(0), z(0){ }
    Point(float _x, float _y, float _z) : x(_x), y(_y), z(_z){ }
    void print() { printf("x:%f,y:%f,z:%f", x, y, z); }
};
unsigned int _hash(Point& p, int size) {
    unsigned int hash = 0;
    hash += (int)(p.x * 1000) << 20;
    hash += (int)(p.y * 1000) << 10;
    hash += (int)(p.z * 1000);
    hash %= size;
    return hash;
}
template <class T>
class ListHashTable {
public:
    DobleList<T>** table;
    int size;
    ListHashTable() : table(new DobleList<T>*[256]), size(256) { 
        for (int i = 0; i < 256; i++){ table[i] = nullptr; }
    }
    ListHashTable(int _size) : table(new DobleList<T>*[_size]), size(_size) { 
        for (int i = 0; i < _size; i++) { table[i] = nullptr; } 
    }
    void AddElement(T value) {
        int hash = _hash(value, size);
        if (table[hash] == nullptr) { table[hash] = new DobleList<T>(); }
        table[hash]->append(value);
    }
};

int main()
{
    ListHashTable<Point> t;
    for (int i = 0; i < 100; i++)
    {
        Point* p = new Point();
        p->x = (float)(rand() % 10000) / 100.0f;
        p->y = (float)(rand() % 10000) / 100.0f;
        p->z = (float)(rand() % 10000) / 100.0f;
        t.AddElement(*p);
    }
}
