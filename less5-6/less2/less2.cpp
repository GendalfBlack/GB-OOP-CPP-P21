#include <iostream>
#include <Windows.h>

using namespace std;

class Student {
public:
    char* name;
    char* group;
    Student() : name(new char[30]), group(new char[10]) {}
    Student(const Student& s) {
        char* p2 = name; // ��������� ��������� �������� ��� ���������
        name = new char[30]; // �������� ���� ���'��� ��� ����
        for (char* p1 = s.name; *p1 != '\0'; p1++) { *p2 = *p1; p2++; } // ������� ��'�
        *p2 = '\0'; // ��������� ����� ���� ���������
        p2 = group; // ���� ���������� ���������
        group = new char[10]; // �������� ���� ���'��� ��� �����
        for (char* p1 = s.group; *p1 != '\0'; p1++) { *p2 = *p1; p2++; } // ������� �����
        *p2 = '\0'; // ��������� ����� ���� ���������
    }
    void print() { cout << name << ' ' << group << '\n'; }
};

int main()
{
    Student s1;
    cin >> s1.name;
    cin >> s1.group;
    s1.print();
    Student s2 = s1;
    s2.print();
    cin >> s1.group;
    s1.print();
    s2.print();
    
}
