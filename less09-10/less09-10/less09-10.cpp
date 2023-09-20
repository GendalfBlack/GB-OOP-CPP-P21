#include <iostream>
using namespace std; 

class Ratio {
    friend Ratio Multiply(Ratio r1, Ratio r2);
public:
    int nomenator;
    int denomenator;
    Ratio(int n, int d) : nomenator(n), denomenator(d){ }
    void print() { printf("%d/%d", nomenator, denomenator); }
};

Ratio Multiply(Ratio r1, Ratio r2) {
    return Ratio(r1.nomenator * r2.nomenator, r1.denomenator * r2.denomenator);
}

int main()
{
    Ratio r1(1, 2);
    Ratio r2(1, 3);
    Ratio r3 = Multiply(r1, r2);
    r3.print();
;}