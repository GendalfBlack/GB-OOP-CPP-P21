#include <iostream>
using namespace std;

class A{
public: 
    int32_t a1;
    int32_t a2;
    A(): a1(1), a2(2) {}
    void fun() { cout << "A"; }
};

class B : public A {
public:
    int32_t b1;
    B(): b1(3) {}
    void fun() { cout << "B"; }
};

class C : public A{
public:
    int32_t c1;
    C() : c1(4) {}
    C(int32_t x1, int32_t x2, int32_t x3) : c1(x3) { a1 = x1; a2 = x2; }
    void fun() { cout << "C"; }
};

class D : public B, public C {
public:
    int32_t d1;
    D(): d1(0) {}
    void fun() { cout << "B"; }
};

int32_t main()
{

}
