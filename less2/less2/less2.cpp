#include <iostream>
using namespace std;

class Drib {
public:
    int ch;
    int zn;
    Drib() : ch(0), zn(1) { }
    Drib(int _ch, int _zn) : ch(_ch), zn(_zn) {
        if (_zn == 0) { cout << "Drib ne bulo stvoreno"; zn = 1; }
    }
    bool operator> (Drib& other) {
        return double(ch) / zn > double(other.ch) / other.zn;
    }
    bool operator< (Drib& other) {
        return double(ch) / zn < double(other.ch) / other.zn;
    }
    bool operator== (Drib& other) {
        return double(ch) / zn == double(other.ch) / other.zn;
    }
    void print() { 
        if (ch < zn)
        {
            cout << ch << '/' << zn << ",\t";
        }
        else {
            if (ch - zn * (ch / zn) > 0)
            {
                cout << ch / zn << ' ' << ch - zn * (ch / zn) << '/' << zn << ",\t";
            }
            else {
                cout << ch / zn << ",\t";
            }
        }
    }
};

int main()
{
    Drib* dribs = new Drib[15];
    for (int i = 0; i < 15; i++) { dribs[i] = Drib(rand() % 10 + 1, rand() % 10 + 1); dribs[i].print(); }
    for (int i = 0; i < 15; i++)
    {
        for (int j = 14; j > i; j--)
        {
            if (dribs[j] < dribs[j - 1])
            {
                swap(dribs[j], dribs[j - 1]);
            }

        }
    }
    cout << endl;
    for (int i = 0; i < 15; i++) { dribs[i].print(); }
}
