#include <iostream>
#include <conio.h>
#include <Windows.h>

using namespace std;
// ������ 1. �������� ������� ����������� ������ �������, ��'� �� ��-�������, 
// �� �� ����� ��������. ϳ��� ���� �������� �� ����� ���� �������������� � ������
// ��������(���� �� ��������). ϳ��� ���� �������� �� ���� �� ���� �������
// ����-��� � ������������ ������ ��������.

void cut(char* string) {
    while (*string != '\0' && *string != '\n') { string++; }
    *string = '\0';
}
// ���� - �� �������������� ��� �����. �� ������� �������. ���� ������ ����(���� �����) �� 
// ��������(������ �����). ���� ������� � ��� ��������. ���� ��������� ���������� ��������� �� 
// �������� �� �������.
class Student {
public:
    // ���� �����
    char gender;
    int age;
    char* name;
    char* middle_name;
    char* last_name;
    // �����������. �����(�������) �����, �� ����������� ����������� ��� �������� ��'���� 
    // �����(��������� �����). ��� ����� ������� �� 䳿 �� ����������� �� ���������� ������� ����.
    Student() {
        name = new char[30];
        last_name = new char[30];
        middle_name = new char[30];
    }
    // �����(�������) �����. � �� � ������ �� ��� ���� ������ ���������� ����� � ���� �� ��� ���������. �� ����� ������ 
    // ����� ��'���� ��� ��������������� ���������� �������� � ����� ��'���.
    void printStudent() {
        printf("ϲ�: %s %s %s\n�����: %c\t³�: %d\n", name, last_name, middle_name, gender, age);
    }

    void fillStudentInfo() {
        printf("������ ��'� ��������: ");
        cin.ignore(); fgets(name, 30, stdin); cut(name);
        printf("������ ������� ��������: ");
        fgets(last_name, 30, stdin); cut(last_name);
        printf("������ ��-������� ��������: ");
        fgets(middle_name, 30, stdin); cut(middle_name);

        printf("������ �� ��������: ");
        cin >> age;
        printf("������ ����� ��������: ");
        cin >> gender;
    }
    void changeName() {         printf("������ ��'� ��������: ");        cin.ignore(); fgets(name, 30, stdin);        cut(name); }
    void changeLastName() {     printf("������ ������� ��������: ");    cin.ignore(); fgets(last_name, 30, stdin);   cut(last_name); }
    void changeMiddleName() {   printf("������ ��-������� ��������: "); cin.ignore(); fgets(middle_name, 30, stdin); cut(middle_name); }
    void changeAge() {          printf("������ �� ��������: ");         cin >> age; }
    void changeGender() {       printf("������ ����� ��������: ");       cin >> gender; }
    // ����������. ����� ����� �� ����������� ����������� ���� ����� ��� �� �������(�� ��� 
    // ��������� ������ �������� ����). � ��� ����� �������� ���'��� �� ������� ����-�� ��'����
    // � ���������� ������ � ��'����� 䳿.
    ~Student() {
        delete[] name;
        delete[] last_name;
        delete[] middle_name;
    }
};



int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Student arr[5];
    Student s;
    while (true)
    {
        printf("������ ����� ��������(1-5) ��� ��������� ����������, ��� f ��� ���������");
        char a;
        cin >> a;
        switch (a)
        {
        case '1': arr[0] = Student(); arr[0].fillStudentInfo(); break;
        case '2': arr[1] = Student(); arr[1].fillStudentInfo(); break;
        case '3': arr[2] = Student(); arr[2].fillStudentInfo(); break;
        case '4': arr[3] = Student(); arr[3].fillStudentInfo(); break;
        case '5': arr[4] = Student(); arr[4].fillStudentInfo(); break;
        case 'f': break;
        default: break;
        }
        if (a == 'f') { break; }
        for (int i = 0; i < 5; i++) { cout << i+1 << ". "; arr[i].printStudent(); }
    }
    while (true)
    {
        printf("\n������� �������� ��� �����������(1-5):");
        
        int a;
        cin >> a;
        s = arr[a - 1];

        printf("\n1. ������� ��'�\n2. ������� �������\n3. ������� ��-�������\n4. ������� ��\n5. ������� �����\n");
        char b;
        cin >> b;
        switch (b)
        {
        case '1': s.changeName();       break;
        case '2': s.changeLastName();   break;
        case '3': s.changeMiddleName(); break;
        case '4': s.changeAge();        break;
        case '5': s.changeGender();     break;
        default:  break;
        }
        for (int i = 0; i < 5; i++) { cout << i+1 << ". "; arr[i].printStudent(); }
    }
}