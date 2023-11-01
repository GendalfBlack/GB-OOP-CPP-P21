#include <iostream>
using namespace std;

uint8_t _hash(const char* str) {
    uint8_t hash_number = 0;
    for (const char* current = str; *current != '\0'; current++)
    {
        hash_number += *current;
    }
    return hash_number;
}

class HashTable {
public:
    char** table;
    HashTable(): table(new char*[256]){
        for (int i = 0; i < 256; i++)
        {
            table[i] = new char[2];
            table[i][0] = '-';
            table[i][1] = '\0';
        }
    }
    void print() {
        int k = 0;
        for (int i = 0; i < 16; i++)
        {
            for (int j = 0; j < 16; j++)
            {
                cout << table[k] << ' ';
                k++;
            }
            cout << '\n';
        }
    }
};

int main()
{
    HashTable t;
    t.print();

    cout << (int)_hash("Sasha Garmash") << endl;
    cout << (int)_hash("Vladislav Dem`yanchuk") << endl;
    cout << (int)_hash("Ulya Goncharova") << endl;
    cout << (int)_hash("Artem Popov") << endl;
    cout << (int)_hash("Bogdan Shalovilo") << endl;
    cout << (int)_hash("Bogdan Iskachov") << endl;
    cout << (int)_hash("Danylo Mikhnevych") << endl;
    
}
